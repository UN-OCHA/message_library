<?php
/**
 * @file
 * infoasaid_documentation.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function infoasaid_documentation_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function infoasaid_documentation_node_info() {
  $items = array(
    'documentation' => array(
      'name' => t('Documentation page'),
      'base' => 'node_content',
      'description' => t('Add a page to the Users or Editors documentation.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
