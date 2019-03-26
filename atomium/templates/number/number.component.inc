<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_theme_hook().
 */
function atomium_atomium_theme_number(array $existing, $type, $theme, $path) {
  return array(
    'number' => array(
      'render element' => 'element',
      'template' => 'number',
    ),
  );
}

/**
 * Implements hook_atomium_definition_hook().
 */
function atomium_atomium_definition_number() {
  return array(
    'label' => 'Number element',
    'description' => 'Number description.',
  );
}

/**
 * Implements hook_atomium_definition_form_hook().
 */
function atomium_atomium_definition_form_number(array $form, array &$form_state) {
  $form['element1'] = array(
    '#title' => 'Number',
    '#description' => 'Number description',
    '#type' => 'number',
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
function atomium_preprocess_number(array &$variables, $hook) {
  _form_set_class($variables['element'], array('form-number'));
  element_set_attributes(
    $variables['element'],
    array(
      'id',
      'name',
      'value',
      'size',
      'step',
      'min',
      'max',
      'maxlength',
      'placeholder',
    )
  );

  $attributes = _atomium_get_attributes($variables['element']);
  $attributes += array('type' => 'number');

  if (isset($variables['element']['#atomium']['attributes']['element'])) {
    $variables['atomium']['attributes']['element']
      ->merge($variables['element']['#atomium']['attributes']['element']);
  }

  $variables['atomium']['attributes']['element']->merge($attributes);
}
