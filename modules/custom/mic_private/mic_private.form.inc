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
<p class="intro">1. <strong>NEW PRIVATE INSTRUCTION STUDENT</strong> at the Music Institute
of Chicago who has completed the placement interview with your local Campus Director. In addition, you
may use this form to sign up for classes packaged with your private
instruction (Musicianship and Suzuki Repertoire Classes).</p>
<p class="intro">2. <strong>CURRENT STUDENT</strong> wishing to re-register in the fall.
(Current students only need to register once a year. Fall to Spring
registration is assumed. For summer private instruction registration, please <a href="https://musicinst.org/summer-lessons-music-institute-chicago">click here</a>.)</p>
<p class="intro">If you have not already created an account, <strong><a href="https://www.musicinst.org/user/register">please do so before registering</a></strong>.
If you have an account, please make sure your information is up-to-date and that you are <strong><a href="https://www.musicinst.org/user/login?destination=cart" target="_blank">logged in</a></strong> before registering.</p>
<p class="intro">New students and current students registering after the early registration deadline of June 8 are charged the annual $25 registration fee.</p>
<p class="intro">All online registrations will be charged a 2% processing fee.  If you wish to avoid this fee, you may fill out a <a href="https://www.musicinst.org/sites/default/files/attachments/FY16%20Registration%20Form-8.5x11.pdf">paper registration form</a> and submit it with payment by cash or check, or in person by debit card at one of our main MIC campus locations.</p>
<p class="intro">If you wish to apply for financial aid, but have not yet done so, complete your
<a href="https://musicinst.wufoo.com/forms/20152016-financial-aid-application/" target="_blank">financial aid paperwork</a>
before using this form.</p>
<p class="intro">The <span class="form-required" title="This field is required.">*</span> = required fields</p>',
  );
  // Student Information
  $form['student'] = array(
    '#type' => 'fieldset',
    '#title' => t('Student Information'),
  );
  $form['student']['year'] = array(
    '#type' => 'select',
    '#title' => t('Private Instruction Year'),
    '#options' => array(
      'FY16' => 'FY16',
    ),
    '#required' => TRUE,
  );
  $form['student']['student_type'] = array(
    '#type' => 'select',
    '#title' => t('Student Type'),
    '#options' => array(
      'new' => 'New',
      'continuing' => 'Continuing',
      'returning' => 'Returning',
    ),
    '#required' => TRUE,
    '#attributes' => array(
      'class' => array(
        'hasqtip',
      ),
    ),
    '#suffix' => '<div class="tooltiptext">Continuing: you studied at MIC spring 2015.
New or Returning: you are new MIC or you studied here sometime in the past, but it was prior to spring 2015.</div>',
  );
  $form['student']['adult_student'] = array(
    '#type' => 'select',
    '#title' => t('Is the student an adult?'),
    '#options' => array('no' => 'No', 'yes' => 'Yes'),
    '#required' => TRUE,
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
    '#title' => t('Student First Name'),
    '#size' => 30,
    '#required' => TRUE,
  );
  $form['student']['last'] = array(
    '#type' => 'textfield',
    '#title' => t('Student Last Name'),
    '#size' => 30,
    '#required' => TRUE,
    '#suffix' => '</div>',
  );
  $form['student']['birthdate'] = array(
    '#prefix' => '<div class="inline">',
    '#type' => 'textfield',
    '#title' => t('Birthdate'),
    '#size' => 15,
    '#description' => t('Format: mm/dd/yyyy'),
    '#required' => TRUE,
  );
  $form['student']['grade'] = array(
    '#type' => 'textfield',
    '#title' => t('Grade'),
    '#size' => 15,
    '#attributes' => array(
      'class' => array(
        'hasqtip',
      ),
    ),
    '#suffix' => '<div class="tooltiptext">Grade as of 9/1/2015.</div></div>',
  );
  $form['student']['gender'] = array(
    '#type' => 'select',
    '#title' => t('Gender'),
    '#options' => drupal_map_assoc(array(
      'Male',
      'Female',
      'Other',
    )),
    '#required' => TRUE,
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
  $form['student']['how_did_you_hear'] = array(
    '#type' => 'select',
    '#title' => t('How did you hear about MIC?'),
    '#options' => drupal_map_assoc(array(
      '' => '- Select -',
      'Alumni',
      'Campus Visibility',
      'Flyer',
      'Internet Search',
      'MIC Event (Concerts/Outreach)',
      'Music Store',
      'Nichols Concert Hall',
      'Paid Advertising',
      'Referred by MIC Family',
      'Referred by MIC Faculty/Staff',
      'Referred by Private/School Teacher',
      'Sibling',
      'Social Media/MIC Website',
      'Word of Mouth',
    )),
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
    '#description' => 'Format: 06:00pm',
  );
  $form['instruction']['length'] = array(
    '#type' => 'select',
    '#title' => t('Private Instruction Lesson Length'),
    '#options' => array(
      '' => '- Select -',
      '30' => '30 minutes',
      '45' => '45 minutes',
      '60' => '60 minutes',
      '90' => '90 minutes',
      '120' => '120 minutes',
    ),
    '#suffix' => '</div>',
    '#required' => TRUE,
  );

  $form['instruction']['weeks'] = array(
    '#type' => 'select',
    '#title' => t('Requested Number of Weeks'),
    '#options' => drupal_map_assoc(range(17, 1)),
    '#states' => array(
      'visible' => array(
        ':input[name="adult_student"]' => array('value' => 'yes'),
      ),
    ),
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
  );

  // Musicianship Information
  $form['musicianship'] = array(
    '#type' => 'fieldset',
    '#title' => t('Musicianship'),
  );

  $form['musicianship']['take_musicianship'] = array(
    '#type' => 'select',
    '#title' => t('Do you wish to take Musicianship classes?'),
    '#options' => array('no' => 'No', 'yes' => 'Yes'),
    '#required' => TRUE,
    '#attributes' => array(
      'class' => array(
        'hasqtip',
      ),
    ),
    '#suffix' => '<div class="tooltiptext">Private instruction students are encouraged to take Musicianship classes
at the heavily discounted rate of $90 annually.</div>',
  );

  $options = mic_private_get_additional_classes('musicianship');
  $form['musicianship']['musicianship'] = array(
    '#type' => 'select',
    '#title' => t('Musicianship Class'),
    '#options' => $options,
    '#states' => array(
      'visible' => array(
        ':input[name="take_musicianship"]' => array('value' => 'yes'),
      ),
    ),
    '#attributes' => array(
      'class' => array(
        'hasqtip',
      ),
    ),
    '#suffix' => '<div class="tooltiptext">Please select your Musicianship class based upon teacher placement and your schedule.<br /><br />
If you don’t know what class to take, it’s ok to skip this field.<br /><br />
If the student is between ages 3-7, a Musikgarten class may be substituted for just the cost of materials per semester.</div>',
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
    '#markup' => 'Seniors - (age 65+) receive a 15% discount on private lessons.<br />
    Adults - (age 19+), taking a private lesson before 3 p.m. M-F in MIC studios, receives a 20% reduction in tuition.<br />
(Do not pay in full, the adjusted balance will be reflected on your next statement)<br />
Merit Scholarship (Do not pay in full, the adjusted balance will be reflected on your next statement)<br />
It should be noted that there is no "stacking" of percentage discounts, the highest % applies.',
  );

  $form['other_discount']['senior_discount'] = array(
    '#type' => 'select',
    '#title' => t('Are you a senior?'),
    '#options' => drupal_map_assoc(array('No', 'Yes')),
  );

  $form['other_discount']['adult_discount'] = array(
    '#type' => 'select',
    '#title' => t('Are you an adult who is taking a class before 3pm M-F?'),
    '#options' => drupal_map_assoc(array('No', 'Yes')),
  );

  $form['staff_discount'] = array(
    '#type' => 'fieldset',
    '#title' => t('Music Institute of Chicago Employees'),
  );

  $form['staff_discount']['staff'] = array(
    '#type' => 'select',
    '#title' => t('Are you MIC faculty or staff?'),
    '#options' => array('No' => 'No', 'part' => 'Yes - Part-Time', 'full' => 'Yes - Full-time'),
  );

  // Payment
  $form['payment'] = array(
    '#type' => 'fieldset',
    '#title' => t('Payment Information'),
  );

  $form['payment']['payment_explanation'] = array(
    '#markup' => '<a href="https://www.musicinst.org/installment-plan" target="_blank"> Learn more about the Installment Plan and download the necessary enrollment paperwork here >></a><br />
     <a href="https://www.musicinst.org/financial-aid" target="_blank">Learn more about Financial Aid and complete the application here >></a><br />',
  );

  $form['payment']['payment'] = array(
    '#type' => 'select',
    '#title' => t('Choose Payment Option'),
    '#options' => array(
      'full' => 'Pay in Full now.',
      'partial' => 'Partial: Pay $500 Now.  Balance due before lessons begin/start of semester.',
      'installment' => 'Installment Plan: Pay $200 now. Remaining balance paid in installments.',
      'financialaid' => 'Financial Aid: Pay $175 now. Balance due before lessons begin/start of semester.',
    ),
    '#required' => TRUE,
    '#attributes' => array(
      'class' => array(
        'hasqtip',
      ),
    ),
    '#suffix' => '<div class="tooltiptext">Your registration cannot be accepted without some payment. Please choose the plan that is right for you.</div>',
  );

  $form['submit'] = array(
    '#prefix' => 'Submitting this form will open a new window. Please disable any pop-up blockers.<br />',
    '#type' => 'submit',
    '#value' => t('Review your Registration'),
  );

  $form['#attached']['css'] = array(
    drupal_get_path('module', 'mic_private') . '/css/jquery.qtip.min.css',
    drupal_get_path('module', 'mic_private') . '/css/mic_private.css',
  );
  // Attach the tooltip library.
  $form['#attached']['js'][] = '//cdn.jsdelivr.net/qtip2/2.2.0/jquery.qtip.min.js';
  $form['#attached']['js'][] = drupal_get_path('module', 'mic_private') . '/js/mic_private.js';

  $form['#attributes'] = array(
    'target' => "_blank",
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

  $musicianship_fee = NULL;

  $rate = mic_private_calculate_instructor_rate($instructor, $length);
  $default_rate = mic_private_default_rate($instruction_type, $length);
  $rate = ($rate) ? $rate : $default_rate;

  // If adult student, set their own weeks
  $adult_student = $form_state['values']['adult_student'];
  if ($adult_student == 'yes') {
    $weeks = !empty($form_state['values']['weeks'])
      ? $form_state['values']['weeks']
      : 17;
  }
  else {
    $weeks = 17;
  }
  $total = $rate * $weeks;

  // Pull out lesson total for display
  $lesson_total = $total;

  // Calculate discounts
  $discount = array($total);

  if ($form_state['values']['adult_discount'] == 'Yes') {
    $discount[] = $total * .80;
  }

  if ($form_state['values']['senior_discount'] == 'Yes') {
    $discount[] = $total * .85;
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

  $total = (!empty($discount)) ? min($discount) : $total;

  // Additional fees
  $student_types = array(
    'new',
    'returning',
  );
  if (in_array($form_state['values']['student_type'], $student_types)) {
    $total += 25;
  }

  // Charge continuing students on June 8, 2015.
  if (time() > 1433739600) {
    if ($form_state['values']['student_type'] == 'continuing') {
      $total += 25;
    }
  }

  // Add suzuki, musicianship fee
  $musicianship = $form_state['values']['musicianship'];
  $suzuki = $form_state['values']['suzuki'];
  foreach (array($musicianship, $suzuki) as $pi_class) {
    if (!empty($pi_class)) {
      $musicianship_fee = mic_private_calculate_class_fee($pi_class);
      $total += $musicianship_fee;
    }
  }

  if ($form_state['values']['multiple'] == 'Yes') {
    $total -= 25;
  }

  $calculated_total = $total;

  // Payment options
  switch ($form_state['values']['payment']) {
    case 'installment':
      $total = 200;
      $number = ($calculated_total - $total) / 3;
      $form_state['values']['installment payments'] = '$' . number_format((float)$number, 2, '.', '');
      break;

    case 'partial':
      $total = 500;
      break;

    case 'financialaid':
      $total = 175;
      break;
  }

  $data = array(
    'values' => $form_state['values'],
    'lesson_total' => money_format('%i', $lesson_total),
    'musicianship_fee' => money_format('%i', $musicianship_fee),
    'calculated_total' => money_format('%i', $calculated_total),
    'total' => money_format('%i', $total),
  );
  $data = serialize($data);
  $hash = hash('md5', time());
  db_insert('mic_private')
    ->fields(array(
      'hash' => $hash,
      'data' => $data,
    ))
    ->execute();
  setcookie('mic-private-instruction', $data, time() + 86400);

  drupal_goto("private-instruction-review", array(
    'query' => array(
      'destination' => 'cart',
      'hash' => $hash,
    )
  ));
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
    ->entityCondition('bundle', $bundle);

  // Only grab profiles teaching private instruction.
  if ($bundle == 'profile') {
    $query->fieldCondition('field_profile_program_area', 'tid', 178)
      ->fieldOrderBy('field_last_name', 'value', 'ASC')
      ->fieldOrderBy('field_first_name', 'value', 'ASC');
  }
  else {
    $query->propertyOrderBy('title');
  }

  $result = $query->execute();
  $nids = array_keys($result['node']);
  $nodes = node_load_multiple($nids);
  foreach ($nodes as $node) {
    $first = field_get_items('node', $node, 'field_first_name');
    $first = reset($first);
    $last = field_get_items('node', $node, 'field_last_name');
    $last = reset($last);
    $options[$node->nid] = $last['value'] . ', ' . $first['value'];
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
    ->propertyCondition('status', 1)
    ->fieldCondition('field_pi_class_type', 'value', $type)
    ->fieldOrderBy('field_pi_class_order', 'value', 'ASC');
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
function mic_private_calculate_instructor_rate($nid, $length) {
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
 * Return the musicianship/suzuki fee value.
 *
 * @param $nid
 * @return int
 */
function mic_private_calculate_class_fee($nid) {
  if (is_numeric($nid) && $nid) {
    $node = node_load($nid);
    $fee = field_get_items('node', $node, 'field_pi_class_fee');
    $fee = is_array($fee) ? reset($fee) : $fee;
    return $fee['value'];
  }
  return 0;
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
