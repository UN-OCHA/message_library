<?php
/**
 * @file
 * message_libarary_subscription.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function message_libarary_subscription_user_default_permissions() {
  $permissions = array();

  // Exported permission: administer search_api_saved_searches.
  $permissions['administer search_api_saved_searches'] = array(
    'name' => 'administer search_api_saved_searches',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'search_api_saved_searches',
  );

  // Exported permission: use search_api_saved_searches.
  $permissions['use search_api_saved_searches'] = array(
    'name' => 'use search_api_saved_searches',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'search_api_saved_searches',
  );

  return $permissions;
}
