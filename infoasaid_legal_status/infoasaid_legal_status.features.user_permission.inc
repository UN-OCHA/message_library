<?php
/**
 * @file
 * infoasaid_legal_status.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function infoasaid_legal_status_user_default_permissions() {
  $permissions = array();

  // Exported permission: delete terms in legal_status
  $permissions['delete terms in legal_status'] = array(
    'name' => 'delete terms in legal_status',
    'roles' => array(),
  );

  // Exported permission: edit terms in legal_status
  $permissions['edit terms in legal_status'] = array(
    'name' => 'edit terms in legal_status',
    'roles' => array(),
  );

  return $permissions;
}
