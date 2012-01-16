<form method="GET" accept-charset="UTF-8" action="<?php base_path(); ?>class-finder">

    <div class="left col">
    	
    	<div class="age">
    		<div class="left">
	    		<span class="bold-font">Age:</span>
    		</div>
    		<div class="right">
    			<select name="age">
    				<option value="">Select one</option>
    				<?php foreach($filters['ages'] as $tid => $term): ?>
    					<option value="<?php echo $tid; ?>" <?php echo $_GET['age'] == $tid ? 'selected' : ''; ?>><?php echo $term; ?></option>
    				<?php endforeach; ?>
    			</select>
    		</div>
    		<div class="clear"></div>
    	</div>
    	
    	
    	<div class="program-area">
    		<div class="left">
	    		<span class="bold-font">Program Area:</span>
    		</div>
    		<div class="right">
	    		<select name="interest">
    				<option value="">Select one</option>
    				<?php foreach($filters['program_areas'] as $tid => $term): ?>
    					<option value="<?php echo $tid; ?>" <?php echo $_GET['interest'] == $tid ? 'selected' : ''; ?>><?php echo $term; ?></option>
    				<?php endforeach; ?>
	    		</select>
    		</div>
    		<div class="clear"></div>
    	</div>
    	
    	<div class="instrument">
    		<div class="left">
    			<span class="bold-font">Instrument:</span>
    		</div>
    		<div class="right">
    			<select name="instrument">
    				<option value="">Select one</option>
    				<?php foreach($filters['instruments'] as $tid => $term): ?>
    					<option value="<?php echo $tid; ?>" <?php echo $_GET['instrument'] == $tid ? 'selected' : ''; ?>><?php echo $term; ?></option>
    				<?php endforeach; ?>
    			</select>
    		</div>
    		<div class="clear"></div>
    	</div>
    
    </div>
    
    <div class="right col">
    
    	<div class="campus">
			<div class="left">
				<span class="bold-font">Campus:</span>
			</div>
			<div class="right">
    	   		<select name="campus">
    	   			<option value="">Select one</option>
    	   			<?php foreach($filters['campuses'] as $tid => $term): ?>
    	   				<option value="<?php echo $tid; ?>" <?php echo $_GET['campus'] == $tid ? 'selected' : ''; ?>><?php echo $term; ?></option>
    	   			<?php endforeach; ?>
    	   		</select>																																									</div>
			<div class="clear"></div>
		</div>
    	   
    	<div class="semester">
			
			<div class="left">
				<span class="bold-font">Semester:</span>
			</div>
    	  	<div class="right">
				<select name="semester">
					<option value="">Select one</option>
					<?php foreach($filters['semesters'] as $tid => $term): ?>
						<option value="<?php echo $tid; ?>" <?php echo $_GET['semester'] == $tid ? 'selected' : ''; ?>><?php echo $term; ?></option>
					<?php endforeach; ?>
				</select>
    	  	</div>
    		<div class="clear"></div>   
		</div>
    	   
    	<div class="submit right clear">
    	   <input class="form-submit" type="submit" value="submit" name="submit" />
    	</div>
    
    </div>
    
    <div class="clear"></div>																	
    
</form>
    		