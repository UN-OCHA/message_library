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


// affiche le formulaire de login si besoin
function iaa_notices_warning_form_login(form) {
  $.ajax({
    type: "POST",
    url: '/iaa_notices_warning/formlogin',
    data: "nid="+$(form).children('._iaa_notices_warning_questions_id').val(),
    success: function(retour) {
      // puis on affiche le rendu
      $.fn.colorbox({html:retour});
      //$(form).parents('._iaa_notices_warning_questions').html(retour);
      iaa_notices_warning_form_login_action(form);
    },
    error: function () {
      alert(Drupal.t("An error occured getting login form."));
    }
  });
}

function iaa_notices_warning_form_login_action(form) {
  $('#iaa_notices_warning_form_login #user-login-form').submit(function(){
    $.ajax({
      type: "POST",
      url: '/iaa_notices_warning/login',
      data: $(this).serialize(),
      dataType: 'json',
      success: function(retour) {
        // puis on affiche le rendu
        if (retour.login) {
          $.fn.colorbox.close();
          window.location.reload(true);
        }
        else {
          alert(retour.message);
        }
        //$(form).parents('._iaa_notices_warning_questions').html(retour);
        //$.fn.colorbox.close();
      },
      error: function () {
        alert(Drupal.t("An error occured while getting the message."));
      }
    });
    return false;
  });
  $('#iaa_notices_warning_form_login ._iaa_notices_warning_form_login_no_account').click(function(){
    iaa_notices_warning_get_message(form);
    return false;
  });
}

// affiche le message en Ajax
function iaa_notices_warning_get_message(form) {
  $.ajax({
    type: "POST",
    url: '/iaa_notices_warning/getmessage',
    data: "nid="+$(form).children('._iaa_notices_warning_questions_id').val(),
    success: function(retour) {
      // puis on affiche le rendu
      $(form).parents('._iaa_notices_warning_questions').html(retour);
      $.fn.colorbox.close();
    },
    error: function () {
      alert(Drupal.t("An error occured while getting the message."));
    }
  });
}


//// displays the login form if necessary
//function iaa_notices_warning_cgi_accepted(form) {
//  $.ajax({
//    type: "POST",
//    url: $(form).attr('action'),
//    data: $(form).serialize(),
//    success: function(retour) {
//      location.href = $('#iaa_notices_warning_cgi_destination').val() ;
//    },
//    error: function () {
//      alert(Drupal.t("An error occured, please retry."));
//    }
//  });
//}


//affiche le formulaire de login si besoin
function iaa_notices_warning_cgi_form_login(form) {
  $.ajax({
    type: "POST",
    url: '/cgi-message-library/formlogin',
    success: function(retour) {
      //then displays the report
      $.fn.colorbox({html:retour});
      //$(form).parents('._iaa_notices_warning_questions').html(retour);
      iaa_notices_warning_cgi_form_login_action(form);
    },
    error: function () {
      alert(Drupal.t("An error occured getting login form."));
    }
  });
}

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
