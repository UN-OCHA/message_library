<?php
/**
 * @file
 * infoasaid_others.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function infoasaid_others_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function infoasaid_others_node_info() {
  $items = array(
    'page_with_view' => array(
      'name' => t('Page with view'),
      'base' => 'node_content',
      'description' => t('Add a page with a view inside'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
