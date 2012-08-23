<?php

/**
 * @todo Please document this function.
 * @see http://drupal.org/node/1354
 */
function iaa_inline_help_get_fields() {
  $help_fields = array(
    'message_library' => array(
      'label' => t("Message Library"),
      'fields' => array(
        'ml_view_view' => t("ML Search Intro"),
        'ml_view_bundle' => t("ML Hazard Bundle"),
        'ml_view_quick_search' => t("ML Quick Search"),
        'ml_view_counter' => t("ML Counter"),
      ),
    ),
    'threat' => array(
      'label' => t("Threat"),
      'fields' => array(
        'threat_nav' => t("Threat's navigation"),
        'threat_threat' => t("Threat's information"),
      ),
    ),
    /*
 'message' => array(
 'label' => t("Message"),
 'fields' => array(
 'message_intro' => t("Message's introduction"),
 )
 ),*/
  );
  return $help_fields;
}



/**
 *
 * Formulaire d'administration des messages d'aide
 */
function iaa_inline_help_admin_page_form($form, &$form_state) {

  $help_fields = iaa_inline_help_get_fields();

  foreach ($help_fields as $fieldset => $fields) :

    $form[$fieldset] = array(
      '#type' => 'fieldset',
      '#title' => t($fields['label']),
      '#collapsible' => TRUE,
      '#collapsed' => FALSE,
      '#tree' => TRUE,
    );

    foreach ($fields['fields'] as $field => $label) :
      $form[$fieldset][$field] = array(
        '#type' => 'textarea',
        '#title' => t($label),
        '#default_value' => variable_get('iaa_inline_help_' . $field, ""),
        //'#description' => t("One item per line"),
        '#wysiwyg' => false,
      );
    endforeach;

  endforeach;

  $form['#pre_render'][] = 'vertical_tabs_form_pre_render';

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
    '#weight' => 100,
  );

  return $form;
}

/**
 *
 * Sauvegarde des messages d'aide
 * @param unknown_type $form
 * @param unknown_type $form_state
 */
function iaa_inline_help_admin_page_form_submit($form, &$form_state) {
  $help_fields = iaa_inline_help_get_fields();
  foreach ($help_fields as $fieldset => $fields) :
    foreach ($fields['fields'] as $field => $label) :
      if ($form_state['values'][$fieldset][$field] != IAA_INLINE_HELP_EMPTY) {
        variable_set('iaa_inline_help_' . $field, $form_state['values'][$fieldset][$field]);
      }
    endforeach;
  endforeach;
  drupal_set_message(t('The configuration has been saved.'));
}


/**
 * @todo Please document this function.
 * @see http://drupal.org/node/1354
 */
function iaa_inline_help_admin_edit() {
  $message = $_POST['message'];
  $id = $_POST['id'];
  if ($message != IAA_INLINE_HELP_EMPTY) {
    variable_set('iaa_inline_help_' . $id, $message);
  }
}
