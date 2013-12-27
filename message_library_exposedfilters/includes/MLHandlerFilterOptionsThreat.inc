<?php

class MLHandlerFilterOptionsThreat extends SearchApiViewsHandlerFilterOptions {
  public function exposed_translate(&$form, $type) {
    parent::exposed_translate($form, $type);

    if (!empty($this->view->exposed_input['issue'])) {
      $iss_tid = $this->view->exposed_input['issue'];
      if ($iss_tid == 'All') {
        $form['#options']['All'] = t('<Please select an issue>');
        $form['#attributes']['disabled'] = 'disabled';
      }
      else {
        $form['#options']['All'] = t('<All threats>');
        $grouped = $this->threats_group_by_issue($iss_tid);

        if (!empty($grouped) && !empty($form['#options'])) {
          $intersect = array_intersect($form['#options'], $grouped);
          $form['#options'] = array('All' => t('<All threats>'))
            + $intersect;
        }
      }
    }
  }

  public function threats_group_by_issue($tid) {
    $result = message_library_exposedfilters_get_issue_threats();
    if ($tid && !empty($result[$tid])){
      return $result[$tid];
    }
    return $result;
  }
}
