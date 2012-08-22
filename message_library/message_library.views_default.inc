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
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
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
  /* Relationship: Broken/missing handler */
  $handler->display->display_options['relationships']['field_threat']['id'] = 'field_threat';
  $handler->display->display_options['relationships']['field_threat']['table'] = 'search_api_index_node_search';
  $handler->display->display_options['relationships']['field_threat']['field'] = 'field_threat';
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_issue']['id'] = 'field_issue';
  $handler->display->display_options['fields']['field_issue']['table'] = 'entity_node';
  $handler->display->display_options['fields']['field_issue']['field'] = 'field_issue';
  $handler->display->display_options['fields']['field_issue']['relationship'] = 'field_threat';
  $handler->display->display_options['fields']['field_issue']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_issue']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_issue']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_issue']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_issue']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_issue']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_issue']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_issue']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_issue']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_issue']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_issue']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_issue']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_issue']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_issue']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_issue']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_issue']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_issue']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_issue']['hide_alter_empty'] = 1;
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
  /* Field: Node: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'entity_node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'field_threat';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['title']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['title']['link_to_entity'] = 0;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_threat']['id'] = 'field_threat';
  $handler->display->display_options['fields']['field_threat']['table'] = 'search_api_index_node_search';
  $handler->display->display_options['fields']['field_threat']['field'] = 'field_threat';
  $handler->display->display_options['fields']['field_threat']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_threat']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_threat']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_threat']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_threat']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_threat']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_threat']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_threat']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_threat']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_threat']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_threat']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_threat']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_threat']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_threat']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_threat']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_threat']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_threat']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_threat']['hide_alter_empty'] = 1;
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
  $handler->display->display_options['fields']['title_1']['link_to_entity'] = 0;
  /* Field: Node: Node ID */
  $handler->display->display_options['fields']['nid_1']['id'] = 'nid_1';
  $handler->display->display_options['fields']['nid_1']['table'] = 'entity_node';
  $handler->display->display_options['fields']['nid_1']['field'] = 'nid';
  $handler->display->display_options['fields']['nid_1']['relationship'] = 'field_threat';
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
  $handler->display->display_options['fields']['nid_1']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['nid_1']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['nid_1']['hide_empty'] = 0;
  $handler->display->display_options['fields']['nid_1']['empty_zero'] = 0;
  $handler->display->display_options['fields']['nid_1']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['nid_1']['format_plural'] = 0;
  $handler->display->display_options['fields']['nid_1']['link_to_entity'] = 0;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_message']['id'] = 'field_message';
  $handler->display->display_options['fields']['field_message']['table'] = 'search_api_index_node_search';
  $handler->display->display_options['fields']['field_message']['field'] = 'field_message';
  $handler->display->display_options['fields']['field_message']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_message']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_message']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_message']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_message']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_message']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_message']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_message']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_message']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_message']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_message']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_message']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_message']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_message']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_message']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_message']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_message']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_message']['hide_alter_empty'] = 1;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_com_example']['id'] = 'field_com_example';
  $handler->display->display_options['fields']['field_com_example']['table'] = 'search_api_index_node_search';
  $handler->display->display_options['fields']['field_com_example']['field'] = 'field_com_example';
  $handler->display->display_options['fields']['field_com_example']['label'] = 'Resources';
  $handler->display->display_options['fields']['field_com_example']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_com_example']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_com_example']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_com_example']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_com_example']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_com_example']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_com_example']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_com_example']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_com_example']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_com_example']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_com_example']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_com_example']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_com_example']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_com_example']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_com_example']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_com_example']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_com_example']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_com_example']['hide_alter_empty'] = 1;
  /* Field: Node: Node ID */
  $handler->display->display_options['fields']['nid_2']['id'] = 'nid_2';
  $handler->display->display_options['fields']['nid_2']['table'] = 'entity_node';
  $handler->display->display_options['fields']['nid_2']['field'] = 'nid';
  $handler->display->display_options['fields']['nid_2']['relationship'] = 'field_threat';
  $handler->display->display_options['fields']['nid_2']['label'] = '';
  $handler->display->display_options['fields']['nid_2']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid_2']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['nid_2']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['nid_2']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['nid_2']['alter']['external'] = 0;
  $handler->display->display_options['fields']['nid_2']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['nid_2']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['nid_2']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['nid_2']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['nid_2']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['nid_2']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['nid_2']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['nid_2']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['nid_2']['alter']['html'] = 0;
  $handler->display->display_options['fields']['nid_2']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nid_2']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['nid_2']['hide_empty'] = 0;
  $handler->display->display_options['fields']['nid_2']['empty_zero'] = 0;
  $handler->display->display_options['fields']['nid_2']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['nid_2']['format_plural'] = 0;
  $handler->display->display_options['fields']['nid_2']['link_to_entity'] = 0;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'message_library';
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
    t('field_threat'),
    t('Broken handler entity_node.field_issue'),
    t('.'),
    t(','),
    t('Title'),
    t('Broken handler search_api_index_node_search.field_threat'),
    t('Information requirement'),
    t('Node ID'),
    t('Broken handler search_api_index_node_search.field_message'),
    t('Resources'),
    t('Page'),
  );
  $export['message_library'] = $view;

  return $export;
}
