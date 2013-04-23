(function ($) {
  Drupal.behaviors.messageLibraryExposedFilters = {
    attach: function (context, settings) {
      // Handle the 'remove' links for search facets, this will reset the
      // correponding facet and should trigger the re-submit for the exposed
      // widget form
      var exposedForm = $('#views-exposed-form-message-library-search-page');

      $('.ml-views-facets').click(function() {
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
          exposedForm.trigger('submit');
        }
        else {
          exposedElement.attr('selectedIndex', 0);
          exposedElement.trigger('change');
        }

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

      // This form is auto-submitted, which is configured in the views
//      facets.change(function(e) {
//        searchForm.submit();
//      });

      updateThreatOptionsByIssue();

      // The options in the threat drop-down should be filter by the value in
      // issue filter
      function updateThreatOptionsByIssue() {
        var threatOptionsObj = Drupal.settings.messageLibraryExposedfilter.threatOptions;
        // Sort the options alphanumerically first
        var sortedOptions = [];
        for(var option in threatOptionsObj) {
          sortedOptions.push([option, threatOptionsObj[option]]);
        }
        sortedOptions.sort(function(a, b) {
          var textA = a[1].toUpperCase();
          var textB = b[1].toUpperCase();
          return (textA < textB) ? -1 : (textA > textB) ? 1 : 0;
        });

        var threatSelect = $('#edit-threat');
        var threatVal = threatSelect.val();
        var issueSelect = $('#edit-issue');
        var issueVal = issueSelect.val();

        // - If no specific issue selected, display 'Select threat first' and
        //   disable the threat selected element
        if (issueVal == 'All') {
          var optionEl = $('<option></option>').text(Drupal.t('Select Issue First')).attr('disabled','disabled');
          threatSelect.empty().append(optionEl).attr('disabled', 'disabled');
        }
        // - If a specific Issue is selected, display all the relevant threat
        //   options
        else {
          $.ajax({
            type: 'GET',
            url: 'message-library-filter-threat-by-issue/' + issueVal,
            dataType: 'json',
            success: function(data) {
              // The option 'All' is required, for the ajax call may fail
              var defaultOption = $('<option></option>').attr('value', 'All').text(Drupal.t('<All threats>'));
              threatSelect.empty().removeAttr('disabled').append(defaultOption);

              if (data) {
                // Recalculate the select options
                var newOptions = [];
                $.each(sortedOptions, function(index, option) {
                  var optionVal = option[0];
                  if (data.hasOwnProperty(optionVal)) {
                    newOptions.push(option);
                  }
                });

                // Replace with new options
                $.each(newOptions, function(key, value) {
                  if (threatVal == value[0]) {
                    var optionEl = $('<option></option>').attr('value', value[0]).text(value[1]).attr('selected','selected');
                  }
                  else {
                    var optionEl = $('<option></option>').attr('value', value[0]).text(value[1]);
                  }
                  threatSelect.append(optionEl);
                });
              }
            },
            error: function(jqXHR, errorText) {
              // @todo:
            }
          });
        }
      }

    }
  }
})(jQuery);
