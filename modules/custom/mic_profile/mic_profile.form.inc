<?php
/**
 * @file
 * Forms for MIC Profile functionality
 */

/**
 * Custom profile add form
 * Requires auth code match to be visible
 *
 * @param $form
 * @param $form_state
 * @return array|void
 */
function mic_profile_add_profile_form($form, &$form_state) {
  $parameters = drupal_get_query_parameters();
  if (isset($parameters['auth'])) {
    if (!mic_profile_salt($parameters['auth'])) {
      return drupal_not_found();
    }
  }
  else {
    return drupal_not_found();
  }

  drupal_add_css(drupal_get_path('module', 'mic_profile') . '/css/mic_profile.css', 'file');

  //name
  $form['name'] = array(
    '#type' => 'fieldset',
    '#title' => t('Name'),
    '#description' => t('Please type your name as you wish it to appear to the public including prefix/suffix as applicable.
Example:  Dr. Jonathan S. Smith'),
  );
  $form['name']['title'] = array(
    '#prefix' => '<div class="inline">',
    '#type' => 'textfield',
    '#title' => t('Title'),
    '#size' => 15,
  );
  $form['name']['first'] = array(
    '#type' => 'textfield',
    '#title' => t('First'),
    '#size' => 30,
    '#required' => TRUE,
  );
  $form['name']['last'] = array(
    '#type' => 'textfield',
    '#title' => t('Last'),
    '#size' => 30,
    '#required' => TRUE,
  );
  $form['name']['suffix'] = array(
    '#type' => 'textfield',
    '#title' => t('Suffix'),
    '#size' => 15,
    '#suffix' => '</div>',
  );

  //titles
  $form['titles'] = array(
    '#type' => 'textfield',
    '#title' => t('MIC Title(s)'),
    '#description' => t('Are you a department head, or Program Director?
Please indicate your faculty titles here.  If you also have an administrative role at MIC, that information will be handled elsewhere.'),
  );

  //headshot
  $form['headshot'] = array(
    '#type' => 'file',
    '#title' => t('Attach your photo here'),
    '#description' => t('Upload your professional head shot. If you don\'t have one or want a new one, contact Mike Canale for your free headshot at musicinst.org/office. Allowed extensions: jpg, jpeg, png, gif'),
  );

  //program areas
  $form['program_areas'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Program Area(s)'),
    '#options' => mic_profile_get_taxonomy_options('program_area'),
    '#description' => t('Please select the program areas with which you are affiliated.  Only include areas for which you have been hired to teach at MIC.'),
    '#required' => TRUE,
  );

  foreach (mic_profile_instruments() as $key => $instrument) {
    $form[$key] = array(
      '#type' => 'checkboxes',
      '#title' => $instrument['label'],
      '#options' => mic_profile_get_taxonomy_options('instrument', $instrument['term']),
      '#description' => t('Please select your instrument affiliations (include only the instruments for which you have been hired to teach at MIC.'),
    );
  }

  //campus
  $form['campus'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Campus(es)'),
    '#options' => mic_profile_get_taxonomy_options('campus'),
    '#description' => t('At which MIC campus or campuses do you currently teach.'),
  );

  //hire date
  $form['field_profile_hire_date'] = array(
    '#type' => 'date_popup',
    '#title' => t('With Music Institute of Chicago since'),
    '#date_label_position' => 'none',
    '#date_type' => DATE_DATETIME,
    '#date_timezone' => date_default_timezone(),
    '#date_format' => 'm/d/Y',
    '#date_year_range' => '-20:+0',
    '#required' => TRUE,
  );

  foreach (mic_profile_textareas() as $key => $textarea) {
    $form[$key] = array(
      '#type' => 'textarea',
      '#title' => $textarea['title'],
      '#description' => (isset($textarea['description'])) ? $textarea['description']: '',
      '#required' => (isset($textarea['required'])) ? TRUE : FALSE,
    );
  }

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Submit'),
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
function mic_profile_add_profile_form_validate($form, &$form_state) {
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
function mic_profile_add_profile_form_submit($form, &$form_state) {
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
 * List of instruments
 *
 * @return array
 */
function mic_profile_instruments() {
  return array(
    'strings' => array(
      'label' => t('String(s)'),
      'term' => 'Strings',
    ),
    'guitar' => array(
      'label' => t('Guitar'),
      'term' => 'Guitar',
    ),
    'woodwinds' => array(
      'label' => t('Woodwinds'),
      'term' => 'Woodwinds',
    ),
    'voice' => array(
      'label' => t('Voice'),
      'term' => 'Voice',
    ),
    'brass' => array(
      'label' => t('Brass'),
      'term' => 'Brass',
    ),
    'percussion' => array(
      'label' => t('Percussion'),
      'term' => 'Percussion',
    ),
    'keyboard' => array(
      'label' => t('Keyboard Instruments'),
      'term' => 'Keyboard Instruments',
    ),
    'other' => array(
      'label' => t('Other'),
      'term' => 'Other',
    ),
  );
}

/**
 * List of textarea questions.
 *
 * @return array
 */
function mic_profile_textareas() {
  $output = array();
  $fields = array(
    'field_profile_affiliations',
    'field_profile_awards',
    'field_profile_composer',
    'field_profile_education',
    'field_profile_expertise',
    'field_profile_interests',
    'field_profile_mentors',
    'field_profile_moments',
    'field_profile_practice',
    'field_profile_quote',
  );
  foreach ($fields as $field) {
    $details = mic_profile_get_label_description($field);
    $data = unserialize($details['data']);
    $output[$field] = array(
      'title' => $data['label'],
      'description' => $data['description'],
    );
  }
  return $output;
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

/**
 * Get details of profile field questions.
 *
 * @param $field_name
 * @return mixed
 */
function mic_profile_get_label_description($field_name) {
  $query = db_select('field_config_instance', 'fci');
  $query
    ->condition('fci.field_name', $field_name)
    ->fields('fci', array('field_name', 'data'));
  $result = $query->execute()->fetchAssoc();

  return $result;
}