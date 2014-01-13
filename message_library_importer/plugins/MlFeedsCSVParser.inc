<?php
class MlFeedsCSVParser extends FeedsCSVParser {

  public function parse(FeedsSource $source, FeedsFetcherResult $fetcher_result) {
    $result = parent::parse ( $source, $fetcher_result );
    if (! empty ( $result->items ) && is_array ( $result->items )) {
      // strip the surrounding spaces
      foreach ( $result->items as &$item ) {
        if (! is_array ( $item ) || ! count ( $item ))
          continue;
        foreach ( $item as &$v )
          $v = trim ( $v );
      }
    }
    return $result;
  }

  // The following threee methods are used in some vocabulary which has nested
  // terms to make sure the parent terms get created before child terms.

  /**
   * Reorder the terms so that the parent term could be created prior to child
   * terms.
   */
  public function reorderTerms($items) {
    $term_tree = $this->toTree($items, 0);
    $sorted_tids = ($this->extractTids($term_tree));

    // Sort it
    $sorted_terms = array_flip($sorted_tids);
    foreach ($items as $key => $item) {
      if (array_key_exists($item['term id'], $sorted_terms)) {
        $sorted_terms[$item['term id']] = $item;
        unset($items[$key]);
      }
    }
    return $sorted_terms;
  }

  /**
   * Callback for grouping the parsed terms by hierarchy
   */
  private function toTree($items, $parent) {
    $result = array();

    foreach ($items as $item) {
      if (!is_null($item['parent term id']) && !is_null($item['term id']) && $item['parent term id'] == $parent) {
        $new_item = $item;
        $new_item['children'] = $this->toTree($items, $new_item['term id']);
        $result[] = $new_item;
      }
    }
    return !empty($result) ? $result : NULL;
  }

  /**
   * flattening the terms nested by hierarchy
   */
  private function extractTids($children) {
    $result = array();
    // Outter
    foreach ($children as $child) {
      $result[] = $child['term id'];
    }
    // Inner
    foreach ($children as $child) {
      if (!empty($child['children'])) {
        $result = array_merge($result, $this->extractTids($child['children']));
      }
    }
    return $result;
  }
}
