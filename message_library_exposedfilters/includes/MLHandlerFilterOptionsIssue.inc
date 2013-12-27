<?php

define('ML_ISSUES_FLAT', 0);  // only issues terms
define('ML_ISSUES_NEST', 1);  // grouped by sector terms.

/**
 * @file
 * Contains the MLViewsHandlerFilterOptions class.
 */

/**
 * Views filter handler for fields with a limited set of possible values.
 */
class MLHandlerFilterOptionsIssue extends SearchApiViewsHandlerFilterOptions {
  private $nest_value_options;

  public function construct() {
    parent::construct();

    // add an new member to record the nested options
    $this->nest_value_options = $this->get_nest_value_options();
  }

  /**
   * Fills the value_options property with all possible options.
   */
  protected function get_value_options() {
    parent::get_value_options();
  }

  /**
   * Categorize the issues terms using sector terms.
   */
  private function get_nest_value_options() {
    $vocab_obj_iss = taxonomy_vocabulary_machine_name_load('issues');
    $vocab_obj_sec = taxonomy_vocabulary_machine_name_load('sector');

    $iss_terms = taxonomy_get_tree($vocab_obj_iss->vid, 0, 1, true);
    $sec_terms = taxonomy_get_tree($vocab_obj_sec->vid, 0, 1, false);
    foreach($sec_terms as $k => $v) {
      unset($sec_terms[$k]);
      $sec_terms[$v->tid] = $v;
    }

    $group = array();
    foreach ($iss_terms as $term) {
      $items = field_get_items('taxonomy_term', $term, 'field_issues_sector');
      if (!empty($items[0]['tid'])) {
        $sector_tid = $items[0]['tid'];
        if (!array_key_exists($sector_tid, $sec_terms)) {
          continue;
        }
        $group[$sector_tid][$term->tid] = $term->name;
      }
      else {
        continue;
      }
    }
    $this->nested_options = $group;

    // assemble the new option list.
    $options = array();
    foreach($group as $sec_tid => $items) {
      $options[$sec_tid] = $sec_terms[$sec_tid]->name;
      foreach ($items as $iss_tid => $iss_name) {
        $options[$iss_tid] = '-'.$iss_name;
      }
    }
    return $options;
  }

  /**
   * The exposed filter form component.
   */
  public function exposed_form(&$form, &$form_state) {
    parent::exposed_form($form, $form_state);


    // add a hidden field for the issue field's display mode.
    $form['iss_mode'] = array(
      '#type' => 'hidden',
      '#default_value' => ML_ISSUES_FLAT,
      '#attributes' => array(
        'id' => 'ml_iss_id_input'
      ),
    );

    $form['ml_search_text']['#attributes']['placeholder'] = t('enter search terms');
    $form['issue']['#prefix'] = theme('issues_options_display_mode_switcher');

    if ($form_state['input']['iss_mode'] == ML_ISSUES_NEST) {
      $form['issue']['#prefix'] = '<div id="issues-options-dispaly-mode-switcher"><a href="#" style="display:none" class="mode-link flat">'.t('Alphabetically').'</a><a href="#" class="mode-link nest">'.t('Sectors').'</a></div>';
    }
    else {
      $form['issue']['#prefix'] = '<div id="issues-options-dispaly-mode-switcher"><a href="#" class="mode-link flat">'.t('Alphabetically').'</a><a href="#" class="mode-link nest" style="display:none">'.t('Sectors').'</a></div>';
    }
  }

  public function value_form(&$form, &$form_state) {
    parent::value_form($form, $form_state);
    if ($form_state['input']['iss_mode'] == ML_ISSUES_NEST) {
      $form['value']['#options'] = $this->nest_value_options;
    }
    else {
      $form['value']['#options'] = $this->value_options;
    }
  }

  public function accept_exposed_input($input) {
    parent::accept_exposed_input($input);


//     if ($input['iss_mode'] == '0' && array_key_exists($input['issue'], $this->nested_options)) {
//       $input['issue'] = 'All';
//     }

    // convert the a sector value to multiple issues values
    $sec_tids = array_keys($this->nested_options);
    if (!empty($this->value) && count($this->value) == 1 && !empty($this->value[0])) {
      $tid = $this->value[0];
      if (in_array($tid, $sec_tids)) {
        $sec_issue_tids = array_keys($this->nested_options[$tid]);
        $this->value = $sec_issue_tids;
      }
    }
    return true;
  }

  public function store_exposed_input($input, $status) {
    parent::store_exposed_input($input, $status);

    $session = &$_SESSION['views']['message_library']['default'];

    if (isset($input['iss_mode'])) {
      $session['iss_mode'] = $input['iss_mode'];
      $this->view->exposed_input['iss_mode'] = $input['iss_mode'];
    }

    if ($input['iss_mode'] == '0' && array_key_exists($input['issue'], $this->nested_options)) {
      dpm($this);
      $this->view->exposed_input['issue'] = 'All';
    }
  }
}
