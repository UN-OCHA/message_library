<?php
/**
 * @file
 * message_library_help.box.inc
 */

/**
 * Implements hook_default_box().
 */
function message_library_help_default_box() {
  $export = array();

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'ml_help_criteria';
  $box->plugin_key = 'simple';
  $box->title = '';
  $box->description = 'Message Library Help Criteria';
  $box->options = array(
    'body' => array(
      'value' => 'Every time you do a search, you will create search \'criteria\'. Each word or term acts as a filter to narrow the results down. To widen the search, click on "remove". To start a new search, you will need to remove all criteria. Once you have pressed search, the number of records tells you how many messages have come up using that term.',
      'format' => 'simple',
    ),
    'additional_classes' => '',
  );
  $export['ml_help_criteria'] = $box;

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'ml_help_general';
  $box->plugin_key = 'simple';
  $box->title = '';
  $box->description = 'Message Library Help General';
  $box->options = array(
    'body' => array(
      'value' => 'The infoasaid Message Library allows you to search through a database of generic humanitarian messages which have been peer reviewed by humanitarian experts in a number of different clusters/sectors including, Health, Water, Sanitation and Hygiene (WASH), Nutrition, Food Security, Protection (Child Protection, Gender-based Violence, Mine Risk Education), Education and Camp Coordination Camp Management. The messages include: warnings and alerts, advice on risks and threats and how to mitigate them and prompts for programmatic interventions. The message library is designed to be used as a reference tool and each message should be translated, piloted and adapted to suit the local context and to ensure comprehension before dissemination. Click on the "Show" button to learn about a feature. The best browsers to use when navigating the library are Firefox and Google Chrome.',
      'format' => 'simple',
    ),
    'additional_classes' => '',
  );
  $export['ml_help_general'] = $box;

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'ml_help_quick_search';
  $box->plugin_key = 'simple';
  $box->title = '';
  $box->description = 'Message Library Help Quick Search';
  $box->options = array(
    'body' => array(
      'value' => 'A quick search allows users to type in a key word and the tool will list below all messages related to that particular word or phrase categorised under the following table headings: Issue, Threat, At Risk Group, Target Audience, and Information Requirement. Several sectors could be represented in the list of messages. 

The advanced search allows the user to select their search criteria from a set of drop down menus. There are four main drop down menus: ‘Issue’, ‘Threat’, ‘At-Risk Group’ and ‘Target Audience’. \'Issues\' are categorised in two ways: alphabetically or by sector. Once the user has chosen the most useful categorisation, they then simply select an item from the list from each drop down menu, starting with \'Issue\' and ending in \'Target Audience\' and click search.',
      'format' => 'simple',
    ),
    'additional_classes' => '',
  );
  $export['ml_help_quick_search'] = $box;

  return $export;
}
