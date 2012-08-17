<?php
/**
 * @file
 * infoasaid_media.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function infoasaid_media_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function infoasaid_media_node_info() {
  $items = array(
    'media_telecom_transmitter' => array(
      'name' => t('Media Telecom Transmitter'),
      'base' => 'node_content',
      'description' => t('A transmitter content item describes the location of a transmission site.'),
      'has_title' => '1',
      'title_label' => t('Name'),
      'help' => '',
    ),
  );
  return $items;
}
