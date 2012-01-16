<?php
// $Id: calendar-main.tpl.php,v 1.8 2010/12/21 13:41:24 karens Exp $
/**
 * @file
 * Template to display calendar navigation and links.
 * 
 * @see template_preprocess_calendar_main.
 *
 * $view: The view.
 * $calendar_links: Array of formatted links to other calendar displays - year, month, week, day.
 * $calendar_popup: The popup calendar date selector.
 * $display_type: year, month, day, or week.
 * $mini: Whether this is a mini view.
 * $min_date_formatted: The minimum date for this calendar in the format YYYY-MM-DD HH:MM:SS.
 * $max_date_formatted: The maximum date for this calendar in the format YYYY-MM-DD HH:MM:SS.
 * 
 */
//dsm('Display: '. $display_type .': '. $min_date_formatted .' to '. $max_date_formatted);
$links = array(
  'links' => $calendar_links, 
  'attributes' => array('class' => 'inline'),
);
?>

<?php if (empty($block)): ?>
	
	<div class="left-column">

		<h1><?php echo $view->display['default']->display_options['title']; ?></h1>
							
	</div>

	<div class="middle-column">
		
		<?php print theme('date_navigation', array('view' => $view)) ?>
		
	</div>
	
	<div class="right-column">
	
		<div class="links-wrapper">
			<span class="call-out">View by:</span>
			<?php print theme('links', $links);?>
		</div>
		<div class="clear"></div>

	</div>
	
	<div class="clear"></div>
	
<?php else: ?>
	
	<?php print theme('date_navigation', array('view' => $view)) ?>
	
<?php endif; ?>

