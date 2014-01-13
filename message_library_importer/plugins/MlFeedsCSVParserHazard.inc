<?php

require_once 'MlFeedsCSVParser.inc';

class MlFeedsCSVParserHazard extends MlFeedsCSVParser {
  // hazard vocabulary doesn't have nested terms, and no need to reorder.
}
