
/**
 * @file
 * Attaches the behaviors for the Field Tooltips module.
 */

(function ($) {
    Drupal.behaviors.fieldTooltips = {
        attach: function (context, settings) {
            $('.hasqtip').each(function() {
                $(this).qtip({
                    content: {
                        text: $(this).parent().next('.tooltiptext')
                    }
                });
            });
        }
    };
}(jQuery));
