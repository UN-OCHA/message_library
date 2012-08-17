<?php
/**
 * @file
 * infoasaid_country.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function infoasaid_country_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass;
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'country_importer';
  $feeds_importer->config = array(
    'name' => 'Country Importer',
    'description' => 'Importer for vocabulary Country',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv tsv xml opml',
        'direct' => FALSE,
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
        'vocabulary' => 'country',
        'mappings' => array(
          0 => array(
            'source' => 'name',
            'target' => 'name',
            'unique' => 0,
          ),
          1 => array(
            'source' => 'flag',
            'target' => 'field_country_flag',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'lat',
            'target' => 'field_location:lat',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'lon',
            'target' => 'field_location:lon',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'iso3',
            'target' => 'field_iso3',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'iso3',
            'target' => 'guid',
            'unique' => 1,
          ),
        ),
        'update_existing' => '0',
        'input_format' => 'plain_text',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['country_importer'] = $feeds_importer;

  return $export;
}
