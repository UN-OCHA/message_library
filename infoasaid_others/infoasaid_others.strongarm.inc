<?php
/**
 * @file
 * infoasaid_others.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function infoasaid_others_strongarm() {
  $export = array();

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_page_with_view';
  $strongarm->value = 0;
  $export['comment_anonymous_page_with_view'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_page_with_view';
  $strongarm->value = 1;
  $export['comment_default_mode_page_with_view'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_page_with_view';
  $strongarm->value = '50';
  $export['comment_default_per_page_page_with_view'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_page_with_view';
  $strongarm->value = 1;
  $export['comment_form_location_page_with_view'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_page_with_view';
  $strongarm->value = '2';
  $export['comment_page_with_view'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_page_with_view';
  $strongarm->value = '1';
  $export['comment_preview_page_with_view'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_page_with_view';
  $strongarm->value = 1;
  $export['comment_subject_field_page_with_view'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_page_with_view';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_page_with_view'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_page_with_view';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_page_with_view'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_page_with_view';
  $strongarm->value = array(
    0 => 'status',
    1 => 'promote',
  );
  $export['node_options_page_with_view'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_page_with_view';
  $strongarm->value = '1';
  $export['node_preview_page_with_view'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_page_with_view';
  $strongarm->value = 1;
  $export['node_submitted_page_with_view'] = $strongarm;

  return $export;
}
