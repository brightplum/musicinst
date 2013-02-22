<?php
/**
 * @file
 * Custom admin MIC commerce functions.
 */

/**
 * Student Fee Admin form.
 */
function mic_commerce_admin_student_fee_form() {
  $form = array();

  $form['student_fee_text'] = array(
    '#type' => 'item',
    '#title' => t('Student fee option labels'),
    '#markup' => t('!label to change the student fee labels.', array('!label' => l(t('Go to the class line item'), 'admin/commerce/config/line-items/product-class/fields/field_class_lineitem_newstud',  array('attributes' => array('target'=>'_blank'))))),
  );

  $fee_options = array(
    0 => t('New and Continuing Students'),
    1 => t('New or Returning Students Only'),
  );

  $form['mic_student_fee'] = array(
    '#type' => 'radios',
    '#title' => t('Set student fee'),
    '#options' => $fee_options,
    '#default_value' => variable_get('mic_student_fee', 0),
    '#required' => TRUE,
    '#description' => t('Set how the student fee is applied.'),
  );

  return system_settings_form($form);
}
