<?php

/**
 * This form provides an interface to save the current search with a specified
 * human readable name
 */
function message_library_subscription_save_search_simple_form(
  $form,
  &$form_state,
  SearchApiSavedSearchesSettings $settings,
  SearchApiQueryInterface $query = NULL) {

  global $user;
  if (!isset($form_state['query']) && isset($query)) {
    $options = $query->getOptions();
    unset($options['offset'], $options['limit']);

    $options['search id'] = $settings->delta . ':' . 'saved-search';
    $form_state['query'] = array(
      'index_id'      => $query->getIndex()->machine_name,
      'keys'          => $query->getKeys(),
      'original_keys' => $query->getOriginalKeys(),
      'fields'        => $query->getFields(),
      'filters'       => $query->getFilter()->getFilters(),
      'options'       => $options,
    );
  }
  $form_state['settings'] = $settings;

  $form['title'] = array(
    '#type' => 'item',
    '#title' => t('Save new search'),
  );

  $form['name'] = array(
    '#type' => 'textfield',
    '#maxlength' => 50,
    '#required' => TRUE,
    '#description' => t('Enter the name that will be displayed for this saved search.'),
    '#attributes' => array(
      //'placeholder' => t('Enter the name for this search'),
    ),
  );

  // Let the user decides to subscribe to this saved search
  $form['subscription_enabled'] = array(
    '#type' => 'checkbox',
    '#title' => t('Also subscribe to this search.'),
  );

  $form['subscription'] = array(
    '#type' => 'fieldset',
    '#title' => t('Subscription options'),
    '#collapsible' => TRUE,
    // Only display the subscription options when the user wants to subscribe
    '#states' => array(
      'visible' => array(
        ':input[name="subscription_enabled"]' => array('checked' => TRUE),
      ),
    ),
  );

  // The email used to receieve update of this saved search
  if (empty($user->mail) || $settings->options['registered_choose_mail']) {
    $form['subscription']['mail'] = array(
      '#type' => 'textfield',
      '#title' => t('E-mail address'),
      '#maxlength' => 100,
      '#size' => 16,
      '#default_value' => isset($user->mail) ? $user->mail : '',
      '#description' => t('Use another email address to receieve notification.'),
    );
  }
  else {
    $form['subscription']['mail'] = array(
      '#type' => 'value',
      '#value' => $user->mail,
    );
  }

  // The interval
  if ($settings->options['user_select_interval'] &&
      !empty($settings->options['interval_options'])) {
    $form['subscription']['notify_interval'] = array(
      '#type' => 'select',
      '#title' => t('Notification interval'),
      '#options' => $settings->options['interval_options'],
    );
  }
  else {
    $form['subscription']['notify_interval'] = array(
      '#type' => 'value',
      '#value' => $settings->options['user_select_interval'] ?
        reset($settings->options['interval_options']) :
        $settings->options['set_interval'],
    );
  }

  $form['save'] = array(
    '#type' => 'submit',
    '#value' => t('Save Search'),
  );

  if (!empty($form_state['query'])) {
    $form_state['page'] = array(
      'path' => $_GET['q'],
      'query' => drupal_get_query_parameters(),
    );
  }

  return $form;
}


/**d
 * Handle validation, for #message_library_subscription_save_search_simple_form
 */
function message_library_subscription_save_search_simple_form_validate($form, &$form_state) {
  $values = $form_state['values'];

  // Ensure that a valid email is provided if the user want to subscribe
  if (!empty($values['subscription_enabled'])) {
    if (empty($values['mail'])) {
      form_set_error('mail', t('The email can\'t be empty.'));
    }

    if ($msg = user_validate_mail($values['mail'])) {
      form_set_error('mail', $msg);
    }
  }
}


/**
 * Handle submission, for #message_library_subscription_save_search_simple_form
 */
function message_library_subscription_save_search_simple_form_submit($form, &$form_state) {
  global $user;

  $values   = $form_state['values'];
  $settings = $form_state['settings'];

  $query = array_intersect_key($form_state['query'],
    drupal_map_assoc(array('keys', 'fields', 'filters', 'options'))
  );


  // If the user don't want to subscribe, then set the interval as -1, which
  // stands for never notify.
  $interval = !empty($values['subscription_enabled']) ?
      $values['subscription_enabled'] : -1;

  $search = entity_create('search_api_saved_search', array(
    // The users that created this saved search
    'uid' => $user->uid,
    // The search index this saved search uses
    'settings_id' => $settings->delta,
    'enabled' => (!empty($user->mail) && $user->mail == $values['mail']) || user_access('administer search_api_saved_searches'),
    // The displayed name for this saved search
    'name' => $values['name'],
    'mail' => $values['mail'],
    'created' => REQUEST_TIME,
    'last_execute' => REQUEST_TIME,
    // The interval in which this saved search will be checked for new results, in seconds.
    'notify_interval' => $interval,
    // The actual search query to be executed.
    'query' => $query,
    // Additional options for this saved search.
    'options' => array(),
  ));

  if (!empty($form_state['page'])) {
    $search->options['page'] = $form_state['page'];
    $form_state['redirect'] = array($form_state['page']['path'], $form_state['page']);
  }
  elseif ($user->uid) {
    $form_state['redirect'] = 'user/' . $user->uid . '/saved-searches';
  }
  if (!$search->enabled && $user->uid) {
    if (search_api_saved_search_load_multiple(FALSE, array('enabled' => TRUE, 'uid' => $user->uid, 'mail' => $search->mail))) {
      $search->enabled = TRUE;
    }
  }

  $ret = $search->save();

  if (!$ret) {
    drupal_set_message(t('An error occurred while trying to save the search. Please contact the site administrator.'), 'error');
    $form_state['rebuild'] = TRUE;
    return FALSE;
  }
  else {
    if ($search->enabled) {
      drupal_set_message(t('Your saved search was successfully created. You will receive e-mail notifications for new results in the future.'));
    }
    else {
      drupal_set_message(t('Your saved search was successfully created. You will soon receive an e-mail with a confirmation link to activate it.'));
    }
    return TRUE;
  }
}


/** Ajax callbacks
 * ---------------------------------------------------------------------------*/
