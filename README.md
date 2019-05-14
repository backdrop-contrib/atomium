# Atomium
[![Current Release](https://img.shields.io/github/release/backdrop-contrib/atomium.svg?style=flat-square)](https://github.com/backdrop-contrib/atomium/releases)
[![GitHub issues](https://img.shields.io/github/issues/backdrop-contrib/atomium.svg?style=flat-square)](https://github.com/backdrop-contrib/atomium/issues?q=is:open+is:issue) 

The Atomium theme is a base theme.

The goal of this base theme is to rewrite most of the core theme functions of
Backdrop and use proper render arrays and then templates instead.
This will allow users to customize most of the elements in a custom
sub-theme using preprocess functions or by providing a custom template.

Table of contents:
=================
- [Installation](#installation-and-usage)
- [Issues](#issues)
- [Activation](#activation)
- [Configuration](#configuration)
- [Contributing](#contributing)
- [Extending](#extending)
- [Developers note](#developers-note)
- [Known issues](#known-issues)
- [In the press](#in-the-press)
- [Current maintainers](#current-maintainers)
- [Credits](#credits)
- [License](#license)

[Go to top](#table-of-content)

# Installation and Usage

- Install this module using the [official Backdrop CMS instructions](https://backdropcms.org/guide/themes)

# Issues

 - Bugs and Feature requests should be reported in the [Issue Queue](https://github.com/backdrop-contrib/atomium/issues).

# Requirements
* PHP: greater or equal to version 5.6.
* Backdrop 1.x: latest stable version,

[Go to top](#table-of-content)

# Activation
To enable the theme, go to **admin/appearance** and select an Atomium
based theme.

Atomium comes with a sub-theme provided as example.

 - Atomium Basis.
 
Atomium Basis is a fork of the Basis core theme using the Atomium mechanisms.

The sub-theme provide examples of *preprocess* functions and templates so you
can craft your own theme quickly.

[Go to top](#table-of-content)

# Configuration
Atomium is not intended to be a full featured and fancy theme,
full of configurable settings and with a friendly user interface.
The sole purpose of this theme is to provide clean markup that you can
easily extend.

In order to easily see which template is used, enable the `theme debug mode`
option provided by the [devel contrib module](https://github.com/backdrop-contrib/devel).

The `theme debug mode` can be used to see possible template suggestions and the
locations of template files right in your HTML markup (as HTML comments).

[Go to top](#table-of-content)

# Contributing

Atomium is licenced under the [GPL-2 Licence](LICENSE.txt).
All contributions to Atomium and its sub-themes are made on [Github](https://github.com/backdrop-contrib/atomium), the main
Atomium repository.

To ensure its code quality, Atomium depends on: 
 - [GrumPHP](https://github.com/phpro/grumphp)
 - [Backdrop conventions](https://github.com/drupol/backdrop-conventions)

# Extending

Atomium provides a way of extending just by creating some files without modifying
the core Atomium files.
Each theme definition, core or custom, is treated as a component.
You can find all the theme definitions in the *templates* directory of
each sub-theme.

To create a new theme definition:

 - Create a directory in *templates* and name it as you will. A good practice
 is to give it the name of the definition.
 - Create a file *[NAME-OF-THE-THEME-DEFINITION].component.inc*,
 - Create the function *[NAME-OF-THE-THEME]\_atomium_theme\_[NAME-OF-THE-THEME-DEFINITION]\()*,
 - Create a file *[NAME-OF-THE-THEME_DEFINITION].css* and/or *[NAME-OF-THE-THEME_DEFINITION].js* to get these files
  automatically loaded.
  
Atomium provides a custom page available on the path: **atomium-overview**.
This particular page is only available to users with _administer themes_ permission.

This page acts as a showcase page of components.
To add a component in there, your component needs to define two hooks:
 - hook_atomium_definition_hook().
   
   This hook allows you to define simply a component.
 - hook_atomium_definition_form_hook().
   
   This hook allows you to define one or multiple components in a Backdrop form.
   
For a better understanding and examples, see the [atomium.api.php](https://github.com/ec-europa/atomium/blob/7.x-1.x/atomium/atomium.api.php) file.
  
Do not forget to clear the cache every time a new theme definition or
process/preprocess is added or removed.

[Go to top](#table-of-content)

# Developer's note

During the development of this project, a lot of time has been put into
analyzing how Backdrop's core functions were implemented and how to improve them
for better customization.

A good example of this is the breadcrumb generation.

Let's analyse how it is currently done in Backdrop and how it is implemented on this project.

````php
$variables['breadcrumb'] = theme('breadcrumb', array('breadcrumb' => backdrop_get_breadcrumb()));
````

By default, Backdrop uses the function *backdrop_get_breadcrumb()* in its
*template_process_page()* hook.

The function *backdrop_get_breadcrumb()* returns raw HTML.
Thus, it is impossible to alter the breadcrumbs links properly.

In order to get a render array, it requires a deeper analyse and rewrite functions
accordingly.

*backdrop_get_breadcrumb()* calls *menu_get_active_breadcrumb()*.
This is actually the function that returns the HTML.

There is no way to alter the result of that function as it returns an array of
raw HTML links.

Unfortunately, in order to change this behaviour, two extra
functions were implemented in Atomium, also the way
the breadcrumb is generated changed, by overriding the default one as shown below:

````php
  $variables['breadcrumb'] = array(
    '#theme' => array('breadcrumb'),
    '#breadcrumb' => atomium_backdrop_get_breadcrumb(),
  );
````

*atomium_backdrop_get_breadcrumb()* is an Atomium internal function written only
for the breadcrumb handling. Instead of calling *menu_get_active_breadcrumb()*,
it calls *atomium_menu_get_active_breadcrumb()* which is also a
custom Atomium function that, instead of returning an array of raw HTML links,
returns an array of render arrays.

This is why, in *page.tpl.php*, instead of writing:

````php
<?php print $breadcrumb; ?>
````

You have to use:

````php
<?php print render($breadcrumb); ?>
````

The rendering process is at the very end of the Backdrop's chain of preprocess,
process and render functions.

[Go to top](#table-of-content)

# Known issues

* Vertical tabs: Unable to apply the theme function call inheritance. It has a link with the process function. 

[Go to top](#table-of-content)


# In the press

* [A word about Atomium](http://not-a-number.io/2017/a-word-about-atomium)

[Go to top](#table-of-content)

# Current Maintainers

- Pol Dellaiera (https://github.com/drupol).

# Credits

- Ported to Backdrop CMS by Pol Dellaiera (https://github.com/drupol).
- Originally written for Backdrop by the European Commission (https://www.drupal.org/european-commission).

# License

This project is GPL v2 software. See the [LICENSE.txt](LICENSE.txt) file in this directory for
complete text.
