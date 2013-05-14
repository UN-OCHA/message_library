<?php

/**
 * Search api processor for aggragating the parent terms into a single field
 *
 */
class MessageLibraryAggregateParentTerms extends SearchApiAbstractProcessor {
  public function preprocessIndexItems(array &$items) {
    parent::preprocessIndexItems($items);

    foreach ($items as &$item) {
      if ($this->issueFieldExistsInItem($item)) {
        $has_change = $this->aggregateIssueFieldTids($item);
        if ($has_change) {
          $this->aggregateIssueFiedlNames($item);
        }
      }
    }
  }

  /**
   * Return all the parent 'issues' terms for a 'issues' term
   */
  protected function getParentIssueTerms($tid) {
    $result = array();
    $vocab = taxonomy_vocabulary_machine_name_load('issues');

    $p_terms = taxonomy_get_parents($tid);
    if (!empty($p_terms)) {
      foreach ($p_terms as $p_term) {
        if ($p_term->vid != $vocab->vid) {
          continue;
        }
        $result[$p_term->tid] = $p_term;
        $p_p_terms = $this->getParentIssueTerms($p_term->tid);
        if (!empty($p_p_terms)) {
          $result = array_merge($result, $p_p_terms);
        }
      }
    }
    return $result;
  }

  /**
   * Check whether we should proceed process the issues field by check if the
   * relevant fields are there
   */
  protected function issueFieldExistsInItem($item) {
    if (array_key_exists('field_message_threat:field_threat_category', $item)
      && $item['field_message_threat:field_threat_category']['type'] == 'list<integer>') {
      return TRUE;
    }
    else if (array_key_exists('field_message_threat:field_threat_category:tid', $item)
      &&$item['field_message_threat:field_threat_category:tid']['type'] == 'list<integer>') {
      return TRUE;
    }
    else {
      return FALSE;
    }
  }

  /**
   * Add the terms ids of the missing parent terms
   *
   * @return
   *  TRUE if there are new parent terms found; FALSE if not
   */
  protected function aggregateIssueFieldTids(&$item) {
    // This will try to fix fields:
    // - field_message_threat:field_threat_category
    // - field_message_threat:field_threat_category:tid

    if (!empty($item['field_message_threat:field_threat_category'])) {
      $origin_tids = $item['field_message_threat:field_threat_category']['value'];
    }
    else if (!empty($item['field_message_threat:field_threat_category:tid'])) {
      $origin_tids = $item['field_message_threat:field_threat_category:tid']['value'];
    }
    else {
      $origin_tids = array();
    }

    if (empty($origin_tids)) {
      return FALSE;
    }

    $new_tids = $origin_tids;

    // A container to store all the parent terms found
    foreach ($origin_tids as $tid) {
      $p_terms = $this->getParentIssueTerms($tid);
      if (!empty($p_terms)) {
        foreach ($p_terms as $p_term) {
          if (!in_array($p_term->tid, $new_tids)) {
            $new_tids[] = $p_term->tid;
          }
        }
      }
    }

    // Check if there are some new parent terms found, if true update the fields
    $tids_diff = array_diff($new_tids, $origin_tids);
    if (!empty($tids_diff)) {
      if (isset($item['field_message_threat:field_threat_category'])) {
        $item['field_message_threat:field_threat_category']['value'] = $new_tids;
      }

      if (isset($item['field_message_threat:field_threat_category:tid'])) {
        $item['field_message_threat:field_threat_category:tid']['value'] = $new_tids;
      }
    }

    return TRUE;
  }

  /**
   * Add the term names of the missing parent terms
   */
  protected function aggregateIssueFiedlNames(&$item) {
    // This will try to fix the field:
    // field_message_threat:field_threat_category:name

    if (!empty($item['field_message_threat:field_threat_category:name'])) {
      $tids = $this->getIssueTermIds($item);
      if (!empty($tids)) {
        $terms = taxonomy_term_load_multiple($tids);
        $term_names = array();
        foreach($terms as $term) {
          $term_names[] = $term->name;
        }
        if (!empty($term_names)) {
          $item['field_message_threat:field_threat_category:name']['value'] = $term_names;
        }
      }
    }
  }

  /**
   * A helper function to get the term ids of the issues
   */
  protected function getIssueTermIds($item) {
    if (!empty($item['field_message_threat:field_threat_category'])) {
      $tids = $item['field_message_threat:field_threat_category']['value'];
    }
    else if (!empty($item['field_message_threat:field_threat_category:tid'])) {
      $tids = $item['field_message_threat:field_threat_category:tid']['value'];
    }
    else {
      $tids = array();
    }
    return $tids;
  }
}
