<?php
/**
 * @file
 * infoasaid_language.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function infoasaid_language_user_default_permissions() {
  $permissions = array();

  // Exported permission: delete terms in languages
  $permissions['delete terms in languages'] = array(
    'name' => 'delete terms in languages',
    'roles' => array(),
  );

  // Exported permission: edit terms in languages
  $permissions['edit terms in languages'] = array(
    'name' => 'edit terms in languages',
    'roles' => array(),
  );

  return $permissions;
}
