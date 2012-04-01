<?php
/**
 * @file
 * mic_commerce.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function mic_commerce_field_group_info() {
  $export = array();

  $field_group = new stdClass;
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_cp_custom_enroll|commerce_product|product_class|form';
  $field_group->group_name = 'group_cp_custom_enroll';
  $field_group->entity_type = 'commerce_product';
  $field_group->bundle = 'product_class';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Custom Enrollment',
    'weight' => '9',
    'children' => array(
      0 => 'field_custom_enrollment',
      1 => 'field_custom_enrollment_message',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_cp_custom_enroll|commerce_product|product_class|form'] = $field_group;

  $field_group = new stdClass;
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_cp_date|commerce_product|product_class|form';
  $field_group->group_name = 'group_cp_date';
  $field_group->entity_type = 'commerce_product';
  $field_group->bundle = 'product_class';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Date / Time',
    'weight' => '7',
    'children' => array(
      0 => 'field_day_of_week',
      1 => 'field_time',
      2 => 'field_start_date',
      3 => 'field_end_date',
      4 => 'field_sunrise_date',
      5 => 'field_sunset_date',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_cp_date|commerce_product|product_class|form'] = $field_group;

  return $export;
}
