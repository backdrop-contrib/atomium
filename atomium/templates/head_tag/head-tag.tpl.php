<?php

/**
 * @file
 * Contains template file.
 */
?>
<?php if (!isset($element['#value'])): ?>
  <<?php print $element['#tag']; ?><?php print $atomium['attributes']['element']; ?>/>
<?php else: ?>
  <<?php print $element['#tag']; ?><?php print $atomium['attributes']['element']; ?>><?php print render($element['#value_prefix']); ?><?php print render($element['#value']); ?><?php print render($element['#value_suffix']); ?></<?php print $element['#tag']; ?>>
<?php endif; ?>
