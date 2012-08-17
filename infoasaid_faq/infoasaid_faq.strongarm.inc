<?php
/**
 * @file
 * infoasaid_faq.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function infoasaid_faq_strongarm() {
  $export = array();

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_type_faq';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_type_faq'] = $strongarm;

  return $export;
}
