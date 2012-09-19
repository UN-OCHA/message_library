<?php


/**
 * Message Library TOU form
 */
function message_library_tou_cgi_form($form, &$form_state) {
  $form['tou_text'] = array();

  $params = drupal_get_query_parameters();
  $form['cgi_destination'] = array(
    '#type' => 'hidden',
    '#value' => !empty($params['cgi-destination']) ? $params['cgi-destination'] : '',
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

  $form['#submit'] = array('message_library_tou_cgi_form_submit');

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

  // For guest user who decide to login/register
  if (!user_is_logged_in() && !empty($values['cgi_login'])) {
    //$form_state['redirect'] = 'user/login';
    $form_state['redirect'] = array('user/login',
        array('query' => array(
          'destination' => $values['cgi_destination'])
        ));
    // @todo: Display a login form in a modal window
    return;
  }

  // For the guests who don't want to register, store in the session
  // For the authenticated user, store in the database, this TOU will only be
  // displayed this time
  message_library_tou_save_cgi_access();

  $form_state['redirect'] = $values['cgi_destination'];
}
