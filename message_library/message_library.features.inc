<?php
/**
 * @file
 * message_library.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function message_library_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  list($module, $api) = func_get_args();
  if ($module == "facetapi" && $api == "facetapi_defaults") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function message_library_views_api() {
  return array("version" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function message_library_node_info() {
  $items = array(
    'message' => array(
      'name' => t('Message'),
      'base' => 'node_content',
      'description' => t('Use <em>Message</em> for creating message in <strong>Message Library</strong>'),
      'has_title' => '1',
      'title_label' => t('Information Requirement'),
      'help' => '',
    ),
  );
  return $items;
}
