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