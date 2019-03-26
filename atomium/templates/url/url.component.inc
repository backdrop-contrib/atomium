<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_theme_hook().
 */
function atomium_atomium_theme_url(array $existing, $type, $theme, $path) {
  return array(
    'url' => array(
      'render element' => 'element',
      'template' => 'url',
    ),
  );
}

/**
 * Implements hook_atomium_definition_hook().
 */
function atomium_atomium_definition_url() {
  return array(
    'label' => 'URL element',
    'description' => 'URL description.',
  );
}

/**
 * Implements hook_atomium_definition_form_hook().
 */
function atomium_atomium_definition_form_url(array $form, array &$form_state) {
  $form['element1'] = array(
    '#title' => 'URL',
    '#description' => 'URL description',
    '#type' => 'url',
  );

  return $form;
}

/**
 * Implements hook_preprocess_hook().
 */
function atomium_preprocess_url(array &$variables, $hook) {
  _form_set_class($variables['element'], array('form-url'));
  element_set_attributes(
    $variables['element'],
    array(
      'id',
      'name',
      'value',
      'size',
      'maxlength',
      'placeholder',
    )
  );

  $variables['atomium']['attributes']['element']
    ->setAttributes(_atomium_get_attributes($variables['element']), FALSE);

  $attributes['type'] = 'url';

  if (isset($variables['element']['#autocomplete_path']) &&
    backdrop_valid_path($variables['element']['#autocomplete_path'])) {
    backdrop_add_library('system', 'backdrop.autocomplete');
    $attributes['class'][] = 'form-autocomplete';

    $variables['suffix'] = array(
      '#type' => 'hidden',
      '#id' => $variables['element']['#attributes']['id'] . '-autocomplete',
      '#value' => url($variables['element']['#autocomplete_path'], array('absolute' => TRUE)),
      '#disabled' => 'disabled',
      '#atomium' => array(
        'attributes' => array(
          'element' => array(
            'class' => array(
              'autocomplete',
            ),
          ),
        ),
      ),
    );
  }

  if (isset($variables['element']['#field_name'])) {
    $variables['theme_hook_suggestions'][] = 'url__' . $variables['element']['#field_name'];
  }
  if (isset($variables['element']['#entity_type'])) {
    $variables['theme_hook_suggestions'][] = 'url__' . $variables['element']['#entity_type'];
    if (isset($variables['element']['#field_name'])) {
      $variables['theme_hook_suggestions'][] = 'url__' . $variables['element']['#entity_type'] . '__' . $variables['element']['#field_name'];
    }
    if (isset($variables['element']['#bundle'])) {
      $variables['theme_hook_suggestions'][] = 'url__' . $variables['element']['#entity_type'] . '__' . $variables['element']['#bundle'];
    }
  }

  if (isset($variables['element']['#atomium']['attributes']['element'])) {
    $variables['atomium']['attributes']['element']
      ->merge($variables['element']['#atomium']['attributes']['element']);
  }

  $variables['atomium']['attributes']['element']->merge($attributes);
}
