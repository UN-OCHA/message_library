<?php
/**
 * @file
 * infoasaid_settings.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function infoasaid_settings_user_default_roles() {
  $roles = array();

  // Exported role: administrator
  $roles['administrator'] = array(
    'name' => 'administrator',
    'weight' => '13',
  );

  // Exported role: editor
  $roles['editor'] = array(
    'name' => 'editor',
    'weight' => '14',
  );

  // Exported role: guide contributor
  $roles['guide contributor'] = array(
    'name' => 'guide contributor',
    'weight' => '18',
  );

  // Exported role: guide editor
  $roles['guide editor'] = array(
    'name' => 'guide editor',
    'weight' => '21',
  );

  // Exported role: member/contributor
  $roles['member/contributor'] = array(
    'name' => 'member/contributor',
    'weight' => '17',
  );

  // Exported role: ml contributor
  $roles['ml contributor'] = array(
    'name' => 'ml contributor',
    'weight' => '20',
  );

  // Exported role: ml editor
  $roles['ml editor'] = array(
    'name' => 'ml editor',
    'weight' => '19',
  );

  // Exported role: subscriber
  $roles['subscriber'] = array(
    'name' => 'subscriber',
    'weight' => '16',
  );

  // Exported role: web master
  $roles['web master'] = array(
    'name' => 'web master',
    'weight' => '15',
  );

  return $roles;
}
