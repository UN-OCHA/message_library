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

  // Prepare some data to be used for the submit handler
  global $user;

  $form['name'] = array(
    '#type' => 'textfield',
    '#maxlength' => 50,
    '#required' => TRUE,
    '#attributes' => array(
      'placeholder' => t('Enter a name for this search'),
    ),
  );

  $form['save'] = array(
    '#type' => 'submit',
    '#value' => t('Save Search'),
  );
  return $form;
}


/**d
 * Handle validation, for #message_library_subscription_save_search_simple_form
 */
function message_library_subscription_save_search_simple_form_validate($form, &$form_state) {
  // Nothing to put here yet.
}


/**
 * Handle submission, for #message_library_subscription_save_search_simple_form
 */
function message_library_subscription_save_search_simple_form_submit($form, &$form_state) {
  $values = $form_state['values'];

  $setting_index_id = $setting->index_id;
  $setting_options  = $setting->options;

  // This represents the IDs selected in 'Search IDs' of section 'Miscellaneous'
  // combined with the option selected in 'Display for searches'('default_true')
  // it decides which searches are enabled.
  $ids_list = drupal_map_assoc($setting_options['ids_list']);


  // The structure of the $search_ids, it's the same as $id_list:
  // array('message_library_index' => array(
  //   'search_api_views:message_library:search_page' => 'search_api_views:message_library:search_page',
  //   'search_api_views:message_library:search_page-1' => 'search_api_views:message_library:search_page-1',
  //   'message_library_views' => 'message_library_views'
  // ));
  $search_ids = variable_get('search_api_saved_searches_search_ids', array());

  foreach ($searches as $id => $data) {
    if ($data[0]->getIndex()->machine_name !== $setting_index_id) continue;

    // Check non-captured id under the current search index?
    if (!isset($search_ids[$setting_index_id][$id])) {
      $search_ids[$setting_index_id][] = array($id => $id);
      $search_ids_updated = TRUE;
    }

    // The 'default_true' is for the configuration 'Display for searches'
    // Check whether the current index is enabled for the 'Save Search' feature
    // ignore it if not enabled
    if ($setting_options['default_true'] == TRUE) {
      // TRUE = Only for the selected
      if (!in_array($id, $ids_list)) continue;
    }
    else {
      // FALSE = For all except the selected IDs
      if (in_array($id, $ids_list)) continue;
    }

    if (!isset($query)) {
      list($query, $results) = $data;
    }
    else {
      watchdog(
        'search_api_saved_searches',
        'Two matching searches on index %index for saved search block.',
        array('%index' => $setting->index()->name),
        WATCHDOG_WARNING,
        l(t('view page'), $_GET['q'], array('query' => drupal_get_query_parameters()))
      );
    }
  }

  if (!empty($search_ids_updated)) {
    variable_set('search_api_saved_searches_search_ids', $search_ids);
  }

  // type: SearchApiQuery
  if (empty($query)) {
    return;
  }

  $query = array(
    'keys' => isset($fields['search_api_saved_searches_fulltext']) ? $fields['search_api_saved_searches_fulltext'] : NULL,
    'fields' => NULL,
    'filters' => array(),
    'options' => array(
      'search id' => $settings->delta . ':' . 'saved-search',
    ),
  );
  unset($fields['search_api_saved_searches_fulltext']);

  global $user;

  $search = entity_create('search_api_saved_search', array(
    // The users.uid that created this saved search.
    'uid' => $user->uid,
    // The search_api_saved_searches_settings.delta this saved search uses.
    'settings_id' => $setting->delta,
    'enabled' => (!empty($user->mail) && $user->mail == $values['mail']) || user_access('administer search_api_saved_searches'),
    // The displayed name for this saved search.
    'name' => $values['name'],
    'mail' => $values['mail'],
    'created' => REQUEST_TIME,
    'last_execute' => REQUEST_TIME,
    // The interval in which this saved search will be checked for new results, in seconds.
    'notify_interval' => 90000000,
    // The actual search query to be executed.
    'query' => $query,
    // Additional options for this saved search.
    'options' => array(),
  ));

  dpm($query);
}



/** Ajax callbacks
 * ---------------------------------------------------------------------------*/
