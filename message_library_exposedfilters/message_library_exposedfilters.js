(function ($) {
  Drupal.behaviors.messageLibraryExposedFilters = {
    attach: function (context, settings) {
      // Handle the 'remove' links for search facets, this will reset the
      // correponding facet and should trigger the re-submit for the exposed
      // widget form
      var exposedForm = $('#views-exposed-form-message-library-search-page');

      $('.ml-views-facets').click(function() {
        var var_names = {
          'edit-ml-views-ml-search-text'  : 'edit-ml-search-text',
          'edit-ml-views-issue'           : 'edit-issue',
          'edit-ml-views-threat'          : 'edit-threat',
          'edit-ml-views-at-risk-group'   : 'edit-at-risk-group',
          'edit-ml-views-target-audience' : 'edit-target-audience',
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

      var iss_mode = $('input#ml_iss_id_input',exposedForm);
      $('a.mode-link', exposedForm).click(function (e) {
        if($(this).hasClass('flat')){
          $(this).hide();
          $(this).next('a.mode-link.nest').show();

          iss_mode.attr('value', '1');
          iss_mode.attr('default_value', '1');
          exposedForm.trigger('submit');
        }
        else if ($(this).hasClass('nest')){
          $(this).hide();
          $(this).prev('a.mode-link.flat').show();

          iss_mode.attr('value', '0');
          iss_mode.attr('default_value', '0');
          exposedForm.trigger('submit');
        }
      });
    }
  };
})(jQuery);
