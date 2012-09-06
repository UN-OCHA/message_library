<?php
/**
 * @file
 * message_library_subscription.features.inc
 */

/**
 * Implements hook_default_search_api_saved_searches_settings().
 */
function message_library_subscription_default_search_api_saved_searches_settings() {
  $items = array();
  $items['message_library_index'] = entity_import('search_api_saved_searches_settings', '{
    "delta" : "message_library_index",
    "index_id" : "message_library_index",
    "enabled" : "1",
    "options" : {
      "default_true" : "0",
      "ids_list" : { "message_library_views" : "message_library_views" },
      "registered_choose_mail" : 1,
      "user_select_interval" : 1,
      "interval_options" : {
        "3600" : "Every Hour",
        "43200" : "Twice a day",
        "86400" : "Daily",
        "604800" : "Weekly"
      },
      "set_interval" : "86400",
      "mail" : {
        "activate" : {
          "send" : 1,
          "title" : "Activate your saved search at [site:name]",
          "body" : "A saved search on [site:name] with this e-mail address was created.\\r\\nTo activate this saved search, click the following link:\\r\\n\\r\\n[search-api-saved-search:activate-url]\\r\\n\\r\\nIf you didn\\u0027t create this saved search, just ignore this mail and it will be deleted.\\r\\n\\r\\n--  [site:name] team"
        },
        "notify" : {
          "title" : "New results for your saved search at [site:name]",
          "body" : "[user:name],\\r\\n\\r\\nThere are new results for your saved search on [site:name]:\\r\\n\\r\\n[search-api-saved-searches:results]\\r\\n\\r\\nYou can configure your saved searches at the following address:\\r\\n[user:search-api-saved-searches-url]\\r\\n\\r\\n--  [site:name] team",
          "results" : "New results for search \\u0022[search-api-saved-search:name]\\u0022:\\r\\n[search-api-saved-search:items]",
          "result" : "[search-api-saved-search-result:label] ([search-api-saved-search-result:url])"
        }
      },
      "manual" : {
        "allow" : 1,
        "fulltext" : 0,
        "fields" : [
          "field_message_group_risk",
          "field_message_audience",
          "field_message_info_type",
          "field_message_threat"
        ],
        "page" : {
          "path" : "view_search_results",
          "fulltext" : "",
          "direct_filter_params" : "0"
        }
      }
    },
    "rdf_mapping" : []
  }');
  return $items;
}