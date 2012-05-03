<?php
/**
 * @file
 * Rules alters for MIC Commerce
 */

/**
 * Implements hook_rules_action_info_alter()
 *
 * @param unknown_type $actions
 */
function mic_commerce_rules_action_info_alter(&$actions) {
  $actions['commerce_cart_add_to_cart_message']['callbacks']['execute'] = 'mic_commerce_cart_rules_add_to_cart_message';
}