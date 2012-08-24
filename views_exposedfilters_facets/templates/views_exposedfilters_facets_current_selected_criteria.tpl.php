<?php if ($has_criteria): ?>
  <h4>Currently Selected Criteria</h4>

  <?php if (!empty($search_api_views_fulltext)): ?>
  <!-- Search Text -->
  <div class="exposedfilterscontainer">
    <label>Search Text:</label>
    <em><?php print $search_api_views_fulltext; ?></em>
    <a class="_vef_facets pointer" id="vef_edit-text">(remove)</a>
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

  <input type="reset" class="form-reset" value="Reset Search" id="edit-reset2" />
<?php endif; ?>
