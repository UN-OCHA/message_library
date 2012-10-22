<?php
/**
 * @file
 *
 * Implementation of file hook.drush.inc, as per the drush command
 * creating process, see `drush topic docs-commands`
 */

/**
 * Implements hook_drush_command()
 *
 * Creating all the terms need by the 'Message Library'
 */
function message_library_drush_command() {
  $items = array();

  // The 'prepopulate-ml-terms' command
  $items['prepopulate-ml-terms'] = array(
    'description' => "Generate all the terms needed by the 'Message Library'.",
    'bootstrap' => DRUSH_BOOTSTRAP_DRUSH,
  );
  $items['prepopulate-ml-threat-terms'] = array(
    'description' => "Generate all the theat terms.",
    'bootstrap' => DRUSH_BOOTSTRAP_DRUSH,
  );
  $items['prepopulate-ml-message-threat'] = array(
    'description' => "Set the threat for each message.",
    'bootstrap' => DRUSH_BOOTSTRAP_DRUSH,
  );
  return $items;
}

/**
 * Implements drush_hook_COMMANDNAME()
 *
 * The specific drush command callback
 */
function drush_message_library_prepopulate_ml_terms() {
  // The following vocabularies need prepopulating:
  // 1. At risk group
  // 2. Hazard
  // 3. Information Type
  // 4. Issues
  // 5. Sector
  // 6. Target audience
  $vocab_list = array(
    'at_risk_groups',
    'hazard',
    'information_type',
    'issues',
    'sector',
    'target_audience'
  );

  $dir = drupal_get_path('module', 'message_library') . '/csv/terms';

  foreach($vocab_list as $vocab) {
    drush_print('--------------------------------------------------------');
    $vocab_obj = taxonomy_vocabulary_machine_name_load($vocab);

    if (!$vocab_obj) {
      continue;
    }

    $vocab_vid = $vocab_obj->vid;
    $vocab_m_name = $vocab_obj->machine_name;

    // Empty all the terms in that vocabulary
    $vocab_term_ids = array();
    $vocab_term_ids = message_library_get_terms($vocab_vid);
    foreach($vocab_term_ids as $tid) {
      taxonomy_term_delete($tid);
    }

    drush_log(dt('Removed @count terms in @vocab_name', array(
        '@count' => count($vocab_term_ids),
        '@vocab_name' => $vocab_obj->name)), 'success');

    // Read the corresponding csv file
    $file_name = $vocab . '.csv';
    $csv_file  = $dir . '/' . $file_name;

    if (!file_exists($csv_file) && is_readable($csv_file)) {
      drush_log('The file [' . $file_name . '] doesn\'t exist.', 'warning');
      continue;
    }
    else {
      drush_log('The file [' . $file_name . '.csv] found.', 'success');
    }

    $row_num = 1;
    // Process each csv file
    if (($handle = fopen($csv_file, 'r')) !== FALSE)  {
      // Process each line of csv file
      while (($data = fgetcsv($handle, 1000, ",")) !== FALSE) {
        if (empty($data)) break;

        // Process each col in a line
        // - First check the first element in the array, check existence in db,
        //   and return the tid, save it for the next element's parent tid
        // - Then check the next element, assign the parent, return the tid,
        //   refresh the tid
        //

        // Temp container for parent tid
        $parent_tid = '';

        for (reset($data); list($key, $term_name) = each($data);) {
          $duplicate_terms = taxonomy_get_term_by_name($term_name, $vocab_m_name);

          if (empty($duplicate_terms)) {
            // Prepare the term object for inserting
            $term_obj = new stdClass();
            $term_obj->vid = $vocab_vid;
            $term_obj->name  = $term_name;
            $term_obj->parent = !empty($parent_tid) ? $parent_tid : 0;

            // Update the parent tid
            if (in_array(taxonomy_term_save($term_obj),array(SAVED_NEW, SAVED_UPDATED))) {
              $parent_tid = $term_obj->tid;
            }
            else {
              $parent_tid = '';
            }
          }
          // The term already exists
          else {
            $duplicate_term = reset($duplicate_terms);

            drush_print(dt('The term \'@term_name\' with tid @tid already exists.', array(
                '@term_name' => $duplicate_term->name,
                '@tid' => $duplicate_term->tid)));

            $parent_tid = $duplicate_term->tid;
          }
        }
      }

      fclose($handle);
    }
  }
}

/**
 * Drush command used for generate threat terms
 */
function drush_message_library_prepopulate_ml_threat_terms() {
  // @todo: remove all the terms in the 'threat' vocabulary

  $info = array(
    'database' => 'infoasaidorg',
    'username' => 'root',
    'password' => 'root',
    'host' => 'localhost',
    'port' => '',
    'driver' => 'mysql',
    'prefix' => array(
      'default' => '',
    ),
  );
  Database::addConnectionInfo('default', 'migration', $info);
  $query = Database::getConnection('migration', 'default')
    ->select('node', 'n')
    ->fields('n', array('nid'))
    ->condition('type', 'threat', '=')
    ->condition('status', '1', '=')
    ->orderBy('changed');

  $query->innerJoin('node_revisions', 'nr', 'n.vid=nr.vid');
  $query->fields('nr', array('title'));

  // Issues
  $query->leftJoin('content_field_threat_category', 'issues', 'n.vid = issues.vid');
  $query->fields('issues', array('field_threat_category_value'));

  // Hazard
  $query->leftJoin('content_field_threat_hazard', 'hazard', 'n.vid = hazard.vid');
  $query->fields('hazard', array('field_threat_hazard_value'));

  // Messages
  $query->leftJoin('content_field_threat_message', 'message', 'n.vid = message.vid');
  $query->fields('message', array('field_threat_message_nid'));

  // Sectors
  $query->leftJoin('content_field_threat_sector', 'sector', 'n.vid = sector.vid');
  $query->fields('sector', array('field_threat_sector_value'));

  $result = $query->execute();
  $rows = array();
  while ($row = $result->fetchAssoc()) {
    $rows[] = $row;
  }

  $nodes = array();
  foreach ($rows as $row) {
    // Node id
    $nodes[$row['nid']]['title'] = $row['title'];

    $field_names = array(
      'field_threat_category_value',
      'field_threat_hazard_value',
      'field_threat_message_nid',
      'field_threat_sector_value'
    );

    foreach ($field_names as $field_name) {
      if (!empty($row[$field_name])) {
        if (empty($nodes[$row['nid']][$field_name])) {
          $nodes[$row['nid']][$field_name] = array();
        }

        if (!in_array($row[$field_name], $nodes[$row['nid']][$field_name])) {
          $nodes[$row['nid']][$field_name][] = $row[$field_name];
        }
      }
    }
  }

  $old_nodes = $nodes;

  // Replace with the migrated tids or nids
  foreach ($nodes as $key => $node) {
    // messages
    if (!empty($nodes[$key]['field_threat_message_nid'])) {
      array_walk($nodes[$key]['field_threat_message_nid'], '_message_library_get_message_map_dest_nid');
    }

    // issues
    if (!empty($nodes[$key]['field_threat_category_value'])) {
      array_walk($nodes[$key]['field_threat_category_value'], '_message_library_get_issue_map_dest_tid');
    }

    // hazard
    if (!empty($nodes[$key]['field_threat_hazard_value'])) {
      array_walk($nodes[$key]['field_threat_hazard_value'], '_message_library_get_hazard_map_dest_tid');
    }

    // sector
    if (!empty($nodes[$key]['field_threat_sector_value'])) {
      array_walk($nodes[$key]['field_threat_sector_value'], '_message_library_get_sector_map_dest_tid');
    }
  }

  // drush_print_r($nodes);
  // drush_print_r(array_diff($old_nodes, $nodes));

  $threat_vocab = taxonomy_vocabulary_machine_name_load('threat');
  $theat_vid = $threat_vocab->vid;

  // Create threat terms
  foreach ($nodes as $key => $node) {
    $term = new stdClass();
    $term->name = $node['title'];
    $term->vid = $theat_vid;

    // Issues
    if (!empty($node['field_threat_category_value'])) {
      foreach($node['field_threat_category_value'] as $value) {
        $term->field_threat_category[LANGUAGE_NONE][]['tid'] = $value;
      }
    }

    // Hazard
    if (!empty($node['field_threat_hazard_value'])) {
      foreach($node['field_threat_hazard_value'] as $value) {
        $term->field_threat_hazard[LANGUAGE_NONE][]['tid'] = $value;
      }
    }

    // Sector
    if (!empty($node['field_threat_sector_value'])) {
      foreach( $node['field_threat_sector_value'] as $value) {
        $term->field_threat_sector[LANGUAGE_NONE][]['tid'] = $value;
      }
    }

    taxonomy_term_save($term); // Finally, save our term
  }
}

/**
 * Get all the term ids in a specific vocabulary
 * Adapted from `devel_generate_get_terms()`
 */
function message_library_get_terms($vid) {
  return db_select('taxonomy_term_data', 'td')
    ->fields('td', array('tid'))
    ->condition('vid', $vid, '=')
    ->orderBy('tid', 'ASC')
    ->execute()
    ->fetchCol('tid');
}

/**
 * Drush command used for setting threat for each message
 */
function drush_message_library_prepopulate_ml_message_threat() {
  $info = array(
    'database' => 'infoasaidorg',
    'username' => 'root',
    'password' => 'root',
    'host' => 'localhost',
    'port' => '',
    'driver' => 'mysql',
    'prefix' => array(
      'default' => '',
    ),
  );
  Database::addConnectionInfo('default', 'migration', $info);

  $d7_threat_vocab = taxonomy_vocabulary_machine_name_load('threat');
  $d7_threat_vocab_vid = $threat_vocab->vid;

  // Get all messages in the D7
  $messages = node_load_multiple(array(), array('type' => 'message'));

  // For each message, get the match message in D6
  foreach ($messages as $message) {
    drush_print("\n\n");
    drush_print(dt('For message [!title]', array('!title' => $message->title)));

    $d6_message_nid = _message_library_get_message_map_source_nid($message->nid);


    // Find no source in D6
    if (empty($d6_message_nid)) {
      drush_log(dt('The d6 message can\'t be found.'), 'warning');
      continue;
    }
    else {
      drush_print(dt('The d6 message match\'s nid is: !nid', array('!nid' => $d6_message_nid)));
    }

    // Get the D6 message's threat()
    $query = Database::getConnection('migration', 'default')
      ->select('node', 'n')
      ->fields('n', array('nid'))
      ->condition('n.type', 'message', '=')
      ->condition('n.nid', $d6_message_nid, '=')
      ->condition('n.status', '1', '=')
      ->orderBy('n.changed');

    $query->innerJoin('node_revisions', 'nr', 'n.vid=nr.vid');
    $query->fields('nr', array('title'));

    $query->leftJoin('content_field_message_threat', 'threat', 'n.vid = threat.vid');
    $query->fields('threat', array('field_message_threat_nid'));

    $result = $query->execute();

    $rows = array();
    while ($row = $result->fetchAssoc()) {
      if (!empty($row['field_message_threat_nid'])) {
        $rows[] = $row;
      }
    }

    if (empty($rows)) continue;

    $d6_threat_nid = reset($rows)['field_message_threat_nid'];
    drush_print(dt('It\'s point to threat nid: !nid', array('!nid' => $d6_threat_nid)));
    // Get its title
    $query = Database::getConnection('migration', 'default')
      ->select('node', 'n')
      ->fields('n', array('title'))
      ->condition('n.type', 'threat')
      ->condition('n.nid', $d6_threat_nid);

    $d6_threat_title = $query->execute()->fetchField();

    // Check which term it is in D7(by title)
    drush_print(dt('Search term in D7 by name: @name', array('@name' => $d6_threat_title)));
    if (!empty($d6_threat_title)) {
      $search_terms = taxonomy_get_term_by_name($d6_threat_title, $d7_threat_vocab_vid);

     drush_log(dt('!count terms found.', array('!count' => count($search_terms))));
     if (!empty($search_terms)) {
       $d7_threat_term = reset($search_terms);
       drush_log(dt('Got the term name in D7.'), 'success');

       $d7_threat_term_tid = $d7_threat_term->tid;

       $message->field_message_threat['und']['0']['tid'] = $d7_threat_term_tid;
       node_save($message);
     }
    }
    else {
      drush_log(dt('Can\'t get threat name in D6 by it nid'), 'error');
    }
  }
  // Assign it to the D7 message
}

/**
 * Help function callbacks
 */
function _message_library_get_message_map_dest_nid(&$nid) {
  $nid =  db_query('SELECT destid1 FROM {migrate_map_nodemessagemigration} WHERE sourceid1 = :nid', array(':nid' => $nid))->fetchField();
}

function _message_library_get_message_map_source_nid($nid) {
  $nid =  db_query('SELECT sourceid1 FROM {migrate_map_nodemessagemigration} WHERE destid1 = :nid', array(':nid' => $nid))->fetchField();
  return $nid;
}

function _message_library_get_issue_map_dest_tid(&$tid) {
  $tid = db_query('SELECT destid1 FROM {migrate_map_termissues} WHERE sourceid1 = :tid', array(':tid' => $tid))->fetchField();
}

function _message_library_get_hazard_map_dest_tid(&$tid) {
  $tid = db_query('SELECT destid1 FROM {migrate_map_termhazard} WHERE sourceid1 = :tid', array(':tid' => $tid))->fetchField();
}

function _message_library_get_sector_map_dest_tid(&$tid) {
  $tid = db_query('SELECT destid1 FROM {migrate_map_termsector} WHERE sourceid1 = :tid', array(':tid' => $tid))->fetchField();
}
