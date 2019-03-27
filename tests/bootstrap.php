<?php

/**
 * @file
 * PHPUnit bootstrap file.
 */

require_once './vendor/autoload.php';

// Directory change necessary since Drupal often uses relative paths.
\chdir(BACKDROP_ROOT);

require_once BACKDROP_ROOT . '/includes/bootstrap.inc';

/**
 * Return template file and variables array for testing purposes.
 *
 * @param string $template_file
 *   Template file.
 * @param mixed $variables
 *   Variables array.
 *
 * @return array
 *   Template file and variables array for testing purposes.
 */
function atomium_test_render_template($template_file, $variables) {
  return array(
    'template' => $template_file,
    'variables' => $variables,
  );
}

backdrop_bootstrap(BACKDROP_BOOTSTRAP_FULL);
