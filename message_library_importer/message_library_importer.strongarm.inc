<?php
/**
 * @file
 * message_library_importer.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function message_library_importer_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ml_importer_base_url';
  $strongarm->value = 'http://infoasaid.org/message-library-export/';
  $export['ml_importer_base_url'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ml_importer_interval';
  $strongarm->value = '14400';
  $export['ml_importer_interval'] = $strongarm;

  return $export;
}
