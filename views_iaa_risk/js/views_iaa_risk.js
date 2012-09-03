(function ($) {

	Drupal.iaarisk = Drupal.iaarisk || {};

	Drupal.behaviors.iaarisk = function(context) {

		if ($('.view-message-library .views-exposed-widgets #edit-group-risk').size()>0){
			if ($("body").hasClass("views_iaa_risk_hierarchy")) {
				views_iaa_risk_change_apparence('.view-message-library .views-exposed-widgets #edit-group-risk','hierarchy');
			}
			else {
				views_iaa_risk_change_apparence('.view-message-library .views-exposed-widgets #edit-group-risk','alpha');
			}
		}
	};
// END jQuery
})(jQuery);


