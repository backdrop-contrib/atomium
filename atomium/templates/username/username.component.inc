<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_theme_HOOK().
 */
function atomium_atomium_theme_username() {
  return array(
    'username' => array(
      'render element' => 'element',
      'template' => 'username',
      'variables' => array('account' => NULL),
    ),
  );
}

/**
 * Implements hook_preprocess_HOOK().
 */
function atomium_preprocess_username(&$variables) {
  if (isset($variables['uid'])) {
    $variables['theme_hook_suggestions'][] = 'username__uid_' . $variables['uid'];
  }
  if (isset($variables['name'])) {
    $variables['theme_hook_suggestions'][] = 'username__name_' . drupal_html_class($variables['name']);
  }

  $variables['link_options'] += array(
    'attributes' => array(),
  );

  if (isset($variables['link_path'])) {
    $variables['name'] = array(
      '#theme' => 'link',
      '#text' => $variables['name'] . $variables['extra'],
      '#path' => $variables['link_path'],
      '#options' => $variables['link_options'],
    );
  }
}