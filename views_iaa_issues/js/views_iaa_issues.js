(function ($) {

	Drupal.iaaissues = Drupal.iaaissues || {};

	Drupal.behaviors.iaaissues = function(context) {

		if ($('.view-message-library .views-exposed-widgets #edit-issues').size()>0){
			if ($("body").hasClass("views_iaa_issues_hierarchy")) {
				views_iaa_issues_change_apparence('.view-message-library .views-exposed-widgets #edit-issues','hierarchy');
			}
			else { // views_iaa_issues_alpha
				views_iaa_issues_change_apparence('.view-message-library .views-exposed-widgets #edit-issues','alpha');
			}
		}
		
		if ($('#messagesearchissue #edit-issues').size()>0){
			if ($("body").hasClass("views_iaa_issues_hierarchy")) {
				views_iaa_issues_change_apparence('#messagesearchissue #edit-issues','hierarchy');
			}
			else {
				views_iaa_issues_change_apparence('#messagesearchissue #edit-issues','alpha');
			}
		}
			
	};
// END jQuery
})(jQuery);


