<?php
/**
 * @file
 * message_libarary.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function message_libarary_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function message_libarary_node_info() {
  $items = array(
    'message' => array(
      'name' => t('Message'),
      'base' => 'node_content',
      'description' => t('Use <em>Message</em> for creating message in <strong>Message Library</strong>'),
      'has_title' => '1',
      'title_label' => t('Information Requirement'),
      'help' => '',
    ),
    'threat' => array(
      'name' => t('Threat'),
      'base' => 'node_content',
      'description' => t('Use <em>Threat</em> for creating the corresponding content in <strong>Message Library</strong>'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
