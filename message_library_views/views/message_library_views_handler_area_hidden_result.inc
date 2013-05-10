<?php

/**
 * @file
 */

/**
 * Views area handler.
 */
class message_library_views_handler_area_hidden_result extends views_handler_area {

  function option_definition() {
    $options = parent::option_definition();

    return $options;
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
  }

  function render($empty = FALSE) {
    $output = '';

    // [Legacy code].
    $arrayThreat = array();
    $arrayMessage = array();

    // Get total.
    $total = $this->view->total_rows;

    // Get all results, with Search API.
    if (!empty($total)) {
      $query = $this->query;
      if (!empty($query) && ($query instanceof SearchApiViewsQuery)) {
        $api_query = clone $query->getSearchApiQuery();
        $api_query->range(NULL, NULL);
        $result = $api_query->execute();
        if (!empty($result['results'])) {
          // Load all the entities.
          // @see EntityFieldHandlerHelper::pre_render().
          $entities = entity_load($query->getIndex()->item_type, array_keys($result['results']));
          foreach ($entities as $node) {
            $arrayMessage[] = $node->nid;
            if (!empty($node->field_message_threat['und'][0]['target_id'])) {
              $arrayThreat[] = $node->field_message_threat['und'][0]['target_id'];
            }
          }

          // [Legacy code].
          $arrayThreat = array_unique($arrayThreat);
          $arrayMessage = array_unique($arrayMessage);

          // TODO: filter_xss_admin()?
          $output .= '<input type="hidden" id="search_list_threat" value="' . implode(',', $arrayThreat) . '" />';
          $output .= '<input type="hidden" id="search_list_mess" value="' . implode(',', $arrayMessage) . '" />';
        }
      }
    }

    return $output;
  }
}
