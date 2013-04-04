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

  $form['ml_importer_interval'] = array(
    '#type' => 'select',
    '#title' => 'Interval',
    '#options' => drupal_map_assoc($intervals, 'format_interval'),
    '#default_value' => 3600 * 4,
  );

  $form['ml_importer_base_url'] = array(
    '#type' => 'textfield',
    '#title' => t('Base URL'),
    '#default_value' => 'http://infoasaid.org/message-library-export/',
  );

  return system_settings_form($form);
}
