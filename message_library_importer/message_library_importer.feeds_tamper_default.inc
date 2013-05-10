<?php
/**
 * @file
 * message_library_importer.feeds_tamper_default.inc
 */

/**
 * Implements hook_feeds_tamper_default().
 */
function message_library_importer_feeds_tamper_default() {
  $export = array();

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'message_library_node_message-alert_questions-explode_quesitons';
  $feeds_tamper->importer = 'message_library_node_message';
  $feeds_tamper->source = 'Alert Questions';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'separator' => '?',
    'limit' => '',
    'real_separator' => '?',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Explode ';
  $export['message_library_node_message-alert_questions-explode_quesitons'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'message_library_node_message-at_risk_group-explode_arg_terms_by_comma';
  $feeds_tamper->importer = 'message_library_node_message';
  $feeds_tamper->source = 'At Risk Group';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'separator' => ',',
    'limit' => '',
    'real_separator' => ',',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Explode terms by comma';
  $export['message_library_node_message-at_risk_group-explode_arg_terms_by_comma'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'message_library_node_message-information_type-explode_it_terms_by_comma';
  $feeds_tamper->importer = 'message_library_node_message';
  $feeds_tamper->source = 'Information Type';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'separator' => ',',
    'limit' => '',
    'real_separator' => ',',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Explode terms by comma';
  $export['message_library_node_message-information_type-explode_it_terms_by_comma'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'message_library_node_message-target_audience-explode_ta_terms_by_comma';
  $feeds_tamper->importer = 'message_library_node_message';
  $feeds_tamper->source = 'Target Audience';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'separator' => ',',
    'limit' => '',
    'real_separator' => ',',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Explode terms by comma';
  $export['message_library_node_message-target_audience-explode_ta_terms_by_comma'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'message_library_term_threat-threat_hazard-explode_hazard_by_comma';
  $feeds_tamper->importer = 'message_library_term_threat';
  $feeds_tamper->source = 'Threat Hazard';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'separator' => ',',
    'limit' => '',
    'real_separator' => ',',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Explode hazard by comma';
  $export['message_library_term_threat-threat_hazard-explode_hazard_by_comma'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'message_library_term_threat-threat_issue-explode_issues_by_comma';
  $feeds_tamper->importer = 'message_library_term_threat';
  $feeds_tamper->source = 'Threat Issue';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'separator' => ',',
    'limit' => '',
    'real_separator' => ',',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Explode Issues by comma';
  $export['message_library_term_threat-threat_issue-explode_issues_by_comma'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'message_library_term_threat-threat_sector-explode_sectors_by_comma';
  $feeds_tamper->importer = 'message_library_term_threat';
  $feeds_tamper->source = 'Threat Sector';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'separator' => ',',
    'limit' => '',
    'real_separator' => ',',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Explode sectors by comma';
  $export['message_library_term_threat-threat_sector-explode_sectors_by_comma'] = $feeds_tamper;

  return $export;
}
