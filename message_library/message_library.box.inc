<?php
/**
 * @file
 * message_library.box.inc
 */

/**
 * Implements hook_default_box().
 */
function message_library_default_box() {
  $export = array();

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'message_library_about';
  $box->plugin_key = 'i18n';
  $box->title = 'About Message Library';
  $box->description = 'Message Library About ';
  $box->options = array(
    'body' => array(
      'value' => '<p><a href="message-library-quick-reference-user-manual">Quick reference User Manual</a></p>
<p><a href="http://infoasaid.org/sites/infoasaid.org/files/message_library_guide_sept_2012_0.pdf">Download message library guide (.pdf)</a></p>
<p>Watch <a class="ext" href="http://fr.slideshare.net/infoasaid/message-library-slide-show-for-users" target="_self">slide show</a> introduction</p>
<p><a href="frequently-asked-questions-users-faq">Frequently asked questions</a></p>',
      'format' => 'filtered_html',
    ),
    'i18n_boxes' => array(
      'language' => '__LOCALIZE__',
    ),
    'additional_classes' => '',
  );
  $export['message_library_about'] = $box;

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'message_library_admin';
  $box->plugin_key = 'i18n';
  $box->title = 'Admin Message Library';
  $box->description = 'Message Library Admin';
  $box->options = array(
    'body' => array(
      'value' => '<p><a href="/node/add/message">Add Message</a></p><p><a href="/admin/structure/taxonomy/threat">Manage Threats</a></p><p><a href="/admin/structure/taxonomy/issues">Manage Issues</a></p><p><a href="/admin/structure/taxonomy/at_risk_groups">Manage At Risk Groups</a></p><p><a href="/admin/structure/taxonomy/target_audiences">Manage Target Audiences</a></p><p><a href="/admin/structure/taxonomy/hazard">Manage Hazards</a></p><p><a href="/admin/config/search/search_api/index/message_library_index/status">Index Message Library</a></p>',
      'format' => 'filtered_html',
    ),
    'i18n_boxes' => array(
      'language' => '__LOCALIZE__',
    ),
    'additional_classes' => '',
  );
  $export['message_library_admin'] = $box;

  return $export;
}
