<?php
/**
 * @file
 * infoasaid_guide.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function infoasaid_guide_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function infoasaid_guide_node_info() {
  $items = array(
    'book' => array(
      'name' => t('Book page'),
      'base' => 'node_content',
      'description' => t('<em>Books</em> have a built-in hierarchical navigation. Use for handbooks or tutorials.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'guide' => array(
      'name' => t('Guide'),
      'base' => 'node_content',
      'description' => t('Create a new guide'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'guide_page' => array(
      'name' => t('Guide Page'),
      'base' => 'node_content',
      'description' => t('Create a new page for an existing guide'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
