<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_theme_hook().
 */
function atomium_atomium_theme_range(array $existing, $type, $theme, $path) {
  return array(
    'range' => array(
      'render element' => 'element',
      'template' => 'range',
    ),
  );
}

/**
 * Implements hook_atomium_definition_hook().
 */
function atomium_atomium_definition_range() {
  return array(
    'label' => 'Range element',
    'description' => 'Range description.',
  );
}

/**
 * Implements hook_atomium_definition_form_hook().
 */
function atomium_atomium_definition_form_range(array $form, array &$form_state) {
  $form['element1'] = array(
    '#title' => 'Range',
    '#description' => 'Range description',
    '#type' => 'range',
    '#min' => 1,
    '#max' => 10,
    '#step' => 1,
    '#size' => 30,
  );

  return $form;
}

/**
 * Implements hook_preprocess_hook().
 */
function atomium_preprocess_range(array &$variables, $hook) {
  _form_set_class($variables['element'], array('form-range'));
  element_set_attributes(
    $variables['element'],
    array('id', 'name', 'value', 'step', 'min', 'max', 'placeholder')
  );

  $attributes = _atomium_get_attributes($variables['element']);
  $attributes += array('type' => 'range');

  if (isset($variables['element']['#atomium']['attributes']['element'])) {
    $variables['atomium']['attributes']['element']
      ->merge($variables['element']['#atomium']['attributes']['element']);
  }

  $variables['atomium']['attributes']['element']->merge($attributes);
}
