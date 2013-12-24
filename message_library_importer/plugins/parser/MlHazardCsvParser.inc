<?php

require_once 'MlCSVParser.inc';

class MlHazardCsvParser extends MlCsvParser {
  // hazard vocabulary doesn't have nested terms, and no need to reorder.
}
