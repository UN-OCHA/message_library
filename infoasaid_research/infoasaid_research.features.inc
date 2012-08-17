<?php
/**
 * @file
 * infoasaid_research.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function infoasaid_research_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function infoasaid_research_node_info() {
  $items = array(
    'research' => array(
      'name' => t('Research'),
      'base' => 'node_content',
      'description' => t('Post your Research Reports here.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
