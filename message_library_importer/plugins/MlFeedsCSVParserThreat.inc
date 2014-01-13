<?php

require_once 'MlFeedsCSVParser.inc';

class MlFeedsCSVParserThreat extends MlFeedsCSVParser {

  public function parse(FeedsSource $source, FeedsFetcherResult $fetcher_result) {
    $result = parent::parse($source, $fetcher_result);

    foreach ($result->items as &$item) {
      // IMHO, the issue - sector relationship should be managed in this importer
      unset($item['threat sector']);

      foreach (array('threat hazard','threat issue') as $field) {
        if (!empty($item[$field])) {
          $item[$field] = preg_split('/\s*,\s*/', $item[$field], -1, PREG_SPLIT_NO_EMPTY);
        }
      }
    }
    return $result;
  }
}
