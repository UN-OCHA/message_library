<?php

/**
 * @file
 * Contains the administrative functions of the message_library_prev_next_views
 * module.
 *
 */

/**
 * Menu callback for the message_library_prev_next_views module settings form.
 */
function message_library_prev_next_views_settings() {
  $views = views_get_all_views();
  $options = !empty($views) ? drupal_map_assoc(array_keys($views)) : array();

  $form['message_library_prev_next_views_enabled'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Enable the Prev/Next API for the following views'),
    '#default_value' => variable_get('message_library_prev_next_views_enabled', array()),
    '#options' => $options,
  );

  return system_settings_form($form);
}
