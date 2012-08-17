<?php
/**
 * @file
 * infoasaid_media.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function infoasaid_media_user_default_permissions() {
  $permissions = array();

  // Exported permission: delete terms in media_audience
  $permissions['delete terms in media_audience'] = array(
    'name' => 'delete terms in media_audience',
    'roles' => array(),
  );

  // Exported permission: delete terms in media_contact_position
  $permissions['delete terms in media_contact_position'] = array(
    'name' => 'delete terms in media_contact_position',
    'roles' => array(),
  );

  // Exported permission: delete terms in media_themes
  $permissions['delete terms in media_themes'] = array(
    'name' => 'delete terms in media_themes',
    'roles' => array(),
  );

  // Exported permission: edit terms in media_audience
  $permissions['edit terms in media_audience'] = array(
    'name' => 'edit terms in media_audience',
    'roles' => array(),
  );

  // Exported permission: edit terms in media_contact_position
  $permissions['edit terms in media_contact_position'] = array(
    'name' => 'edit terms in media_contact_position',
    'roles' => array(),
  );

  // Exported permission: edit terms in media_themes
  $permissions['edit terms in media_themes'] = array(
    'name' => 'edit terms in media_themes',
    'roles' => array(),
  );

  return $permissions;
}
