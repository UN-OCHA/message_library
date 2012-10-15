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
  $handler->display->display_options['exposed_form']['options']['autosubmit_hide'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'nid_1' => 'nid_1',
    'url' => 'url',
    'nid' => 'nid',
    'field_threat_category' => 'field_threat_category',
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
    'nid_1' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'url' => array(
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
    'field_threat_category' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_message_threat' => array(
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
  /* Field: Indexed Node: Node ID */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'search_api_index_message_library_index';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Threat: Issue (indexed) */
  $handler->display->display_options['fields']['field_message_threat_field_threat_category']['id'] = 'field_message_threat_field_threat_category';
  $handler->display->display_options['fields']['field_message_threat_field_threat_category']['table'] = 'search_api_index_message_library_index';
  $handler->display->display_options['fields']['field_message_threat_field_threat_category']['field'] = 'field_message_threat_field_threat_category';
  $handler->display->display_options['fields']['field_message_threat_field_threat_category']['label'] = 'Issue';
  $handler->display->display_options['fields']['field_message_threat_field_threat_category']['link_to_entity'] = 1;
  $handler->display->display_options['fields']['field_message_threat_field_threat_category']['view_mode'] = 'full';
  /* Field: Indexed Node: Threat */
  $handler->display->display_options['fields']['field_message_threat']['id'] = 'field_message_threat';
  $handler->display->display_options['fields']['field_message_threat']['table'] = 'search_api_index_message_library_index';
  $handler->display->display_options['fields']['field_message_threat']['field'] = 'field_message_threat';
  /* Field: Indexed Node: Title */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'search_api_index_message_library_index';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['label'] = 'Information requirement';
  $handler->display->display_options['fields']['title_1']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title_1']['alter']['path'] = '[url]#[nid]';
  $handler->display->display_options['fields']['title_1']['element_label_colon'] = FALSE;
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
  /* Field: Indexed Node: Websites */
  $handler->display->display_options['fields']['field_message_url']['id'] = 'field_message_url';
  $handler->display->display_options['fields']['field_message_url']['table'] = 'search_api_index_message_library_index';
  $handler->display->display_options['fields']['field_message_url']['field'] = 'field_message_url';
  $handler->display->display_options['fields']['field_message_url']['exclude'] = TRUE;
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
    1 => 0,
    6 => 0,
    5 => 0,
    4 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['search_api_views_fulltext']['fields'] = array(
    'title' => 'title',
    'field_message_group_mess' => 'field_message_group_mess',
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
  $handler->display->display_options['filters']['field_message_threat_field_threat_category']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    5 => 0,
    4 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['field_message_threat_field_threat_category']['expose']['reduce'] = 0;
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
    1 => 0,
    6 => 0,
    5 => 0,
    4 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['field_message_group_risk']['expose']['reduce'] = 0;
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
  $handler->display->display_options['filters']['field_message_audience']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    5 => 0,
    4 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['field_message_audience']['expose']['reduce'] = 0;
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
    1 => 0,
    6 => 0,
    5 => 0,
    4 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['field_message_threat']['expose']['reduce'] = 0;

  /* Display: Search Page */
  $handler = $view->new_display('page', 'Search Page', 'search_page');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['path'] = 'message-library';

  /* Display: Edit Page */
  $handler = $view->new_display('page', 'Edit Page', 'edit_page');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['path'] = 'edit-message-library';

  /* Display: Feed */
  $handler = $view->new_display('page', 'Feed', 'feed');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['path'] = 'message-library/export';
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
    t('.'),
    t(','),
    t('Issue'),
    t('Threat'),
    t('Information requirement'),
    t('At risk group'),
    t('Target audience'),
    t('Message'),
    t('Resources'),
    t('Websites'),
    t('Quick Search'),
    t('Issues'),
    t('Search Page'),
    t('Edit Page'),
    t('Feed'),
  );
  $export['message_library'] = $view;

  return $export;
}
