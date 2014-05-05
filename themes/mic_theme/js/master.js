(function($) {

Drupal.behaviors.mic_mask = {
  attach: function (context, settings) {
    $(".form-phone", context).mask("(999) 999-9999");
    $(".form-date", context).mask("99/99/9999");
    $("#edit-birthdate", context).mask("99/99/9999");
    $("#edit-time", context).mask("99:99 aa");
  }
};

})(jQuery);
