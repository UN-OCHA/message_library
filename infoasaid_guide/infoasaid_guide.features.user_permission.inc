<?php
/**
 * @file
 * infoasaid_guide.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function infoasaid_guide_user_default_permissions() {
  $permissions = array();

  // Exported permission: create guide content
  $permissions['create guide content'] = array(
    'name' => 'create guide content',
    'roles' => array(),
  );

  // Exported permission: create guide_page content
  $permissions['create guide_page content'] = array(
    'name' => 'create guide_page content',
    'roles' => array(),
  );

  // Exported permission: delete any guide content
  $permissions['delete any guide content'] = array(
    'name' => 'delete any guide content',
    'roles' => array(),
  );

  // Exported permission: delete any guide_page content
  $permissions['delete any guide_page content'] = array(
    'name' => 'delete any guide_page content',
    'roles' => array(),
  );

  // Exported permission: delete own guide content
  $permissions['delete own guide content'] = array(
    'name' => 'delete own guide content',
    'roles' => array(),
  );

  // Exported permission: delete own guide_page content
  $permissions['delete own guide_page content'] = array(
    'name' => 'delete own guide_page content',
    'roles' => array(),
  );

  // Exported permission: edit any guide content
  $permissions['edit any guide content'] = array(
    'name' => 'edit any guide content',
    'roles' => array(),
  );

  // Exported permission: edit any guide_page content
  $permissions['edit any guide_page content'] = array(
    'name' => 'edit any guide_page content',
    'roles' => array(),
  );

  // Exported permission: edit own guide content
  $permissions['edit own guide content'] = array(
    'name' => 'edit own guide content',
    'roles' => array(),
  );

  // Exported permission: edit own guide_page content
  $permissions['edit own guide_page content'] = array(
    'name' => 'edit own guide_page content',
    'roles' => array(),
  );

  return $permissions;
}
