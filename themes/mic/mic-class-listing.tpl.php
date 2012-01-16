<?php echo $class['course']; ?><br/>
<span class="liven-up"><?php echo $class['campus']; ?> | Start Date: <?php echo date('n/j/Y', $class['start_date']); ?> | <?php echo $class['day_of_week']; ?> <?php echo $class['time']; ?></span>
<!--<span class="bold-font">Ages:</span> <?php echo $class['ages']; ?><br/>-->
<!--<span class="bold-font">Instruments:</span> <?php echo $class['instruments']; ?><br/>-->
<span class="bold-font">Program Area:</span> <?php echo $class['interests']; ?>
<br/>
<br/>
<?php if($class['status'] != 'Open'): ?>
	<?php echo $class['status']; ?>
	<br/>
	<br/>	
<?php endif; ?>
$<?php echo $class['price']; ?>&nbsp;for&nbsp;<?php echo $class['duration']; ?>
<?php if(isset($class['instructor'])): ?>
    &nbsp;|&nbsp;<?php echo $class['instructor']; ?>
<?php endif; ?>

