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
  $box->description = 'About Message Library';
  $box->options = array(
    'body' => array(
      'value' => '<p><a href="/node/6682">Quick reference User Manual</a></p>
<p><a href="http://infoasaid.org/sites/infoasaid.org/files/message_library_guide_sept_2012_0.pdf">Download message library guide (.pdf)</a></p>
<p>Watch&nbsp;<a href="http://fr.slideshare.net/infoasaid/message-library-slide-show-for-users" target="_self" class="ext">slide show</a><span class="ext"></span> introduction&nbsp;</p>
<p><a href="/faq">Frequently asked questions</a></p>
',
      'format' => 'full_html',
    ),
    'i18n_boxes' => array(
      'language' => '__LOCALIZE__',
    ),
  );
  $export['message_library_about'] = $box;

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'ml_about';
  $box->plugin_key = 'i18n';
  $box->title = 'About Message Library';
  $box->description = 'About Message Library';
  $box->options = array(
    'body' => array(
      'value' => '<p><a href="/node/6682">Quick reference User Manual</a></p>
<p><a href="http://infoasaid.org/sites/infoasaid.org/files/message_library_guide_sept_2012_0.pdf">Download message library guide (.pdf)</a></p>
<p>Watch&nbsp;<a href="http://fr.slideshare.net/infoasaid/message-library-slide-show-for-users" target="_self" class="ext">slide show</a><span class="ext"></span> introduction&nbsp;</p>
<p><a href="/faq">Frequently asked questions</a></p>
',
      'format' => 'full_html',
    ),
    'i18n_boxes' => array(
      'language' => '__LOCALIZE__',
    ),
  );
  $export['ml_about'] = $box;

  return $export;
}
