<?php
/**
 * @file
 * infoasaid_threat.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function infoasaid_threat_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function infoasaid_threat_node_info() {
  $items = array(
    'threat' => array(
      'name' => t('Threat'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
