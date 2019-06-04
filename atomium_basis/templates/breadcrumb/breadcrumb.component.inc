<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_preprocess_hook().
 */
function atomium_basis_preprocess_breadcrumb(&$variables, $hook) {
  $variables[$hook][$hook]['#type'] = 'ol';

  foreach ($variables[$hook][$hook]['#items'] as &$item) {
    unset($item['#theme_wrappers']);
  }

  $variables['atomium']['attributes']['wrapper']
    ->append('class', array('breadcrumb'))
    ->append('role', 'breadcrumb');
}
