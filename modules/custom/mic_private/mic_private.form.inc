<?php
/**
 * @file
 * Forms for MIC Private Registration functionality
 */

/**
 * Private Registration form
 * Requires auth code match to be visible
 *
 * @param $form
 * @param $form_state
 * @return array|void
 */
function mic_private_private_registration_form($form, &$form_state) {
  // Student Information
  $form['student'] = array(
    '#type' => 'fieldset',
    '#title' => t('Student Information'),
  );
  $form['student']['type'] = array(
    '#type' => 'select',
    '#title' => t('Student Type'),
    '#options' => array('New or Returning', 'Continuing'),
  );
  $form['student']['family_record'] = array(
    '#type' => 'textfield',
    '#title' => t('Family Record ID'),
    '#size' => 15,
  );
  $form['student']['first'] = array(
    '#prefix' => '<div class="inline">',
    '#type' => 'textfield',
    '#title' => t('First Name'),
    '#size' => 30,
    '#required' => TRUE,
  );
  $form['student']['last'] = array(
    '#type' => 'textfield',
    '#title' => t('Last Name'),
    '#size' => 30,
    '#required' => TRUE,
    '#suffix' => '</div>',
  );
  $form['student']['birthdate'] = array(
    '#type' => 'textfield',
    '#title' => t('Birthdate'),
    '#size' => 15,
  );
  $form['student']['gender'] = array(
    '#type' => 'select',
    '#title' => t('Gender'),
    '#options' => array('' => '- Select - ', 'Male', 'Female', 'Other'),
  );
  $form['student']['ethnicity'] = array(
    '#type' => 'select',
    '#title' => t('Ethnicity'),
    '#options' => array(
      '' => '- Select - ',
      'American Indian or Alaskan Native',
      'Asian',
      'Black/African-American',
      'Native Hawaiian or Other Pacific Islander',
      'Hispanic/Latino',
      'White',
      'Two or more races/ethnicities',
    ),
    '#description' => t('Each year, foundations & corporations supporting MIC with grants ask us to provide information about the race & ethnicity of our student. This voluntary information is confidential and will only be used to form aggregate numbers for our programs.'),
  );
  $form['student']['school'] = array(
    '#prefix' => '<div class="inline">',
    '#type' => 'textfield',
    '#title' => t('School'),
    '#size' => 15,
  );
  $form['student']['school_location'] = array(
    '#type' => 'textfield',
    '#title' => t('School Location'),
    '#size' => 15,
    '#suffix' => '</div>',
  );
  $form['student']['instrument'] = array(
    '#type' => 'textfield',
    '#title' => t('Instrument'),
    '#size' => 15,
  );

  // Instructor Information
  $form['instruction'] = array(
    '#type' => 'fieldset',
    '#title' => t('Instruction Information'),
  );

  $form['instruction']['type'] = array(
    '#type' => 'select',
    '#title' => t('Type'),
    '#options' => array(
      '' => '- Select -',
      'suzuki' => 'Suzuki',
      'musicianship' => 'Musicianship',
    ),
  );

  $options = mic_private_get_list('profile');

  $form['instruction']['instructor'] = array(
    '#type' => 'select',
    '#title' => t('Instructor'),
    '#options' => $options,
  );
  $form['instruction']['day'] = array(
    '#prefix' => '<div class="inline">',
    '#type' => 'select',
    '#title' => t('Requested Day'),
    '#options' => array(
      '' => '- Select -',
      'Sunday',
      'Monday',
      'Tuesday',
      'Wednesday',
      'Thursday',
      'Friday',
      'Saturday',
    ),
  );
  $form['instruction']['time'] = array(
    '#type' => 'textfield',
    '#title' => t('Requested Time'),
    '#size' => 15,
  );
  $form['instruction']['length'] = array(
    '#type' => 'select',
    '#title' => t('Length'),
    '#options' => array(
      '' => '- Select - ',
      '20' => '20 minutes',
      '30' => '30 minutes',
      '45' => '45 minutes',
      '60' => '60 minutes',
    ),
    '#suffix' => '</div>',
  );

  $form['instruction']['campus'] = array(
    '#type' => 'select',
    '#title' => t('Location'),
    '#options' => array('' => '- Select -') + mic_profile_get_taxonomy_options('campus'),
  );

  $options = mic_private_get_additional_classes('suzuki');
  $form['suzuki'] = array(
    '#type' => 'select',
    '#title' => t('Additional Suzuki Repertoire Class'),
    '#options' => $options,
  );

  $options = mic_private_get_additional_classes('musicianship');
  $form['musicianship'] = array(
    '#type' => 'select',
    '#title' => t('Additional Musicianship Class'),
    '#options' => $options,
  );

  // Discounts
  $form['discount'] = array(
    '#type' => 'fieldset',
    '#title' => t('Discounts'),
  );

  $form['discount']['multiple'] = array(
    '#type' => 'select',
    '#title' => t('Are you registering more than one student?'),
    '#options' => array('No', 'Yes'),
  );

  $form['discount']['senior'] = array(
    '#type' => 'select',
    '#title' => t('Are you a senior?'),
    '#options' => array('No', 'Yes'),
  );

  $form['discount']['staff'] = array(
    '#type' => 'select',
    '#title' => t('Are you a MIC staff member?'),
    '#options' => array('No', 'Yes'),
  );

  // Payment
  $form['payment'] = array(
    '#type' => 'fieldset',
    '#title' => t('Payment Information'),
  );

  $form['payment']['payment'] = array(
    '#type' => 'select',
    '#title' => t('Choose Payment Option'),
    '#options' => array(
      'full' => 'Pay in full now',
      'installment' => 'Pay $225 now. Balance spread over 3 additional payments.',
      'partial' => 'Pay $500 now. Balance invoiced in 30 days.',
      'financialaid' => 'Financial Aid: Pay $160 now. Balance invoiced in 30 days.',
    ),
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Get Price and Review'),
  );

  $form['#attached']['css'] = array(
    drupal_get_path('module', 'mic_private') . '/css/mic_private.css',
  );

  return $form;
}

/**
 * Validate profile form
 * Grab uploaded headshot file
 *
 * @param $form
 * @param $form_state
 */
function mic_private_private_registration_form_validate($form, &$form_state) {
  $file = file_save_upload('headshot', array(
    'file_validate_is_image' => array(), // Validates file is really an image.
    'file_validate_extensions' => array('png gif jpg jpeg'), // Validate extensions.
  ));
  // If the file passed validation:
  if ($file) {
    // Move the file, into the Drupal file system
    if ($file = file_move($file, 'public://')) {
      // Save the file for use in the submit handler.
      $form_state['storage']['file'] = $file;
    }
    else {
      form_set_error('file', t('Failed to write the uploaded file the site\'s file folder.'));
    }
  }
}

/**
 * Save profile from form
 *
 * @param $form
 * @param $form_state
 */
function mic_private_private_registration_form_submit($form, &$form_state) {
  $firstname = $form_state['values']['first'];
  $lastname = $form_state['values']['last'];
  $name = $firstname . ' ' . $lastname;

  //save headshot
  if ($file = $form_state['storage']['file']) {
    unset($form_state['storage']['file']);
    $file->status = FILE_STATUS_PERMANENT;
    file_save($file);
  }

  //check if profile exists
  $nid = mic_profile_namelookup($name);
  if ($nid) {
    $node = node_load($nid);
  }
  else {
    $node = new stdClass();
    $node->type = 'profile';
    $node->language = LANGUAGE_NONE;
    node_object_prepare($node);
    $node->status = 0;
  }

  $node->title = $form_state['values']['title'] . ' ' . $name . ' ' . $form_state['values']['suffix'];
  $node->uid = 4;
  $node->field_prefix[LANGUAGE_NONE][0]['value'] = $form_state['values']['title'];
  $node->field_first_name[LANGUAGE_NONE][0]['value'] = $firstname;
  $node->field_last_name[LANGUAGE_NONE][0]['value'] = $lastname;
  $node->field_suffix[LANGUAGE_NONE][0]['value'] = $form_state['values']['suffix'];
  $node->field_job_title[LANGUAGE_NONE][0]['value'] = $form_state['values']['titles'];

  //headshot
  if (isset($file->fid)) {
    $node->field_image[LANGUAGE_NONE][0] = (array) $file;
  }

  //program areas
  $node->field_profile_program_area[LANGUAGE_NONE] = mic_profile_terms($form_state['values']['program_areas']);

  //campus
  $node->field_profile_campus[LANGUAGE_NONE] = mic_profile_terms($form_state['values']['campus']);

  //instruments
  $instruments = array();
  foreach (mic_profile_instruments() as $key => $instrument) {
    $instruments += $form_state['values'][$key];
  }
  $node->field_profile_instruments[LANGUAGE_NONE] = mic_profile_terms($instruments);

  //profile fields
  $textareas = array(
    'field_profile_hire_date' => 'hire_date',
  );
  $textareas += mic_profile_textareas();
  foreach ($textareas as $key => $textarea) {
    if (isset($form_state['values'][$key]) && !empty($form_state['values'][$key])) {
      $node->$key = array(
        LANGUAGE_NONE => array(
          array(
            'value' => $form_state['values'][$key],
          ),
        ),
      );
    }
  }

  node_save($node);

  drupal_goto("add/profile/$node->nid/thankyou");
}

/**
 * Helper to get list of nodes as option
 *
 * @param $bundle
 * @return array
 */
function mic_private_get_list($bundle) {
  $options = array('' => '- Select -');
  $query = new EntityFieldQuery();
  $query
    ->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', $bundle)
    ->propertyOrderBy('title');
  $result = $query->execute();
  $nids = array_keys($result['node']);
  $nodes = node_load_multiple($nids);
  foreach ($nodes as $node) {
    $options[$node->nid] = $node->title;
  }

  return $options;
}

function mic_private_get_additional_classes($type) {
  $options = array('' => '- Select -');
  $query = new EntityFieldQuery();
  $query
    ->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'pi_additional_classes')
    ->fieldCondition('field_pi_class_type', 'value', $type);
  $result = $query->execute();
  $nids = array_keys($result['node']);
  $nodes = node_load_multiple($nids);
  $fields = array(
    'field_pi_class_display',
    'field_pi_class_age',
    'field_pi_class_length_class',
    'field_pi_class_duration',
    'field_pi_class_day',
    'field_pi_class_time',
    'field_instructor_reference',
    'field_location_reference',
  );
  foreach ($nodes as $node) {
    $display = array();
    foreach ($fields as $field) {
      $field_option = mic_private_get_field_display('node', $node, $field);
      if (!empty($field_option)) {
        $display[] = $field_option;
      }
    }
    $options[$node->nid] = implode(' | ', $display);
  }

  return $options;
}

function mic_private_get_field_display($entity_type, $entity, $field) {
  $field = field_get_items($entity_type, $entity, $field);
  $field = is_array($field) ? reset($field) : $field;
  $key = key($field);
  if ($key == 'nid') {
    $field = node_load($field[$key]);
    $field = $field->title;
  }
  elseif ($key == 'tid') {
    $field = taxonomy_term_load($field[$key]);
    $field = $field->name;
  }
  else {
    $field = $field[$key];
  }
  return $field;
}

/**
 * Format form values for term saving
 *
 * @param $form_values
 * @return array
 */
function mic_profile_terms($form_values) {
  $terms = array();
  foreach ($form_values as $term) {
    if ($term != 0) {
      $terms[]['tid'] = $term;
    }
  }

  return $terms;
}
