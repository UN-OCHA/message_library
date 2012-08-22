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

  $view = new view;
  $view->name = 'message_library';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'search_api_index_node_search';
  $view->human_name = 'Message Library';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Message Library';
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = 0;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'nid' => 'nid',
    'title' => 'title',
    'title_1' => 'title_1',
    'nid_1' => 'nid_1',
    'field_threat' => 'field_threat',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'nid' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title_1' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nid_1' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_threat' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['override'] = 1;
  $handler->display->display_options['style_options']['sticky'] = 0;
  $handler->display->display_options['style_options']['empty_table'] = 0;
  /* Header: Global: Result summary */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  $handler->display->display_options['header']['result']['empty'] = FALSE;
  $handler->display->display_options['header']['result']['content'] = '@total records matched criteria.
';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = FALSE;
  $handler->display->display_options['empty']['area']['content'] = 'There is no result for this search. Your search might be too narrow. Click the remove link next to the criteria to expand the search, or click on the Reset Search button to remove all currently selected criteria.';
  $handler->display->display_options['empty']['area']['format'] = 'simple';
  $handler->display->display_options['empty']['area']['tokenize'] = 0;
  /* Relationship: Indexed Node: Threat */
  $handler->display->display_options['relationships']['field_message_threat']['id'] = 'field_message_threat';
  $handler->display->display_options['relationships']['field_message_threat']['table'] = 'search_api_index_node_search';
  $handler->display->display_options['relationships']['field_message_threat']['field'] = 'field_message_threat';
  /* Field: Node: Node ID */
  $handler->display->display_options['fields']['nid_1']['id'] = 'nid_1';
  $handler->display->display_options['fields']['nid_1']['table'] = 'entity_node';
  $handler->display->display_options['fields']['nid_1']['field'] = 'nid';
  $handler->display->display_options['fields']['nid_1']['relationship'] = 'field_message_threat';
  $handler->display->display_options['fields']['nid_1']['label'] = '';
  $handler->display->display_options['fields']['nid_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid_1']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['nid_1']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['nid_1']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['nid_1']['alter']['external'] = 0;
  $handler->display->display_options['fields']['nid_1']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['nid_1']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['nid_1']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['nid_1']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['nid_1']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['nid_1']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['nid_1']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['nid_1']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['nid_1']['alter']['html'] = 0;
  $handler->display->display_options['fields']['nid_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nid_1']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['nid_1']['hide_empty'] = 0;
  $handler->display->display_options['fields']['nid_1']['empty_zero'] = 0;
  $handler->display->display_options['fields']['nid_1']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['nid_1']['separator'] = '';
  $handler->display->display_options['fields']['nid_1']['format_plural'] = 0;
  $handler->display->display_options['fields']['nid_1']['link_to_entity'] = 0;
  /* Field: Node: URL */
  $handler->display->display_options['fields']['url']['id'] = 'url';
  $handler->display->display_options['fields']['url']['table'] = 'entity_node';
  $handler->display->display_options['fields']['url']['field'] = 'url';
  $handler->display->display_options['fields']['url']['relationship'] = 'field_message_threat';
  $handler->display->display_options['fields']['url']['label'] = 'Threat URL';
  $handler->display->display_options['fields']['url']['exclude'] = TRUE;
  $handler->display->display_options['fields']['url']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['url']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['url']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['url']['alter']['external'] = 0;
  $handler->display->display_options['fields']['url']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['url']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['url']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['url']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['url']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['url']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['url']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['url']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['url']['alter']['html'] = 0;
  $handler->display->display_options['fields']['url']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['url']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['url']['hide_empty'] = 0;
  $handler->display->display_options['fields']['url']['empty_zero'] = 0;
  $handler->display->display_options['fields']['url']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['url']['display_as_link'] = 1;
  $handler->display->display_options['fields']['url']['link_to_entity'] = 0;
  /* Field: Indexed Node: Node ID */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'search_api_index_node_search';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['external'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nid']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['nid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['nid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['nid']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['nid']['format_plural'] = 0;
  $handler->display->display_options['fields']['nid']['link_to_entity'] = 0;
  /* Field: Node: Issue */
  $handler->display->display_options['fields']['field_threat_category']['id'] = 'field_threat_category';
  $handler->display->display_options['fields']['field_threat_category']['table'] = 'entity_node';
  $handler->display->display_options['fields']['field_threat_category']['field'] = 'field_threat_category';
  $handler->display->display_options['fields']['field_threat_category']['relationship'] = 'field_message_threat';
  $handler->display->display_options['fields']['field_threat_category']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_threat_category']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_threat_category']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_threat_category']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_threat_category']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_threat_category']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_threat_category']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_threat_category']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_threat_category']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_threat_category']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_threat_category']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_threat_category']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_threat_category']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_threat_category']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_threat_category']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_threat_category']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_threat_category']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_threat_category']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_threat_category']['list']['mode'] = 'first';
  $handler->display->display_options['fields']['field_threat_category']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_threat_category']['view_mode'] = 'full';
  /* Field: Indexed Node: Threat */
  $handler->display->display_options['fields']['field_message_threat']['id'] = 'field_message_threat';
  $handler->display->display_options['fields']['field_message_threat']['table'] = 'search_api_index_node_search';
  $handler->display->display_options['fields']['field_message_threat']['field'] = 'field_message_threat';
  $handler->display->display_options['fields']['field_message_threat']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_message_threat']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_message_threat']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_message_threat']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_message_threat']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_message_threat']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_message_threat']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_message_threat']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_message_threat']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_message_threat']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_message_threat']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_message_threat']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_message_threat']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_message_threat']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_message_threat']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_message_threat']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_message_threat']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_message_threat']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_message_threat']['link_to_entity'] = 1;
  $handler->display->display_options['fields']['field_message_threat']['view_mode'] = 'full';
  /* Field: Indexed Node: Title */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'search_api_index_node_search';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['label'] = 'Information requirement';
  $handler->display->display_options['fields']['title_1']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title_1']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title_1']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title_1']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title_1']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title_1']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['title_1']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title_1']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['title_1']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['title_1']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['title_1']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title_1']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title_1']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title_1']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['title_1']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title_1']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title_1']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title_1']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['title_1']['link_to_entity'] = 1;
  /* Field: Indexed Node: At risk group */
  $handler->display->display_options['fields']['field_message_group_risk']['id'] = 'field_message_group_risk';
  $handler->display->display_options['fields']['field_message_group_risk']['table'] = 'search_api_index_node_search';
  $handler->display->display_options['fields']['field_message_group_risk']['field'] = 'field_message_group_risk';
  $handler->display->display_options['fields']['field_message_group_risk']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_message_group_risk']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_message_group_risk']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_message_group_risk']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_message_group_risk']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_message_group_risk']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_message_group_risk']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_message_group_risk']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_message_group_risk']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_message_group_risk']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_message_group_risk']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_message_group_risk']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_message_group_risk']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_message_group_risk']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_message_group_risk']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_message_group_risk']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_message_group_risk']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_message_group_risk']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_message_group_risk']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_message_group_risk']['link_to_entity'] = 1;
  $handler->display->display_options['fields']['field_message_group_risk']['view_mode'] = 'full';
  /* Field: Indexed Node: Target audience */
  $handler->display->display_options['fields']['field_message_audience']['id'] = 'field_message_audience';
  $handler->display->display_options['fields']['field_message_audience']['table'] = 'search_api_index_node_search';
  $handler->display->display_options['fields']['field_message_audience']['field'] = 'field_message_audience';
  $handler->display->display_options['fields']['field_message_audience']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_message_audience']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_message_audience']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_message_audience']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_message_audience']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_message_audience']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_message_audience']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_message_audience']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_message_audience']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_message_audience']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_message_audience']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_message_audience']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_message_audience']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_message_audience']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_message_audience']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_message_audience']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_message_audience']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_message_audience']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_message_audience']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_message_audience']['link_to_entity'] = 1;
  $handler->display->display_options['fields']['field_message_audience']['view_mode'] = 'full';
  /* Field: Indexed Node: Message */
  $handler->display->display_options['fields']['field_message_group_mess']['id'] = 'field_message_group_mess';
  $handler->display->display_options['fields']['field_message_group_mess']['table'] = 'search_api_index_node_search';
  $handler->display->display_options['fields']['field_message_group_mess']['field'] = 'field_message_group_mess';
  $handler->display->display_options['fields']['field_message_group_mess']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_message_group_mess']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_message_group_mess']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_message_group_mess']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_message_group_mess']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_message_group_mess']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_message_group_mess']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_message_group_mess']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_message_group_mess']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_message_group_mess']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_message_group_mess']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_message_group_mess']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_message_group_mess']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_message_group_mess']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_message_group_mess']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_message_group_mess']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_message_group_mess']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_message_group_mess']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_message_group_mess']['field_api_classes'] = 0;
  /* Field: Indexed Node: Examples of Communication around this issue */
  $handler->display->display_options['fields']['field_message_example_communic']['id'] = 'field_message_example_communic';
  $handler->display->display_options['fields']['field_message_example_communic']['table'] = 'search_api_index_node_search';
  $handler->display->display_options['fields']['field_message_example_communic']['field'] = 'field_message_example_communic';
  $handler->display->display_options['fields']['field_message_example_communic']['label'] = 'Resources';
  $handler->display->display_options['fields']['field_message_example_communic']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_message_example_communic']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_message_example_communic']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_message_example_communic']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_message_example_communic']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_message_example_communic']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_message_example_communic']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_message_example_communic']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_message_example_communic']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_message_example_communic']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_message_example_communic']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_message_example_communic']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_message_example_communic']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_message_example_communic']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_message_example_communic']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_message_example_communic']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_message_example_communic']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_message_example_communic']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_message_example_communic']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_message_example_communic']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_message_example_communic']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_message_example_communic']['delta_first_last'] = 0;
  $handler->display->display_options['fields']['field_message_example_communic']['field_api_classes'] = 0;
  /* Field: Indexed Node: Websites */
  $handler->display->display_options['fields']['field_message_url']['id'] = 'field_message_url';
  $handler->display->display_options['fields']['field_message_url']['table'] = 'search_api_index_node_search';
  $handler->display->display_options['fields']['field_message_url']['field'] = 'field_message_url';
  $handler->display->display_options['fields']['field_message_url']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_message_url']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_message_url']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_message_url']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_message_url']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_message_url']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_message_url']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_message_url']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_message_url']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_message_url']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_message_url']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_message_url']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_message_url']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_message_url']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_message_url']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_message_url']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_message_url']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_message_url']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_message_url']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_message_url']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_message_url']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_message_url']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_message_url']['delta_first_last'] = 0;
  $handler->display->display_options['fields']['field_message_url']['field_api_classes'] = 0;
  /* Filter criterion: Search: Fulltext search */
  $handler->display->display_options['filters']['search_api_views_fulltext']['id'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['table'] = 'search_api_index_node_search';
  $handler->display->display_options['filters']['search_api_views_fulltext']['field'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['exposed'] = TRUE;
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator_id'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['label'] = 'Quick Search';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['identifier'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['fields'] = array(
    'field_humprofile_source' => 'field_humprofile_source',
    'field_message_group_risk_comment' => 'field_message_group_risk_comment',
    'field_message_target_comment' => 'field_message_target_comment',
    'field_message_sensitivity_messag' => 'field_message_sensitivity_messag',
    'field_message_sensitivity_questi' => 'field_message_sensitivity_questi',
    'field_message_sensitivity_causes' => 'field_message_sensitivity_causes',
    'field_message_group_mess' => 'field_message_group_mess',
  );
  /* Filter criterion: Indexed Node: Issue */
  $handler->display->display_options['filters']['field_threat_category_1']['id'] = 'field_threat_category_1';
  $handler->display->display_options['filters']['field_threat_category_1']['table'] = 'search_api_index_node_search';
  $handler->display->display_options['filters']['field_threat_category_1']['field'] = 'field_threat_category';
  $handler->display->display_options['filters']['field_threat_category_1']['value'] = array();
  $handler->display->display_options['filters']['field_threat_category_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_threat_category_1']['expose']['operator_id'] = 'field_threat_category_1_op';
  $handler->display->display_options['filters']['field_threat_category_1']['expose']['label'] = 'Issues';
  $handler->display->display_options['filters']['field_threat_category_1']['expose']['operator'] = 'field_threat_category_1_op';
  $handler->display->display_options['filters']['field_threat_category_1']['expose']['identifier'] = 'field_threat_category_1';
  $handler->display->display_options['filters']['field_threat_category_1']['expose']['reduce'] = 0;
  /* Filter criterion: Indexed Node: At risk group */
  $handler->display->display_options['filters']['field_message_group_risk']['id'] = 'field_message_group_risk';
  $handler->display->display_options['filters']['field_message_group_risk']['table'] = 'search_api_index_node_search';
  $handler->display->display_options['filters']['field_message_group_risk']['field'] = 'field_message_group_risk';
  $handler->display->display_options['filters']['field_message_group_risk']['value'] = array();
  $handler->display->display_options['filters']['field_message_group_risk']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_message_group_risk']['expose']['operator_id'] = 'field_message_group_risk_op';
  $handler->display->display_options['filters']['field_message_group_risk']['expose']['label'] = 'At risk group';
  $handler->display->display_options['filters']['field_message_group_risk']['expose']['operator'] = 'field_message_group_risk_op';
  $handler->display->display_options['filters']['field_message_group_risk']['expose']['identifier'] = 'field_message_group_risk';
  $handler->display->display_options['filters']['field_message_group_risk']['expose']['reduce'] = 0;
  /* Filter criterion: Indexed Node: Target audience */
  $handler->display->display_options['filters']['field_message_audience']['id'] = 'field_message_audience';
  $handler->display->display_options['filters']['field_message_audience']['table'] = 'search_api_index_node_search';
  $handler->display->display_options['filters']['field_message_audience']['field'] = 'field_message_audience';
  $handler->display->display_options['filters']['field_message_audience']['value'] = array();
  $handler->display->display_options['filters']['field_message_audience']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_message_audience']['expose']['operator_id'] = 'field_message_audience_op';
  $handler->display->display_options['filters']['field_message_audience']['expose']['label'] = 'Target audience';
  $handler->display->display_options['filters']['field_message_audience']['expose']['operator'] = 'field_message_audience_op';
  $handler->display->display_options['filters']['field_message_audience']['expose']['identifier'] = 'field_message_audience';
  $handler->display->display_options['filters']['field_message_audience']['expose']['reduce'] = 0;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'search_page');
  $handler->display->display_options['path'] = 'message-library';
  $translatables['message_library'] = array(
    t('Master'),
    t('Message Library'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('@total records matched criteria.
'),
    t('There is no result for this search. Your search might be too narrow. Click the remove link next to the criteria to expand the search, or click on the Reset Search button to remove all currently selected criteria.'),
    t('Threat'),
    t('.'),
    t('Threat URL'),
    t(','),
    t('Issue'),
    t('Information requirement'),
    t('At risk group'),
    t('Target audience'),
    t('Message'),
    t('Resources'),
    t('Websites'),
    t('Quick Search'),
    t('Issues'),
    t('Page'),
  );
  $export['message_library'] = $view;

  return $export;
}
