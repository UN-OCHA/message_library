<?php
/**
 * @file
 * infoasaid_hazard.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function infoasaid_hazard_user_default_permissions() {
  $permissions = array();

  // Exported permission: delete terms in hazard
  $permissions['delete terms in hazard'] = array(
    'name' => 'delete terms in hazard',
    'roles' => array(),
  );

  // Exported permission: edit terms in hazard
  $permissions['edit terms in hazard'] = array(
    'name' => 'edit terms in hazard',
    'roles' => array(),
  );

  return $permissions;
}
