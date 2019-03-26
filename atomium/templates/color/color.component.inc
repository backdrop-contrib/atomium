<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_theme_hook().
 */
function atomium_atomium_theme_color(array $existing, $type, $theme, $path) {
  return array(
    'color' => array(
      'render element' => 'element',
      'template' => 'color',
    ),
  );
}

/**
 * Implements hook_atomium_definition_hook().
 */
function atomium_atomium_definition_color() {
  return array(
    'label' => 'Color',
    'description' => 'Color field description.',
    'preview' => array(
      array(
        'title' => 'Color field',
        'description' => 'Color field description',
      ),
    ),
  );
}

/**
 * Implements hook_preprocess_hook().
 */
function atomium_preprocess_color(array &$variables, $hook) {
  _form_set_class($variables['element'], array('form-color'));
  element_set_attributes(
    $variables['element'],
    array(
      0 => 'id',
      1 => 'name',
      2 => 'value',
    )
  );

  $variables['atomium']['attributes']['element']
    ->setAttributes(_atomium_get_attributes($variables['element']), FALSE);

  $attributes['type'] = 'color';

  if (isset($variables['element']['#field_name'])) {
    $variables['theme_hook_suggestions'][] = 'color__' . $variables['element']['#field_name'];
  }
  if (isset($variables['element']['#entity_type'])) {
    $variables['theme_hook_suggestions'][] = 'color__' . $variables['element']['#entity_type'];
    if (isset($variables['element']['#field_name'])) {
      $variables['theme_hook_suggestions'][] = 'color__' . $variables['element']['#entity_type'] . '__' . $variables['element']['#field_name'];
    }
    if (isset($variables['element']['#bundle'])) {
      $variables['theme_hook_suggestions'][] = 'color__' . $variables['element']['#entity_type'] . '__' . $variables['element']['#bundle'];
    }
  }

  if (isset($variables['element']['#atomium']['attributes']['element'])) {
    $variables['atomium']['attributes']['element']
      ->merge($variables['element']['#atomium']['attributes']['element']);
  }

  $variables['atomium']['attributes']['element']->merge($attributes);
}
