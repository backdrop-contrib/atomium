<?php

/**
 * @file
 * Menu_local_tasks.component.inc.
 */

/**
 * Implements hook_preprocess_hook().
 */
function atomium_basis_preprocess_menu_local_tasks(array &$variables, $hook) {
  if (!empty($variables['primary'])) {
    $variables['primary']['#atomium']['attributes']['list']['class'][] = 'tabs';
    $variables['primary']['#atomium']['attributes']['list']['class'][] = 'primary';
  }
  if (!empty($variables['secondary'])) {
    $variables['secondary']['#atomium']['attributes']['list']['class'][] = 'tabs';
    $variables['secondary']['#atomium']['attributes']['list']['class'][] = 'secondary';
    $variables['secondary']['#atomium']['attributes']['list']['class'][] = 'clearfix';
  }
}
