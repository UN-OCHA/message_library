<?php
/**
 * @file
 * message_library.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function message_library_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "facetapi" && $api == "facetapi_defaults") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function message_library_views_api() {
  return array("version" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function message_library_node_info() {
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

/**
 * Implements hook_default_search_api_index().
 */
function message_library_default_search_api_index() {
  $items = array();
  $items['node_search'] = entity_import('search_api_index', '{
    "name" : "Message Library Index",
    "machine_name" : "node_search",
    "description" : null,
    "server" : "solr_server",
    "item_type" : "node",
    "options" : {
      "index_directly" : 0,
      "cron_limit" : "50",
      "fields" : {
        "field_arg_comment" : { "type" : "text" },
        "field_at_risk_group" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_info_type" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_message" : { "type" : "text" },
        "field_sensitivity" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "field_sensitivity_cause" : { "type" : "text" },
        "field_ta_comment" : { "type" : "text" },
        "field_target_audience" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_threat" : { "type" : "integer", "entity_type" : "node" },
        "field_hazard" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_issue" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_reference_msg" : { "type" : "integer", "entity_type" : "node" },
        "field_sector" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "search_api_language" : { "type" : "string" }
      },
      "data_alter_callbacks" : {
        "search_api_alter_bundle_filter" : {
          "status" : 1,
          "weight" : "-10",
          "settings" : { "default" : "0", "bundles" : { "message" : "message" } }
        },
        "search_api_alter_node_access" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_hierarchy" : { "status" : 0, "weight" : "0", "settings" : { "fields" : [] } },
        "search_api_alter_add_aggregation" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_url" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_viewed_entity" : { "status" : 0, "weight" : "0", "settings" : { "mode" : "full" } }
      },
      "processors" : {
        "search_api_case_ignore" : {
          "status" : 0,
          "weight" : "0",
          "settings" : { "fields" : {
              "field_arg_comment" : true,
              "field_message" : true,
              "field_sensitivity_cause" : true,
              "field_ta_comment" : true
            }
          }
        },
        "search_api_html_filter" : {
          "status" : 0,
          "weight" : "10",
          "settings" : {
            "fields" : {
              "field_arg_comment" : true,
              "field_message" : true,
              "field_sensitivity_cause" : true,
              "field_ta_comment" : true
            },
            "title" : 0,
            "alt" : 1,
            "tags" : "h1 = 5\\r\\nh2 = 3\\r\\nh3 = 2\\r\\nstrong = 2\\r\\nb = 2\\r\\nem = 1.5\\r\\nu = 1.5"
          }
        },
        "search_api_tokenizer" : {
          "status" : 0,
          "weight" : "20",
          "settings" : {
            "fields" : {
              "field_arg_comment" : true,
              "field_message" : true,
              "field_sensitivity_cause" : true,
              "field_ta_comment" : true
            },
            "spaces" : "[^[:alnum:]]",
            "ignorable" : "[\\u0027]"
          }
        },
        "search_api_stopwords" : {
          "status" : 0,
          "weight" : "30",
          "settings" : {
            "fields" : {
              "field_arg_comment" : true,
              "field_message" : true,
              "field_sensitivity_cause" : true,
              "field_ta_comment" : true
            },
            "file" : "",
            "stopwords" : "but\\r\\ndid\\r\\nthe this that those\\r\\netc"
          }
        }
      }
    },
    "enabled" : "1",
    "read_only" : "0",
    "rdf_mapping" : []
  }');
  return $items;
}
