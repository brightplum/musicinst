<?php


function mic_wufoo_profiles_form() {
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Start'),
  );

  return $form;
}

function mic_wufoo_profiles_form_submit(&$form, &$form_state) {
  $form_id = 'm7p7s5';
  $operations = array();

  $wufoo = new WufooApiWrapper(WUFOO_API, WUFOO_SUBDOMAIN);
  $form = $wufoo->getFields($form_id);
  mic_wufoo_profiles_fieldmap($form->Fields);

  $count = $wufoo->getEntryCount($form_id);
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
        if ($tid) {
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
      }
    }
    else {
      $tid = _mic_wufoo_taxonomy_lookup($field->Title);
      if ($tid) {
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
    }
  }
  variable_set('mic_wufoo_fieldmap', $map);
  return;
}

function mic_wufoo_profiles_batch_import($entry, &$context) {
  $entry = (array) $entry;
  $firstname = mic_wufoo_profiles_firstname($entry);
  $lastname = mic_wufoo_profiles_lastname($entry);
  $title = mic_wufoo_profiles_title($entry);
  $suffix = mic_wufoo_profiles_suffix($entry);
  $titles = mic_wufoo_profiles_titles($entry);
  $body = mic_wufoo_profiles_body($entry);

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
  $node->field_prefix[LANGUAGE_NONE][0]['value'] = $title;
  $node->field_first_name[LANGUAGE_NONE][0]['value'] = $firstname;
  $node->field_last_name[LANGUAGE_NONE][0]['value'] = $lastname;
  $node->field_suffix[LANGUAGE_NONE][0]['value'] = $suffix;
  $node->field_job_title[LANGUAGE_NONE][0]['value'] = $titles;

  $node->body[LANGUAGE_NONE][0]['value'] = $body;
  $node->body[LANGUAGE_NONE][0]['format'] = 'full_html';

  node_save($node);

  $context['message'] = t('Imported profile %title', array('%title' => $$name));
}

function mic_wufoo_profiles_batch_finished($success, $results, $operations) {
  if ($success) {
    drupal_set_message(t('Import successful'));
  }
}

function mic_wufoo_profiles_firstname($entry) {
  return $entry['Field1343'];
}

function mic_wufoo_profiles_lastname($entry) {
  return $entry['Field1344'];
}

function mic_wufoo_profiles_title($entry) {
  return $entry['Field1342'];
}

function mic_wufoo_profiles_suffix($entry) {
  return $entry['Field1345'];
}

function mic_wufoo_profiles_titles($entry) {
  return $entry['Field1336'];
}

function mic_wufoo_profiles_body($entry) {
  $body = array();
  $ignore = array(
    'Field1343',
    'Field1344',
    'Field1342',
    'Field1345',
    'Field1336',
    'Field1235',
    'Field1236',
  );
  $map = variable_get('mic_wufoo_fieldmap', array());
  foreach ($entry as $key => $value) {
    if ((isset($map[$key]['tid']) || in_array($key, $ignore)) || (!_mic_wufoo_fieldcheck($key))) {
      continue;
    }
    $body[] = $map[$key]['title'] . '<br />' . $value;
  }

  return implode('<br /><hr><br />', $body);
}

function mic_wufoo_profiles_namelookup($name) {
  $result = db_select('node', 'n')
    ->fields('n', array('nid'))
    ->condition('title', $name)
    ->execute()
    ->fetchCol();
  return reset($result);
}