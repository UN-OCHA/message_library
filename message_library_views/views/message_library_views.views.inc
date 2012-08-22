<?php

/**
 * @file
 * ...
 */

/**
 * Implements hook_views_data()
 */
function message_library_views_views_data() {
  $data['message_library']['table']['group'] = t('Message Library');
  $data['message_library']['table']['join'] = array(
    // #global is a special flag which let's a table appear all the time.
    '#global' => array(),
  );

  $data['message_library']['hidden_result'] = array(
    'title' => t('Hidden search results'),
    'help' => t('Some hidden text came from the views footer of the old site.'),
    'area' => array(
      'handler' => 'message_library_views_handler_area_hidden_result',
    ),
  );

  return $data;
}
