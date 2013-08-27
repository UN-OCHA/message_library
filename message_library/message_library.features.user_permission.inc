<?php
/**
 * @file
 * message_library.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function message_library_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'access contextual links'.
  $permissions['access contextual links'] = array(
    'name' => 'access contextual links',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'manager' => 'manager',
    ),
    'module' => 'contextual',
  );

  // Exported permission: 'administer at_risk_groups vocabulary terms'.
  $permissions['administer at_risk_groups vocabulary terms'] = array(
    'name' => 'administer at_risk_groups vocabulary terms',
    'roles' => array(
      'manager' => 'manager',
    ),
    'module' => 'vppr',
  );

  // Exported permission: 'administer information_type vocabulary terms'.
  $permissions['administer information_type vocabulary terms'] = array(
    'name' => 'administer information_type vocabulary terms',
    'roles' => array(),
    'module' => 'vppr',
  );

  // Exported permission: 'administer issues vocabulary terms'.
  $permissions['administer issues vocabulary terms'] = array(
    'name' => 'administer issues vocabulary terms',
    'roles' => array(
      'manager' => 'manager',
    ),
    'module' => 'vppr',
  );

  // Exported permission: 'administer target_audience vocabulary terms'.
  $permissions['administer target_audience vocabulary terms'] = array(
    'name' => 'administer target_audience vocabulary terms',
    'roles' => array(
      'manager' => 'manager',
    ),
    'module' => 'vppr',
  );

  // Exported permission: 'administer threat vocabulary terms'.
  $permissions['administer threat vocabulary terms'] = array(
    'name' => 'administer threat vocabulary terms',
    'roles' => array(
      'manager' => 'manager',
    ),
    'module' => 'vppr',
  );

  // Exported permission: 'create message content'.
  $permissions['create message content'] = array(
    'name' => 'create message content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any message content'.
  $permissions['delete any message content'] = array(
    'name' => 'delete any message content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own message content'.
  $permissions['delete own message content'] = array(
    'name' => 'delete own message content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit any message content'.
  $permissions['edit any message content'] = array(
    'name' => 'edit any message content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit own message content'.
  $permissions['edit own message content'] = array(
    'name' => 'edit own message content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'use search_api_autocomplete for search_api_views_message_library'.
  $permissions['use search_api_autocomplete for search_api_views_message_library'] = array(
    'name' => 'use search_api_autocomplete for search_api_views_message_library',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'search_api_autocomplete',
  );

  return $permissions;
}
