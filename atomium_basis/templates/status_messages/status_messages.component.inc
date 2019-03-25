<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_preprocess_hook().
 */
function atomium_basis_preprocess_status_messages(&$variables, $hook) {
  $variables += array('status_messages' => array('status_messages' => array()));

  if ($variables['status_messages']['status_messages'] !== NULL) {
    array_walk($variables['status_messages']['status_messages'], function (&$messages) {
      unset($messages['messages']['#title']);
      $messages['#attributes']['class'][] = 'messages';
    });
  }
}
