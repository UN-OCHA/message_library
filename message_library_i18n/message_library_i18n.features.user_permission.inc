<?php
/**
 * @file
 * message_library_i18n.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function message_library_i18n_user_default_permissions() {
  $permissions = array();

  // Exported permission: translate content.
  $permissions['translate content'] = array(
    'name' => 'translate content',
    'roles' => array(
      0 => 'administrator',
      1 => 'message library translator',
    ),
    'module' => 'translation',
  );

  return $permissions;
}
