<?php

class MLHandlerFilterOptionsThreat extends SearchApiViewsHandlerFilterOptions {
  public function exposed_translate(&$form, $type) {
    parent::exposed_translate($form, $type);

    if (!empty($this->view->exposed_input['issue'])) {
      $iss_tid = $this->view->exposed_input['issue'];
      if ($iss_tid == 'All') {
        $form['#options']['All'] = t('<Select Issue First>');
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
    $result = $this->getThreatsByIssueOrSector($tid);
    return $result;
  }

  public function getThreatsByIssueOrSector($tid) {
    // check if sector or issue
    $term = taxonomy_term_load($tid);
    $sql = 'SELECT v.machine_name FROM {taxonomy_term_data} d INNER JOIN {taxonomy_vocabulary} v ON d.vid = v.vid WHERE d.tid = :tid';
    $result = db_query($sql, array(':tid' => $tid));
    $vname = $result->fetchField();

    $tids = array();
    if ($vname == 'issues') {
      $query = new EntityFieldQuery;
      $query
        ->entityCondition('entity_type', 'taxonomy_term', '=')
        ->entityCondition('bundle', 'threat', '=' )
        ->fieldCondition('field_threat_category', 'tid', $tid);
      $result = $query->execute();

      if (!empty($result) && !empty($result['taxonomy_term'])) {
        $tids = array_keys($result['taxonomy_term']);
        if (!empty($tids)) {
          $tids = array_unique($tids);
        }
      }
    }
    else if ($vname == 'sector') {
      // get all issues under this sector
      $query = new EntityFieldQuery;
      $result = $query
        ->entityCondition('entity_type', 'taxonomy_term', '=')
        ->entityCondition('bundle', 'issues', '=' )
        ->fieldCondition('field_issues_sector', 'tid', $tid)
        ->execute();
      if (!empty($result) && !empty($result['taxonomy_term'])) {
        $issue_tids = array_keys($result['taxonomy_term']);
        if (!empty($issue_tids)) {
          $issue_tids = array_unique($issue_tids);
        }

        // get threats terms by issue
        $query = new EntityFieldQuery();
        $query
          ->entityCondition('entity_type', 'taxonomy_term', '=')
          ->entityCondition('bundle', 'threat', '=' )
          ->fieldCondition('field_threat_category', 'tid', $issue_tids);
        $result = $query->execute();

        if (!empty($result) && !empty($result['taxonomy_term'])) {
          $tids = array_keys($result['taxonomy_term']);
          if (!empty($tids)) {
            $tids = array_unique($tids);
          }
        }
      }
    }

    if ($tids) {
      $result = db_query("SELECT d.tid, d.name FROM {taxonomy_term_data} d INNER JOIN {taxonomy_vocabulary} v ON d.vid = v.vid WHERE v.machine_name = 'threat' AND d.tid IN (:tids)", array(':tids' => $tids));
      return $result->fetchAllKeyed(0, 1);
    }
    return array();
  }
}
