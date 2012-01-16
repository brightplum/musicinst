<?php
// $Id: calendar-week.tpl.php,v 1.10 2010/12/21 13:41:24 karens Exp $
/**
 * @file
 * Template to display a view as a calendar week.
 * 
 * @see template_preprocess_calendar_week.
 *
 * $day_names: An array of the day of week names for the table header.
 * $rows: The rendered data for this week.
 * 
 * For each day of the week, you have:
 * $rows['date'] - the date for this day, formatted as YYYY-MM-DD.
 * $rows['datebox'] - the formatted datebox for this day.
 * $rows['empty'] - empty text for this day, if no items were found.
 * $rows['all_day'] - an array of formatted all day items.
 * $rows['items'] - an array of timed items for the day.
 * $rows['items'][$time_period]['hour'] - the formatted hour for a time period.
 * $rows['items'][$time_period]['ampm'] - the formatted ampm value, if any for a time period.
 * $rows['items'][$time_period]['values'] - An array of formatted items for a time period.
 * 
 * $view: The view.
 * $min_date_formatted: The minimum date for this calendar in the format YYYY-MM-DD HH:MM:SS.
 * $max_date_formatted: The maximum date for this calendar in the format YYYY-MM-DD HH:MM:SS.
 * 
 */
//dsm('Display: '. $display_type .': '. $min_date_formatted .' to '. $max_date_formatted);
//dsm($rows);
//dsm($items);
?>
<?php if(count($items) > 0): ?>

	<div class="week-view-wrapper">
		<?php foreach ($rows as $day): ?>
			<div class="day-header">
				<?php $date = strtotime($day['date']); ?>
				<span class="day_name"><a href="<?php echo base_path(); ?>calendar/<?php echo $day['date']; ?>"><?php print date('l', $date); ?></a></span>
				<span class="day_num"><a href="<?php echo base_path(); ?>calendar/<?php echo $day['date']; ?>"><?php print date('j', $date); ?></a></span>
			</div>
		<?php endforeach; ?>
		<div class="clear"></div>
		
		<div class="day-body-wrapper">
			<?php foreach ($rows as $day): ?>
				<div class="day-body">
					<?php $date = strtotime($day['date']); ?>
					<div class="item-wrapper">
						
						<?php foreach($day['items'] as $time => $node): ?>
							<?php if((date('j', $date) == date('j', $node[0]->field_data_field_event_date_field_event_date_value)) || (date('j', $date) == date('j', $node[0]->field_data_field_event_date_field_event_date_value2)) || ($date >= $node[0]->field_data_field_event_date_field_event_date_value && $date <= $node[0]->field_data_field_event_date_field_event_date_value2) ): ?>
							
								<?//php if(date('j', $date) == 2): print_r($node); endif; ?>
								<?php foreach($node as $n): ?>
								
								<span class="title"><?php echo $n->node_title; ?></span>
								
								<?php if(date('F j', $n->field_data_field_event_date_field_event_date_value) != date('F j', $n->field_data_field_event_date_field_event_date_value2) ): ?>
									<span class="date"><?php echo date('F j, g:i a', $n->field_data_field_event_date_field_event_date_value); ?> - <?php echo date('F j, g:i a', $n->field_data_field_event_date_field_event_date_value2); ?></span>
								<?php else: ?>
									<span class="date"><?php echo date('g:i a', $n->field_data_field_event_date_field_event_date_value); ?><!-- - <?php echo date('g:i a', $n->field_data_field_event_date_field_event_date_value2); ?>--></span>
								<?php endif; ?>
								
								<?php echo mic_get_display_body($n->_field_data['nid']['entity']->body['und'][0]); ?>
								<div style="margin: 0px 0px 20px;"></div>
								
								<?php endforeach; ?>
								
							<?php else: ?>

							<?php endif; ?>
						<?php endforeach; ?>
					</div>
				</div>
			<?php endforeach; ?>
			<div class="clear"></div>
		</div>
		
	</div>

<?php else: ?>
	<p>There are no events to display for this week.</p>
<?php endif; ?>