<?php
/**
 * @file
 * infoasaid_aar.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function infoasaid_aar_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function infoasaid_aar_node_info() {
  $items = array(
    'aas' => array(
      'name' => t('After Action Reviews'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
