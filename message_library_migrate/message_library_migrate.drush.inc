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
function message_library_migrate_drush_command() {
  $items = array();

  // The 'prepopulate-ml-terms' command
  $items['prepopulate-ml-terms'] = array(
    'description' => "Generate all the terms needed by the 'Message Library'.",
    'bootstrap' => DRUSH_BOOTSTRAP_DRUSH,
  );

  return $items;
}

/**
 * Implements drush_hook_COMMANDNAME()
 *
 * The specific drush command callback
 */
function drush_message_library_migrate_prepopulate_ml_terms() {
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

  $dir = drupal_get_path('module', 'message_library_migrate') . '/csv/terms';

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
    $vocab_term_ids = message_library_migrate_get_terms($vocab_vid);
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
 * Get all the term ids in a specific vocabulary
 * Adapted from `devel_generate_get_terms()`
 */
function message_library_migrate_get_terms($vid) {
  return db_select('taxonomy_term_data', 'td')
    ->fields('td', array('tid'))
    ->condition('vid', $vid, '=')
    ->orderBy('tid', 'ASC')
    ->execute()
    ->fetchCol('tid');
}
