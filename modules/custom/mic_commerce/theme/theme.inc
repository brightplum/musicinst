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
  drupal_add_css(drupal_get_path('module', 'mic_commerce') . '/theme/cart.css', array('group' => CSS_DEFAULT, 'every_page' => TRUE));
  $output = array();
  $output[] = ($vars['name'])
    ? l(t('My Account'), 'user') . '&nbsp;/&nbsp;' . l(t('Logout'), 'user/logout')
    : l(t('Sign In'), 'user/login', array('query' => array('destination' => 'cart'))) . '&nbsp;/&nbsp;' . l(t('Create account'), 'user/register', array('query' => array('destination' => 'cart')));
  $img = '<img src="/' . drupal_get_path('module', 'mic_commerce') . '/images/cart.png" alt="Shopping cart" class="cart-icon" />';
  $plural = ($vars['num_items'] == 1) ? 'item' : 'items';
  $class = ($vars['num_items'] >= 1) ? 'green' : 'black';
  $items = $img . $vars['num_items'] . '&nbsp;' . $plural;
  $output[] = l($items, 'cart', array('html' => TRUE, 'attributes' => array('class' => array($class, 'items'))));

  return '<div class="mic-shopping-cart">' . implode('<br />', $output) . '</div>';
}