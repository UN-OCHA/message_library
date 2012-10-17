<?php

/**
 * @file
 */

/**
 * Views area handler.
 */
class message_library_views_handler_area_link_email_rtf extends views_handler_area {

  function option_definition() {
    $options = parent::option_definition();

    return $options;
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
  }

  function render($empty = FALSE) {
    $output = '';

    // The href need to open the email client
    $href_prefix = 'mailto:?body=' . t('Download the RTF from the server at the URL: ');

    // For view 'messsage_library_threat'
    if ($this->view->name == 'messsage_library_threat') {
      $threat_tid = reset($this->view->args);

      if (!empty($threat_tid)) {
        $href = $href_prefix . $download_url;
        $output .= '<div class="download_email_email_rtf_box">'
          . l(t('Email as an RTF'), $href_prefix . 'message-library/threat/' . $threat_tid, array('absolute' => TRUE))
          . '</div>';
      }
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
          $arrayThreat = message_library_views_search_all_threat($cache_id, $query);

          if (!empty($arrayThreat)) {
            $output .= '<div class="download_email_email_rtf_box">' . l(t('Email as an RTF'), download_email_getRTFEmailUrl() . '/' . implode(',', $arrayThreat)) . '</div>';
          }
        }
      }
    }
    return $output;
  }
}
