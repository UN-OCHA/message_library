<?php
/**
 * @file
 * infoasaid_organisation.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function infoasaid_organisation_user_default_permissions() {
  $permissions = array();

  // Exported permission: create media_telecom_organisation content
  $permissions['create media_telecom_organisation content'] = array(
    'name' => 'create media_telecom_organisation content',
    'roles' => array(),
  );

  // Exported permission: delete any media_telecom_organisation content
  $permissions['delete any media_telecom_organisation content'] = array(
    'name' => 'delete any media_telecom_organisation content',
    'roles' => array(),
  );

  // Exported permission: delete own media_telecom_organisation content
  $permissions['delete own media_telecom_organisation content'] = array(
    'name' => 'delete own media_telecom_organisation content',
    'roles' => array(),
  );

  // Exported permission: delete terms in organization_category
  $permissions['delete terms in organization_category'] = array(
    'name' => 'delete terms in organization_category',
    'roles' => array(),
  );

  // Exported permission: delete terms in organization_type
  $permissions['delete terms in organization_type'] = array(
    'name' => 'delete terms in organization_type',
    'roles' => array(),
  );

  // Exported permission: edit any media_telecom_organisation content
  $permissions['edit any media_telecom_organisation content'] = array(
    'name' => 'edit any media_telecom_organisation content',
    'roles' => array(),
  );

  // Exported permission: edit own media_telecom_organisation content
  $permissions['edit own media_telecom_organisation content'] = array(
    'name' => 'edit own media_telecom_organisation content',
    'roles' => array(),
  );

  // Exported permission: edit terms in organization_category
  $permissions['edit terms in organization_category'] = array(
    'name' => 'edit terms in organization_category',
    'roles' => array(),
  );

  // Exported permission: edit terms in organization_type
  $permissions['edit terms in organization_type'] = array(
    'name' => 'edit terms in organization_type',
    'roles' => array(),
  );

  return $permissions;
}
