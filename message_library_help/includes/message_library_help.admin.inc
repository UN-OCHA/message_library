<?php

/**
 * Get a list of the fields for message library messages
 */
function message_library_help_get_fields() {
  $fields['message_library'] = array(
    'label' => t('Message Library'),
    'fields' => array(
      'ml_view_view' => t('ML Search Intro'),
      'ml_view_bundle' => t('ML Hazard Bundle'),
      'ml_view_quick_search' => t('ML Quick Search'),
      'ml_view_counter' => t('ML Counter'),
    )
  );
  $fields['threat'] = array(
    'label' => t('Threat'),
    'fields' => array(
      'threat_nav' => t('Threat\'s navigation'),
      'threat_threat' => t('Threat\'s information'),
    )
  );
  return $fields;
}

/**
 * Form for managing help messages.
 */
function message_library_help_admin_page_form($form, &$form_state) {
  $help_fields = message_library_help_get_fields();

  $form['types'] = array(
    '#type' => 'vertical_tabs',
  );

  // Create fieldset
  foreach ($help_fields as $fieldset => $fields) {
    $form[$fieldset] = array(
      '#type' => 'fieldset',
      '#title' => $fields['label'],
      '#collapsible' => TRUE,
      '#collapsed' => FALSE,
      '#group' => 'types',
    );

    // Add a field under the fieldset
    foreach ($fields['fields'] as $field => $label) {
      // This field name is the same as the variable to be set.
      $field_name = 'message_library_help_' . $field;
      $form[$fieldset][$field_name] = array(
        '#type' => 'textarea',
        '#title' => $label,
        '#default_value' => variable_get($field_name, ''),
        '#group' => 'types',
      );
    }
  };

  return system_settings_form($form);
}
