<?php
/**
 * @file
 * message_library.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function message_library_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'message_library_node';
  $context->description = 'Used for \'Message Library\' relevant node pages.';
  $context->tag = 'message library';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'message' => 'message',
        'threat' => 'threat',
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'export2rtf-delta-0' => array(
          'module' => 'export2rtf',
          'delta' => 'delta-0',
          'region' => 'content',
          'weight' => '8',
        ),
        'download_email-delta-0' => array(
          'module' => 'download_email',
          'delta' => 'delta-0',
          'region' => 'content',
          'weight' => '9',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Used for \'Message Library\' relevant node pages.');
  t('message library');
  $export['message_library_node'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'message_library_search';
  $context->description = 'Displayed on \'Message Library\' search relevant pages.';
  $context->tag = 'message library';
  $context->conditions = array(
    'views' => array(
      'values' => array(
        'message_library:bundle_page' => 'message_library:bundle_page',
        'message_library:search_page' => 'message_library:search_page',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'download_email-delta-0' => array(
          'module' => 'download_email',
          'delta' => 'delta-0',
          'region' => 'content',
          'weight' => '9',
        ),
        'export2rtf-delta-0' => array(
          'module' => 'export2rtf',
          'delta' => 'delta-0',
          'region' => 'content',
          'weight' => '8',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Displayed on \'Message Library\' search relevant pages.');
  t('message library');
  $export['message_library_search'] = $context;

  return $export;
}
