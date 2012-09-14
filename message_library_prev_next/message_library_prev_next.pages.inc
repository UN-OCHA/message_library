<?php

/**
 * Menu callback argument.
 * Creates the message_library_prev_next administration form.
 */
function message_library_prev_next_admin($form, &$form_state) {
  // Index status overview
  $form['status'] = array(
    '#type' => 'fieldset',
    '#title' => t('Indexing status'),
  );

  $max_nid = variable_get('message_library_prev_next_index_nid', 0);

  $index_nids = _message_library_prev_next_get_index_nids();
  $total = count($index_nids);
  $completed = db_query("SELECT COUNT(nid) FROM {message_library_prev_next_node}")->fetchField();
  $remaining = max(0, ($total - $completed));

  $percentage = ((int) min(100, 100 * ($total - $remaining) / max(1, $total))) . '%';

  $status = t('<p>%percentage of nodes have been indexed. There are %remaining
    items left to index, out of a total of %total.</p>',
    array(
    '%percentage' => $percentage,
    '%remaining' => $remaining,
    '%total' => $total,
  ));

  $status .= ($remaining) ?
    t('<p>Max node ID for indexing on the next cron run: @max.</p>',
        array('@max' => $max_nid)) :
    t('<p>Existing nodes have finished prev/next indexing.</p>');

  $form['status']['status'] = array(
    '#type' => 'item',
    '#markup' => $status,
  );

  $form['status']['reindex'] = array(
    '#type' => 'submit',
    '#value' => t('Re-index'),
  );

  $form['message_library_prev_next_batch_size'] = array(
    '#title' => t('Batch size'),
    '#description' => t('Number of nodes to index during each cron run.'),
    '#type' => 'textfield',
    '#size' => 6,
    '#maxlength' => 7,
    '#default_value' => variable_get('message_library_prev_next_batch_size', 200),
    '#required' => TRUE,
  );

  $form['message_library_prev_next_num_blocks'] = array(
    '#title' => t('Blocks'),
    '#description' => t('Number of blocks available.'),
    '#type' => 'textfield',
    '#size' => 2,
    '#maxlength' => 3,
    '#default_value' => variable_get('message_library_prev_next_num_blocks', 1),
    '#required' => TRUE,
  );

  $form['node_types'] = array(
    '#type' => 'fieldset',
    '#title' => t('Content types'),
    '#description' => t('Define settings for each content type. If none of them
                        is included, then all of them will be.'),
  );

  $node_types = node_type_get_types();

  // Put the 'threat' and 'message' at the beginning, for easier accessibility
  foreach (array('threat', 'message') as $type) {
    if (array_key_exists($type, $node_types)) {
      $temp = $node_types[$type];
      unset($node_types[$type]);
      $node_types = array($type => $temp) + $node_types;
    }
  }

  foreach ($node_types as $type => $name) {
    // Example: message_library_prev_next_node_type_message
    //          message_library_prev_next_node_type_threat
    $base = PREV_NEXT_NODE_TYPE . $type;

    $form['node_types'][$type] = array(
      '#type' => 'fieldset',
      '#description' => t('Note: changing one of these values will reset the
                           entire Prev/Next index.'),
      '#title' => node_type_get_name($type),
      '#collapsible' => TRUE,
      '#collapsed' => !variable_get($base),
    );

    // Include this node type when index
    $form['node_types'][$type][$base . '_current'] = array(
      '#type' => 'value',
      '#value' => variable_get($base, 0),
    );

    $form['node_types'][$type][$base] = array(
      '#type' => 'checkbox',
      '#title' => t('Include'),
      '#default_value' => variable_get($base),
    );

    // Index criteria
    $form['node_types'][$type][$base. '_indexing_criteria_current'] = array(
      '#type' => 'value',
      '#value' => variable_get($base. '_indexing_criteria', 'nid'),
    );

    $form['node_types'][$type][$base. '_indexing_criteria'] = array(
      '#title' => t('Indexing criteria'),
      '#type' => 'select',
      '#options' => array(
        'nid' => t('Node ID'),
        'created' => t('Post date'),
        'changed' => t('Updated date'),
        'title' => t('Title'),
      ),
      '#default_value' => variable_get($base . '_indexing_criteria', 'nid'),
    );

    // Only nodes with the same content type
    $form['node_types'][$type][$base . '_same_type_current'] = array(
      '#type' => 'value',
      '#default_value' => variable_get($base . '_same_type'),
    );

    $form['node_types'][$type][$base. '_same_type'] = array(
      '#type' => 'checkbox',
      '#title' => t('Only nodes with same content type'),
      '#default_value' => variable_get($base . '_same_type'),
    );
  }

  $form['#submit'][] = 'message_library_prev_next_admin_submit';
  return system_settings_form($form);
}

/**
 * Validate callback.
 */
function message_library_prev_next_admin_validate($form, &$form_state) {
  $values = $form_state['values'];

  if ($values['op'] == t('Re-index')) {
    drupal_goto('admin/config/message_library/prev_next/re-index');
  }

  // The variables must be non-negative and numeric.
  $batch_size = $values['message_library_prev_next_batch_size'];
  if (!is_numeric($batch_size) || $batch_size <= 0) {
    form_set_error('message_library_prev_next_batch_size',
        t('The batch size must be a number and greater than zero.'));
  }
}

/**
 * Submit callback.
 */
function message_library_prev_next_admin_submit($form, &$form_state) {
  $values = $form_state['values'];
  $types = node_type_get_types();

  // Gather the content types to be indexed
  $index_types = array();
  foreach($types as $key => $type) {
    $form_key = PREV_NEXT_NODE_TYPE . $type->type;
    if (!empty($values[$form_key]))  {
      $index_types[] = $type->type;
    }
  }

  // If no type is specified, then index all types
  if (empty($index_types)) {
    $index_types = array_keys($types);
  }
  variable_set('message_library_prev_next_index_types', $index_types);

  // Determine whether to index by checking newly change
  foreach ($types as $type => $name) {
    // Example: message_library_prev_next_node_type_message
    //          message_library_prev_next_node_type_threat
    $base = PREV_NEXT_NODE_TYPE . $type;
    $keys_map = array(
      $base . '_current' => $base,
      $base . '_indexing_criteria_current' => $base . '_indexing_criteria',
      $base . '_same_type_current' => $base . '_same_type'
    );

    foreach($keys_map as $current => $old) {
      if ($values[$current] != $values[$old]) {
        // If the found a search criteria has been changed, re-index.
        message_library_prev_next_reindex();
        drupal_set_message(t('The Prev/Next index will be rebuilt.'));
        break 2;
      }
    }
  }

  $form_state['redirect'] = 'admin/config/message_library/prev_next';
}

/**
 * Reindex confirm form
 */
function message_library_prev_next_reindex_confirm($form, &$form_state) {
  $form = confirm_form(
    array(),
    t('Are you sure you want to re-index Prev/Next?'),
    'admin/config/message_library/prev_next',
    t('The entire Prev/Next index will be reset and rebuilt incrementally as
        cron runs. action cannot be undone.'),
    t('Re-index'),
    t('Cancel')
  );
  return $form;
}

/**
 * Submit handler
 */
function message_library_prev_next_reindex_confirm_submit(&$form, &$form_state) {
  if ($form['confirm']) {
    message_library_prev_next_reindex();
    drupal_set_message(t('The Prev/Next index will be rebuilt.'));
    $form_state['redirect'] = 'admin/config/message_library/prev_next';
  }
}
