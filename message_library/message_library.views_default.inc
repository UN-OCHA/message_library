<?php
/**
 * @file
 * message_library.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function message_library_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'message_library';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'search_api_index_message_library_index';
  $view->human_name = 'Message Library';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Message Library';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['search_api_bypass_access'] = 1;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Search';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Reset Search';
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['autosubmit_hide'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'field_message_threat_tid' => 'field_message_threat_tid',
    'nid' => 'nid',
    'field_message_threat_field_threat_category' => 'field_message_threat_field_threat_category',
    'field_message_threat' => 'field_message_threat',
    'title_1' => 'title_1',
    'field_message_group_risk' => 'field_message_group_risk',
    'field_message_audience' => 'field_message_audience',
    'field_message_group_mess' => 'field_message_group_mess',
    'field_message_example_communic' => 'field_message_example_communic',
    'field_message_url' => 'field_message_url',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'field_message_threat_tid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_message_threat_field_threat_category' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_message_threat' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title_1' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_message_group_risk' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_message_audience' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_message_group_mess' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_message_example_communic' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_message_url' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['sticky'] = TRUE;
  /* Footer: Global: Result summary */
  $handler->display->display_options['footer']['result']['id'] = 'result';
  $handler->display->display_options['footer']['result']['table'] = 'views';
  $handler->display->display_options['footer']['result']['field'] = 'result';
  $handler->display->display_options['footer']['result']['label'] = 'Search Summary';
  $handler->display->display_options['footer']['result']['content'] = '<strong>@total</strong> records matched criteria.';
  /* Footer: Message Library: Link to download rtf */
  $handler->display->display_options['footer']['link_rtf']['id'] = 'link_rtf';
  $handler->display->display_options['footer']['link_rtf']['table'] = 'message_library';
  $handler->display->display_options['footer']['link_rtf']['field'] = 'link_rtf';
  /* Footer: Message Library: Link to email rtf */
  $handler->display->display_options['footer']['link_email_rtf']['id'] = 'link_email_rtf';
  $handler->display->display_options['footer']['link_email_rtf']['table'] = 'message_library';
  $handler->display->display_options['footer']['link_email_rtf']['field'] = 'link_email_rtf';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['content'] = 'There is no result for this search. Your search might be too narrow. Click the remove link next to the criteria to expand the search, or click on the Reset Search button to remove all currently selected criteria.';
  $handler->display->display_options['empty']['area']['format'] = 'simple';
  /* Relationship: Indexed Node: Threat */
  $handler->display->display_options['relationships']['field_message_threat']['id'] = 'field_message_threat';
  $handler->display->display_options['relationships']['field_message_threat']['table'] = 'search_api_index_message_library_index';
  $handler->display->display_options['relationships']['field_message_threat']['field'] = 'field_message_threat';
  /* Field: Threat: Term ID (indexed) */
  $handler->display->display_options['fields']['field_message_threat_tid']['id'] = 'field_message_threat_tid';
  $handler->display->display_options['fields']['field_message_threat_tid']['table'] = 'search_api_index_message_library_index';
  $handler->display->display_options['fields']['field_message_threat_tid']['field'] = 'field_message_threat_tid';
  $handler->display->display_options['fields']['field_message_threat_tid']['exclude'] = TRUE;
  /* Field: Indexed Node: Node ID */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'search_api_index_message_library_index';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nid']['separator'] = '';
  $handler->display->display_options['fields']['nid']['link_to_entity'] = 0;
  /* Field: Threat: Issue (indexed) */
  $handler->display->display_options['fields']['field_message_threat_field_threat_category']['id'] = 'field_message_threat_field_threat_category';
  $handler->display->display_options['fields']['field_message_threat_field_threat_category']['table'] = 'search_api_index_message_library_index';
  $handler->display->display_options['fields']['field_message_threat_field_threat_category']['field'] = 'field_message_threat_field_threat_category';
  $handler->display->display_options['fields']['field_message_threat_field_threat_category']['label'] = 'Issue';
  $handler->display->display_options['fields']['field_message_threat_field_threat_category']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_message_threat_field_threat_category']['view_mode'] = 'full';
  /* Field: Indexed Node: Threat */
  $handler->display->display_options['fields']['field_message_threat']['id'] = 'field_message_threat';
  $handler->display->display_options['fields']['field_message_threat']['table'] = 'search_api_index_message_library_index';
  $handler->display->display_options['fields']['field_message_threat']['field'] = 'field_message_threat';
  $handler->display->display_options['fields']['field_message_threat']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_message_threat']['alter']['path'] = 'message-library/threat/[field_message_threat_tid]';
  $handler->display->display_options['fields']['field_message_threat']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_message_threat']['view_mode'] = 'full';
  /* Field: Indexed Node: Title */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'search_api_index_message_library_index';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['label'] = 'Information requirement';
  $handler->display->display_options['fields']['title_1']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title_1']['alter']['path'] = 'message-library/threat/[field_message_threat_tid]#[nid] ';
  $handler->display->display_options['fields']['title_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title_1']['link_to_entity'] = 0;
  /* Field: Indexed Node: At risk group */
  $handler->display->display_options['fields']['field_message_group_risk']['id'] = 'field_message_group_risk';
  $handler->display->display_options['fields']['field_message_group_risk']['table'] = 'search_api_index_message_library_index';
  $handler->display->display_options['fields']['field_message_group_risk']['field'] = 'field_message_group_risk';
  $handler->display->display_options['fields']['field_message_group_risk']['exclude'] = TRUE;
  /* Field: Indexed Node: Target audience */
  $handler->display->display_options['fields']['field_message_audience']['id'] = 'field_message_audience';
  $handler->display->display_options['fields']['field_message_audience']['table'] = 'search_api_index_message_library_index';
  $handler->display->display_options['fields']['field_message_audience']['field'] = 'field_message_audience';
  $handler->display->display_options['fields']['field_message_audience']['exclude'] = TRUE;
  /* Field: Indexed Node: Message */
  $handler->display->display_options['fields']['field_message_group_mess']['id'] = 'field_message_group_mess';
  $handler->display->display_options['fields']['field_message_group_mess']['table'] = 'search_api_index_message_library_index';
  $handler->display->display_options['fields']['field_message_group_mess']['field'] = 'field_message_group_mess';
  /* Field: Indexed Node: Examples of Communication around this issue */
  $handler->display->display_options['fields']['field_message_example_communic']['id'] = 'field_message_example_communic';
  $handler->display->display_options['fields']['field_message_example_communic']['table'] = 'search_api_index_message_library_index';
  $handler->display->display_options['fields']['field_message_example_communic']['field'] = 'field_message_example_communic';
  $handler->display->display_options['fields']['field_message_example_communic']['label'] = 'Resources';
  $handler->display->display_options['fields']['field_message_example_communic']['element_label_colon'] = FALSE;
  /* Field: Indexed Node: Localized Message */
  $handler->display->display_options['fields']['field_message_localized']['id'] = 'field_message_localized';
  $handler->display->display_options['fields']['field_message_localized']['table'] = 'search_api_index_message_library_index';
  $handler->display->display_options['fields']['field_message_localized']['field'] = 'field_message_localized';
  $handler->display->display_options['fields']['field_message_localized']['link_to_entity'] = 1;
  $handler->display->display_options['fields']['field_message_localized']['view_mode'] = 'full';
  /* Field: Indexed Node: Message Synonyms */
  $handler->display->display_options['fields']['field_message_synonyms_1']['id'] = 'field_message_synonyms_1';
  $handler->display->display_options['fields']['field_message_synonyms_1']['table'] = 'search_api_index_message_library_index';
  $handler->display->display_options['fields']['field_message_synonyms_1']['field'] = 'field_message_synonyms';
  $handler->display->display_options['fields']['field_message_synonyms_1']['exclude'] = TRUE;
  /* Sort criterion: Threat: Name (indexed) */
  $handler->display->display_options['sorts']['field_message_threat_name']['id'] = 'field_message_threat_name';
  $handler->display->display_options['sorts']['field_message_threat_name']['table'] = 'search_api_index_message_library_index';
  $handler->display->display_options['sorts']['field_message_threat_name']['field'] = 'field_message_threat_name';
  /* Filter criterion: Search: Fulltext search */
  $handler->display->display_options['filters']['search_api_views_fulltext']['id'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['table'] = 'search_api_index_message_library_index';
  $handler->display->display_options['filters']['search_api_views_fulltext']['field'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['group'] = 1;
  $handler->display->display_options['filters']['search_api_views_fulltext']['exposed'] = TRUE;
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator_id'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['label'] = 'Quick Search';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['identifier'] = 'ml_search_text';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['remember_roles'] = array(
    2 => '2',
    1 => '1',
    200153887 => 0,
    52310416 => 0,
    30037204 => 0,
    142035489 => 0,
  );
  $handler->display->display_options['filters']['search_api_views_fulltext']['fields'] = array(
    'title' => 'title',
    'field_message_group_mess' => 'field_message_group_mess',
    'field_message_synonyms' => 'field_message_synonyms',
    'search_api_aggregation_1' => 'search_api_aggregation_1',
    'field_message_threat:description' => 'field_message_threat:description',
    'field_message_threat:field_threat_category:name' => 'field_message_threat:field_threat_category:name',
  );
  /* Filter criterion: Threat: Issue (indexed) */
  $handler->display->display_options['filters']['field_message_threat_field_threat_category']['id'] = 'field_message_threat_field_threat_category';
  $handler->display->display_options['filters']['field_message_threat_field_threat_category']['table'] = 'search_api_index_message_library_index';
  $handler->display->display_options['filters']['field_message_threat_field_threat_category']['field'] = 'field_message_threat_field_threat_category';
  $handler->display->display_options['filters']['field_message_threat_field_threat_category']['value'] = array();
  $handler->display->display_options['filters']['field_message_threat_field_threat_category']['group'] = 1;
  $handler->display->display_options['filters']['field_message_threat_field_threat_category']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_message_threat_field_threat_category']['expose']['operator_id'] = 'field_message_threat_field_threat_category_op';
  $handler->display->display_options['filters']['field_message_threat_field_threat_category']['expose']['label'] = 'Issues';
  $handler->display->display_options['filters']['field_message_threat_field_threat_category']['expose']['operator'] = 'field_message_threat_field_threat_category_op';
  $handler->display->display_options['filters']['field_message_threat_field_threat_category']['expose']['identifier'] = 'issue';
  $handler->display->display_options['filters']['field_message_threat_field_threat_category']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_message_threat_field_threat_category']['expose']['remember_roles'] = array(
    2 => '2',
    1 => '1',
    218860149 => 0,
    188284353 => 0,
    200153887 => 0,
    197637936 => 0,
    52310416 => 0,
    30037204 => 0,
  );
  $handler->display->display_options['filters']['field_message_threat_field_threat_category']['expose']['reduce'] = 0;
  $handler->display->display_options['filters']['field_message_threat_field_threat_category']['group_info']['label'] = 'Issue (indexed)';
  $handler->display->display_options['filters']['field_message_threat_field_threat_category']['group_info']['identifier'] = 'field_message_threat_field_threat_category';
  $handler->display->display_options['filters']['field_message_threat_field_threat_category']['group_info']['remember'] = FALSE;
  $handler->display->display_options['filters']['field_message_threat_field_threat_category']['group_info']['group_items'] = array(
    1 => array(),
    2 => array(),
    3 => array(),
  );
  /* Filter criterion: Indexed Node: Threat */
  $handler->display->display_options['filters']['field_message_threat']['id'] = 'field_message_threat';
  $handler->display->display_options['filters']['field_message_threat']['table'] = 'search_api_index_message_library_index';
  $handler->display->display_options['filters']['field_message_threat']['field'] = 'field_message_threat';
  $handler->display->display_options['filters']['field_message_threat']['value'] = array();
  $handler->display->display_options['filters']['field_message_threat']['group'] = 1;
  $handler->display->display_options['filters']['field_message_threat']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_message_threat']['expose']['operator_id'] = 'field_message_threat_op';
  $handler->display->display_options['filters']['field_message_threat']['expose']['label'] = 'Threat';
  $handler->display->display_options['filters']['field_message_threat']['expose']['operator'] = 'field_message_threat_op';
  $handler->display->display_options['filters']['field_message_threat']['expose']['identifier'] = 'threat';
  $handler->display->display_options['filters']['field_message_threat']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_message_threat']['expose']['remember_roles'] = array(
    2 => '2',
    1 => '1',
    6 => 0,
    5 => 0,
    4 => 0,
    3 => 0,
  );
  /* Filter criterion: Indexed Node: At risk group */
  $handler->display->display_options['filters']['field_message_group_risk']['id'] = 'field_message_group_risk';
  $handler->display->display_options['filters']['field_message_group_risk']['table'] = 'search_api_index_message_library_index';
  $handler->display->display_options['filters']['field_message_group_risk']['field'] = 'field_message_group_risk';
  $handler->display->display_options['filters']['field_message_group_risk']['value'] = array();
  $handler->display->display_options['filters']['field_message_group_risk']['group'] = 1;
  $handler->display->display_options['filters']['field_message_group_risk']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_message_group_risk']['expose']['operator_id'] = 'field_message_group_risk_op';
  $handler->display->display_options['filters']['field_message_group_risk']['expose']['label'] = 'At risk group';
  $handler->display->display_options['filters']['field_message_group_risk']['expose']['operator'] = 'field_message_group_risk_op';
  $handler->display->display_options['filters']['field_message_group_risk']['expose']['identifier'] = 'at_risk_group';
  $handler->display->display_options['filters']['field_message_group_risk']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_message_group_risk']['expose']['remember_roles'] = array(
    2 => '2',
    1 => '1',
    6 => 0,
    5 => 0,
    4 => 0,
    3 => 0,
  );
  /* Filter criterion: Indexed Node: Target audience */
  $handler->display->display_options['filters']['field_message_audience']['id'] = 'field_message_audience';
  $handler->display->display_options['filters']['field_message_audience']['table'] = 'search_api_index_message_library_index';
  $handler->display->display_options['filters']['field_message_audience']['field'] = 'field_message_audience';
  $handler->display->display_options['filters']['field_message_audience']['value'] = array();
  $handler->display->display_options['filters']['field_message_audience']['group'] = 1;
  $handler->display->display_options['filters']['field_message_audience']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_message_audience']['expose']['operator_id'] = 'field_message_audience_op';
  $handler->display->display_options['filters']['field_message_audience']['expose']['label'] = 'Target audience';
  $handler->display->display_options['filters']['field_message_audience']['expose']['operator'] = 'field_message_audience_op';
  $handler->display->display_options['filters']['field_message_audience']['expose']['identifier'] = 'target_audience';
  $handler->display->display_options['filters']['field_message_audience']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_message_audience']['expose']['remember_roles'] = array(
    2 => '2',
    1 => '1',
    6 => 0,
    5 => 0,
    4 => 0,
    3 => 0,
  );
  /* Filter criterion: Indexed Node: Status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'search_api_index_message_library_index';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['status']['group'] = 1;
  /* Filter criterion: Indexed Node: Threat */
  $handler->display->display_options['filters']['field_message_threat_1']['id'] = 'field_message_threat_1';
  $handler->display->display_options['filters']['field_message_threat_1']['table'] = 'search_api_index_message_library_index';
  $handler->display->display_options['filters']['field_message_threat_1']['field'] = 'field_message_threat';
  $handler->display->display_options['filters']['field_message_threat_1']['operator'] = 'not empty';
  $handler->display->display_options['filters']['field_message_threat_1']['value'] = array();
  $handler->display->display_options['filters']['field_message_threat_1']['group'] = 1;
  /* Filter criterion: Indexed Node: Content type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'search_api_index_message_library_index';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'message' => 'message',
  );

  /* Display: Search Page */
  $handler = $view->new_display('page', 'Search Page', 'search_page');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['path'] = 'message-library';

  /* Display: Feed */
  $handler = $view->new_display('page', 'Feed', 'feed');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['path'] = 'message-library/export';

  /* Display: Unpublished Messages */
  $handler = $view->new_display('page', 'Unpublished Messages', 'page_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Message Library (Unpublished Messages)';
  $handler->display->display_options['display_description'] = 'Unpublished Messages';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Threat: Term ID (indexed) */
  $handler->display->display_options['fields']['field_message_threat_tid']['id'] = 'field_message_threat_tid';
  $handler->display->display_options['fields']['field_message_threat_tid']['table'] = 'search_api_index_message_library_index';
  $handler->display->display_options['fields']['field_message_threat_tid']['field'] = 'field_message_threat_tid';
  $handler->display->display_options['fields']['field_message_threat_tid']['exclude'] = TRUE;
  /* Field: Indexed Node: Node ID */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'search_api_index_message_library_index';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nid']['separator'] = '';
  $handler->display->display_options['fields']['nid']['link_to_entity'] = 0;
  /* Field: Threat: Issue (indexed) */
  $handler->display->display_options['fields']['field_message_threat_field_threat_category']['id'] = 'field_message_threat_field_threat_category';
  $handler->display->display_options['fields']['field_message_threat_field_threat_category']['table'] = 'search_api_index_message_library_index';
  $handler->display->display_options['fields']['field_message_threat_field_threat_category']['field'] = 'field_message_threat_field_threat_category';
  $handler->display->display_options['fields']['field_message_threat_field_threat_category']['label'] = 'Issue';
  /* Field: Indexed Node: Threat */
  $handler->display->display_options['fields']['field_message_threat']['id'] = 'field_message_threat';
  $handler->display->display_options['fields']['field_message_threat']['table'] = 'search_api_index_message_library_index';
  $handler->display->display_options['fields']['field_message_threat']['field'] = 'field_message_threat';
  $handler->display->display_options['fields']['field_message_threat']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_message_threat']['alter']['path'] = 'message-library/threat/[field_message_threat_tid]';
  $handler->display->display_options['fields']['field_message_threat']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_message_threat']['view_mode'] = 'full';
  /* Field: Indexed Node: Title */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'search_api_index_message_library_index';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['label'] = 'Information requirement';
  $handler->display->display_options['fields']['title_1']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title_1']['alter']['path'] = 'message-library/threat/[field_message_threat_tid]#[nid] ';
  $handler->display->display_options['fields']['title_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title_1']['link_to_entity'] = 0;
  /* Field: Indexed Node: At risk group */
  $handler->display->display_options['fields']['field_message_group_risk']['id'] = 'field_message_group_risk';
  $handler->display->display_options['fields']['field_message_group_risk']['table'] = 'search_api_index_message_library_index';
  $handler->display->display_options['fields']['field_message_group_risk']['field'] = 'field_message_group_risk';
  $handler->display->display_options['fields']['field_message_group_risk']['exclude'] = TRUE;
  /* Field: Indexed Node: Target audience */
  $handler->display->display_options['fields']['field_message_audience']['id'] = 'field_message_audience';
  $handler->display->display_options['fields']['field_message_audience']['table'] = 'search_api_index_message_library_index';
  $handler->display->display_options['fields']['field_message_audience']['field'] = 'field_message_audience';
  $handler->display->display_options['fields']['field_message_audience']['exclude'] = TRUE;
  /* Field: Indexed Node: Message */
  $handler->display->display_options['fields']['field_message_group_mess']['id'] = 'field_message_group_mess';
  $handler->display->display_options['fields']['field_message_group_mess']['table'] = 'search_api_index_message_library_index';
  $handler->display->display_options['fields']['field_message_group_mess']['field'] = 'field_message_group_mess';
  /* Field: Indexed Node: Examples of Communication around this issue */
  $handler->display->display_options['fields']['field_message_example_communic']['id'] = 'field_message_example_communic';
  $handler->display->display_options['fields']['field_message_example_communic']['table'] = 'search_api_index_message_library_index';
  $handler->display->display_options['fields']['field_message_example_communic']['field'] = 'field_message_example_communic';
  $handler->display->display_options['fields']['field_message_example_communic']['label'] = 'Resources';
  $handler->display->display_options['fields']['field_message_example_communic']['element_label_colon'] = FALSE;
  /* Field: Indexed Node: Localized Message */
  $handler->display->display_options['fields']['field_message_localized']['id'] = 'field_message_localized';
  $handler->display->display_options['fields']['field_message_localized']['table'] = 'search_api_index_message_library_index';
  $handler->display->display_options['fields']['field_message_localized']['field'] = 'field_message_localized';
  $handler->display->display_options['fields']['field_message_localized']['link_to_entity'] = 1;
  $handler->display->display_options['fields']['field_message_localized']['view_mode'] = 'full';
  /* Field: Indexed Node: Edit URL */
  $handler->display->display_options['fields']['edit_url']['id'] = 'edit_url';
  $handler->display->display_options['fields']['edit_url']['table'] = 'search_api_index_message_library_index';
  $handler->display->display_options['fields']['edit_url']['field'] = 'edit_url';
  $handler->display->display_options['fields']['edit_url']['label'] = 'Edi';
  $handler->display->display_options['fields']['edit_url']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['edit_url']['alter']['text'] = 'Edit';
  $handler->display->display_options['fields']['edit_url']['link_to_entity'] = 0;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Indexed Node: Status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'search_api_index_message_library_index';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = array(
    0 => '0',
  );
  $handler->display->display_options['filters']['status']['group'] = 1;
  /* Filter criterion: Indexed Node: Threat */
  $handler->display->display_options['filters']['field_message_threat_1']['id'] = 'field_message_threat_1';
  $handler->display->display_options['filters']['field_message_threat_1']['table'] = 'search_api_index_message_library_index';
  $handler->display->display_options['filters']['field_message_threat_1']['field'] = 'field_message_threat';
  $handler->display->display_options['filters']['field_message_threat_1']['operator'] = 'not empty';
  $handler->display->display_options['filters']['field_message_threat_1']['value'] = array();
  $handler->display->display_options['filters']['field_message_threat_1']['group'] = 1;
  /* Filter criterion: Indexed Node: Content type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'search_api_index_message_library_index';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'message' => 'message',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  $handler->display->display_options['path'] = 'message-library/unpublished';

  /* Display: My Messages */
  $handler = $view->new_display('page', 'My Messages', 'page_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Message Library (My Messages)';
  $handler->display->display_options['display_description'] = 'My Messages';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Threat: Term ID (indexed) */
  $handler->display->display_options['fields']['field_message_threat_tid']['id'] = 'field_message_threat_tid';
  $handler->display->display_options['fields']['field_message_threat_tid']['table'] = 'search_api_index_message_library_index';
  $handler->display->display_options['fields']['field_message_threat_tid']['field'] = 'field_message_threat_tid';
  $handler->display->display_options['fields']['field_message_threat_tid']['exclude'] = TRUE;
  /* Field: Indexed Node: Node ID */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'search_api_index_message_library_index';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nid']['separator'] = '';
  $handler->display->display_options['fields']['nid']['link_to_entity'] = 0;
  /* Field: Threat: Issue (indexed) */
  $handler->display->display_options['fields']['field_message_threat_field_threat_category']['id'] = 'field_message_threat_field_threat_category';
  $handler->display->display_options['fields']['field_message_threat_field_threat_category']['table'] = 'search_api_index_message_library_index';
  $handler->display->display_options['fields']['field_message_threat_field_threat_category']['field'] = 'field_message_threat_field_threat_category';
  $handler->display->display_options['fields']['field_message_threat_field_threat_category']['label'] = 'Issue';
  /* Field: Indexed Node: Threat */
  $handler->display->display_options['fields']['field_message_threat']['id'] = 'field_message_threat';
  $handler->display->display_options['fields']['field_message_threat']['table'] = 'search_api_index_message_library_index';
  $handler->display->display_options['fields']['field_message_threat']['field'] = 'field_message_threat';
  $handler->display->display_options['fields']['field_message_threat']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_message_threat']['alter']['path'] = 'message-library/threat/[field_message_threat_tid]';
  $handler->display->display_options['fields']['field_message_threat']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_message_threat']['view_mode'] = 'full';
  /* Field: Indexed Node: Title */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'search_api_index_message_library_index';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['label'] = 'Information requirement';
  $handler->display->display_options['fields']['title_1']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title_1']['alter']['path'] = 'message-library/threat/[field_message_threat_tid]#[nid] ';
  $handler->display->display_options['fields']['title_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title_1']['link_to_entity'] = 0;
  /* Field: Indexed Node: At risk group */
  $handler->display->display_options['fields']['field_message_group_risk']['id'] = 'field_message_group_risk';
  $handler->display->display_options['fields']['field_message_group_risk']['table'] = 'search_api_index_message_library_index';
  $handler->display->display_options['fields']['field_message_group_risk']['field'] = 'field_message_group_risk';
  $handler->display->display_options['fields']['field_message_group_risk']['exclude'] = TRUE;
  /* Field: Indexed Node: Target audience */
  $handler->display->display_options['fields']['field_message_audience']['id'] = 'field_message_audience';
  $handler->display->display_options['fields']['field_message_audience']['table'] = 'search_api_index_message_library_index';
  $handler->display->display_options['fields']['field_message_audience']['field'] = 'field_message_audience';
  $handler->display->display_options['fields']['field_message_audience']['exclude'] = TRUE;
  /* Field: Indexed Node: Message */
  $handler->display->display_options['fields']['field_message_group_mess']['id'] = 'field_message_group_mess';
  $handler->display->display_options['fields']['field_message_group_mess']['table'] = 'search_api_index_message_library_index';
  $handler->display->display_options['fields']['field_message_group_mess']['field'] = 'field_message_group_mess';
  /* Field: Indexed Node: Examples of Communication around this issue */
  $handler->display->display_options['fields']['field_message_example_communic']['id'] = 'field_message_example_communic';
  $handler->display->display_options['fields']['field_message_example_communic']['table'] = 'search_api_index_message_library_index';
  $handler->display->display_options['fields']['field_message_example_communic']['field'] = 'field_message_example_communic';
  $handler->display->display_options['fields']['field_message_example_communic']['label'] = 'Resources';
  $handler->display->display_options['fields']['field_message_example_communic']['element_label_colon'] = FALSE;
  /* Field: Indexed Node: Localized Message */
  $handler->display->display_options['fields']['field_message_localized']['id'] = 'field_message_localized';
  $handler->display->display_options['fields']['field_message_localized']['table'] = 'search_api_index_message_library_index';
  $handler->display->display_options['fields']['field_message_localized']['field'] = 'field_message_localized';
  $handler->display->display_options['fields']['field_message_localized']['link_to_entity'] = 1;
  $handler->display->display_options['fields']['field_message_localized']['view_mode'] = 'full';
  /* Field: Indexed Node: Edit URL */
  $handler->display->display_options['fields']['edit_url']['id'] = 'edit_url';
  $handler->display->display_options['fields']['edit_url']['table'] = 'search_api_index_message_library_index';
  $handler->display->display_options['fields']['edit_url']['field'] = 'edit_url';
  $handler->display->display_options['fields']['edit_url']['label'] = 'Edit';
  $handler->display->display_options['fields']['edit_url']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['edit_url']['alter']['text'] = 'Edit';
  $handler->display->display_options['fields']['edit_url']['link_to_entity'] = 0;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Indexed Node: Author */
  $handler->display->display_options['arguments']['author']['id'] = 'author';
  $handler->display->display_options['arguments']['author']['table'] = 'search_api_index_message_library_index';
  $handler->display->display_options['arguments']['author']['field'] = 'author';
  $handler->display->display_options['arguments']['author']['default_action'] = 'default';
  $handler->display->display_options['arguments']['author']['default_argument_type'] = 'current_user';
  $handler->display->display_options['arguments']['author']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['author']['break_phrase'] = 0;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Indexed Node: Threat */
  $handler->display->display_options['filters']['field_message_threat_1']['id'] = 'field_message_threat_1';
  $handler->display->display_options['filters']['field_message_threat_1']['table'] = 'search_api_index_message_library_index';
  $handler->display->display_options['filters']['field_message_threat_1']['field'] = 'field_message_threat';
  $handler->display->display_options['filters']['field_message_threat_1']['operator'] = 'not empty';
  $handler->display->display_options['filters']['field_message_threat_1']['value'] = array();
  $handler->display->display_options['filters']['field_message_threat_1']['group'] = 1;
  /* Filter criterion: Indexed Node: Content type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'search_api_index_message_library_index';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'message' => 'message',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  $handler->display->display_options['path'] = 'message-library/mymessages';
  $translatables['message_library'] = array(
    t('Master'),
    t('Message Library'),
    t('more'),
    t('Search'),
    t('Reset Search'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('Search Summary'),
    t('<strong>@total</strong> records matched criteria.'),
    t('There is no result for this search. Your search might be too narrow. Click the remove link next to the criteria to expand the search, or click on the Reset Search button to remove all currently selected criteria.'),
    t('Threat'),
    t('Term ID (indexed)'),
    t('.'),
    t(','),
    t('Issue'),
    t('Information requirement'),
    t('At risk group'),
    t('Target audience'),
    t('Message'),
    t('Resources'),
    t('Localized Message'),
    t('Message Synonyms'),
    t('Quick Search'),
    t('Issues'),
    t('Issue (indexed)'),
    t('Search Page'),
    t('Feed'),
    t('Unpublished Messages'),
    t('Message Library (Unpublished Messages)'),
    t('Edi'),
    t('Edit'),
    t('My Messages'),
    t('Message Library (My Messages)'),
    t('All'),
  );
  $export['message_library'] = $view;

  $view = new view();
  $view->name = 'messsage_library_threat';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Messsage Library Threat';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['links'] = FALSE;
  /* Relationship: Nodequeue: Queue */
  $handler->display->display_options['relationships']['nodequeue_rel']['id'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['nodequeue_rel']['field'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['limit'] = 1;
  $handler->display->display_options['relationships']['nodequeue_rel']['queues'] = array(
    'message_library_threat' => 'message_library_threat',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: Has taxonomy term ID */
  $handler->display->display_options['arguments']['tid']['id'] = 'tid';
  $handler->display->display_options['arguments']['tid']['table'] = 'taxonomy_index';
  $handler->display->display_options['arguments']['tid']['field'] = 'tid';
  $handler->display->display_options['arguments']['tid']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['tid']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['tid']['title'] = '%1';
  $handler->display->display_options['arguments']['tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['tid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'message' => 'message',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'main_page');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['footer'] = FALSE;
  /* Footer: Message Library: Link to download rtf */
  $handler->display->display_options['footer']['link_rtf']['id'] = 'link_rtf';
  $handler->display->display_options['footer']['link_rtf']['table'] = 'message_library';
  $handler->display->display_options['footer']['link_rtf']['field'] = 'link_rtf';
  /* Footer: Message Library: Link to email rtf */
  $handler->display->display_options['footer']['link_email_rtf']['id'] = 'link_email_rtf';
  $handler->display->display_options['footer']['link_email_rtf']['table'] = 'message_library';
  $handler->display->display_options['footer']['link_email_rtf']['field'] = 'link_email_rtf';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Nodequeue: Queue */
  $handler->display->display_options['relationships']['nodequeue_rel']['id'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['nodequeue_rel']['field'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['limit'] = 1;
  $handler->display->display_options['relationships']['nodequeue_rel']['queues'] = array(
    'message_library_threat' => 'message_library_threat',
  );
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Nodequeue: Position */
  $handler->display->display_options['sorts']['position']['id'] = 'position';
  $handler->display->display_options['sorts']['position']['table'] = 'nodequeue_nodes';
  $handler->display->display_options['sorts']['position']['field'] = 'position';
  $handler->display->display_options['sorts']['position']['relationship'] = 'nodequeue_rel';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Has taxonomy term ID */
  $handler->display->display_options['arguments']['tid']['id'] = 'tid';
  $handler->display->display_options['arguments']['tid']['table'] = 'taxonomy_index';
  $handler->display->display_options['arguments']['tid']['field'] = 'tid';
  $handler->display->display_options['arguments']['tid']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['tid']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['tid']['title'] = '%1';
  $handler->display->display_options['arguments']['tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['tid']['summary_options']['items_per_page'] = '25';
  /* Contextual filter: Nodequeue: Subqueue reference */
  $handler->display->display_options['arguments']['reference']['id'] = 'reference';
  $handler->display->display_options['arguments']['reference']['table'] = 'nodequeue_subqueue';
  $handler->display->display_options['arguments']['reference']['field'] = 'reference';
  $handler->display->display_options['arguments']['reference']['relationship'] = 'nodequeue_rel';
  $handler->display->display_options['arguments']['reference']['default_action'] = 'default';
  $handler->display->display_options['arguments']['reference']['default_argument_type'] = 'php';
  $handler->display->display_options['arguments']['reference']['default_argument_options']['code'] = 'return arg(2);';
  $handler->display->display_options['arguments']['reference']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['reference']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['reference']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['reference']['limit'] = '0';
  $handler->display->display_options['path'] = 'message-library/threat/%';

  /* Display: Manage */
  $handler = $view->new_display('attachment', 'Manage', 'attachment_1');
  $handler->display->display_options['defaults']['group_by'] = FALSE;
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    30037204 => '30037204',
    200153887 => '200153887',
    52310416 => '52310416',
  );
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'field_message_threat' => 'field_message_threat',
    'nodequeue_all_subqueues' => 'nodequeue_all_subqueues',
  );
  $handler->display->display_options['row_options']['separator'] = ' | ';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Threat */
  $handler->display->display_options['fields']['field_message_threat']['id'] = 'field_message_threat';
  $handler->display->display_options['fields']['field_message_threat']['table'] = 'field_data_field_message_threat';
  $handler->display->display_options['fields']['field_message_threat']['field'] = 'field_message_threat';
  $handler->display->display_options['fields']['field_message_threat']['label'] = 'Edit Threat';
  $handler->display->display_options['fields']['field_message_threat']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_message_threat']['alter']['path'] = 'taxonomy/term/[field_message_threat-tid]/edit';
  $handler->display->display_options['fields']['field_message_threat']['alter']['replace_spaces'] = TRUE;
  $handler->display->display_options['fields']['field_message_threat']['alter']['path_case'] = 'lower';
  $handler->display->display_options['fields']['field_message_threat']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_message_threat']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Nodequeue: All subqueues */
  $handler->display->display_options['fields']['nodequeue_all_subqueues']['id'] = 'nodequeue_all_subqueues';
  $handler->display->display_options['fields']['nodequeue_all_subqueues']['table'] = 'node';
  $handler->display->display_options['fields']['nodequeue_all_subqueues']['field'] = 'nodequeue_all_subqueues';
  $handler->display->display_options['fields']['nodequeue_all_subqueues']['label'] = 'Reorder Messages';
  $handler->display->display_options['fields']['nodequeue_all_subqueues']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['nodequeue_all_subqueues']['link_to_queue'] = 1;
  $handler->display->display_options['fields']['nodequeue_all_subqueues']['limit'] = 0;
  $handler->display->display_options['fields']['nodequeue_all_subqueues']['queues'] = array(
    'message_library_threat' => 0,
  );
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Nodequeue: Subqueue ID */
  $handler->display->display_options['sorts']['sqid']['id'] = 'sqid';
  $handler->display->display_options['sorts']['sqid']['table'] = 'nodequeue_nodes';
  $handler->display->display_options['sorts']['sqid']['field'] = 'sqid';
  $handler->display->display_options['sorts']['sqid']['relationship'] = 'nodequeue_rel';
  $handler->display->display_options['sorts']['sqid']['order'] = 'DESC';
  $handler->display->display_options['displays'] = array(
    'main_page' => 'main_page',
    'default' => 0,
  );

  /* Display: Attachment */
  $handler = $view->new_display('attachment', 'Attachment', 'attachment_header');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['group_by'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['style_options']['columns'] = array(
    'field_threat_category' => 'field_threat_category',
    'field_threat_sector' => 'field_threat_sector',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'field_threat_category' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_threat_sector' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['override'] = FALSE;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: Taxonomy terms on node */
  $handler->display->display_options['relationships']['term_node_tid']['id'] = 'term_node_tid';
  $handler->display->display_options['relationships']['term_node_tid']['table'] = 'node';
  $handler->display->display_options['relationships']['term_node_tid']['field'] = 'term_node_tid';
  $handler->display->display_options['relationships']['term_node_tid']['label'] = 'threat';
  $handler->display->display_options['relationships']['term_node_tid']['vocabularies'] = array(
    'threat' => 'threat',
    'map_types' => 0,
    'at_risk_groups' => 0,
    'clusters' => 0,
    'coordination_hubs' => 0,
    'disaster_types' => 0,
    'display_properties' => 0,
    'document_types' => 0,
    'emergencies' => 0,
    'event_categories' => 0,
    'funding' => 0,
    'gallery_collections' => 0,
    'hazard' => 0,
    'information_type' => 0,
    'issues' => 0,
    'job_title' => 0,
    'locations' => 0,
    'organization_types' => 0,
    'organizations' => 0,
    'sector' => 0,
    'tags' => 0,
    'target_audience' => 0,
    'themes' => 0,
  );
  /* Relationship: Taxonomy term: Issue (field_threat_category) */
  $handler->display->display_options['relationships']['field_threat_category_tid']['id'] = 'field_threat_category_tid';
  $handler->display->display_options['relationships']['field_threat_category_tid']['table'] = 'field_data_field_threat_category';
  $handler->display->display_options['relationships']['field_threat_category_tid']['field'] = 'field_threat_category_tid';
  $handler->display->display_options['relationships']['field_threat_category_tid']['relationship'] = 'term_node_tid';
  $handler->display->display_options['relationships']['field_threat_category_tid']['label'] = 'issue';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Taxonomy term: Issue */
  $handler->display->display_options['fields']['field_threat_category']['id'] = 'field_threat_category';
  $handler->display->display_options['fields']['field_threat_category']['table'] = 'field_data_field_threat_category';
  $handler->display->display_options['fields']['field_threat_category']['field'] = 'field_threat_category';
  $handler->display->display_options['fields']['field_threat_category']['relationship'] = 'term_node_tid';
  $handler->display->display_options['fields']['field_threat_category']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_threat_category']['group_columns'] = array(
    'entity_id' => 'entity_id',
  );
  $handler->display->display_options['fields']['field_threat_category']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_threat_category']['multi_type'] = 'ul';
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = 'Sector';
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_value'] = '$issues_parent_list = array();
$threat_term = taxonomy_term_load($row->field_threat_category);
foreach ($threat_term->field_threat_category[\'und\'] as $key => $val){
$issue_parent = taxonomy_get_parents($val[\'tid\']);
foreach($issue_parent as $key => $val) {
$issues_parent_list[] = $val->name;
}
}
$result = array_unique($issues_parent_list);

$static[\'parent\'] = $result 
';
  $handler->display->display_options['fields']['php']['php_output'] = '<div class="item-list">
<ul>
<?php
foreach($static[\'parent\'] as $key => $val) {
echo("<li>" . $val . "</li>");
}
?>
</ul>
</div>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  $handler->display->display_options['displays'] = array(
    'main_page' => 'main_page',
    'default' => 0,
  );
  $translatables['messsage_library_threat'] = array(
    t('Master'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('queue'),
    t('All'),
    t('%1'),
    t('Page'),
    t('Manage'),
    t('Edit Threat'),
    t('Reorder Messages'),
    t('Attachment'),
    t('threat'),
    t('issue'),
    t('Issue'),
    t('Sector'),
  );
  $export['messsage_library_threat'] = $view;

  return $export;
}
