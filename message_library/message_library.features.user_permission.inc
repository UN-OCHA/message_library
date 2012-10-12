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

  // Exported permission: create message content.
  $permissions['create message content'] = array(
    'name' => 'create message content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: delete any message content.
  $permissions['delete any message content'] = array(
    'name' => 'delete any message content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: delete own message content.
  $permissions['delete own message content'] = array(
    'name' => 'delete own message content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: delete terms in at_risk_groups.
  $permissions['delete terms in at_risk_groups'] = array(
    'name' => 'delete terms in at_risk_groups',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: delete terms in hazard.
  $permissions['delete terms in hazard'] = array(
    'name' => 'delete terms in hazard',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: delete terms in information_type.
  $permissions['delete terms in information_type'] = array(
    'name' => 'delete terms in information_type',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: delete terms in issues.
  $permissions['delete terms in issues'] = array(
    'name' => 'delete terms in issues',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: delete terms in sector.
  $permissions['delete terms in sector'] = array(
    'name' => 'delete terms in sector',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: delete terms in target_audience.
  $permissions['delete terms in target_audience'] = array(
    'name' => 'delete terms in target_audience',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: delete terms in threat.
  $permissions['delete terms in threat'] = array(
    'name' => 'delete terms in threat',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: edit any message content.
  $permissions['edit any message content'] = array(
    'name' => 'edit any message content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: edit own message content.
  $permissions['edit own message content'] = array(
    'name' => 'edit own message content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: edit terms in at_risk_groups.
  $permissions['edit terms in at_risk_groups'] = array(
    'name' => 'edit terms in at_risk_groups',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: edit terms in hazard.
  $permissions['edit terms in hazard'] = array(
    'name' => 'edit terms in hazard',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: edit terms in information_type.
  $permissions['edit terms in information_type'] = array(
    'name' => 'edit terms in information_type',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: edit terms in issues.
  $permissions['edit terms in issues'] = array(
    'name' => 'edit terms in issues',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: edit terms in sector.
  $permissions['edit terms in sector'] = array(
    'name' => 'edit terms in sector',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: edit terms in target_audience.
  $permissions['edit terms in target_audience'] = array(
    'name' => 'edit terms in target_audience',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: edit terms in threat.
  $permissions['edit terms in threat'] = array(
    'name' => 'edit terms in threat',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  return $permissions;
}
