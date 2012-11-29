(function ($) {
  Drupal.behaviors.messageLibraryHelp = {
    attach: function (context, settings) {
      var ml_help_boxes =  $('#boxes-box-ml_help_general, #boxes-box-ml_help_quick_search, #boxes-box-ml_help_criteria');

      // Add some html toggle links:
      // 1. a toggle link to toggle all help boxes
      if (!!$('#ml_help_all_toggle').length == false) {
        $('h1#page-title').append('<span><a id="ml_help_all_toggle" class="ml-help-toggle hidden" toggle-box-target="all" href="#" >display all help</a></span>');
      }

      // 2. a toggle link about the whole message library
      if (!!$('#ml_help_general_toggle').length == false) {
        $('h1#page-title').append('<a id="ml_help_general_toggle" class="ml-help-toggle hidden" toggle-box-target="ml_help_general" href="#" >show</a>');
      }

      // 3. a toggle link for the quick search section
      if (!!$('#ml_help_quick_search_toggle').length == false) {
        $('#ml-view-quick-search-title').append('<a id="ml_help_quick_search_toggle" class="ml-help-toggle hidden" toggle-box-target="ml_help_quick_search" href="#" >show</a>');
      }

      // 4. a toggle link for the search criteria
      if (!!$('#ml_help_criteria_toggle').length == false) {
        $('#ml-view-crt-criteria-title').append('<a id="ml_help_criteria_toggle" class="ml-help-toggle hidden" toggle-box-target="ml_help_criteria"  href="#" >show</a>');
      }

      var ml_help_toggle_links = $('#ml_help_general_toggle, #ml_help_quick_search_toggle, #ml_help_criteria_toggle');
      var ml_help_toogle_all_link = $('#ml_help_all_toggle');

      function mesasage_library_help_show_box(type) {
        if (type == 'all') {
          ml_help_toogle_all_link.html('Hide all help').removeClass('hidden');
          ml_help_toggle_links.html('hide').removeClass('hidden');
          ml_help_boxes.show();
        }
        else {
          $('#boxes-box-' + type).show();
          $('a[toggle-box-target=' + type + ']').html('hide').removeClass('hidden');
        }
      }

      function mesasage_library_help_hide_box(type) {
        if (type == 'all') {
          ml_help_toogle_all_link.html('Display all help').addClass('hidden');
          ml_help_toggle_links.html('show').addClass('hidden');
          ml_help_boxes.hide();
        }
        else {
          $('#boxes-box-' + type).hide();
          $('a[toggle-box-target=' + type + ']').html('show').addClass('hidden');
        }
      }

      // By default, hide all help boxes
      mesasage_library_help_hide_box('all');

      $('.ml-help-toggle').unbind('click').click(function(e) {
        e.preventDefault();
        e.stopPropagation();

        var box_target = $(this).attr('toggle-box-target');

        if ($(this).hasClass('hidden')) {
          mesasage_library_help_show_box(box_target);
          $(this).removeClass('hidden');
        }
        else {
          mesasage_library_help_hide_box(box_target);
          $(this).addClass('hidden');
        }
      });
    }
  }
})(jQuery);
