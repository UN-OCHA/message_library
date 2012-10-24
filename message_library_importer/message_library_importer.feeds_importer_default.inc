<?php
/**
 * @file
 * message_library_importer.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function message_library_importer_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'message_import';
  $feeds_importer->config = array(
    'name' => 'Message Import',
    'description' => 'import message from csv',
    'fetcher' => array(
      'plugin_key' => 'FeedsHTTPFetcher',
      'config' => array(
        'auto_detect_feeds' => FALSE,
        'use_pubsubhubbub' => FALSE,
        'designated_hub' => '',
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsCSVParser',
      'config' => array(
        'delimiter' => ',',
        'no_headers' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'content_type' => 'message',
        'expire' => '-1',
        'author' => 0,
        'mappings' => array(
          0 => array(
            'source' => 'guid',
            'target' => 'guid',
            'unique' => 1,
          ),
          1 => array(
            'source' => 'nid',
            'target' => 'nid',
            'unique' => 0,
          ),
          2 => array(
            'source' => 'title',
            'target' => 'title',
            'unique' => 0,
          ),
          3 => array(
            'source' => 'message',
            'target' => 'field_message_group_mess',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'risk group',
            'target' => 'field_message_group_risk',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'risk group comment',
            'target' => 'field_message_group_risk_comment',
            'unique' => FALSE,
          ),
          6 => array(
            'source' => 'target audience',
            'target' => 'field_message_audience',
            'unique' => FALSE,
          ),
          7 => array(
            'source' => 'target audience comment',
            'target' => 'field_message_target_comment',
            'unique' => FALSE,
          ),
          8 => array(
            'source' => 'information type',
            'target' => 'field_message_info_type',
            'unique' => FALSE,
          ),
          9 => array(
            'source' => 'sensitivity',
            'target' => 'field_message_sensitivity',
            'unique' => FALSE,
          ),
          10 => array(
            'source' => 'sensitivity message',
            'target' => 'field_message_sensitivity_messag',
            'unique' => FALSE,
          ),
          11 => array(
            'source' => 'alert questions',
            'target' => 'field_message_sensitivity_questi',
            'unique' => FALSE,
          ),
          12 => array(
            'source' => 'sensitivity causes',
            'target' => 'field_message_sensitivity_causes',
            'unique' => FALSE,
          ),
          13 => array(
            'source' => 'threat',
            'target' => 'field_message_threat',
            'unique' => FALSE,
          ),
          14 => array(
            'source' => 'source',
            'target' => 'field_message_source:url',
            'unique' => FALSE,
          ),
          15 => array(
            'source' => 'examples',
            'target' => 'field_message_example_communic',
            'unique' => FALSE,
          ),
          16 => array(
            'source' => 'websites',
            'target' => 'field_message_url:url',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'input_format' => 'plain_text',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '0',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['message_import'] = $feeds_importer;

  return $export;
}
