<?php
/**
 * @file views-exposed-form.tpl.php
 *
 * This template handles the layout of the views exposed filter form.
 *
 * Variables available:
 * - $widgets: An array of exposed form widgets. Each widget contains:
 * - $widget->label: The visible label to print. May be optional.
 * - $widget->operator: The operator for the widget. May be optional.
 * - $widget->widget: The widget itself.
 * - $sort_by: The select box to sort the view using an exposed form.
 * - $sort_order: The select box with the ASC, DESC options to define order. May be optional.
 * - $items_per_page: The select box with the available items per page. May be optional.
 * - $offset: A textfield to define the offset of the view. May be optional.
 * - $reset_button: A button to reset the exposed filter applied. May be optional.
 * - $button: The submit button for the form.
 *
 * @ingroup views_templates
 */
?>
<?php if (!empty($q)): ?>
  <?php
    // This ensures that, if clean URLs are off, the 'q' is added first so that
    // it shows up first in the URL.
    print $q;
  ?>
<?php endif; ?>
<div class="views-exposed-form">
  <div class="views-exposed-widgets clearfix">
    <!-- Simple search -->
    <div class="views-exposed-widget ml-title-text fulltext-search clearfix">
      <h2>Quick Search</h2>
        <?php
          echo iaa_inline_help_generate('ml_view_quick_search','both');
        ?>
        <div class="clearfix"></div>
        <?php $text_widget = $widgets['filter-search_api_views_fulltext']; ?>
        <?php if (!empty($text_widget)): ?>
          <?php if (!empty($widget->label)): ?>
            <label for="<?php print $widget->id; ?>" style="display:none;">
              <?php print $widget->label; ?>
            </label>
          <?php endif; ?>
          <?php if (!empty($text_widget->operator)): ?>
            <div class="views-operator">
              <?php print $text_widget->operator; ?>
            </div>
          <?php endif; ?>

          <div class="views-widget text-advanced ml-text-box">
            <?php print $text_widget->widget; ?>
          </div>

          <div class="views-exposed-widget text-advanced ml-search-button views-submit-button">
            <?php print $button ?>
          </div>

          <div class="views-exposed-widget views-reset-button reset_simple_search">
            <?php print $reset_button; ?>
          </div>
       <?php endif; ?>
    </div>


    <!-- Advanced search, collapsed by default -->
    <div class="clearfix"></div>

    <fieldset class="collapsible <?php if ($advanced_search_collapsed) print 'collapsed'; ?> clearfix">
      <legend>
        <span class="fieldset-legend"><?php print t('Advanced Search'); ?></span>
      </legend>
      <div class="fieldset-wrapper">
        <?php foreach ($widgets as $id => $widget): ?>
          <?php if ($id == 'filter-search_api_views_fulltext') continue; ?>
          <div class="views-exposed-widget ml-select-list <?php print $id ?>">
            <?php if (!empty($widget->label)): ?>
              <label for="<?php print $widget->id; ?>">
                <?php print $widget->label; ?>
              </label>
            <?php endif; ?>
            <?php if (!empty($widget->operator)): ?>
              <div class="views-operator">
                <?php print $widget->operator; ?>
              </div>
            <?php endif; ?>
            <div class="views-widget text-advanced">
              <?php print $widget->widget; ?>
            </div>
           </div>
        <?php endforeach; ?>
      </div>
    </fieldset>

    <?php if (!empty($sort_by)): ?>
      <div class="views-exposed-widget views-widget-sort-by">
        <?php print $sort_by; ?>
      </div>
      <div class="views-exposed-widget views-widget-sort-order">
        <?php print $sort_order; ?>
      </div>
    <?php endif; ?>

    <?php if (!empty($items_per_page)): ?>
      <div class="views-exposed-widget views-widget-per-page">
        <?php print $items_per_page; ?>
      </div>
    <?php endif; ?>

    <?php if (!empty($offset)): ?>
      <div class="views-exposed-widget views-widget-offset">
        <?php print $offset; ?>
      </div>
    <?php endif; ?>


  </div>
</div>
