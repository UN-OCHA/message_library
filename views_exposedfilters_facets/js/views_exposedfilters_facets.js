(function ($) {
  Drupal.behaviors.messageLibraryExposedFilter = {
    attach: function (context, settings) {
      if (!$('.view-message-library .views-exposed-widgets').length) return;

      $('.view-message-library .view-filters').append('<div id="view-filters-facets"></div>');

      var list = '';
      var listHTML = '';

      // Iterate all exposed filters
      var exposedFilters = $('.view-filters .views-exposed-widget select, \
          .view-filters .views-exposed-widget input[type="text"]');

      exposedFilters.each(function() {
        // If input text, gets "value", else, gets "text"
        var thisVal = $(this).val();
        var allowedVals = ['All', '', 'Enter search terms'];

        if (!$.inArray(thisVal, allowedVals) && $(this).not('._not_show_filter')) {
          if ($(this).attr('type') == 'text') {
            value = $(this).val();
          }
          else {
            value = $('#'+$(this).attr('id')+' option:selected').text();
            if (value.substring(0,3) == ' - ') {
              value = value.substring(3);
            }
          }

          link = '<div class="exposedfilterscontainer">\n\
              <label>\n\
                + $(this).parents(".views-exposed-widget").children("label").html() + ':' \
              </label> \
              <em> + value+ </em> \
              <a class="_vef_facets pointer" id="vef_'+$(this).attr("id")+'">(remove)</a> \
            </div>';

          list += link;
        }
      });

      return;

        if ($("._bundleNameToFilter").size()>0) {
          list += '<div class="exposedfilterscontainer"><label>Bundle:</label> <em>'+$("._bundleNameToFilter").val()+'</em> <a href="/message-library">(remove)</a></div>';
        }

        if (list != '') {
          listHTML = "<h4>Currently Selected Criteria</h4>";
          if ($(".view-message-library .view-footer p").size()>0) {
            listHTML += "<div class='criteria_inline'><div class ='nb_result'>"+$(".view-message-library .view-footer p").html()+"</div></div>";
          }
          listHTML += list+'<input type="reset" class="form-reset" value="Reset Search" id="edit-reset2">';
        }
        else if ($(".view-message-library .view-footer p").size()>0) {
          listHTML = "<div class='no_criteria'><div class ='nb_result'>"+$(".view-message-library .view-footer p").html()+"</div></div>";
        }

        $('#view-filters-facets').html(listHTML);
        $("#edit-reset2,#edit-reset1").click(function(){
          $('.view-message-library .view-filters form .form-item :input')
           .not(':button, :submit, :reset, ._iaa_inline_help_form_id, ._iaa_inline_help_form_message')
           .val('')
           .removeAttr('checked')
           .removeAttr('selected');
          if ($('.view-message-library .view-filters form').attr("action").search("message-library-bundle") != '-1') {
            $('.view-message-library .view-filters form').unbind("submit").unbind("click").attr("action","/message-library").submit();
          }
          else {
            $('.view-message-library .view-filters form').submit();
          }
        });

        if ($(".view-message-library .views-exposed-widgets #edit-text").val() == '') {
          $(".view-message-library .views-exposed-widgets #edit-text").val("Enter search terms");
          $(".view-message-library .views-exposed-widgets #edit-text").addClass("graytext");
        }

        $(".view-message-library form").submit(function(){
          if ($(".view-message-library .views-exposed-widgets #edit-text").val() == "Enter search terms") {
            $(".view-message-library .views-exposed-widgets #edit-text").val("");
          }
        });

        $(".view-message-library .views-exposed-widgets #edit-text").focus(function(){
          $(".view-message-library .views-exposed-widgets #edit-text").removeClass("graytext");
          if ($(".view-message-library .views-exposed-widgets #edit-text").val() == "Enter search terms") {
            $(".view-message-library .views-exposed-widgets #edit-text").val("");
          }
        });

        $(".view-message-library .views-exposed-widgets #edit-text").blur(function(){
          if ($(".view-message-library .views-exposed-widgets #edit-text").val() == "") {
            $(".view-message-library .views-exposed-widgets #edit-text").addClass("graytext");
            $(".view-message-library .views-exposed-widgets #edit-text").val("Enter search terms");
          }
        });

        $('.ac_results').remove();


//        $.each(Drupal.settings.search_autocomplete, function(key, value) {
//          var obj = 'Drupal.settings.search_autocomplete.' + key;
//          $(eval(obj + '.selector') + ' input:first').autocomplete(
//            eval(obj + '.url'), {
//            //"http://sited6.axiomcafe.fr/search_autocomplete/1/autocomplete/l", {
//            dataType: "json",
//            cacheLength : 20,
//            matchContains: true,
//            minChars: eval(obj + '.minChars'),
//            selectFirst: false,
//            max: eval(obj + '.max_sug')
//          }).result(function () {
//            $(this).get(0).form.submit();
//          }).focus();
//        });


      $("._vef_facets").click(function(){
        var idParent = $(this).attr("id").substring(4);
        if ($("#"+idParent).attr("type") == "text") {
          $("#"+idParent).val("");
        }
        else {
          $("#"+idParent).attr("selectedIndex",0);
        }
        $("#"+idParent).parents("form").submit();
        return false;
      });
    }
  }
})(jQuery);


