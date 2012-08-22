(function ($) {

	Drupal.export2rtf = Drupal.export2rtf || {};
	
	Drupal.behaviors.export2rtf = function(context) {
		if ($('.view-message-library .views-exposed-widgets').size()>0){
			if ($('.view-message-library #search_list_threat').size()>0) {
				$('.block-export2rtf').show();
				$('.export2rtf_link').attr("href",'/export2rtf/'+$("#search_list_threat").val());
			}
			else {
				$('.block-export2rtf').hide();
			}
		}
	};

// END jQuery
})(jQuery);