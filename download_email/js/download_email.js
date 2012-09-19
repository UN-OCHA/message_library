(function ($) {

  Drupal.behaviors.downloademail = {
      attach: function(context, settings) {
    if ($('.view-message-library .views-exposed-widgets').size()>0){
      if ($('.view-message-library #search_list_threat').size()>0) {
        $('.block-download_email').show();
        $('.download_email_email_rtf_link').attr("href",$('.download_email_email_rtf_link').attr("href")+'/'+$("#search_list_threat").val());
      }
      else {
        $('.block-download_email').hide();
      }
    }
      }
  };

// END jQuery
})(jQuery);
