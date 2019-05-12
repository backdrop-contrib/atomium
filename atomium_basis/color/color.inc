<?php

$info = array(
  // Available colors and color labels used in theme.
  'fields' => array(
    'header' => t('Header background'),
    'base' => t('Site name background'),
    'slogan' => t('Slogan background'),
    'titleslogan' => t('Site name and slogan'),
    'bg' => t('Main background'),
    'footer' => t('Footer background'),
    'text' => t('Text color'),
    'link' => t('Link color'),
    'hovermenu' => t('Main menu hover background'),
    'primarytabs' => t('Primary Tabs background'),
    'borders' => t('Borders'),
    'formfocusborder' => t('Form element borders when selected'),
    'buttons' => t('Buttons and Breadcrumb'),
  ),
  // Pre-defined color schemes.
  'schemes' => array(
    'default' => array(
      'title' => t('Basis (default)'),
      'colors' => array(
        'header' => '#20252e',
        'base' => '#0074bd',
        'slogan' => '#000000',
        'titleslogan' => '#fffffe',
        'bg' => '#ffffff',
        'footer' => '#fffeff',
        'text' => '#000001',
        'link' => '#0073bd',
        'hovermenu' => '#114a75',
        'primarytabs' => '#586172',
        'borders' => '#bbbbbb',
        'formfocusborder' => '#43afe4',
        'buttons' => '#dee2ea',
      ),
    ),
  ),

  'blend_target' => '#ffffff',

  // CSS files (excluding @import) to rewrite with new color scheme.
  'css' => array(
    'assets/css/base.css',
    'assets/css/layout.css',
    'assets/css/component/small-text-components.css',
    'assets/css/component/header.css',
    'assets/css/component/footer.css',
    'assets/css/component/menu-dropdown.css',
    'assets/css/component/menu-toggle.css',
    'assets/css/component/backdrop-form.css',
    'assets/css/component/tabledrag.css',
    'assets/css/component/vertical-tabs.css',
    'assets/css/component/fieldset.css',
    'assets/css/component/dialog.css',
    'assets/css/component/progress.css',
    'assets/css/component/admin-tabs.css',
    'assets/css/component/breadcrumb.css',
    'assets/css/component/pager.css',
    'assets/css/component/hero.css',
    'assets/css/component/teasers.css',
    'assets/css/component/comment.css',
    'assets/css/component/caption.css',
    'assets/css/skin.css',
  ),
);
