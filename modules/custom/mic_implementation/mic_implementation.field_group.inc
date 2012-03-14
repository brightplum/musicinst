<?php
/**
 * @file
 * mic_implementation.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function mic_implementation_field_group_info() {
  $export = array();

  $field_group = new stdClass;
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_age|node|item_course|form';
  $field_group->group_name = 'group_age';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'item_course';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_semester_details';
  $field_group->data = array(
    'label' => 'Age',
    'weight' => '14',
    'children' => array(
      0 => 'field_age',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_age|node|item_course|form'] = $field_group;

  $field_group = new stdClass;
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_fall|node|item_course|default';
  $field_group->group_name = 'group_fall';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'item_course';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Fall',
    'weight' => '4',
    'children' => array(
      0 => 'field_fall_price',
      1 => 'field_fall_materials_fees',
      2 => 'field_fall_semester_duration',
      3 => 'field_fall_class_duration',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
      ),
    ),
  );
  $export['group_fall|node|item_course|default'] = $field_group;

  $field_group = new stdClass;
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_fall|node|item_course|form';
  $field_group->group_name = 'group_fall';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'item_course';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_semester_details';
  $field_group->data = array(
    'label' => 'Fall',
    'weight' => '12',
    'children' => array(
      0 => 'field_fall_price',
      1 => 'field_fall_materials_fees',
      2 => 'field_fall_semester_duration',
      3 => 'field_fall_class_duration',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_fall|node|item_course|form'] = $field_group;

  $field_group = new stdClass;
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_instrument|node|item_course|form';
  $field_group->group_name = 'group_instrument';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'item_course';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_semester_details';
  $field_group->data = array(
    'label' => 'Instrument',
    'weight' => '13',
    'children' => array(
      0 => 'field_instrument',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_instrument|node|item_course|form'] = $field_group;

  $field_group = new stdClass;
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_program_area|node|item_course|form';
  $field_group->group_name = 'group_program_area';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'item_course';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_semester_details';
  $field_group->data = array(
    'label' => 'Program Area',
    'weight' => '15',
    'children' => array(
      0 => 'field_program_area',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_program_area|node|item_course|form'] = $field_group;

  $field_group = new stdClass;
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_semester_details|node|item_course|form';
  $field_group->group_name = 'group_semester_details';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'item_course';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Semester Details',
    'weight' => '5',
    'children' => array(
      0 => 'group_spring',
      1 => 'group_summer',
      2 => 'group_fall',
      3 => 'group_instrument',
      4 => 'group_age',
      5 => 'group_program_area',
    ),
    'format_type' => 'tabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => '',
      ),
    ),
  );
  $export['group_semester_details|node|item_course|form'] = $field_group;

  $field_group = new stdClass;
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_spring|node|item_course|default';
  $field_group->group_name = 'group_spring';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'item_course';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Spring',
    'weight' => '2',
    'children' => array(
      0 => 'field_spring_price',
      1 => 'field_spring_materials_fees',
      2 => 'field_spring_class_duration',
      3 => 'field_spring_semester_duration',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
      ),
    ),
  );
  $export['group_spring|node|item_course|default'] = $field_group;

  $field_group = new stdClass;
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_spring|node|item_course|form';
  $field_group->group_name = 'group_spring';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'item_course';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_semester_details';
  $field_group->data = array(
    'label' => 'Spring',
    'weight' => '10',
    'children' => array(
      0 => 'field_spring_price',
      1 => 'field_spring_materials_fees',
      2 => 'field_spring_class_duration',
      3 => 'field_spring_semester_duration',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_spring|node|item_course|form'] = $field_group;

  $field_group = new stdClass;
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_summer|node|item_course|form';
  $field_group->group_name = 'group_summer';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'item_course';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_semester_details';
  $field_group->data = array(
    'label' => 'Summer',
    'weight' => '11',
    'children' => array(
      0 => 'field_summer_price',
      1 => 'field_summer_materials_fees',
      2 => 'field_summer_class_duration',
      3 => 'field_summer_semester_duration',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_summer|node|item_course|form'] = $field_group;

  return $export;
}