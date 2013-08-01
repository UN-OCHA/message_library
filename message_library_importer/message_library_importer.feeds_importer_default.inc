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
  $feeds_importer->id = 'message_library_node_message';
  $feeds_importer->config = array(
    'name' => '[Message Library] Node - Message',
    'description' => 'Import <Message> nodes',
    'fetcher' => array(
      'plugin_key' => 'FeedsHTTPFetcher',
      'config' => array(
        'auto_detect_feeds' => FALSE,
        'use_pubsubhubbub' => FALSE,
        'designated_hub' => '',
        'request_timeout' => NULL,
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
        'expire' => '-1',
        'author' => '1',
        'mappings' => array(
          0 => array(
            'source' => 'Message Nid',
            'target' => 'guid',
            'unique' => 1,
          ),
          1 => array(
            'source' => 'Information Requirement',
            'target' => 'title',
            'unique' => 0,
          ),
          2 => array(
            'source' => 'Message',
            'target' => 'field_message_group_mess',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'At Risk Group',
            'target' => 'field_message_group_risk',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'At Risk Group Comment',
            'target' => 'field_message_group_risk_comment',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'Target Audience',
            'target' => 'field_message_audience',
            'unique' => FALSE,
          ),
          6 => array(
            'source' => 'Target Audience Comment',
            'target' => 'field_message_target_comment',
            'unique' => FALSE,
          ),
          7 => array(
            'source' => 'Information Type',
            'target' => 'field_message_info_type',
            'unique' => FALSE,
          ),
          8 => array(
            'source' => 'Sensitivity',
            'target' => 'field_message_sensitivity',
            'unique' => FALSE,
          ),
          9 => array(
            'source' => 'Warning/Alert Message',
            'target' => 'field_message_sensitivity_messag',
            'unique' => FALSE,
          ),
          10 => array(
            'source' => 'Alert Questions',
            'target' => 'field_message_sensitivity_questi',
            'unique' => FALSE,
          ),
          11 => array(
            'source' => 'Sensitivity Causes',
            'target' => 'field_message_sensitivity_causes',
            'unique' => FALSE,
          ),
          12 => array(
            'source' => 'Threat',
            'target' => 'field_message_threat',
            'unique' => FALSE,
          ),
          13 => array(
            'source' => 'Source',
            'target' => 'field_message_source:url',
            'unique' => FALSE,
          ),
          14 => array(
            'source' => 'Examples of Communication around this Issue',
            'target' => 'field_message_example_communic',
            'unique' => FALSE,
          ),
          15 => array(
            'source' => 'Websites',
            'target' => 'field_message_url:url',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'input_format' => 'plain_text',
        'authorize' => 0,
        'skip_hash_check' => 1,
        'bundle' => 'message',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['message_library_node_message'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'message_library_term_at_risk_group';
  $feeds_importer->config = array(
    'name' => '[Message Library] Term - At Risk Group',
    'description' => 'Import <At risk group> terms',
    'fetcher' => array(
      'plugin_key' => 'FeedsHTTPFetcher',
      'config' => array(
        'auto_detect_feeds' => FALSE,
        'use_pubsubhubbub' => FALSE,
        'designated_hub' => '',
        'request_timeout' => NULL,
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
      'plugin_key' => 'FeedsTermProcessor',
      'config' => array(
        'vocabulary' => 'at_risk_groups',
        'mappings' => array(
          0 => array(
            'source' => 'Term ID',
            'target' => 'guid',
            'unique' => 1,
          ),
          1 => array(
            'source' => 'Term Name',
            'target' => 'name',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'Term description',
            'target' => 'description',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'Parent Term ID',
            'target' => 'parentguid',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'input_format' => 'plain_text',
        'skip_hash_check' => 1,
        'bundle' => 'at_risk_groups',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['message_library_term_at_risk_group'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'message_library_term_hazard';
  $feeds_importer->config = array(
    'name' => '[Message Library] Term - Hazard',
    'description' => 'Import <Hazard> terms',
    'fetcher' => array(
      'plugin_key' => 'FeedsHTTPFetcher',
      'config' => array(
        'auto_detect_feeds' => FALSE,
        'use_pubsubhubbub' => FALSE,
        'designated_hub' => '',
        'request_timeout' => NULL,
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
      'plugin_key' => 'FeedsTermProcessor',
      'config' => array(
        'vocabulary' => 'hazard',
        'mappings' => array(
          0 => array(
            'source' => 'Term ID',
            'target' => 'guid',
            'unique' => 1,
          ),
          1 => array(
            'source' => 'Term Name',
            'target' => 'name',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'Term description',
            'target' => 'description',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'Parent Term ID',
            'target' => 'parentguid',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'input_format' => 'plain_text',
        'skip_hash_check' => 1,
        'bundle' => 'hazard',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['message_library_term_hazard'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'message_library_term_information_type';
  $feeds_importer->config = array(
    'name' => '[Message Library] Term - Information Type',
    'description' => 'Import <Information Types> terms',
    'fetcher' => array(
      'plugin_key' => 'FeedsHTTPFetcher',
      'config' => array(
        'auto_detect_feeds' => FALSE,
        'use_pubsubhubbub' => FALSE,
        'designated_hub' => '',
        'request_timeout' => NULL,
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
      'plugin_key' => 'FeedsTermProcessor',
      'config' => array(
        'vocabulary' => 'information_type',
        'mappings' => array(
          0 => array(
            'source' => 'Term ID',
            'target' => 'guid',
            'unique' => 1,
          ),
          1 => array(
            'source' => 'Term Name',
            'target' => 'name',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'Term description',
            'target' => 'description',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'Parent Term ID',
            'target' => 'parentguid',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'input_format' => 'plain_text',
        'skip_hash_check' => 1,
        'bundle' => 'information_type',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['message_library_term_information_type'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'message_library_term_issues';
  $feeds_importer->config = array(
    'name' => '[Message Library] Term - Issues',
    'description' => 'Import <Issues> terms',
    'fetcher' => array(
      'plugin_key' => 'FeedsHTTPFetcher',
      'config' => array(
        'auto_detect_feeds' => FALSE,
        'use_pubsubhubbub' => FALSE,
        'designated_hub' => '',
        'request_timeout' => NULL,
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
      'plugin_key' => 'FeedsTermProcessor',
      'config' => array(
        'vocabulary' => 'issues',
        'mappings' => array(
          0 => array(
            'source' => 'Term ID',
            'target' => 'guid',
            'unique' => 1,
          ),
          1 => array(
            'source' => 'Term Name',
            'target' => 'name',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'Term description',
            'target' => 'description',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'Parent Term ID',
            'target' => 'parentguid',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'input_format' => 'plain_text',
        'skip_hash_check' => 1,
        'bundle' => 'issues',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['message_library_term_issues'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'message_library_term_sector';
  $feeds_importer->config = array(
    'name' => '[Message Library] Term - Sector',
    'description' => 'Import <Sector> terms',
    'fetcher' => array(
      'plugin_key' => 'FeedsHTTPFetcher',
      'config' => array(
        'auto_detect_feeds' => FALSE,
        'use_pubsubhubbub' => FALSE,
        'designated_hub' => '',
        'request_timeout' => NULL,
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
      'plugin_key' => 'FeedsTermProcessor',
      'config' => array(
        'vocabulary' => 'sector',
        'mappings' => array(
          0 => array(
            'source' => 'Term ID',
            'target' => 'guid',
            'unique' => 1,
          ),
          1 => array(
            'source' => 'Term Name',
            'target' => 'name',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'Term description',
            'target' => 'description',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'Parent Term ID',
            'target' => 'parentguid',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'input_format' => 'plain_text',
        'skip_hash_check' => 1,
        'bundle' => 'sector',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['message_library_term_sector'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'message_library_term_target_audience';
  $feeds_importer->config = array(
    'name' => '[Message Library] Term - Target Audience',
    'description' => 'Import <Target Audience> terms',
    'fetcher' => array(
      'plugin_key' => 'FeedsHTTPFetcher',
      'config' => array(
        'auto_detect_feeds' => FALSE,
        'use_pubsubhubbub' => FALSE,
        'designated_hub' => '',
        'request_timeout' => NULL,
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
      'plugin_key' => 'FeedsTermProcessor',
      'config' => array(
        'vocabulary' => 'target_audience',
        'mappings' => array(
          0 => array(
            'source' => 'Term ID',
            'target' => 'guid',
            'unique' => 1,
          ),
          1 => array(
            'source' => 'Term Name',
            'target' => 'name',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'Term description',
            'target' => 'description',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'Weight',
            'target' => 'weight',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'Parent Term ID',
            'target' => 'parentguid',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'input_format' => 'plain_text',
        'skip_hash_check' => 1,
        'bundle' => 'target_audience',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['message_library_term_target_audience'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'message_library_term_threat';
  $feeds_importer->config = array(
    'name' => '[Message Library] Term - Threat',
    'description' => 'Import <Threat> terms',
    'fetcher' => array(
      'plugin_key' => 'FeedsHTTPFetcher',
      'config' => array(
        'auto_detect_feeds' => FALSE,
        'use_pubsubhubbub' => FALSE,
        'designated_hub' => '',
        'request_timeout' => NULL,
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
      'plugin_key' => 'FeedsTermProcessor',
      'config' => array(
        'vocabulary' => 'threat',
        'mappings' => array(
          0 => array(
            'source' => 'Threat Nid',
            'target' => 'guid',
            'unique' => 1,
          ),
          1 => array(
            'source' => 'Title',
            'target' => 'name',
            'unique' => 1,
          ),
          2 => array(
            'source' => 'Threat Hazard',
            'target' => 'field_threat_hazard',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'Threat Issue',
            'target' => 'field_threat_category',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'Threat Sector',
            'target' => 'field_threat_sector',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'input_format' => 'plain_text',
        'skip_hash_check' => 1,
        'bundle' => 'threat',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['message_library_term_threat'] = $feeds_importer;

  return $export;
}
