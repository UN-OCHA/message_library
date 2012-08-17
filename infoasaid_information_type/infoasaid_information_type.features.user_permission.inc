<?php
/**
 * @file
 * infoasaid_information_type.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function infoasaid_information_type_user_default_permissions() {
  $permissions = array();

  // Exported permission: delete terms in information_type
  $permissions['delete terms in information_type'] = array(
    'name' => 'delete terms in information_type',
    'roles' => array(),
  );

  // Exported permission: edit terms in information_type
  $permissions['edit terms in information_type'] = array(
    'name' => 'edit terms in information_type',
    'roles' => array(),
  );

  return $permissions;
}
