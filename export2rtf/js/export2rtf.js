(function ($) {

  Drupal.behaviors.export2rtf = {
      attach: function(context, settings) {
    if ($('.view-message-library').size()>0){
      if ($('.view-message-library #search_list_threat').size()>0) {
        $('.block-export2rtf').show();
        $('.export2rtf_link').attr("href",'/export2rtf/'+$("#search_list_threat").val());
      }
      else {
        $('.block-export2rtf').hide();
      }
    }
      }
  };
// END jQuery
})(jQuery);
