<?php
/**
 * @file
 * infoasaid_arg.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function infoasaid_arg_user_default_permissions() {
  $permissions = array();

  // Exported permission: delete terms in at_risk_groups
  $permissions['delete terms in at_risk_groups'] = array(
    'name' => 'delete terms in at_risk_groups',
    'roles' => array(),
  );

  // Exported permission: edit terms in at_risk_groups
  $permissions['edit terms in at_risk_groups'] = array(
    'name' => 'edit terms in at_risk_groups',
    'roles' => array(),
  );

  return $permissions;
}
