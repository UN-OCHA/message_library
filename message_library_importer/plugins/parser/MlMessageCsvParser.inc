<?php

require_once 'MlCSVParser.inc';

class MlMessageCsvParser extends MlCsvParser {

  public function parse(FeedsSource $source, FeedsFetcherResult $fetcher_result) {
    $result = parent::parse($source, $fetcher_result);
    if (empty($result->items) || !is_array($result->items)) return $result;

    foreach ($result->items as &$item) {
      // map Sensitivity field to the right value.
      if (!empty($item['sensitivity'])) {
        $mapping = array(
          'no guidance required'        => 0,
          'guidance required/sensitive' => 1,
          'highly sensitive'            => 2,
        );

        $old_label = trim(strtolower($item['sensitivity']));
        if (array_key_exists($old_label, $mapping)) {
          $item['sensitivity'] = $mapping[$old_label];
        }
      }

      // explode alert questions field.
      if (!empty($item['alert questions'])) {
        $aqs = preg_split('/\s*\?\s*/', $item['alert questions'], -1, PREG_SPLIT_NO_EMPTY);
        foreach ($aqs as &$v) $v .= '?';
        $item['alert question'] = $aqs;
      }

      // explode 'at risk group','target audience' and 'information type' fields.
      foreach (array('at risk group','target audience','information type') as $field) {
        if (!empty($item[$field])) {
          $item[$field] = preg_split('/\s*,\s*/', $item[$field], -1, PREG_SPLIT_NO_EMPTY);
        }
      }

      // process link fields, including 'websites' and 'source'
      foreach (array('source','websites') as $field) {
        if (empty($item[$field])) continue;

        $item[$field] = preg_replace("/'(?=[:|,|}])|(?<=[:|,|{])'/",  '"', $item[$field]);
        $decoded = json_decode($item[$field], true);
        $item[$field] = array();
        if (empty($decoded)) {
          watchdog('message_library_importer', t('Unable to parse the url data: %url', array('%url' => $json_raw)));
          continue;
        }

        foreach ($decoded as $key => $v) {
          $item[$field][] = $v;
        }
      }

      // process the attachment fields
      $example = $item['examples of communication around this issue'];
      $item['examples of communication around this issue'] = array();
      if (!empty($example)) {
        $example_items = preg_split('/\s*,\s*/', $example, -1, PREG_SPLIT_NO_EMPTY);
        if (!empty($example_items)) {
          foreach ($example_items as $v) {
            if (link_validate_url($v) == FALSE) continue;
            $value['examples of communication around this issue'][] =
              array('url' => $v,'title' => '');
          }
        }
      }

      // remap some terms from infoasaid's at risk group vocabulary to the terms in
      // HR platform's 'population types' terms.
      if (!empty($item['at risk group'])) {
        $mappings = array(
          'All women'                 => 'Women',
          'All children under 18'     => 'Children',
          'All vulnerable groups'     => 'Vulnerable Groups',
          // to be confirmed
          'All affected populations'  => 'All affected population',
          'Post partum women'         => 'Post partum women (up to 6 weeks)',
        );
        foreach ($item['at risk group'] as $k => $v) {
          $v = ucfirst(strtolower($v));
          if (array_key_exists($v, $mappings)) {
            $item['at risk group'][$k] = $mappings[$v];
          }
        }
        $item['at risk group'] = array_unique($item['at risk group']);

        // check all the terms in 'at risk group' field, if it doesn't exist in
        // the population type vocabulary, then don't import it and log it.
        // We do this check so our import process doesn't alter the accidentally
        // add new term to population types vocabulary.
        static $exists = array();
        static $non_exists = array();

        foreach ($item['at risk group'] as $k => $v) {
          if (in_array($v, $exists)) continue;
          if ($res = taxonomy_get_term_by_name($v, 'population_types')) {
            foreach ($res as $t) {
              $exists[$t->tid] = $t->name;
            }
          }
          else {
            if (!in_array($v, $non_exists)) {
              $non_exists[] = $v;
            }
            unset($item['at risk group'][$k]);
            watchdog('message_library_importer', 'Unmapped at risk group term :'.$v);
          }
        }
      }
    } // iterate item end.
    return $result;
  }
}
