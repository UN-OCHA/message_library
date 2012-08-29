(function ($) {

  Drupal.iaa_notices_warning = Drupal.export2rtf || {};

  Drupal.behaviors.iaa_notices_warning = function(context) {
    $('#iaa_notices_warning_cgi').submit(function(){
      var form = this;
      if (!$("#iaa_notices_warning_cgi_understand").attr('checked')) {
        alert(Drupal.t("You have to accept the conditions."));
      }
      else {
        // si il accepte, on regarde s'il veut se logguer ou pas
        if (!$("#iaa_notices_warning_cgi_login").attr('checked')) {
          iaa_notices_warning_cgi_accepted(form);
        }
        else {
          iaa_notices_warning_cgi_form_login(form);
        }
      }
      return false;
    });
  };

// END jQuery
})(jQuery);

function iaa_notices_warning_cgi_form_login_action(form) {
  $('#iaa_notices_warning_cgi_form_login #user-login-form').submit(function(){
    $.ajax({
      type: "POST",
      url: '/cgi-message-library/login',
      data: $(this).serialize(),
      dataType: 'json',
      success: function(retour) {
        // then displays the report
        if (retour.login) {
          iaa_notices_warning_cgi_accepted(form);
          $.fn.colorbox.close();
        }
        else {
          alert(retour.message);
        }
      },
      error: function () {
        alert(Drupal.t("An error occured, please retry."));
      }
    });
    return false;
  });
}
