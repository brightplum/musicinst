<?php
// $Id: calendar-month.tpl.php,v 1.10 2010/12/21 13:41:24 karens Exp $
/**
 * @file
 * Template to display a view as a calendar month.
 * 
 * @see template_preprocess_calendar_month.
 *
 * $day_names: An array of the day of week names for the table header.
 * $rows: An array of data for each day of the week.
 * $view: The view.
 * $calendar_links: Array of formatted links to other calendar displays - year, month, week, day.
 * $display_type: year, month, day, or week.
 * $block: Whether or not this calendar is in a block.
 * $min_date_formatted: The minimum date for this calendar in the format YYYY-MM-DD HH:MM:SS.
 * $max_date_formatted: The maximum date for this calendar in the format YYYY-MM-DD HH:MM:SS.
 * $date_id: a css id that is unique for this date, 
 *   it is in the form: calendar-nid-field_name-delta
 * 
 */
//dsm('Display: '. $display_type .': '. $min_date_formatted .' to '. $max_date_formatted);
?>

<?php if(count($rows) > 0): ?>

	<div class="month-view-wrapper">
	
		<div class="header">
			
			<div class="top">
				<span class="title"><?php echo date('F Y', strtotime($view->args[0])); ?></span>				
			</div>
			
			<div class="bottom">
				<?php $i = 1; ?>
				<?php foreach($day_names as $day): ?>
					<div class="day-name <?php echo $i % 2 == 0 ? 'even' : ''; ?> <?php echo $i == 7 ? 'last' : ''; ?>">
						<?php switch($day['data']) {
							case 'Sun':
								echo 'Sunday';
								break;
							case 'Mon':
								echo 'Monday';
								break;
							case 'Tue':
								echo 'Tuesday';
								break;
							case 'Wed':
								echo 'Wednesday';
								break;
							case 'Thu':
								echo 'Thursday';
								break;
							case 'Fri':
								echo 'Friday';
								break;
							case 'Sat':
								echo 'Saturday';
								break;
						} ?>
					</div>
					<?php $i++; ?>
				<?php endforeach; ?>
			
				<div class="clear"></div>
			</div>
			
		</div>
		
		<div class="body">
			
		    <?php foreach ((array) $rows as $row): ?>
		    	
		    	<div class="row">
					
					<?php $i = 1; ?>
		        	<?php foreach ($row as $cell): ?>
		          		
		          		<div class="cell <?php echo $i % 2 == 0 ? 'even' : ''; ?>">
		            		<?php print $cell['data']; ?>
		          		</div>
		          		
		          		<?php $i++; ?>
			        <?php endforeach; ?>
			        
			        <div class="clear"></div>
		        		    	
		    	</div>

		    <?php endforeach; ?>
		    
		</div>
		
		<div class="footer"></div>
		
	</div>
	
<?php endif; ?>
