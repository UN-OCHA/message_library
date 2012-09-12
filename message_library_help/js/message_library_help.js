(function ($) {

  Drupal.behaviors.iaainlinehelp = {
    attach: function(context, settings) {

    $('._message_library_help_wrapper').hide();
    $('._message_library_help_button_hide').removeClass('_message_library_help_button_hide').addClass('_message_library_help_button_show').children('._message_library_help_button_message').html(Drupal.t("show")).parents('._message_library_help_button_wrapper').removeClass('message_library_help_button_wrapper_hide').addClass('message_library_help_button_wrapper_show');
    $('._message_library_help_hideall').removeClass('_message_library_help_hideall').addClass('_message_library_help_showall').html(Drupal.t("Display help"));
    showAllHelpEvent();

    initHideHelpEvent();
    initShowHelpEvent();


    $('._message_library_help_wrapper_message').click(function(){
      $(this).hide();
      $(this).siblings('._message_library_help_wrapper_form').show();
    });

    $('._message_library_help_form_cancel').click(function(){
      $(this).siblings('._message_library_help_form_message').val($(this).parents('._message_library_help_wrapper_form').siblings('._message_library_help_wrapper_message').html());
      $(this).parents('._message_library_help_wrapper_form').hide();
      $(this).parents('._message_library_help_wrapper_form').siblings('._message_library_help_wrapper_message').show();
      return false;
    });

    $('._message_library_help_form').submit(function(){
      var form = this;
      // on sauve en ajax
      $.ajax({
        type: "POST",
        url: $(form).attr("action"),
        data: "message="+$(form).children('._message_library_help_form_message').val()+"&id="+$(form).children('._message_library_help_form_id').val(),
        success: function(retour) {
          // puis on affiche le rendu
          $(form).parent().hide();
          $(form).parent().siblings('._message_library_help_wrapper_message').html($(form).children('._message_library_help_form_message').val()).show();
        },
        error: function () {
          alert(Drupal.t("An error occured while saving the message."));
        }
      });

      return false;
    });

    }
  };

  function hideAllHelpEvent() {
    $('._message_library_help_hideall').unbind('click').click(function(){
      $('._message_library_help_wrapper').hide();
      $('._message_library_help_button_hide').removeClass('_message_library_help_button_hide').addClass('_message_library_help_button_show').children('._message_library_help_button_message').html(Drupal.t("show")).parents('._message_library_help_button_wrapper').removeClass('message_library_help_button_wrapper_hide').addClass('message_library_help_button_wrapper_show');
      initShowHelpEvent();
      $(this).removeClass('_message_library_help_hideall').addClass('_message_library_help_showall').html(Drupal.t("Display help"));
      showAllHelpEvent();
      return false;
    });
  }

  function showAllHelpEvent() {
    $('._message_library_help_showall').unbind('click').click(function(){
      $('._message_library_help_wrapper').show();
      $('._message_library_help_button_show').removeClass('_message_library_help_button_show').addClass('_message_library_help_button_hide').children('._message_library_help_button_message').html(Drupal.t("hide")).parents('._message_library_help_button_wrapper').removeClass('message_library_help_button_wrapper_show').addClass('message_library_help_button_wrapper_hide');
      initHideHelpEvent();
      $(this).removeClass('_message_library_help_showall').addClass('_message_library_help_hideall').html(Drupal.t("Hide all help"));
      hideAllHelpEvent();
      return false;
    });
  }

  function initHideHelpEvent() {
    $('._message_library_help_button_hide').click(function(){
      //return false;
    });
    $('.message_library_help_button_wrapper_hide').unbind('click').click(function(){
      $($(this).children('a').attr("href")).hide();
      $(this).find('._message_library_help_button_message').html(Drupal.t("show")).parents('._message_library_help_button_hide').removeClass('_message_library_help_button_hide').addClass('_message_library_help_button_show');
      $(this).removeClass('message_library_help_button_wrapper_hide').addClass('message_library_help_button_wrapper_show');
      initShowHelpEvent();
      return false;
    });
  }

  function initShowHelpEvent() {
    $('._message_library_help_button_show').click(function(){
      //return false;
    });
    $('.message_library_help_button_wrapper_show').unbind('click').click(function(){
      $($(this).children('a').attr("href")).show();
      $(this).find('._message_library_help_button_message').html(Drupal.t("hide")).parents('._message_library_help_button_show').removeClass('_message_library_help_button_show').addClass('_message_library_help_button_hide');
      $(this).removeClass('message_library_help_button_wrapper_show').addClass('message_library_help_button_wrapper_hide');
      initHideHelpEvent();
      return false;
    });
  }

// END jQuery
})(jQuery);
