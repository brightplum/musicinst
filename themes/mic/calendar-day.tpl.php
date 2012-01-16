<?php
// $Id: calendar-day.tpl.php,v 1.13 2010/12/21 13:41:24 karens Exp $
/**
 * @file
 * Template to display a view as a calendar day, grouped by time
 * and optionally organized into columns by a field value.
 * 
 * @see template_preprocess_calendar_day.
 *
 * $rows: The rendered data for this day.
 * $rows['date'] - the date for this day, formatted as YYYY-MM-DD.
 * $rows['datebox'] - the formatted datebox for this day.
 * $rows['empty'] - empty text for this day, if no items were found.
 * $rows['all_day'] - an array of formatted all day items.
 * $rows['items'] - an array of timed items for the day.
 * $rows['items'][$time_period]['hour'] - the formatted hour for a time period.
 * $rows['items'][$time_period]['ampm'] - the formatted ampm value, if any for a time period.
 * $rows['items'][$time_period][$column]['values'] - An array of formatted 
 *   items for a time period and field column.
 * 
 * $view: The view.
 * $columns: an array of column names.
 * $min_date_formatted: The minimum date for this calendar in the format YYYY-MM-DD HH:MM:SS.
 * $max_date_formatted: The maximum date for this calendar in the format YYYY-MM-DD HH:MM:SS.
 * 
 * The width of the columns is dynamically set using <col></col> 
 * based on the number of columns presented. The values passed in will
 * work to set the 'hour' column to 10% and split the remaining columns 
 * evenly over the remaining 90% of the table.
 */
//dsm('Display: '. $display_type .': '. $min_date_formatted .' to '. $max_date_formatted);
?>

<?php if(count($rows['items']) > 0): ?>

	<div class="day-view-wrapper">
		
		<div class="header">
			<span class="title"><?php echo date('l F j, Y', strtotime($rows['date'])); ?></span>
		</div>
		<?//php print_r($items); ?>
		<div class="body">
	
			<?php $all_day = false; ?>
			<?php foreach ($columns as $column): ?>
				<?php if(isset($rows['all_day'][$column])): $all_day = true; break; endif; ?>		
			<?php endforeach ?>
			
			<?php if($all_day): ?>
				
				<div class="row">
				
					<div class="time">
					    <span class="calendar-hour"><?php print $hour['hour'].$hour['ampm']; ?></span>
					</div>
					<div class="items">
					    <?php foreach ($columns as $column): ?>
					    	<div class="item">
					    		<?php print isset($rows['all_day'][$column]) ? implode($rows['all_day'][$column]) : '&nbsp;';?>
					    	</div>
					    <?php endforeach; ?>
					</div>
					<div class="clear"></div>
			
				</div>
				
			<?php endif; ?>
				
			<?php foreach($rows['items'] as $key => $hour): ?>
				
				<div class="row">
					
					<div class="time">
						<?//php $time = strtotime($rows['date'] .' '. $key); ?>
			    	    <span class="calendar-hour"><?php print $hour['hour'].$hour['ampm']; ?></span>
					</div>
					<div class="items">
						<?php foreach ($columns as $column): ?>
							<div class="item">
								<?php print isset($hour['values'][$column]) ? implode($hour['values'][$column]) : '&nbsp;'; ?>
							</div>
						<?php endforeach; ?>
					</div>
					<div class="clear"></div>
					
				</div>
				
			<?php endforeach; ?>
			
		</div>
		
	</div>
	
<?php else: ?>
	<p>There are no events to display.</p>
<?php endif; ?>

