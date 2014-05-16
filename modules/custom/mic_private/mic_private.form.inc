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
  $form['intro'] = array(
    '#markup' => '<p class="intro">Please use this form to register if you are a:</p>
<p class="intro">1. <strong>NEW PRIVATE INSTRUCTION</strong> student at the Music Institute
of Chicago who has spoken to your local Campus Director. In addition, you
may use this form to sign up for classes packaged with your private
instruction (Musicianship and Suzuki Repertoire Classes).</p>
<p class="intro">2. <strong>CURRENT STUDENT</strong> wishing to re-register in the fall.
(Current students only need to register once a year. Fall to Spring
registration is assumed. Summer registration is to be arranged with your teacher.)</p>
<p class="intro">Please <strong><a href="https://www.musicinst.org/user/login?destination=cart" target="_blank">log in or create an account</a></strong>
before making purchases.</p>
<p class="intro">New students and current students registering after the early registration deadline
of July 1st are charged the annual $25 registration fee.</p>
<p class="intro"><strong>USER NOTES:</strong><br />
If you wish to apply for financial aid, but have not yet done so, complete your
<a href="https://musicinst.wufoo.com/forms/mic-201314-financial-aid-application/" target="_blank">financial aid paperwork</a>
before using this form.</p>
<p class="intro">The <strong>red asterisks</strong> = required fields</p>',
  );
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
    '#attributes' => array(
      'class' => array(
        'hasqtip',
      ),
    ),
    '#suffix' => '<div class="tooltiptext"><strong>Continuing</strong> means you are studying at MIC spring 2014.<br /><br />
        <strong>New or Returning</strong> means you are new MIC or you studied here sometime in the past, but not in spring 2014.</div>',
  );
  $form['student']['family_record'] = array(
    '#type' => 'textfield',
    '#title' => t('Family Record ID'),
    '#size' => 15,
    '#attributes' => array(
      'class' => array(
        'hasqtip',
      ),
    ),
    '#suffix' => '<div class="tooltiptext">If you have been assigned your basic 6-digit Record ID, please include that number here.<br /><br />
Your Record ID can be found on any MIC billing statement under "Record ID" or on your current MIC Student ID Card. (You do not need to include number(s) after the dash).<br /><br />
If you can\'t find it, please continue.</div>',
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
        '' => '- Select -',
        'Male',
        'Female',
        'Other',
      )),
  );
  $form['student']['ethnicity'] = array(
    '#type' => 'select',
    '#title' => t('Ethnicity'),
    '#options' => drupal_map_assoc(array(
      '' => '- Select -',
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

  // Instructor Information
  $form['instruction'] = array(
    '#type' => 'fieldset',
    '#title' => t('Instruction Information'),
  );

  $form['instruction']['pi_instrument'] = array(
    '#title' => t('Instrument'),
    '#type' => 'select',
    '#options' => array('' => '- Select -') + mic_profile_get_taxonomy_options('pi_instrument'),
    '#required' => TRUE,
  );

  $form['instruction']['instruction_type'] = array(
    '#type' => 'select',
    '#title' => t('Instruction Type'),
    '#options' => array(
      '' => '- Select -',
      'suzuki' => 'Suzuki',
      'traditional' => 'Traditional',
    ),
    '#required' => TRUE,
  );

  $options = mic_private_get_list('profile');

  $form['instruction']['instructor'] = array(
    '#type' => 'select',
    '#title' => t('Teacher Name'),
    '#options' => $options,
    '#required' => TRUE,
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
    '#required' => TRUE,
  );
  $form['instruction']['time'] = array(
    '#type' => 'textfield',
    '#title' => t('Requested Time'),
    '#size' => 15,
    '#required' => TRUE,
  );
  $form['instruction']['length'] = array(
    '#type' => 'select',
    '#title' => t('Private Instruction Lesson Length'),
    '#options' => array(
      '' => '- Select -',
      '20' => '20 minutes',
      '30' => '30 minutes',
      '45' => '45 minutes',
      '60' => '60 minutes',
      '90' => '90 minutes',
      '120' => '120 minutes',
    ),
    '#suffix' => '</div>',
    '#required' => TRUE,
  );

  $form['instruction']['campus'] = array(
    '#type' => 'select',
    '#title' => t('Location'),
    '#options' => array('' => '- Select -') + mic_profile_get_taxonomy_options('campus'),
    '#required' => TRUE,
  );

  $options = mic_private_get_additional_classes('suzuki');
  $form['suzuki'] = array(
    '#type' => 'select',
    '#title' => t('Suzuki Repertoire Class'),
    '#options' => $options,
    '#states' => array(
      'visible' => array(
        ':input[name="instruction_type"]' => array('value' => 'suzuki'),
      ),
    ),
    '#attributes' => array(
      'class' => array(
        'hasqtip',
      ),
    ),
    '#suffix' => '<div class="tooltiptext">Please select your Musicianship class based upon teacher placement and your schedule:<br /><br />
If you don\'t know, its ok to leave blank.<br /><br />
If the student is too young to participate in Musicianship, a Musikgarten class may be substituted.  Please arrange this with your local campus director.</div>'
  );

  $options = mic_private_get_additional_classes('musicianship');
  $form['musicianship'] = array(
    '#type' => 'select',
    '#title' => t('Musicianship Class'),
    '#options' => $options,
    '#attributes' => array(
      'class' => array(
        'hasqtip',
      ),
    ),
    '#suffix' => '<div class="tooltiptext">Please select your Musicianship class based upon teacher placement and your schedule:<br /><br />
If you don\'t know, its ok to leave blank.<br /><br />
If the student is too young to participate in Musicianship, a Musikgarten class may be substituted.  Please arrange this with your local campus director.</div>',
  );

  // Discounts
  $form['discount'] = array(
    '#type' => 'fieldset',
    '#title' => t('Sibling Discount'),
  );

  $form['discount']['multiple'] = array(
    '#prefix' => 'A $25 discount per sibling, per semester, will be applied for each additional child (18 & under) taking private instruction within the same family. The first student pays in full.',
    '#type' => 'select',
    '#title' => t('Is this the registration of a second or more student?'),
    '#options' => drupal_map_assoc(array('No', 'Yes')),
  );

  // Discounts
  $form['other_discount'] = array(
    '#type' => 'fieldset',
    '#title' => t('Other Discounts'),
  );

  $form['other_discount']['discount_explanation'] = array(
    '#markup' => 'Seniors: (those 65 or older as of September 1, 2014) receive 15% discount on private lessons<br /><br />
                  Discounts cannot be stacked. You simply receive the largest discount.<br /><br />
                  For example: You an MIC full-time employee who is 70 years old taking a private lesson at noon on Mondays. You get a 40% discount.<br />
                  Or: you are a senior adult taking a 1pm Tuesday lesson, you\'ll receive a 20% discount only',
  );

  $form['staff_discount'] = array(
    '#type' => 'fieldset',
    '#title' => t('Staff Discount'),
  );

  $form['staff_discount']['staff'] = array(
    '#prefix' => 'MIC Full-time Employees: 40% discount on private lessons.<br />
                  MIC Part-time Employees: 10% discount on private lessons.',
    '#type' => 'select',
    '#title' => t('Are you a MIC staff member?'),
    '#options' => array('No' => 'No', 'part' => 'Yes - Part-Time', 'full' => 'Yes - Full-time'),
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
      'full' => 'Plan 1: Pay in full now',
      'partial' => 'Plan 2: Pay $500 now. Balance invoiced.',
      'installment' => 'Plan 3: Pay $185 now. Balance spread over 3 additional payments.',
      'financialaid' => 'Plan 4: Financial Aid: Pay $165 now. Balance invoiced.',
    ),
    '#required' => TRUE,
  );

  $form['payment']['installment_day'] = array(
    '#type' => 'select',
    '#title' => t('If Plan 3 (Installment Plan) is chosen above, which day should payments be due?'),
    '#options' => array('' => '- Select -', '1st' => '1st of the month', '15th' => '15th of the month'),
  );

  $form['payment']['payment_form'] = array(
    '#type' => 'select',
    '#title' => t('Which form of payment will you be using?'),
    '#options' => array('credit' => 'Credit Card', 'debit' => 'Debit Card', 'echeck' => 'Echeck'),
    '#required' => TRUE,
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Get Price and Review'),
  );

  $form['#attached']['css'] = array(
    drupal_get_path('module', 'mic_private') . '/css/jquery.qtip.min.css',
    drupal_get_path('module', 'mic_private') . '/css/mic_private.css',
  );
  // Attach the tooltip library.
  $form['#attached']['js'][] = '//cdn.jsdelivr.net/qtip2/2.2.0/jquery.qtip.min.js';
  $form['#attached']['js'][] = drupal_get_path('module', 'mic_private') . '/js/mic_private.js';

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
  $birthdate = $form_state['values']['birthdate'];

  $rate = mic_private_calculate_rate($instructor, $length);
  $default_rate = mic_private_default_rate($instruction_type, $length);
  $rate = ($rate) ? $rate : $default_rate;

  $total = $rate * 17;

  if (!empty($musicianship)) {
    if ($instruction_type == 'suzuki') {
      $total += 65;
    }
    else {
      $total += 125;
    }
  }

  // Additional fees
  if ($form_state['values']['student_type'] == 'new') {
    $total += 25;
  }

  // Calculate discounts

  // Senior discount, adult discount
  $birthdate_unix = strtotime($birthdate);
  $senior_unix = strtotime("-65 years");
  $adult_unix = strtotime("-19 years");
  $discount = array($total);
  if (((time() - $senior_unix) > $birthdate_unix) && ($birthdate_unix < 1)) {
    $discount[] = $total * .85;
  }

//  if (((time() - $adult_unix) > $birthdate_unix)) {
//    $discount[] = $total * .80;
//  }

  if ($form_state['values']['multiple'] == 'Yes') {
    $discount[] = $total - 25;
  }

  if ($form_state['values']['staff'] != 'No') {
    switch ($form_state['values']['staff']) {
      case 'part':
        $discount[] = $total * .90;
        break;

      case 'full':
        $discount[] = $total * .60;
        break;
    }
  }

  $total = min($discount);

  $calculated_total = $total;

  // Payment options
  switch ($form_state['values']['payment']) {
    case 'installment':
      $total = 185;
      $form_state['values']['installment payments'] = '$' . round(($calculated_total - $total) / 3, 2);
      break;

    case 'partial':
      $total = 500;
      break;

    case 'financialaid':
      $total = 165;
      break;
  }

  // Credit card fee
  if ($form_state['values']['payment_form'] == 'credit') {
    $total *= 1.0275;
  }

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

  // Only grab profiles teaching private instruction.
  if ($bundle == 'profile') {
    $query->fieldCondition('field_profile_program_area', 'tid', 178);
  }

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

/**
 * Default rate for private instruction.
 *
 * @param $instruction_type
 * @param $length
 * @return bool
 */
function mic_private_default_rate($instruction_type, $length) {
  $query = new EntityFieldQuery();
  $query
    ->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'pi_instructor_rate')
    ->propertyCondition('title', 'Default ' . ucfirst($instruction_type) . ' Rate');
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
