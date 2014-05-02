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
  $form['student']['student_type'] = array(
    '#type' => 'select',
    '#title' => t('Student Type'),
    '#options' => array(
      'new' => 'New or Returning',
      'continuing' => 'Continuing',
    ),
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
    '#options' => drupal_map_assoc(
      array(
        '' => '- Select - ',
        'Male',
        'Female',
        'Other',
      )),
  );
  $form['student']['ethnicity'] = array(
    '#type' => 'select',
    '#title' => t('Ethnicity'),
    '#options' => drupal_map_assoc(array(
      '' => '- Select - ',
      'American Indian or Alaskan Native',
      'Asian',
      'Black/African-American',
      'Native Hawaiian or Other Pacific Islander',
      'Hispanic/Latino',
      'White',
      'Two or more races/ethnicities',
    )),
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

  $form['instruction']['instruction_type'] = array(
    '#type' => 'select',
    '#title' => t('Type'),
    '#options' => array(
      '' => '- Select -',
      'suzuki' => 'Suzuki',
      'traditional' => 'Traditional',
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
    '#options' => drupal_map_assoc(array(
      '' => '- Select -',
      'Sunday',
      'Monday',
      'Tuesday',
      'Wednesday',
      'Thursday',
      'Friday',
      'Saturday',
    )),
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
 * Save profile from form
 *
 * @param $form
 * @param $form_state
 */
function mic_private_private_registration_form_submit($form, &$form_state) {
  // Calculate instruction rate
  $instructor = $form_state['values']['instructor'];
  $length = $form_state['values']['length'];
  $instruction_type = $form_state['values']['instruction_type'];
  $musicianship = $form_state['values']['musicianship'];

  $rate = mic_private_calculate_rate($instructor, $length);
  $rate = ($rate) ? $rate : 85;

  //$weeks = ($type == 'suzuki') ? 15 : 17;
  $total = $rate * 17;

  if (!empty($musicianship)) {
    if ($instruction_type == 'suzuki') {
      $total += 65;
    }
    else {
      $total += 120;
    }
  }

  // Calculate discounts
  if ($form_state['values']['senior']) {
    $total *= .85;
  }

  if ($form_state['values']['multiple']) {
    $total -= 25;
  }

  if ($form_state['values']['staff']) {
    $total *= .60;
  }

  // Additional fees
  if ($form_state['values']['student_type'] == 'new') {
    $total += 25;
  }

  $calculated_total = $total;

  // Payment options
  switch ($form_state['values']['payment']) {
    case 'installment':
      $total = 225;
      break;

    case 'partial':
      $total = 500;
      break;

    case 'financialaid':
      $total = 160;
      break;
  }

  // Credit card fee
  $total *= 1.02;

  $data = array(
    'values' => $form_state['values'],
    'calculated_total' => $calculated_total,
    'total' => $total,
  );
  $data = serialize($data);
  setcookie('mic-private-instruction', $data);

  drupal_goto("pay-bill");
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

/**
 * Helper to load Suzuki and Musicianship classes.
 *
 * @param $type
 * @return array
 */
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

/**
 * Helper to format fields in a select list.
 *
 * @param $entity_type
 * @param $entity
 * @param $field
 * @return array|bool|mixed
 */
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
 * Helper to calculate instructor rate.
 *
 * @param $nid
 * @param $length
 * @return null
 */
function mic_private_calculate_rate($nid, $length) {
  $query = new EntityFieldQuery();
  $query
    ->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'pi_instructor_rate')
    ->fieldCondition('field_instructor_reference', 'nid', $nid);
  $result = $query->execute();
  $nid = array_keys($result['node']);
  if (!empty($nid)) {
    $node = node_load($nid[0]);
    $rate = field_get_items('node', $node, 'field_pi_rate_' . $length . 'min');
    $rate = is_array($rate) ? reset($rate) : $rate;
    return $rate['value'];
  }
  return FALSE;
}
