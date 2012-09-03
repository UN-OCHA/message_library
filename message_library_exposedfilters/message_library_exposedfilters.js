(function ($) {
  Drupal.behaviors.messageLibraryExposedFilters = {
    attach: function (context, settings) {
      /* Handle 'Reset Search' buttons
       * -------------------------------------------------------------------- */
      // Handle 'remove' link beside each search facet, this will remove the
      // correponding facet and resubmit the exposed widget form
      $('._vef_facets').click(function() {
        // Get the id of target exposed element, this need proper setting in the
        // template
        var id = '#' + $(this).attr('id').substring(4);
        var exposedElement = $(id);

        if (exposedElement.attr('type') == 'text') {
          exposedElement.val('');
        }
        else {
          exposedElement.attr('selectedIndex', 0);
        }

        exposedElement.closest('form').submit();
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

      switcherLink.toggle(function() {
        displayNestedList('nested');
      }, function() {
        displayNestedList('alpha');
      });

      /**
       * #1 Replace the link text with the current mode(Issues/alphabetically)
       * #2 Get the issues exposed widget select element
       * #3 Get the preprocessed options in the hidden nested/alphabetic list
       * #4 Replace the options in #2
       */
      function displayNestedList(mode) {
        var issueSelectEl = $('select#edit-issues', viewsForm);
        var selectedOptionVal = issueSelectEl.find(':selected').val();

        var alphaListOptions  = $('#edit-issues-alpha option').clone();
        var nestedListOptions = $('#edit-issues-nested option').clone();

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


        // Maintain the mode, prevent from being reset after the page refreshes
        $.cookie('exposed_issues_display_mode', mode);
        return;
      }
    }
  }
})(jQuery);
