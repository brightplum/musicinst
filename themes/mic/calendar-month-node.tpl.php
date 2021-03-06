<?php
// $Id: calendar-month-node.tpl.php,v 1.9 2010/12/21 13:41:24 karens Exp $
/**
 * @file
 * Template to display a view item as a calendar month node.
 * 
 * $node 
 *   A node object for this calendar item. Note this is
 *   not a complete node object, but it will have $node->nid
 *   that you can use to load the full object, and
 *   $node->type to tell the content type of the node.
 * 
 * $fields
 *   An array of information for every field selected in the 'Fields'
 *   section of this view, formatted as requested in the View setup.
 * 
 * Calendar info for this individual calendar item is in local time --
 * the user timezone where configurable timezones are allowed and set,
 * otherwise the site timezone. If this item has extends over more than
 * one day, it has been broken apart into separate nodes for each calendar
 * date and calendar_start will be no earlier than the start of
 * the current day and calendar_end will be no later than the end
 * of the current day.
 * 
 * $calendar_start - A formatted datetime start date for this item.
 *   i.e. '2008-05-12 05:26:15'.
 * $calendar_end - A formatted datetime end date for this item,
 *   the same as the start date except for fields that have from/to
 *   fields defined, like Date module dates. 
 * $calendar_start_date - a PHP date object for the start time.
 * $calendar_end_date - a PHP date object for the end time.
 * 
 * You can use PHP date functions on the date object to display date
 * information in other ways, like:
 * 
 *   print date_format($calendar_start_date, 'l, j F Y - g:ia');
 * 
 * @see template_preprocess_calendar_month_node.
 */
?>
<div class="item">
  
	<div class="<?php print $node->date_id; ?> calendar monthview">
	
		<?php echo $node->node_title; ?>
    
    <!--
		<?php if(date('F j', $node->field_data_field_event_date_field_event_date_value) != date('F j', $node->field_data_field_event_date_field_event_date_value2)): ?>
		    <span class="date"><?php echo date('F j, g:i a', $node->field_data_field_event_date_field_event_date_value); ?> - <?php echo date('F j, g:i a', $node->field_data_field_event_date_field_event_date_value2); ?></span>
		<?php else: ?>
		    <span class="date"><?php echo date('g:i a', $node->field_data_field_event_date_field_event_date_value); ?> - <?php echo date('g:i a', $node->field_data_field_event_date_field_event_date_value2); ?></span>
		<?php endif; ?>
		
	-->
		
	</div>    
  
</div>
