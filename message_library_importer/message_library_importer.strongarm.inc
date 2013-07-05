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
  $strongarm->name = 'ml_importer_import_paths';
  $strongarm->value = array(
    'message_library_node_message' => 'http://infoasaid.org/message-library-export/message',
    'message_library_term_at_risk_group' => 'http://infoasaid.org/message-library-export/at-risk-group',
    'message_library_term_hazard' => 'http://infoasaid.org/message-library-export/hazard',
    'message_library_term_information_type' => 'http://infoasaid.org/message-library-export/information-type',
    'message_library_term_issues' => 'http://infoasaid.org/message-library-export/issues',
    'message_library_term_sector' => 'http://infoasaid.org/message-library-export/sector',
    'message_library_term_target_audience' => 'http://infoasaid.org/message-library-export/target-audience',
    'message_library_term_threat' => 'http://infoasaid.org/message-library-export/threat',
  );
  $export['ml_importer_import_paths'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ml_importer_interval';
  $strongarm->value = '14400';
  $export['ml_importer_interval'] = $strongarm;

  return $export;
}
