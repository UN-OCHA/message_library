<?php

/**
 * Admin page for the module
 */

/**
 * Generates a config form for the automatic import job
 */
function message_library_importer_admin_form($form, &$form_state) {
  $import_paths_settings = variable_get('ml_importer_import_paths', array());

  $form = array();
  $form['ml_importer_import_paths'] = array(
    '#tree' => TRUE,
    '#type' => 'fieldset',
    '#title' => t('Importer Paths'),
    //'#collapsible' => TRUE,
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
