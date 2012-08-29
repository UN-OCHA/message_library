<?php

/**
 *
 */
function iaa_notices_warning_cgi() {
  $nid = variable_get('message_library_tou_nid');
  if (!$nid) {
    // Go to 'Message Library', if the TOU can work
    $destination = drupal_get_destination();
    drupal_goto($destination['destination']);
  }

  $node = node_load($nid);
  drupal_set_title($node->title);
  return theme('iaa_notices_warning_cgi', array('node' => $node));
}



/**
 * Callback
 */
function iaa_notices_warning_cgi_accepted() {
  if (!iaa_notices_warning_get_cgi()) {
    iaa_notices_warning_save_cgi();
  }

  $destination = drupal_get_destination();
  drupal_goto($destination['destination']);
}


/**
 * Message Library TOU form
 */
function message_library_tou_cgi_form($form, &$form_state) {
  $form['tou_text'] = array();

  $destination = drupal_get_destination();
  $form['cgi_destination'] = array(
    '#type' => 'hidden',
    '#value' => $destination['destination']
  );

  // The TOU text
  $tou_nid = variable_get('message_library_tou_nid');
  if ($tou_nid && ($node = node_load($tou_nid))) {
    $body_field  = field_get_items('node', $node, 'body');
    $body_renderable = field_view_value('node', $node, 'body', $body_field[0]);

    $form['cgi_tou_text'] = array(
      '#prefix' => '<div class="tou-text">',
      '#markup' => render($body_renderable),
      '#suffix' => '</div>'
    );
  }

  // Termporary acceptance button
  $form['cgi_understand'] = array(
    '#type' => 'checkbox',
    '#id' => 'iaa_notices_warning_cgi_understand',
    '#title' => t('I accept'),
  );

  // Register button, so that never see cgi again
  if (!user_is_logged_in()) {
    $form['cgi_login'] = array(
      '#type' => 'checkbox',
      '#id' => 'iaa_notices_warning_cgi_login',
      '#title' => t('I want to register'),
    );
  }

  // Submit button
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Go'),
    '#id' => 'iaa_notices_warning_cgi_submit'
  );

  return $form;
}


/**
 * Validation handler for form '#message_library_tou_cgi_form'
 */
function message_library_tou_cgi_form_validate($form, &$form_state) {
  $values = $form_state['values'];
  if (empty($values['cgi_understand'])) {
    // The original implementation show this error message using js alert()
    form_set_error('cgi_understand', t('You have to accept the conditions'));
  }
}


/**
 * Submit handler for form '#message_library_tou_cgi_form'
 */
function message_library_tou_cgi_form_submit($form, &$form_state) {
  $values = $form_state['values'];

  // The guest uesr hates the TOU, so he decides to register
  if (!user_is_logged_in() && !empty($values['cgi_login'])) {
    // @todo: Display a login form in a modal window
    return;
  }

  // For the guests who don't want to register, store in the session
  // For the authenticated user, store in the database, this TOU will only be
  // displayed this time
  message_library_tou_save_cgi_access();
  $detination = drupal_get_destination();
  drupal_goto($detination['destination']);
}


/**
 * @todo Please document this function.
 * @see http://drupal.org/node/1354
 */
function iaa_notices_warning_cgi_form_login() {
  echo theme('iaa_notices_warning_cgi_form_login');
}


/**
 * @todo Please document this function.
 * @see http://drupal.org/node/1354
 */
function iaa_notices_warning_cgi_login() {
  // TODO : logguer l'utilisateur avec les données en POST
  $name = $_POST['name']; // TODO Set these variables;
  $password = $_POST['pass'];
  $user = user_authenticate($name, $password);
  // puis enregister les données en base
  if ($user->uid) {
    echo drupal_json_output(array('login' => TRUE));
  }
  else {
    echo drupal_json_output(array('login' => FALSE, 'message' => t('Login attempt failed.')));
  }
}
