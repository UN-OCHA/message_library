<?php
/**
 * @file
 * infoasaid_country.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function infoasaid_country_user_default_permissions() {
  $permissions = array();

  // Exported permission: delete terms in country
  $permissions['delete terms in country'] = array(
    'name' => 'delete terms in country',
    'roles' => array(),
  );

  // Exported permission: delete terms in locality_country
  $permissions['delete terms in locality_country'] = array(
    'name' => 'delete terms in locality_country',
    'roles' => array(),
  );

  // Exported permission: edit terms in country
  $permissions['edit terms in country'] = array(
    'name' => 'edit terms in country',
    'roles' => array(),
  );

  // Exported permission: edit terms in locality_country
  $permissions['edit terms in locality_country'] = array(
    'name' => 'edit terms in locality_country',
    'roles' => array(),
  );

  return $permissions;
}
