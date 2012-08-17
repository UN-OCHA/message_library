<?php
/**
 * @file
 * infoasaid_organisation.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function infoasaid_organisation_strongarm() {
  $export = array();

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_media_telecom_organisation';
  $strongarm->value = 0;
  $export['comment_anonymous_media_telecom_organisation'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_media_telecom_organisation';
  $strongarm->value = 1;
  $export['comment_default_mode_media_telecom_organisation'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_media_telecom_organisation';
  $strongarm->value = '50';
  $export['comment_default_per_page_media_telecom_organisation'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_media_telecom_organisation';
  $strongarm->value = 1;
  $export['comment_form_location_media_telecom_organisation'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_media_telecom_organisation';
  $strongarm->value = '1';
  $export['comment_media_telecom_organisation'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_media_telecom_organisation';
  $strongarm->value = '1';
  $export['comment_preview_media_telecom_organisation'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_media_telecom_organisation';
  $strongarm->value = 1;
  $export['comment_subject_field_media_telecom_organisation'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_media_telecom_organisation';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_media_telecom_organisation'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_media_telecom_organisation';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_media_telecom_organisation'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_media_telecom_organisation';
  $strongarm->value = array(
    0 => 'status',
    1 => 'promote',
  );
  $export['node_options_media_telecom_organisation'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_media_telecom_organisation';
  $strongarm->value = '1';
  $export['node_preview_media_telecom_organisation'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_media_telecom_organisation';
  $strongarm->value = 1;
  $export['node_submitted_media_telecom_organisation'] = $strongarm;

  return $export;
}
