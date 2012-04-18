<?php
/**
 * @file
 * mic_user.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function mic_user_field_group_info() {
  $export = array();

  $export = array();

  $field_group = new stdClass;
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_user_additional_guardians|user|user|form';
  $field_group->group_name = 'group_user_additional_guardians';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_user_takingclass';
  $field_group->data = array(
    'label' => 'Additional Guardians',
    'weight' => '9',
    'children' => array(
      0 => 'field_user_guardian',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Additional Guardians',
      'instance_settings' => array(
        'required_fields' => 0,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $export['group_user_additional_guardians|user|user|form'] = $field_group;

  $field_group = new stdClass;
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_user_additionalguardian|user|user|default';
  $field_group->group_name = 'group_user_additionalguardian';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Additional Guardians',
    'weight' => '4',
    'children' => array(
      0 => 'field_user_guardian',
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
  $export['group_user_additionalguardian|user|user|default'] = $field_group;

  $field_group = new stdClass;
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_user_additionalinfo|user|user|default';
  $field_group->group_name = 'group_user_additionalinfo';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Additional Info',
    'weight' => '1',
    'children' => array(
      0 => 'field_user_hearaboutmic',
      1 => 'field_user_occupation',
      2 => 'field_user_company',
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
  $export['group_user_additionalinfo|user|user|default'] = $field_group;

  $field_group = new stdClass;
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_user_additionalinfo|user|user|form';
  $field_group->group_name = 'group_user_additionalinfo';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Additional Info',
    'weight' => '5',
    'children' => array(
      0 => 'field_user_hearaboutmic',
      1 => 'field_user_occupation',
      2 => 'field_user_company',
      3 => 'field_user_mailinglist',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Additional Info',
      'instance_settings' => array(
        'required_fields' => 0,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $export['group_user_additionalinfo|user|user|form'] = $field_group;

  $field_group = new stdClass;
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_user_basic|user|user|form';
  $field_group->group_name = 'group_user_basic';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Primary Account Holder',
    'weight' => '4',
    'children' => array(
      0 => 'field_user_firstname',
      1 => 'field_user_lastname',
      2 => 'field_user_phonenumber',
      3 => 'field_user_secondary_phone',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Primary Account Holder',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $export['group_user_basic|user|user|form'] = $field_group;

  $field_group = new stdClass;
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_user_displaybasic|user|user|default';
  $field_group->group_name = 'group_user_displaybasic';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Basic Info',
    'weight' => '0',
    'children' => array(
      0 => 'field_user_firstname',
      1 => 'field_user_lastname',
      2 => 'field_user_phonenumber',
      3 => 'field_user_secondary_phone',
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
  $export['group_user_displaybasic|user|user|default'] = $field_group;

  $field_group = new stdClass;
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_user_displaystudents|user|user|default';
  $field_group->group_name = 'group_user_displaystudents';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Students',
    'weight' => '3',
    'children' => array(
      0 => 'field_user_students',
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
  $export['group_user_displaystudents|user|user|default'] = $field_group;

  $field_group = new stdClass;
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_user_studentinfo|user|user|form';
  $field_group->group_name = 'group_user_studentinfo';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_user_takingclass';
  $field_group->data = array(
    'label' => 'Students',
    'weight' => '8',
    'children' => array(
      0 => 'field_user_students',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Students',
      'instance_settings' => array(
        'required_fields' => 0,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $export['group_user_studentinfo|user|user|form'] = $field_group;

  $field_group = new stdClass;
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_user_takingclass|user|user|form';
  $field_group->group_name = 'group_user_takingclass';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Taking a class?',
    'weight' => '7',
    'children' => array(
      0 => 'group_user_studentinfo',
      1 => 'group_user_additional_guardians',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Taking a class?',
      'instance_settings' => array(
        'required_fields' => 0,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_user_takingclass|user|user|form'] = $field_group;

  return $export;
}
