<?php

/**
 * Implementation of hook_views_data_alter()
 */
function message_library_exposedfilters_views_data_alter(&$data) {
  if (empty($data['search_api_index_message_library_index'])) return;
  $table = &$data['search_api_index_message_library_index'];
  // Override the views filter handler for the issues field.
  if (isset($table['field_message_threat_field_threat_category'])) {
    $table['field_message_threat_field_threat_category']['filter']['handler'] = 'MLHandlerFilterOptionsIssue';
  }

  // Override the views filter handlerfor the threat field.
  if (isset($table['field_message_threat'])) {
    $table['field_message_threat']['filter']['handler'] = 'MLHandlerFilterOptionsThreat';
  }
}
