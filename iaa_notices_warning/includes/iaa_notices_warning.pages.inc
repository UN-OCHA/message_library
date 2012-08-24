<?php

/**
 * @todo Please document this function.
 * @see http://drupal.org/node/1354
 */
function iaa_notices_warning_get_message() {
  $nid = $_POST['nid'];
  iaa_notices_warning_save_warning($nid);
  $node = node_load($nid);
  echo $node->field_message_group_mess[0]['value'];
}

/**
 * @todo Please document this function.
 * @see http://drupal.org/node/1354
 */
function iaa_notices_warning_form_login() {
  $nid = $_POST['nid'];
  echo theme('iaa_notices_warning_form_login', array('nid' => $nid));
}

/**
 * @todo Please document this function.
 * @see http://drupal.org/node/1354
 */
function iaa_notices_warning_login() {
  // TODO : logguer l'utilisateur avec les données en POST
  $nid = $_POST['nid'];
  $name = $_POST['name']; // TODO Set these variables;
  $password = $_POST['pass'];
  $user = user_authenticate($name, $password);
  // puis enregister les données en base
  if ($user->uid) {
    if (!iaa_notices_warning_get_warning($nid)) {
      iaa_notices_warning_save_warning($nid);
    }
    echo drupal_json_output(array('login' => TRUE));
  }
  else {
    echo drupal_json_output(array('login' => FALSE, 'message' => t('Login attempt failed.')));
  }
}

/**
 * @todo Please document this function.
 * @see http://drupal.org/node/1354
 */
function iaa_notices_warning_cgi() {
  $node = node_load(ML_CGI_NID);
  drupal_set_title($node->title);
  return theme('iaa_notices_warning_cgi', array('node' => $node));
}

/**
 * @todo Please document this function.
 * @see http://drupal.org/node/1354
 */
function iaa_notices_warning_cgi_accepted() {
  if (!iaa_notices_warning_get_cgi()) {
    iaa_notices_warning_save_cgi();
  }
  //drupal_goto($_POST['destination']);
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
