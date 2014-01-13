<?php

require_once 'MlFeedsCSVParser.inc';

class MlFeedsCSVParserArg extends  MlFeedsCSVParser {
  public function parse(FeedsSource $source, FeedsFetcherResult $fetcher_result) {
    $result = parent::parse($source, $fetcher_result);

    if (!empty($result->items) && is_array($result->items)) {
      // Prevent some at risk group terms from importing.
      $blacklist = array(
        'all children under 18',
        'all women',
        'all vulnerable groups'
      );
      foreach ($result->items as $k => $item) {
        $name = strtolower(trim($item['term name']));
        if (in_array($name, $blacklist)) {
          unset($result->items[$k]);
        }
      }

      // Reorder the terms.
      $temp = $this->reorderTerms($result->items);
      $result->items = $temp;
    }

    return $result;
  }
}
