<?php
/**
 * @file
 * Theme functions for mic_commerce
 */

/**
 * Themed cart
 *
 * @param array $vars
 */
function theme_mic_commerce_cart($vars) {
  $output = array();
  $output[] = ($vars['name'])
    ? l(t('My Account'), 'user')
    : l(t('Sign In'), 'user/login') . ' ' . l(t('Register'), 'user/register');
  $img = '<img src="/' . drupal_get_path('module', 'mic_commerce') . '/images/cart.png" alt="Shopping cart" class="cart-icon" />';
  $plural = ($vars['num_items'] == 1) ? 'item' : 'items';
  $items = $img . '&nbsp;' . $vars['num_items'] . '&nbsp;' . $plural;
  $output[] = l($items, 'cart', array('html' => TRUE));

  return '<div class="mic-shopping-cart">' . implode('<br />', $output) . '</div>';
}