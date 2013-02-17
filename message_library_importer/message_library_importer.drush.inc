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
  $items['message-library-wipe-content'] = array(
    'description' => 'Wipe all the content created by the importers of Message Library.',
    'bootstrap' => DRUSH_BOOTSTRAP_DRUSH,
  );
  return $items;
}

/**
 * Drush command callback
 */
function drush_message_library_importer_message_library_import() {
  $items = array(
    // These 3 vocabularies are required by `threat` terms
    // @see: admin/structure/taxonomy/threat/fields
    'message_library_term_hazard' => array('vacab_type' => 'hazard','feed_url_suffix' => 'hazard'),
    'message_library_term_issues' => array('vacab_type' => 'issues','feed_url_suffix' => 'issues'),
    'message_library_term_sector' =>  array('vacab_type' => 'sector','feed_url_suffix' => 'sector'),

    // Import threat (after the above 3 vocabularies imported)
    'message_library_term_threat' =>  array('vacab_type' => 'threat','feed_url_suffix' => 'threat'),
    'message_library_term_information_type' =>  array('vacab_type' => 'information_type','feed_url_suffix' => 'information-type'),
    'message_library_term_at_risk_group' => array('vacab_type' => 'at_risk_groups','feed_url_suffix' => 'at-risk-group'),
    'message_library_term_target_audience' =>  array('vacab_type' => 'target_audience','feed_url_suffix' => 'target-audience'),

    // Import message (after the above 4 vocabularies imported)
    // @see: admin/structure/types/manage/message/fields
    'message_library_node_message' =>  array('content_type' => 'message','feed_url_suffix' => 'message'),
  );

  // The base url of the feeds url on the D6 master instance
  $feeds_url = 'http://infoasaid.org/message-library-export/';
  foreach ($items as $feed_name => $item) {
    drush_print(drush_html_to_text('<br/><hr>'));
    if (!empty($item['content_type'])) {
      $type_name = node_type_get_name($item['content_type']);
      drush_print(dt("Importing [!type_name] nodes <importer: !feed_name> ...", array('!feed_name' => $feed_name, '!type_name' => $type_name)));
    }
    elseif (!empty($item['vacab_type'])) {
      $vocab = taxonomy_vocabulary_machine_name_load($item['vacab_type']);
      $type_name = !(empty($vocab)) ? $vocab->name : $item['vacab_type'];
      drush_print(dt("Importing [!type_name] terms <importer: !feed_name> ...", array('!feed_name' => $feed_name, '!type_name' => $type_name,)));
    }
    drush_print(drush_html_to_text('<hr>'));

    drush_invoke_process('@self', 'feeds-import',
      array('feed-name' => $feed_name),
      array('http' => $feeds_url . $item['feed_url_suffix']));
  }

  // @TODO: There are some empty terms created, just a quick fix for now, remove
  // those empty terms.
  _message_library_importer_remove_empty_terms_and_content();
}

/**
 * Remove the empty tersm and content
 */
function _message_library_importer_remove_empty_terms_and_content() {
  // The vocabulary to check
  $vocabs = array(
    'hazard',
    'issues',
    'sector',
    'information_type',
    'at_risk_groups',
    'target_audience',
    'threat'
  );

  // The content types to check
  $cts = array(
    'message',
  );

  foreach($vocabs as $vocab_name) {
    $vocab_obj = taxonomy_vocabulary_machine_name_load($vocab_name);
    if (empty($vocab_obj)) {
      continue;
    }

    $terms = taxonomy_get_tree($vocab_obj->vid, 0, NULL, TRUE);
    foreach ($terms as $term) {
      if (empty($term->name)) {
        // Check if there are some node referencing it
        $nodes = taxonomy_select_nodes($term->tid);
        // drush_print_r($nodes);
        if (empty($nodes)) {
          drush_log(dt('Found an empty term [tid: @tid] which has no nodes referencing it. Deleting...', array('@tid' => $term->tid)), 'warning');
          $rs = taxonomy_term_delete($term->tid);
          if ($rs == SAVED_DELETED) {
            drush_log(dt('Term [tid: @tid] has been removed successfully.', array('@tid' => $term->tid)), 'success');
          }
          else {
            drush_log(dt('Term [tid: @tid] hasn\'t been removed successfully.', array('@tid' => $term->tid)), 'error');
          }
        }
        else {
          drush_log(dt('Found an empty term [tid: @tid] which has some nodes referencing it.', array('@tid' => $term->tid)), 'warning');
        }
      }
    }

  }
}

/**
 * Drush command callback
 *
 * This command need the devel_generate module be enabled.
 */
function drush_message_library_importer_message_library_wipe_content() {
  // Clear all the content of type: Message
  $content_types = array('message');

  foreach ($content_types as $type) {
    drush_print(drush_html_to_text('<br/><hr><br/>Deleting node in content type: Message ...<br/><hr>'));
    drush_invoke_process('@self', 'generate-content',
      array('number_nodes' => 0),
      array('kill' => TRUE, 'types' => $type)
    );
  }

  // Clear all the terms of vocabulary:
  // - 'At Risk Group'
  // - 'Target Audience'
  // - 'Information Type'
  // - ’Hazard'
  // - 'Issues'
  // - 'Sector'
  // - 'Threat'
  $vocabularies = array(
    'at_risk_groups',
    'hazard',
    'information_type',
    'issues',
    'sector',
    'target_audience',
    'threat',
  );

  foreach ($vocabularies as $vocab) {
    $vocab_obj = taxonomy_vocabulary_machine_name_load($vocab);
    $vocab_name = !empty($vocab_obj) ? $vocab_obj->name :  'Unknown vocabulary';
    drush_print(drush_html_to_text('<br/><hr><br/>' . dt('Deleting terms in vocabulary: !vocab_name ...', array('!vocab_name' => $vocab_name)) . '<br/><hr>'));
    drush_invoke_process('@self', 'generate-terms',
      array('machine_name' => $vocab, 'number_terms' => 0),
      array('kill' => TRUE));
  }
}
