<?php
/**
 * @file
 * message_library_i18n.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function message_library_i18n_user_default_roles() {
  $roles = array();

  // Exported role: message library translator.
  $roles['message library translator'] = array(
    'name' => 'message library translator',
    'weight' => '100',
    'machine_name' => '',
  );

  return $roles;
}
