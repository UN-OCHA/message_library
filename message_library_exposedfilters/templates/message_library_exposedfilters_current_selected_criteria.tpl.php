<?php
$note = <<<EOT
The template stucture of the original 'Currently Selected Criteria'
===================================================================

- 1. No criteria, have result

  Only display the search result summary info.
  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  <div id="view-filters-facets">
    <div class="no_criteria">
      <div class="nb_result">
        <strong>368</strong> records matched criteria.
      </div>
    </div>
  </div>
  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

- 2. No criteria, no result
  This shouldn't happen, unless the library is empty.
  For this case, display nothing.

- 3. Have criteia, have result

  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  <div id="view-filters-facets">
    <h4>Currently Selected Criteria</h4>
    <div class="criteria_inline">
      <div class="nb_result">
        <strong>18</strong> records matched criteria.
      </div>
    </div>

    <div class="exposedfilterscontainer">
      <label>Issues:</label><em>Camp Coordination Camp Management</em>
      <a class="_vef_facets pointer" id="vef_edit-issues">(remove)</a>
    </div>

    <input type="reset" class="form-reset" value="Reset Search" id="edit-reset2">
  </div>
  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

- 4. Have critera, no result
  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  <div id="view-filters-facets">
    <h4>Currently Selected Criteria</h4>
    <div class="exposedfilterscontainer">
      <label>Search Text:</label>
      <em>this is not gonna happen</em>
      <a class="_vef_facets pointer" id="vef_edit-text">(remove)</a>
    </div>
    <input type="reset" class="form-reset" value="Reset Search" id="edit-reset2">
  </div>
  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
EOT;
?>

<?php if (empty($total_rows) && empty($has_criteria)) return; ?>

<div id="ml-crt-selected-criteria">
  <?php if (!$has_criteria): ?>
    <div class="no_criteria">
      <div class="nb_result">
        <?php print $total_rows_text; ?>
      </div>
    </div>
  <?php else: ?>
    <h4>Currently Selected Criteria</h4>
    <?php if (!empty($total_rows)): ?>
      <div class="criteria_inline">
        <div class="nb_result">
          <?php print $total_rows_text; ?>
        </div>
      </div>
    <?php endif;?>

    <?php if (!empty($search_api_views_fulltext)): ?>
    <!-- Search Text -->
    <div class="exposedfilterscontainer">
      <label>Search Text:</label>
      <em><?php print $search_api_views_fulltext; ?></em>
      <a class="_vef_facets pointer" id="vef_edit-search-api-views-fulltext">(remove)</a>
    </div>
    <?php endif; ?>

    <?php if (!empty($issues)): ?>
    <!-- Issues -->
    <div class="exposedfilterscontainer issues">
      <label>Issues:</label>
        <em><?php print $issues; ?></em>
        <a class="_vef_facets pointer" id="vef_edit-issues">(remove)</a>
    </div>
    <?php endif; ?>

    <?php if (!empty($threat)): ?>
    <!-- Threat -->
    <div class="exposedfilterscontainer title">
      <label>Threat:</label>
      <em><?php print $threat; ?></em>
      <a class="_vef_facets pointer" id="vef_edit-title">(remove)</a>
    </div>
    <?php endif; ?>

    <?php if (!empty($group_risk)): ?>
    <!-- At risk group -->
    <div class="exposedfilterscontainer group-risk">
      <label>At risk group:</label>
      <em><?php print $group_risk; ?></em>
      <a class="_vef_facets pointer" id="vef_edit-group-risk">(remove)</a>
    </div>
    <?php endif; ?>

    <?php if (!empty($audience)): ?>
    <!--  Target audience -->
    <div class="exposedfilterscontainer audience">
      <label>Target audience:</label>
      <em><?php print $audience; ?></em>
      <a class="_vef_facets pointer" id="vef_edit-audience">(remove)</a>
    </div>
    <?php endif; ?>

    <?php if (!empty($bundle)): ?>
    <!-- Bundle -->
    <div class="exposedfilterscontainer bundle">
      <label>Bundle:</label>
      <em></em>
      <a href="/message-library">(remove)</a>
    </div>
    <?php endif; ?>

    <?php if (!empty($search_criteria_help)): ?>
      <?php print $search_criteria_help; ?>
    <?php endif; ?>
  <?php endif;?>
</div>
