<?php

/**
 * @file
 * menu_local_action.theme.inc
 */

/**
 * Implements atomium_theme_alter__hook().
 */
function atomium_theme__menu_local_action() {
  return array(
    'menu_local_action' => array(
      'render element' => 'element',
      'template' => 'menu-local-action',
      'variables' => array(
        'link' => NULL,
        'menu_link' => NULL,
      ),
    ),
  );
}