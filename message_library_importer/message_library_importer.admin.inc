<?php

/**
 * Admin page for the module
 */

/**
 * Generates a config form for the automatic import job
 */
function message_library_importer_admin_form($form, &$form_state) {
  $form = array();

  // Give some pre-defined intervals
  $intervals = array(
    3600,
    3600 *  2,
    3600 *  4,
    3600 *  6,
    3600 *  8,
    3600 * 12,
    3600 * 16,
    3600 * 24,
    3600 * 24 * 2,
  );

  $interval_options = drupal_map_assoc($intervals, 'format_interval');
  $interval_setting = variable_get('ml_importer_interval', 14400);
  $form['ml_importer_interval'] = array(
    '#type' => 'select',
    '#title' => 'Auto Import Interval',
    '#options' => $interval_options,
    '#default_value' => $interval_setting,
  );

  $import_paths_settings = variable_get('ml_importer_import_paths', array());
  $form['ml_importer_import_paths'] = array(
    '#tree' => TRUE,
    '#type' => 'fieldset',
    '#title' => t('Importer Paths'),
    '#collapsible' => TRUE,
    '#default_value' => 'http://infoasaid.org/message-library-export/',
  );

  $ids = array(
    'message_library_node_message',
    'message_library_term_at_risk_group',
    'message_library_term_hazard',
    'message_library_term_information_type',
    'message_library_term_issues',
    'message_library_term_sector',
    'message_library_term_target_audience',
    'message_library_term_threat',
  );
  foreach ($ids as $id)  {
    $importer = feeds_importer($id);
    if (!empty($importer->id)) {
      $name = $importer->config['name'];
      $form['ml_importer_import_paths'][$importer->id] = array(
        '#type' => 'textfield',
        '#title' => t('For importer - !importer', array('!importer' => l($importer->config['name'], 'admin/structure/feeds/'.$importer->id))),
        '#default_value' => !empty($import_paths_settings[$id]) ? $import_paths_settings[$id] : '',
      );
    }
  }

  return system_settings_form($form);
}
