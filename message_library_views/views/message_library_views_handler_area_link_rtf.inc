<?php

/**
 * @file
 */

/**
 * Views area handler.
 */
class message_library_views_handler_area_link_rtf extends views_handler_area {

  function option_definition() {
    $options = parent::option_definition();

    return $options;
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
  }

  function render($empty = FALSE) {
    $output = '';

    // Get total.
    $total = $this->view->total_rows;

    // Cache ID.
    // TODO: make it unique?
    $cache_id = 'message_library_views';

    // Get all results, with Search API.
    if (!empty($total)) {
      $query = $this->query;
      if (!empty($query) && ($query instanceof SearchApiViewsQuery)) {
        $array_threat = message_library_views_search_all_threat($cache_id, $query);

        if (!empty($array_threat)) {
          $nid_list = implode(',', $array_threat);
          $output .= '<div class="export2rtf_box">' .
            l(t('Download as an RTF Document'), 'export2rtf/' . $nid_list) .
          '</div>';
        }
      }
    }

    return $output;
  }
}
