<?php

/**
 * @file
 *
 * @see: [Drush integration for Feeds](http://drupal.org/node/608408)
 */

/**
 * Implements of hook_drush_command().
 */
function message_library_importer_drush_command() {
  $items = array();

  $items['message-library-import'] = array(
    'description' => 'Sync Message Library from remote csv feeds.',
    'bootstrap' => DRUSH_BOOTSTRAP_DRUSH,
  );
  return $items;
}

/**
 * Drush command callback
 */
function drush_message_library_importer_message_library_import() {
  $items = array(
    'message_library_term_hazard' => 'hazard',
    'message_library_term_issues' => 'issues',
    'message_library_term_sector' => 'sector',
    'message_library_node_message' => 'message',

    'message_library_term_information_type' => 'information-type',
    'message_library_term_at_risk_group' => 'at-risk-group',
    'message_library_term_target_audience' => 'target-audience',
    'message_library_term_threat' => 'threat',
  );

  foreach ($items as $feed_name => $filename) {
    $feed_source = feeds_source($feed_name);

    if (!$feed_source instanceof FeedsSource) {
      drush_log(dt('Can\'t load feeds importer for !feed_name', array('!feed_name' => $feed_name)), 'error');
      continue;
    }
    $config = $feed_source->getConfig();
    $feeds_url = 'http://infoasaid.org/message-library-export/';
    $config['FeedsHTTPFetcher']['source'] = $feeds_url . $filename;
    $feed_source->setConfig($config);
    $feed_source->save();

    // Set the batch operations.
    $batch = array(
      'title' => dt('Importing !feed_name', array('!feed_name' => $feed_name)),
      'operations' => array(
        array('feeds_batch', array('import', $feed_name, 0)),
      ),
    );
    batch_set($batch);
  }

  drush_backend_batch_process();
}
