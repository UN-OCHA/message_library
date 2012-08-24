(function ($) {

	Drupal.iaainlinehelp = Drupal.iaainlinehelp || {};

	Drupal.behaviors.iaainlinehelp = function(context) {

		$('._iaa_inline_help_wrapper').hide();
		$('._iaa_inline_help_button_hide').removeClass('_iaa_inline_help_button_hide').addClass('_iaa_inline_help_button_show').children('._iaa_inline_help_button_message').html(Drupal.t("show")).parents('._iaa_inline_help_button_wrapper').removeClass('iaa_inline_help_button_wrapper_hide').addClass('iaa_inline_help_button_wrapper_show');
		$('._iaa_inline_help_hideall').removeClass('_iaa_inline_help_hideall').addClass('_iaa_inline_help_showall').html(Drupal.t("Display help"));
		showAllHelpEvent();

		initHideHelpEvent();
		initShowHelpEvent();
		
		
		$('._iaa_inline_help_wrapper_message').click(function(){
			$(this).hide();
			$(this).siblings('._iaa_inline_help_wrapper_form').show();
		});
		
		$('._iaa_inline_help_form_cancel').click(function(){
			$(this).siblings('._iaa_inline_help_form_message').val($(this).parents('._iaa_inline_help_wrapper_form').siblings('._iaa_inline_help_wrapper_message').html());
			$(this).parents('._iaa_inline_help_wrapper_form').hide();
			$(this).parents('._iaa_inline_help_wrapper_form').siblings('._iaa_inline_help_wrapper_message').show();
			return false;
		});
		
		
		
		
		$('._iaa_inline_help_form').submit(function(){
			var form = this;
			// on sauve en ajax
			$.ajax({ 
				type: "POST", 
				url: $(form).attr("action"),
				data: "message="+$(form).children('._iaa_inline_help_form_message').val()+"&id="+$(form).children('._iaa_inline_help_form_id').val(),  
				success: function(retour) {
					// puis on affiche le rendu
					$(form).parent().hide();
					$(form).parent().siblings('._iaa_inline_help_wrapper_message').html($(form).children('._iaa_inline_help_form_message').val()).show();
				},
				error: function () {
					alert(Drupal.t("An error occured while saving the message."));
				}
			});	
			
			
			return false;
		});
		
	};
// END jQuery
})(jQuery);

function hideAllHelpEvent() {
	$('._iaa_inline_help_hideall').unbind('click').click(function(){
		$('._iaa_inline_help_wrapper').hide();
		$('._iaa_inline_help_button_hide').removeClass('_iaa_inline_help_button_hide').addClass('_iaa_inline_help_button_show').children('._iaa_inline_help_button_message').html(Drupal.t("show")).parents('._iaa_inline_help_button_wrapper').removeClass('iaa_inline_help_button_wrapper_hide').addClass('iaa_inline_help_button_wrapper_show');
		initShowHelpEvent();
		$(this).removeClass('_iaa_inline_help_hideall').addClass('_iaa_inline_help_showall').html(Drupal.t("Display help"));
		showAllHelpEvent();
		return false;
	});
}

function showAllHelpEvent() {
	$('._iaa_inline_help_showall').unbind('click').click(function(){
		$('._iaa_inline_help_wrapper').show();
		$('._iaa_inline_help_button_show').removeClass('_iaa_inline_help_button_show').addClass('_iaa_inline_help_button_hide').children('._iaa_inline_help_button_message').html(Drupal.t("hide")).parents('._iaa_inline_help_button_wrapper').removeClass('iaa_inline_help_button_wrapper_show').addClass('iaa_inline_help_button_wrapper_hide');
		initHideHelpEvent();
		$(this).removeClass('_iaa_inline_help_showall').addClass('_iaa_inline_help_hideall').html(Drupal.t("Hide all help"));
		hideAllHelpEvent();
		return false;
	});
}

function initHideHelpEvent() {
	$('._iaa_inline_help_button_hide').click(function(){
		//return false;
	});
	$('.iaa_inline_help_button_wrapper_hide').unbind('click').click(function(){
		$($(this).children('a').attr("href")).hide();
		$(this).find('._iaa_inline_help_button_message').html(Drupal.t("show")).parents('._iaa_inline_help_button_hide').removeClass('_iaa_inline_help_button_hide').addClass('_iaa_inline_help_button_show');
		$(this).removeClass('iaa_inline_help_button_wrapper_hide').addClass('iaa_inline_help_button_wrapper_show');
		initShowHelpEvent();
		return false;
	});
}

function initShowHelpEvent() {
	$('._iaa_inline_help_button_show').click(function(){
		//return false;
	});
	$('.iaa_inline_help_button_wrapper_show').unbind('click').click(function(){
		$($(this).children('a').attr("href")).show();
		$(this).find('._iaa_inline_help_button_message').html(Drupal.t("hide")).parents('._iaa_inline_help_button_show').removeClass('_iaa_inline_help_button_show').addClass('_iaa_inline_help_button_hide');
		$(this).removeClass('iaa_inline_help_button_wrapper_show').addClass('iaa_inline_help_button_wrapper_hide');
		initHideHelpEvent();
		return false;
	});
}