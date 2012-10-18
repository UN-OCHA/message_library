<?php
/**
 * @file
 * message_library_help.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function message_library_help_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "boxes" && $api == "box") {
    return array("version" => "1");
  }
}
