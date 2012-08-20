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

  // Exported permission: create threat content.
  $permissions['create threat content'] = array(
    'name' => 'create threat content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: delete any message content.
  $permissions['delete any message content'] = array(
    'name' => 'delete any message content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: delete any threat content.
  $permissions['delete any threat content'] = array(
    'name' => 'delete any threat content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: delete own message content.
  $permissions['delete own message content'] = array(
    'name' => 'delete own message content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: delete own threat content.
  $permissions['delete own threat content'] = array(
    'name' => 'delete own threat content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: delete terms in 17.
  $permissions['delete terms in 17'] = array(
    'name' => 'delete terms in 17',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: delete terms in 18.
  $permissions['delete terms in 18'] = array(
    'name' => 'delete terms in 18',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: delete terms in 19.
  $permissions['delete terms in 19'] = array(
    'name' => 'delete terms in 19',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: delete terms in 20.
  $permissions['delete terms in 20'] = array(
    'name' => 'delete terms in 20',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: delete terms in 21.
  $permissions['delete terms in 21'] = array(
    'name' => 'delete terms in 21',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: delete terms in 22.
  $permissions['delete terms in 22'] = array(
    'name' => 'delete terms in 22',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: delete terms in 23.
  $permissions['delete terms in 23'] = array(
    'name' => 'delete terms in 23',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: edit any message content.
  $permissions['edit any message content'] = array(
    'name' => 'edit any message content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: edit any threat content.
  $permissions['edit any threat content'] = array(
    'name' => 'edit any threat content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: edit own message content.
  $permissions['edit own message content'] = array(
    'name' => 'edit own message content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: edit own threat content.
  $permissions['edit own threat content'] = array(
    'name' => 'edit own threat content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: edit terms in 17.
  $permissions['edit terms in 17'] = array(
    'name' => 'edit terms in 17',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: edit terms in 18.
  $permissions['edit terms in 18'] = array(
    'name' => 'edit terms in 18',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: edit terms in 19.
  $permissions['edit terms in 19'] = array(
    'name' => 'edit terms in 19',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: edit terms in 20.
  $permissions['edit terms in 20'] = array(
    'name' => 'edit terms in 20',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: edit terms in 22.
  $permissions['edit terms in 22'] = array(
    'name' => 'edit terms in 22',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: edit terms in 23.
  $permissions['edit terms in 23'] = array(
    'name' => 'edit terms in 23',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  return $permissions;
}
