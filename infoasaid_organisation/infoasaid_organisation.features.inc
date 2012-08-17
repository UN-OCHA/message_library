<?php
/**
 * @file
 * infoasaid_organisation.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function infoasaid_organisation_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function infoasaid_organisation_node_info() {
  $items = array(
    'media_telecom_organisation' => array(
      'name' => t('Media Telecom Organisation'),
      'base' => 'node_content',
      'description' => t('Create content for the Media/Telecom Database'),
      'has_title' => '1',
      'title_label' => t('Organisation Name'),
      'help' => '',
    ),
  );
  return $items;
}
