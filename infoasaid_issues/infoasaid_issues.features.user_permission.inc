<?php
/**
 * @file
 * infoasaid_issues.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function infoasaid_issues_user_default_permissions() {
  $permissions = array();

  // Exported permission: delete terms in issues
  $permissions['delete terms in issues'] = array(
    'name' => 'delete terms in issues',
    'roles' => array(),
  );

  // Exported permission: edit terms in issues
  $permissions['edit terms in issues'] = array(
    'name' => 'edit terms in issues',
    'roles' => array(),
  );

  return $permissions;
}
