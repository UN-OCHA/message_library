(function ($) {
  Drupal.behaviors.messageLibraryExposedFilters = {
    attach: function (context, settings) {
      /* Handle 'Reset Search' buttons
       * -------------------------------------------------------------------- */
      // Handle 'remove' link beside each search facet, this will remove the
      // correponding facet and resubmit the exposed widget form
      $('.ml-views-facets').click(function() {
        // #edit-search-api-views-fulltext
        // #edit-issues
        // #edit-group-risk
        // #edit-audience
        // #edit-threat-title

        console.log($(this));

        var var_names = {
          'edit-ml-views-ml-search-text': 'edit-ml-search-text',
          'edit-ml-views-issue': 'edit-issue',
          'edit-ml-views-threat': 'edit-threat',
          'edit-ml-views-at-risk-group': 'edit-at-risk-group',
          'edit-ml-views-target-audience': 'edit-target-audience',
        };

        var id = $(this).attr('id');
        var widget_id = var_names[id];
        var exposedElement = $('#' + widget_id);

        if (exposedElement.attr('type') == 'text') {
          exposedElement.val('');
        }
        else {
          exposedElement.attr('selectedIndex', 0);
        }

        var exposedForm = $('#views-exposed-form-message-library-search-page');
        exposedForm.submit();
        return false;
      });

      /* Handle different display modes for the exposed filter - 'Issues'
       * -------------------------------------------------------------------- */
      var viewsForm = $('#views-exposed-form-message-library-search-page');
      var switcherLink = $('#issues-options-dispaly-mode-switcher a.mode-link', viewsForm);

      // Restore the mode from cookie, or diplay in alphabetic order by default
      var savedMode = $.cookie('exposed_issues_display_mode');
      if ($.inArray(savedMode, ['alpha', 'nested'])) {
        displayNestedList(savedMode);
      } else {
        displayNestedList('alpha');
      }

      switcherLink.toggle(function(e) {
        displayNestedList('nested');
      },function() {
        displayNestedList('alpha');
      });

      /**
       * #1 Replace the link text with the current mode(nestest/alphabetically)
       * #2 Get the issues exposed widget select element
       * #3 Get the preprocessed options in the hidden nested/alphabetic list
       * #4 Replace the options in #2
       */
      function displayNestedList(mode) {
        // Maintain the mode, prevent from being reset after the page refreshes
        $.cookie('exposed_issues_display_mode', mode);

        var issueSelectEl = $('select#edit-issue', viewsForm);
        var selectedOptionVal = issueSelectEl.find(':selected').val();

        var alphaListOptions  = $('#edit-issue-alpha option').clone();
        var nestedListOptions = $('#edit-issue-nested option').clone();
        //console.log(alphaListOptions);
        //console.log(nestedListOptions);

        if (mode == 'alpha') {
          switcherLink.html(Drupal.t('Alphabetically'));
          issueSelectEl.empty().append(alphaListOptions);
        } else {
          switcherLink.html(Drupal.t('Sectors'));
          issueSelectEl.empty().append(nestedListOptions);
        }

        // Maintain the selected option status
        $('option', issueSelectEl).filter(function() {
          return $(this).val() == selectedOptionVal;
        }).attr('selected', true);
        return;
      }

      /* Auto submit the search form while the drop-down facets change
       * -------------------------------------------------------------------- */
      // Issues, At risk group, Threat, Target audience
      var searchForm = $('#views-exposed-form-message-library-search-page');
      var facets = searchForm.find('#edit-issue, #edit-at-risk-group, #edit-threat, #edit-target-audience');

      facets.change(function(e) {
        searchForm.submit();
      });
    }
  }
})(jQuery);
