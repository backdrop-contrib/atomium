<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_theme_hook().
 */
function atomium_atomium_theme_menu_toggle(array $existing, $type, $theme, $path) {
  return array(
    'menu_toggle' => array(
      'template' => 'menu-toggle',
      'variables' => array(
        'enabled' => NULL,
        'id' => NULL,
        'text' => '',
      ),
    ),
  );
}
