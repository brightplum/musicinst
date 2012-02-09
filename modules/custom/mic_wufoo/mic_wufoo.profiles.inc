<?php
/**
 * @file
 * Import profile information from wufoo
 */

/**
 * Import start form
 *
 * @return array
 */
function mic_wufoo_profiles_form() {
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Start'),
  );

  return $form;
}

/**
 * Submit handler for profile import form
 *
 * @param array $form
 * @param array $form_state
 */
function mic_wufoo_profiles_form_submit(&$form, &$form_state) {
  $form_id = 'm7p7s5';
  $operations = array();

  $wufoo = new WufooApiWrapper(WUFOO_API, WUFOO_SUBDOMAIN);
  $form = $wufoo->getFields($form_id);
  mic_wufoo_profiles_fieldmap($form->Fields);
  mic_wufoo_profiles_set_ignore(NULL, TRUE);

  $count = $wufoo->getEntryCount($form_id);
  //25 entries at a time
  for ($i=0; $i <= $count; $i+=25) {
    $entries = $wufoo->getEntries($form_id, 'forms', 'pageStart=' . $i);
    foreach ($entries as $id => $entry) {
      $operations[] = array('mic_wufoo_profiles_batch_import', array($entry));
    }
  }
  $batch = array(
    'operations' => $operations,
    'finished' => 'mic_wufoo_profiles_batch_finished',
    'file' => drupal_get_path('module', 'mic_wufoo') . '/mic_wufoo.profiles.inc',
  );

  batch_set($batch);
}

/**
 * Map fields to values and taxonomy tid's to be referenced later
 *
 * @param array $fields
 */
function mic_wufoo_profiles_fieldmap($fields) {
  $map = array();
  foreach ($fields as $id => $field) {
    if (!_mic_wufoo_fieldcheck($id)) {
      continue;
    }
    $sub_fields = (isset($field->SubFields)) ? $field->SubFields : FALSE;
    if ($sub_fields) {
      foreach ($sub_fields as $sub_id => $sub_field) {
        $tid = _mic_wufoo_taxonomy_lookup($sub_field->Label);
        if (!empty($tid)) {
          $map[$sub_id] = array(
            'title' => $sub_field->Label,
            'tid' => $tid,
          );
        }
        else {
          $map[$sub_id] = array(
            'title' => $sub_field->Label,
          );
        }
        mic_wufoo_profiles_set_ignore($sub_id);
      }
    }
    else {
      $tid = _mic_wufoo_taxonomy_lookup($field->Title);
      if (!empty($tid)) {
        $map[$id] = array(
          'title' => $field->Title,
          'tid' => $tid,
        );
      }
      else {
        $map[$id] = array(
          'title' => $field->Title,
        );
      }
      mic_wufoo_profiles_set_ignore($id);
    }
  }
  variable_del('mic_wufoo_fieldmap');
  variable_set('mic_wufoo_fieldmap', $map);
  return;
}

/**
 * Perform import
 *
 * @param mixed $entry
 * @param array $context
 */
function mic_wufoo_profiles_batch_import($entry, &$context) {
  $entry = (array) $entry;
  $firstname = mic_wufoo_profiles_firstname($entry);
  $lastname = mic_wufoo_profiles_lastname($entry);
  $title = mic_wufoo_profiles_title($entry);
  $suffix = mic_wufoo_profiles_suffix($entry);
  $titles = mic_wufoo_profiles_titles($entry);
  $body = mic_wufoo_profiles_body($entry);

  $terms = mic_wufoo_profiles_terms($entry);

  $name = $firstname . ' ' . $lastname;

  //check if profile exists
  $nid = mic_wufoo_profiles_namelookup($name);
  if ($nid) {
    $node = node_load($nid);
    //something's up with image field
    unset($node->field_image);
  }
  else {
    $node = new stdClass();
    $node->type = 'profile';
    $node->language = LANGUAGE_NONE;
    node_object_prepare($node);
  }

  $node->title = $name;
  $node->uid = 4;
  $node->field_prefix[LANGUAGE_NONE][0]['value'] = $title;
  $node->field_first_name[LANGUAGE_NONE][0]['value'] = $firstname;
  $node->field_last_name[LANGUAGE_NONE][0]['value'] = $lastname;
  $node->field_suffix[LANGUAGE_NONE][0]['value'] = $suffix;
  $node->field_job_title[LANGUAGE_NONE][0]['value'] = $titles;

  //terms
  if ($terms['program']) {
    $node->field_profile_program_area[LANGUAGE_NONE] = $terms['program'];
  }

  if ($terms['instrument']) {
    $node->field_profile_instrument[LANGUAGE_NONE] = $terms['instrument'];
  }

  $node->body[LANGUAGE_NONE][0]['value'] = $body;
  $node->body[LANGUAGE_NONE][0]['format'] = 'full_html';

  node_save($node);

  $context['message'] = t('Imported profile %title', array('%title' => $name));
}

/**
 * Import successful callback
 *
 * @param unknown_type $success
 * @param unknown_type $results
 * @param unknown_type $operations
 */
function mic_wufoo_profiles_batch_finished($success, $results, $operations) {
  if ($success) {
    drupal_set_message(t('Import successful'));
  }
}

function mic_wufoo_profiles_firstname($entry) {
  mic_wufoo_profiles_set_ignore('Field1343');
  return $entry['Field1343'];
}

function mic_wufoo_profiles_lastname($entry) {
  mic_wufoo_profiles_set_ignore('Field1344');
  return $entry['Field1344'];
}

function mic_wufoo_profiles_title($entry) {
  mic_wufoo_profiles_set_ignore('Field1342');
  return $entry['Field1342'];
}

function mic_wufoo_profiles_suffix($entry) {
  mic_wufoo_profiles_set_ignore('Field1345');
  return $entry['Field1345'];
}

function mic_wufoo_profiles_titles($entry) {
  mic_wufoo_profiles_set_ignore('Field1346');
  return $entry['Field1336'];
}

function mic_wufoo_profiles_body($entry) {
  $body = array();
  $ignore = mic_wufoo_profiles_get_ignore();

  $map = variable_get('mic_wufoo_fieldmap', array());
  foreach ($entry as $key => $value) {
    if ((isset($map[$key]['tid']) || in_array($key, $ignore)) || (!_mic_wufoo_fieldcheck($key))) {
      continue;
    }
    if ($value) {
      $body[] = $map[$key]['title'] . '<br />' . $value;
    }
  }

  return implode('<br /><hr><br />', $body);
}

function mic_wufoo_profiles_terms($entry) {
  $terms = array();
  $instrument = taxonomy_vocabulary_machine_name_load('instrument');
  $program = taxonomy_vocabulary_machine_name_load('program_area');
  $map = variable_get('mic_wufoo_fieldmap', array());

  foreach ($entry as $key => $value) {
    if ((!_mic_wufoo_fieldcheck($key)) || !$value) {
      continue;
    }
    else if (isset($map[$key]['tid'])) {
      $term = taxonomy_term_load($map[$key]['tid']);
      if ($term->vid == $instrument->vid) {
        $terms['instrument'][]['tid'] = $map[$key]['tid'];
      }
      else if ($term->vid == $program->vid) {
        $terms['program'][]['tid'] = $map[$key]['tid'];
      }
      mic_wufoo_profiles_set_ignore($key);
    }
    else if (is_int(strpos($value, 'Suzuki')) && (strlen($value) < 30)) {
      $suzuki_inst = substr($value, 7);
      $suzuki_inst_tid = _mic_wufoo_taxonomy_lookup($suzuki_inst);
      $suzuki_tid = _mic_wufoo_taxonomy_lookup('Suzuki Instruction');
      $terms['program'][]['tid'] = $suzuki_tid;
      if ($suzuki_inst_tid) {
        if (!in_array($suzuki_inst_tid, $terms['instrument'])) {
          $terms['instrument'][]['tid'] = $suzuki_inst_tid;
        }
      }
    }
  }
  return $terms;
}

/**
 * Helper to lookup if profile with name already exists
 * Returns the nid if found
 *
 * @param string $name
 * @return int
 */
function mic_wufoo_profiles_namelookup($name) {
  $result = db_select('node', 'n')
    ->fields('n', array('nid'))
    ->condition('title', $name)
    ->execute()
    ->fetchCol();
  return reset($result);
}

function mic_wufoo_profiles_get_ignore() {
  return variable_get('mic_wufoo_ignore');
}

/**
 * Ignore fields so body doesn't reprint
 *
 * @param string $value
 * @param bool $reset
 */
function mic_wufoo_profiles_set_ignore($value, $reset = FALSE) {
  $ignore = variable_get('mic_wufoo_ignore', array());
  if ($reset) {
    variable_del('mic_wufoo_ignore');
    $ignore = array(
      'Field410',
      'Field411',
      'Field412',
      'Field413',
      'Field414',
      'Field415',
      'Field416',
      'Field417',
      'Field418',
      'Field419',
      'Field208',
      'Field1235',
      'Field1236',
    );
  }
  $ignore[] = $value;
  $ignore = drupal_map_assoc($ignore);
  variable_set('mic_wufoo_ignore', $ignore);
}