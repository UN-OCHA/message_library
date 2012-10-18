(function ($) {
  Drupal.behaviors.messageLibraryHelp = {
    attach: function (context, settings) {
      var ml_help_boxes =  $('#boxes-box-ml_help_general, #boxes-box-ml_help_quick_search, #boxes-box-ml_help_criteria');
      console.log(ml_help_boxes);

      // By default, hidden
      ml_help_boxes.hide();

      // Add some html toggle links:
      // 1. a toggle link to toggle all help boxes
      if (!!$('#ml_help_all_toggle').length == false) {
        $('h1#page-title').append('<span><a id="ml_help_all_toggle" class="ml-help-toggle" toggle-box-target="all" href="#" >Display all</a></span>');
      }

      // 2. a toggle link about the whole message library
      if (!!$('#ml_help_general_toggle').length == false) {
        $('h1#page-title').append('<a id="ml_help_general_toggle" class="ml-help-toggle" toggle-box-target="ml_help_general" href="#" >Show</a>');
      }

      // 3. a toggle link for the quick search section
      if (!!$('#ml_help_quick_search_toggle').length == false) {
        $('#ml-view-quick-search-title').append('<a id="ml_help_quick_search_toggle" class="ml-help-toggle" toggle-box-target="ml_help_quick_search" href="#" >Show</a>');
      }

      // 4. a toggle link for the search criteria
      if (!!$('#ml_help_criteria_toggle').length == false) {
        $('#ml-view-crt-criteria-title').append('<a id="ml_help_criteria_toggle" class="ml-help-toggle" toggle-box-target="ml_help_criteria"  href="#" >Show</a>');
      }

      // Handle toggle actions
      $('.ml-help-toggle').toggle(function(e) {
        // handle status - show
        e.preventDefault();
        var box_target = $(this).attr('toggle-box-target');
        if (box_target == 'all') {
          $(this).html('Hide all help');
        }
        else {
          $(this).html('hide');
        }
        mesasage_library_help_show_box(box_target);
      }, function(e) {
        // handle status - hide
        e.preventDefault();
        var box_target = $(this).attr('toggle-box-target');
        if (box_target == 'all') {
          $(this).html('Dislay all help');
        }
        else {
          $(this).html('show');
        }
        mesasage_library_help_hide_box(box_target);
      });

      function mesasage_library_help_show_box(type) {
        console.log('show:' + type );
        if (type == 'all') {
          ml_help_boxes.show();
        }
        else {
          $('#boxes-box-' + type).show();
        }
      }

      function mesasage_library_help_hide_box(type) {
        console.log('hide:' + type );
        if (type == 'all') {
          ml_help_boxes.hide();
        }
        $('#boxes-box-' + type).hide();
      }
    }
  }
})(jQuery);
