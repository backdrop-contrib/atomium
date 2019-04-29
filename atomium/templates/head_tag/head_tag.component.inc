<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_theme_hook().
 */
function atomium_atomium_theme_head_tag(array $existing, $type, $theme, $path) {
  return array(
    'head_tag' => array(
      'render element' => 'element',
      'template' => 'head-tag',
    ),
  );
}

/**
 * Implements hook_preprocess_hook().
 */
function atomium_preprocess_head_tag(array &$variables, $hook) {
  $element = &$variables['element'];

  $variables['atomium']['attributes']['element']->setAttributes($element['#attributes']);
}
