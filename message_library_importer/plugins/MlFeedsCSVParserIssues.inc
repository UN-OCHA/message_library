<?php

require_once 'MlFeedsCSVParser.inc';

class MlFeedsCSVParserIssues extends MlFeedsCSVParser {
  /**
   * Implements FeedsParser::parse().
   */
  public function parse(FeedsSource $source, FeedsFetcherResult $fetcher_result) {
    $result = parent::parse ( $source, $fetcher_result );

    if (! empty ( $result->items ) && is_array ( $result->items )) {
      // remove all the sector terms.
      foreach ( $result->items as $m => $item ) {
        if ($item ['term name'] == 'Sectors' && !empty($item['term id']) && empty($item['parent term id'])) {
          $root_tid = $item['term id'];
          foreach ($result->items as $n => $item) {
            if (!empty($item['parent term id']) && $item['parent term id'] == $root_tid) {
              unset($result->items[$n]);  // remove all embedding sector terms
            }
          }
          unset($result->items[$m]);      // remove the umbrella term 'Sectors'
        }
      }

      // separate the sector term from the issue terms in D6
      foreach ( $result->items as &$item ) {
        unset ( $item ['parent term id'] );
        unset ( $item ['weight'] );

        $item ['sector'] = $item ['parent term name'];
        unset ( $item ['parent term name'] );
      }

      // one more redundant check, check if the sector term is valid.
      $sectors = array();
      foreach ($result->items as $k => $item) {
        if (in_array($item['sector'], $sectors)) continue;
        $sectors[] = $item['sector'];

        $t = taxonomy_get_term_by_name($item['sector'], 'sector');
        if (!$t) {
          unset($result->items[$k]);
        }
      }
    }
    return $result;
  }
}
