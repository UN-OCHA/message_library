<?php
/**
 * @file
 * infoasaid_newsletter.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function infoasaid_newsletter_user_default_permissions() {
  $permissions = array();

  // Exported permission: delete terms in newsletter
  $permissions['delete terms in newsletter'] = array(
    'name' => 'delete terms in newsletter',
    'roles' => array(),
  );

  // Exported permission: edit terms in newsletter
  $permissions['edit terms in newsletter'] = array(
    'name' => 'edit terms in newsletter',
    'roles' => array(),
  );

  return $permissions;
}
