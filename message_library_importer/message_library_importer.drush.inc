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
    'drupal dependencies' => array('feeds'),
    'drush dependencies' => array('feeds'),
  );
  $items['message-library-wipe-content'] = array(
    'description' => 'Wipe all the content created by the importers of Message Library.',
    'bootstrap' => DRUSH_BOOTSTRAP_DRUSH,
    'drupal dependencies' => array('devel_generate'),
  );
  return $items;
}

/**
 * Drush command callback
 */
function drush_message_library_importer_message_library_import() {
  drush_print(drush_html_to_text('<br/><h1>Message Library Import</h1>'));

  $items = array(
    // These 3 vocabularies are required by `threat` terms
    // @see: admin/structure/taxonomy/threat/fields
    'message_library_term_hazard',
    'message_library_term_issues',
    'message_library_term_sector',

    // Import threat (after the above 3 vocabularies imported)
    'message_library_term_threat',
    'message_library_term_information_type',
    'message_library_term_at_risk_group',
    'message_library_term_target_audience',

    // Import message (after the above 4 vocabularies imported)
    // @see: admin/structure/types/manage/message/fields
    'message_library_node_message',
  );

  // Ensure every importer has a valid path set for the HTTP fetcher.
  $import_paths = variable_get('ml_importer_import_paths', array());
  foreach ($items as $id) {
    if (empty($import_paths[$id])) {
      return drush_set_error('ML_FEEDS_MISSING_IMPORT_PATH', dt('No import path specified for feeds importer !id. Please check the settings at !url', array('!id' => $id, '!url' => url('admin/config/message_library/importer'))));
    }
  }

  $i = 1;
  foreach ($items as $feed_name => $id) {
    $importer = feeds_importer($id);
    if (empty($importer->id)) {
      return drush_set_error(dt('Unrecognized feeds importer: !importer', array('!importer' => $id)), 'error');
    }

    drush_print(drush_html_to_text('<br/><hr>'));

    if (empty($importer->processor) || !is_a($importer->processor, 'FeedsProcessor')) {
      return drush_set_error('ML_FEEDS_INVALID_PROCESSOR', dt('No valid processor found.'));
    }

    if (is_a($importer->processor, 'FeedsTermProcessor')) {
      if (!empty($importer->processor->config['vocabulary'])) {
        drush_log(dt("$i. Importing [!type] terms...", array('!type' => $importer->processor->config['vocabulary'])), 'ok');
      }
      else {
        return drush_set_error('ML_FEEDS_NO_VOCABULARY_SET', dt('No vocabulary target.'));
      }
    }
    else if (is_a($importer->processor, 'FeedsNodeProcessor')) {
      if (!empty($importer->processor->config['bundle'])) {
        drush_log(dt("$i. Importing [!type] nodes...", array('!type' => $importer->processor->config['bundle'])), 'ok');
      }
      else {
        return drush_set_error('ML_FEEDS_NO_CONTENT_TYPE_SET', dt('No content type target.'));
      }
    }
    else {
      return drush_set_error('ML_FEEDS_INCORRECT_PROCESSOR', dt('Uncognized feeds processor.'));
    }
    drush_print(drush_html_to_text('<hr>'));

    drush_invoke_process('@self','feeds-import',
      array('feed-name' => $id),
      array('http' => $import_paths[$id])
    );
    $i++;
  }

  // @TODO: There are some empty terms created, just a quick fix for now, remove
  // those empty terms.
  // _message_library_importer_remove_empty_terms_and_content();

  // Fix the fields of threat terms
  // _message_library_importer_fix_threat_term_fields();

  // Reindex
  drush_print(drush_html_to_text('<br/><hr>'));
  drush_log(dt('Reindexing...'), 'ok');
  drush_print(drush_html_to_text('<hr>'));
  drush_invoke('search-api-clear', 'message_library_index');
  drush_invoke('search-api-index', 'message_library_index');

  // Flush cache
  drush_print(drush_html_to_text('<br/><hr>'));
  drush_log(dt('Flushing the caches...'), 'ok');
  drush_print(drush_html_to_text('<hr>'));
  drupal_flush_all_caches();

  drush_print(drush_html_to_text('<br/>'));
  drush_log(dt('Import task complete.'), 'completed');
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
  // - 'Hazard'
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

  // Prevent from some terms from still appearing in the exposed dropdowns
  drupal_flush_all_caches();
}

/**
 * This function will fill the `field_threat_category` field with parent terms
 * for example, when the field has value 'Child Protection', the 'Protection'
 * the parent term, will also be added to the field value
 *
 * Issue links: http://atrium.wiredcraft.com/internews/node/4818
 *              http://drupal.org/node/1100778
 */
function _message_library_importer_fix_threat_term_fields() {
  $vocab = taxonomy_vocabulary_machine_name_load('threat');

  if (!empty($vocab->vid)) {
    $terms = taxonomy_get_tree($vocab->vid, 0, NULL, TRUE);
    if (!empty($terms)) {
      foreach($terms as $term) {
        // Set the missing parent terms value for field 'field_threat_category'
        $wrapper = entity_metadata_wrapper('taxonomy_term', $term);

        // Get the original field value
        $orig_tids = array();
        $parent_tids = array();
        foreach ($wrapper->field_threat_category->getIterator() as $delta => $term_wrapper) {
          $tid = $term_wrapper->tid->value();
          $orig_tids[] = $term_wrapper->tid->value();
          $parent_terms = _message_library_importer_get_parent_terms($term_wrapper->tid->value(), 'issues');
          if (!empty($parent_terms)) {
            foreach ($parent_terms as $parent_term) {
              $parent_tids[] = $parent_term->tid;
            }
          }
        }

        $new_tids = array_unique(array_merge($orig_tids, $parent_tids));
        if (!empty($new_tids)) {
          $new_terms = taxonomy_term_load_multiple($new_tids);
          $wrapper->field_threat_category->set($new_terms);
          $wrapper->save();
        }
      }
    }
  }
}

/**
 * Get all the parent terms of a specified term
 */
function _message_library_importer_get_parent_terms($tid, $vocab_name) {
  $result = array();
  $vocab = taxonomy_vocabulary_machine_name_load($vocab_name);
  if (!empty($vocab->vid)) {
    $p_terms = taxonomy_get_parents($tid);
    if (!empty($p_terms)) {
      foreach ($p_terms as $p_term) {
        if ($p_term->vid != $vocab->vid) {
          continue;
        }
        $result[$p_term->tid] = $p_term;
        $p_p_terms = _message_library_importer_get_parent_terms($p_term->tid, $vocab_name);
        if (!empty($p_p_terms)) {
          $result = array_merge($result, $p_p_terms);
        }
      }
    }
  }
  return $result;
}
