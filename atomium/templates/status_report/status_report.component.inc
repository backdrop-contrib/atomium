<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_theme_hook().
 */
function atomium_atomium_theme_status_report(array $existing, $type, $theme, $path) {
  return array(
    'status_report' => array(
      'render element' => 'element',
      'template' => 'status-report',
    ),
  );
}

/**
 * Implements hook_preprocess_hook().
 */
function atomium_preprocess_status_report(array &$variables, $hook) {
  $requirements = $variables['requirements'];
  $rows = array();

  $severities = array(
    REQUIREMENT_INFO => array(
      'title' => t('Info'),
      'class' => 'report-info',
    ),
    REQUIREMENT_OK => array(
      'title' => t('OK'),
      'class' => 'report-status',
    ),
    REQUIREMENT_WARNING => array(
      'title' => t('Warning'),
      'class' => 'report-warning',
    ),
    REQUIREMENT_ERROR => array(
      'title' => t('Error'),
      'class' => 'report-error',
    ),
  );

  $variables['atomium']['attributes']['wrapper']
    ->append('class', 'system-status-report');

  foreach ($requirements as $requirement) {
    if (!empty($requirement['#type'])) {
      continue;
    }

    $severity = $severities[isset($requirement['severity']) ? (int) $requirement['severity'] : REQUIREMENT_OK];

    $requirement['value'] = isset($requirement['value']) ? $requirement['value'] : '';

    $icon = array(
      'data' => array(
        'container' => array(
          '#theme' => 'html_tag',
          '#tag' => 'div',
          '#attributes' => array(
            'title' => $severity['title'],
          ),
          '#value' => array(
            '#theme' => 'htmltag',
            '#tag' => 'span',
            '#attributes' => array(
              'class' => array(
                'element-invisible',
              ),
            ),
            '#value' => $severity['title'],
          ),
        ),
      ),
      'class' => array(
        'report-icon',
      ),
    );

    $title = array(
      'data' => $requirement['title'],
      'class' => array(
        'status-title',
      ),
    );

    $description = array(
      'data' => array(
        'container' => array(
          '#theme' => 'html_tag',
          '#tag' => 'div',
          '#attributes' => array(
            'class' => array(
              'status-summary',
            ),
          ),
          '#value' => $requirement['value'],
        ),
      ),
      'class' => array(
        'status-value',
      ),
    );

    if (!empty($requirement['description'])) {
      $description['data']['container']['#value'] .= ' <a class="description-toggle" href="#">more</a>' .
        '<div class="status-description">' . $requirement['description'] . '</div>';
    }

    $rows[] = array(
      'data' => array(
        $icon,
        $title,
        $description,
      ),
      'class' => array(
        $severity['class'],
      ),
    );

  }

  $table = array(
    '#theme' => _atomium_extend_theme_hook(
      'table',
      array(
        $variables['theme_hook_original'],
      )
    ),
    '#rows' => $rows,
    '#atomium' => array(
      'attributes' => array(
        'wrapper' => array(
          'class' => array(
            'system-status-report',
          ),
        ),
      ),
    ),
  );

  $path = backdrop_get_path('module', 'system');
  backdrop_add_js($path . '/js/status.js');

  $variables[$variables['base_hook']] = array(
    $variables['base_hook'] => $table,
  );
}
