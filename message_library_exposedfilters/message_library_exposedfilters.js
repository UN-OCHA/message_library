(function ($) {
  Drupal.behaviors.messageLibraryExposedFilters = {
    attach: function (context, settings) {
      // Handle 'Reset Search' buttons


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
    }
  }
})(jQuery);
