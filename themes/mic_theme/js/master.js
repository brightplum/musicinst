(function($) {

Drupal.behaviors.mic_mask = {
  attach: function (context, settings) {
    $(".form-phone", context).mask("(999) 999-9999");
    $(".form-date", context).mask("99/99/9999");
    $("#edit-line-item-fields-field-student-birthdate-und-0-value", context).mask("99/99/9999");
    $("#edit-line-item-fields-field-student-birthdate-und-0-value--2", context).mask("99/99/9999");
    $("#edit-line-item-fields-field-student-birthdate-und-0-value--3", context).mask("99/99/9999");
    $("#edit-line-item-fields-field-requested-time-und-0-value", context).mask("99:99");
    $("#edit-line-item-fields-field-requested-time-und-0-value--2", context).mask("99:99");
    $("#edit-line-item-fields-field-requested-time-und-0-value--3", context).mask("99:99");
  }
};

})(jQuery);
