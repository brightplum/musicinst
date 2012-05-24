
<div class="class-finder-wrapper">

    <div class="class-finder-inner-wrapper">

    	<div class="class-finder">

    		<form method="GET" accept-charset="UTF-8" action="<?php base_path(); ?>class-finder">

    			<div class="age">
    				<label for="age">Age</label>
    				<select name="age">
    					<option value="">Select one</option>
    					<?php foreach($filters['ages'] as $tid => $term): ?>
	    					<option value="<?php echo $tid; ?>"><?php echo $term; ?></option>
	    				<?php endforeach; ?>
    				</select>
    			</div>


    			<div class="program-area">
    				<label for="program_area">Program Area</label>
    				<select name="program_area">
    					<option value="">Select one</option>
    					<?php foreach($filters['program_areas'] as $tid => $term): ?>
	    					<option value="<?php echo $tid; ?>"><?php echo $term; ?></option>
	    				<?php endforeach; ?>
    				</select>
    			</div>

    			<div class="instrument">
    				<label for="instrument">Instrument</label>
    				<select name="instrument">
    					<option value="">Select one</option>
    					<?php foreach($filters['instruments'] as $tid => $term): ?>
	    					<option value="<?php echo $tid; ?>"><?php echo $term; ?></option>
	    				<?php endforeach; ?>
    				</select>
    			</div>

    			<div class="campus">
    				<label for="campus">Campus</label>
    				<select name="campus">
     					<option value="">Select one</option>
    					<?php foreach($filters['campuses'] as $tid => $term): ?>
	    					<option value="<?php echo $tid; ?>"><?php echo $term; ?></option>
	    				<?php endforeach; ?>
    				</select>																																									</div>

    			<div class="semester">
    				<label for="semester">Semester</label>
    				<select name="semester">
    					<option value="">Select one</option>
    					<?php foreach($filters['semesters'] as $tid => $term): ?>
	    					<option value="<?php echo $tid; ?>"><?php echo $term; ?></option>
	    				<?php endforeach; ?>
    				</select>																																									</div>

    			<div class="submit">
    				<input class="form-submit" type="submit" value="submit" name="submit" />
    			</div>

    		</form>

    	</div>

    </div>

</div>