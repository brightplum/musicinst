<?php

/**
 * Implements template_process_html()
 *
 * @param array $variables
 */
function mic_theme_process_html(&$vars) {
  // Render closure into a top level variable
  $closure = $vars['page']['closure'];
  $vars['closure'] = drupal_render($closure);
}

/**
 * Implements theme_preprocess_page()
 *
 * @param array $vars
 */
function mic_theme_preprocess_page(&$vars) {
  $navigation = theme('item_list', array('items' => _mic_theme_primary_navigation()));
  //$vars['navigation'] = menu_tree('menu-primary-navigation');
  $vars['navigation'] = $navigation;
  $vars['middle_column'] = (!empty($vars['page']['sidebar_left'])) ? 'full' : NULL;
}

/**
 * Implements theme_preprocess_block()
 *
 * @param array $vars
 */
function mic_theme_preprocess_block(&$vars) {
  $block = $vars['block'];
  $block_class = str_replace('_', '-', 'block-' . $block->module . '-' . $block->delta);
  $vars['wrapper_class'] = $block_class . '-wrapper';
  $vars['classes_array'][] = $block_class;
}

/**
 * Implements theme_preprocess_field().
 *
 * @param $vars
 */
function mic_theme_preprocess_field(&$vars) {
  switch ($vars['element']['#field_name']) {
    case 'field_profile_hire_date';
      // Year only.
      $date = new DateTime($vars['items']['0']['#markup']);
      $vars['items']['0']['#markup'] = $date->format('Y');
      break;
  }
}

function _mic_theme_primary_navigation() {
  return array(
    array(
      'data' => l('About MIC', 'about-music-institute-chicago'),
      'class' => array('class' => 'about-mic'),
    ),
    array(
      'data' => l('Community Music School', 'community-music-school'),
      'class' => array('class' => 'community-music-school'),
    ),
    array(
      'data' => l('Academy', 'academy'),
      'class' => array('class' => 'academy'),
    ),
    array(
      'data' => l('Creative Arts Therapy', 'institute-therapy-through-arts'),
      'class' => array('class' => 'creative-arts-therapy'),
    ),
    array(
      'data' => l('Nichols Concert Hall', 'nichols-concert-hall'),
      'class' => array('class' => 'nichols-concert-hall'),
    ),
    array(
      'data' => l('Alumni Association', 'alumni-association'),
      'class' => array('class' => 'alumni-association'),
    ),
    array(
      'data' => l('Giving', 'giving'),
      'class' => array('class' => 'giving'),
    ),
  );
}
