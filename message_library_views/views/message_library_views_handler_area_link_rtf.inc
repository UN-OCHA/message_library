<?php

/**
 * @file
 */

/**
 * Views area handler.
 *
 * @see: message_library_views_handler_area_link_email_rtf
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

    // For view 'messsage_library_threat'
    if ($this->view->name == 'messsage_library_threat') {
      $threat_tids =  array(reset($this->view->args));
    }
    else {
      // Get total.
      $total = $this->view->total_rows;

      // Cache ID.
      // TODO: make it unique?
      $cache_id = 'message_library_views';

      // Get all results, with Search API.
      if (!empty($total)) {
        $query = $this->query;
        if (!empty($query) && ($query instanceof SearchApiViewsQuery)) {
          $threat_tids = message_library_views_search_all_threat($cache_id, $query);
        }
      }
    }


    if (!empty($threat_tids)) {
      $threat_seg = drupal_encode_path(implode(',', $threat_tids));
      $output .= '<div class="export2rtf_box">'
        . l(t('Download as an RTF Document'), 'message-library-rtf/threat/' . $threat_seg)
        . '</div>';
    }

    return $output;
  }
}
