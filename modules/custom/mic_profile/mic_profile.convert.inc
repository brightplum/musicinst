<?php
/**
 * @file
 * Convert profile information from body text to fields
 */

/**
 * Convert start form
 *
 * @return array
 */
function mic_profile_convert_form() {
  $form['choice'] = array(
    '#title' => t('Choose'),
    '#type' => 'radios',
    '#options' => array('body' => 'Convert body to profile fields', 'tags' => 'Convert tags to other vocabs'),
    '#required' => TRUE,
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Start'),
  );

  return $form;
}

/**
 * Submit handler for profile convert form
 *
 * @param array $form
 * @param array $form_state
 */
function mic_profile_convert_form_submit(&$form, &$form_state) {
  $operations = array();
  $profiles = mic_profile_get_profiles();
  $file = drupal_get_path('module', 'mic_profile') . '/mic_profile.convert.inc';
  $finished = 'mic_profile_convert_batch_finished';
  $skip = FALSE;

  switch ($form_state['values']['choice']) {
    case 'body':
      $callback = 'mic_profile_convert_batch_import';
      break;
    case 'tags':
      $callback = 'mic_profile_convert_tags_import';
      break;
    default:
      drupal_set_message('Nothing to convert.');
      $skip = TRUE;
      break;
  }

  if (!$skip) {
    foreach ($profiles as $profile) {
      $operations[] = array($callback, array($profile));
    }
    $batch = array(
      'operations' => $operations,
      'finished' => $finished,
      'file' => $file,
    );
    batch_set($batch);
  }
}

/**
 * Parse body text and push into individual fields.
 *
 * @param $profile
 * @param $context
 */
function mic_profile_convert_batch_import($profile, &$context) {
  $node = node_load($profile->nid, $profile->vid);
  $body = $node->body[LANGUAGE_NONE][0];
  $chunks = explode('<br>', $body['value']);
  $step = 2;
  if (count($chunks) <= 1) {
    $chunks = explode('<br />', $body['value']);
    $step = 3;
  }

  // Find question in chunk. Process answer.
  foreach (mic_profile_convert_mapping() as $mapping) {
    for ($i = 0; $i < count($chunks); $i += $step) {
      if (strpos($chunks[$i], $mapping['question']) !== FALSE) {
        $field = $mapping['field'];
        $text = strip_tags($chunks[$i+1]);
        if (!empty($text)) {
          $node->$field = array(
            LANGUAGE_NONE => array(
              array(
                'value' => $text,
              ),
            ),
          );
        }
        break;
      }
    }
  }
  node_save($node);

  $context['message'] = t('Converted profile %title', array('%title' => $node->title));
}

function mic_profile_convert_batch_finished($success, $results, $operations) {
  if ($success) {
    drupal_set_message(t('Convert successful.'));
  }
}

function mic_profile_convert_tags_import($profile, &$context) {
  $node = node_load($profile->nid, $profile->vid);
  $tags = field_get_items('node', $node, 'field_tags');
  $save = FALSE;
  $vocabs = array(
    'instrument',
    'program_area',
  );

  if (is_array($tags)) {
    $terms = array();
    foreach ($vocabs as $vocab) {
      foreach($tags as $tag) {
        $full_tag = taxonomy_term_load($tag['tid']);
        $term = taxonomy_get_term_by_name($full_tag->name, $vocab);
        if (is_array($term) && !empty($term)) {
          $term = reset($term);
          $terms[$vocab][] = $term->tid;
        }
      }
      if (!empty($terms[$vocab]) && isset($terms[$vocab])) {
        module_load_include('inc', 'mic_profile', 'mic_profile.form');
        $field = 'field_profile_' . $vocab;
        $node->{$field} = array(
          LANGUAGE_NONE => mic_profile_terms($terms[$vocab]),
        );
        if (!$save) {
          $save = TRUE;
        }
      }
    }
    if ($save) {
      node_save($node);
      $context['message'] = t('Converted profile tags for %title', array('%title' => $node->title));
    }
  }
}

/**
 * Mapping of questions and fields
 *
 * @return array
 */
function mic_profile_convert_mapping() {
  $mapping = array();
  $mapping[] = array('question' => 'Education','field' => 'field_profile_education');
  $mapping[] = array('question' => 'Hire Date','field' => 'field_profile_hire_date');
  $mapping[] = array('question' => 'Joined MIC','field' => 'field_profile_hire_date');
  $mapping[] = array('question' => 'With whom did you study','field' => 'field_profile_mentors');
  $mapping[] = array('question' => 'Basic Teaching Philosophy','field' => 'field_profile_expertise');
  $mapping[] = array('question' => 'Additional Studies','field' => 'field_profile_awards');
  $mapping[] = array('question' => 'Professional Affiliations','field' => 'field_profile_affiliations');
  $mapping[] = array('question' => 'Interests Outside of Music','field' => 'field_profile_interests');
  $mapping[] = array('question' => 'Favorite Quote','field' => 'field_profile_quote');
  $mapping[] = array('question' => 'Favorite Practice Tip','field' => 'field_profile_practice');
  $mapping[] = array('question' => 'Favorite Composer or piece to play','field' => 'field_profile_composer');
  $mapping[] = array('question' => 'Favorite Personal Musical Moment','field' => 'field_profile_moments');

  return $mapping;
}