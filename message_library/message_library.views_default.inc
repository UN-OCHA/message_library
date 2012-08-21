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
  $view->base_table = 'node';
  $view->human_name = 'Message Library';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Search';
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = 0;
  $handler->display->display_options['exposed_form']['options']['autosubmit_hide'] = 1;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
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
  /* Relationship: Entity Reference: Referencing entity */
  $handler->display->display_options['relationships']['reverse_field_reference_msg_node']['id'] = 'reverse_field_reference_msg_node';
  $handler->display->display_options['relationships']['reverse_field_reference_msg_node']['table'] = 'node';
  $handler->display->display_options['relationships']['reverse_field_reference_msg_node']['field'] = 'reverse_field_reference_msg_node';
  $handler->display->display_options['relationships']['reverse_field_reference_msg_node']['required'] = 1;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Information requirement';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['relationship'] = 'reverse_field_reference_msg_node';
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
  $handler->display->display_options['fields']['nid']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['nid']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['nid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['nid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['nid']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['nid']['link_to_node'] = 0;
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['relationship'] = 'reverse_field_reference_msg_node';
  $handler->display->display_options['fields']['path']['exclude'] = TRUE;
  $handler->display->display_options['fields']['path']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['path']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['path']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['path']['alter']['external'] = 0;
  $handler->display->display_options['fields']['path']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['path']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['path']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['path']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['path']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['path']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['path']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['path']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['path']['alter']['html'] = 0;
  $handler->display->display_options['fields']['path']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['path']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['path']['hide_empty'] = 0;
  $handler->display->display_options['fields']['path']['empty_zero'] = 0;
  $handler->display->display_options['fields']['path']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['path']['absolute'] = 0;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid_1']['id'] = 'nid_1';
  $handler->display->display_options['fields']['nid_1']['table'] = 'node';
  $handler->display->display_options['fields']['nid_1']['field'] = 'nid';
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
  $handler->display->display_options['fields']['nid_1']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['nid_1']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['nid_1']['hide_empty'] = 0;
  $handler->display->display_options['fields']['nid_1']['empty_zero'] = 0;
  $handler->display->display_options['fields']['nid_1']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['nid_1']['link_to_node'] = 0;
  /* Field: Content: Message */
  $handler->display->display_options['fields']['field_message']['id'] = 'field_message';
  $handler->display->display_options['fields']['field_message']['table'] = 'field_data_field_message';
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
  $handler->display->display_options['fields']['field_message']['field_api_classes'] = 0;
  /* Field: Content: Threat */
  $handler->display->display_options['fields']['field_threat']['id'] = 'field_threat';
  $handler->display->display_options['fields']['field_threat']['table'] = 'field_data_field_threat';
  $handler->display->display_options['fields']['field_threat']['field'] = 'field_threat';
  $handler->display->display_options['fields']['field_threat']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_threat']['alter']['make_link'] = 1;
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
  $handler->display->display_options['fields']['field_threat']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_threat']['field_api_classes'] = 0;
  /* Field: Content: At risk group */
  $handler->display->display_options['fields']['field_at_risk_group']['id'] = 'field_at_risk_group';
  $handler->display->display_options['fields']['field_at_risk_group']['table'] = 'field_data_field_at_risk_group';
  $handler->display->display_options['fields']['field_at_risk_group']['field'] = 'field_at_risk_group';
  $handler->display->display_options['fields']['field_at_risk_group']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_at_risk_group']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_at_risk_group']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_at_risk_group']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_at_risk_group']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_at_risk_group']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_at_risk_group']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_at_risk_group']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_at_risk_group']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_at_risk_group']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_at_risk_group']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_at_risk_group']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_at_risk_group']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_at_risk_group']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_at_risk_group']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_at_risk_group']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_at_risk_group']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_at_risk_group']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_at_risk_group']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_at_risk_group']['group_rows'] = 1;
  $handler->display->display_options['fields']['field_at_risk_group']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_at_risk_group']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_at_risk_group']['delta_first_last'] = 0;
  $handler->display->display_options['fields']['field_at_risk_group']['field_api_classes'] = 0;
  /* Field: Content: Examples of Communication around this issue */
  $handler->display->display_options['fields']['field_com_example']['id'] = 'field_com_example';
  $handler->display->display_options['fields']['field_com_example']['table'] = 'field_data_field_com_example';
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
  $handler->display->display_options['fields']['field_com_example']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_com_example']['field_api_classes'] = 0;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'node';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['relationship'] = 'reverse_field_reference_msg_node';
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
  $handler->display->display_options['fields']['title_1']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['title_1']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title_1']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title_1']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title_1']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['title_1']['link_to_node'] = 1;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'main_page');
  $handler->display->display_options['defaults']['filters'] = FALSE;
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
  /* Filter criterion: Content: Hazard (field_hazard) */
  $handler->display->display_options['filters']['field_hazard_tid']['id'] = 'field_hazard_tid';
  $handler->display->display_options['filters']['field_hazard_tid']['table'] = 'field_data_field_hazard';
  $handler->display->display_options['filters']['field_hazard_tid']['field'] = 'field_hazard_tid';
  $handler->display->display_options['filters']['field_hazard_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_hazard_tid']['expose']['operator_id'] = 'field_hazard_tid_op';
  $handler->display->display_options['filters']['field_hazard_tid']['expose']['label'] = 'Hazard ';
  $handler->display->display_options['filters']['field_hazard_tid']['expose']['operator'] = 'field_hazard_tid_op';
  $handler->display->display_options['filters']['field_hazard_tid']['expose']['identifier'] = 'field_hazard_tid';
  $handler->display->display_options['filters']['field_hazard_tid']['expose']['reduce'] = 0;
  $handler->display->display_options['filters']['field_hazard_tid']['reduce_duplicates'] = 0;
  $handler->display->display_options['filters']['field_hazard_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_hazard_tid']['vocabulary'] = 'hazard';
  $handler->display->display_options['filters']['field_hazard_tid']['error_message'] = 1;
  /* Filter criterion: Content: At risk group (field_at_risk_group) */
  $handler->display->display_options['filters']['field_at_risk_group_tid']['id'] = 'field_at_risk_group_tid';
  $handler->display->display_options['filters']['field_at_risk_group_tid']['table'] = 'field_data_field_at_risk_group';
  $handler->display->display_options['filters']['field_at_risk_group_tid']['field'] = 'field_at_risk_group_tid';
  $handler->display->display_options['filters']['field_at_risk_group_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_at_risk_group_tid']['expose']['operator_id'] = 'field_at_risk_group_tid_op';
  $handler->display->display_options['filters']['field_at_risk_group_tid']['expose']['label'] = 'At risk group';
  $handler->display->display_options['filters']['field_at_risk_group_tid']['expose']['operator'] = 'field_at_risk_group_tid_op';
  $handler->display->display_options['filters']['field_at_risk_group_tid']['expose']['identifier'] = 'field_at_risk_group_tid';
  $handler->display->display_options['filters']['field_at_risk_group_tid']['expose']['reduce'] = 0;
  $handler->display->display_options['filters']['field_at_risk_group_tid']['reduce_duplicates'] = 0;
  $handler->display->display_options['filters']['field_at_risk_group_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_at_risk_group_tid']['vocabulary'] = 'at_risk_groups';
  $handler->display->display_options['filters']['field_at_risk_group_tid']['hierarchy'] = 1;
  $handler->display->display_options['filters']['field_at_risk_group_tid']['error_message'] = 1;
  /* Filter criterion: Content: Target audience (field_target_audience) */
  $handler->display->display_options['filters']['field_target_audience_tid']['id'] = 'field_target_audience_tid';
  $handler->display->display_options['filters']['field_target_audience_tid']['table'] = 'field_data_field_target_audience';
  $handler->display->display_options['filters']['field_target_audience_tid']['field'] = 'field_target_audience_tid';
  $handler->display->display_options['filters']['field_target_audience_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_target_audience_tid']['expose']['operator_id'] = 'field_target_audience_tid_op';
  $handler->display->display_options['filters']['field_target_audience_tid']['expose']['label'] = 'Target audience';
  $handler->display->display_options['filters']['field_target_audience_tid']['expose']['operator'] = 'field_target_audience_tid_op';
  $handler->display->display_options['filters']['field_target_audience_tid']['expose']['identifier'] = 'field_target_audience_tid';
  $handler->display->display_options['filters']['field_target_audience_tid']['expose']['reduce'] = 0;
  $handler->display->display_options['filters']['field_target_audience_tid']['reduce_duplicates'] = 0;
  $handler->display->display_options['filters']['field_target_audience_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_target_audience_tid']['vocabulary'] = 'target_audience';
  $handler->display->display_options['filters']['field_target_audience_tid']['error_message'] = 1;
  $handler->display->display_options['path'] = 'message_library';
  $translatables['message_library'] = array(
    t('Master'),
    t('more'),
    t('Search'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('Content referencing Content from field_reference_msg'),
    t('Information requirement'),
    t('Nid'),
    t('Path'),
    t('Message'),
    t('Threat'),
    t('At risk group'),
    t('Resources'),
    t('Title'),
    t('Page'),
    t('Hazard '),
    t('Target audience'),
  );
  $export['message_library'] = $view;

  return $export;
}
