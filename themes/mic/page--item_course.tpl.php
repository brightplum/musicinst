<div class="primary-wrapper">

    <div class="primary-wrapper-inner-wrapper">

    	<div class="top-bar"></div>

    	<div class="header-wrapper">

    		<div class="header-inner-wrapper">

    			<?php include('includes/header.inc'); ?>

    		</div> <!-- end header-inner-wrapper -->

    	</div>  <!-- end header-wrapper -->

		<div class="content-wrapper">

		    <div class="content-inner-wrapper">

		    	<div class="breadcrumb-wrapper margin-top-large">

					<?php echo $breadcrumb; ?>

		    	</div>

				<div class="body-wrapper">

				    <div class="body-inner-wrapper">

				    	<div class="left-column">

				    		<div class="secondary-navigation-wrapper">

				    			<?php if($left_navigation): echo $left_navigation; endif; ?>

				    		</div>

				    		<?php if(!empty($taxonomy_blocks['events'])): ?>

				    			<div class="listing-block-wrapper">

				    				<div class="listing-block-top">

				    					<span class="title blue-font">Upcoming Events</span>

				    				</div> <!-- end listing-block-top -->

				    				<div class="listing-block-bottom">

										<?php echo $taxonomy_blocks['events']; ?>

				    	    		</div> <!-- end lising block-bottom -->

				    	    	</div> <!-- end listing-block-wrapper -->

				    	    <?php endif; ?>


				    	</div>  <!-- end left-column -->

				    	<div class="middle-column">

				    		<div class="main-content-wrapper">
								<h1><?php if ($title): echo $title.' '; endif; ?></h1>
		    	    			<?php if ($tabs): echo render($tabs); endif; ?>

								<?php echo $course['body']; ?><br/>
								<!--<span class="bold-font">Ages: </span><?php echo $course['ages']; ?><br/>-->
								<!--<span class="bold-font">Instruments: </span><?php echo $course['instruments']; ?><br/><br/>-->
								<span class="bold-font">Program Area: </span><?php echo $course['interests']; ?><br/>
								<?php if(!empty($course['requirements'])): ?>
									<br/>
									<span class="bold-font">Requirements: </span><?php echo $course['requirements']; ?><br/>
								<?php else: ?>
									<br/>
								<?php endif; ?>

								<?php if($course['show_semester']): ?>
									<br/>
									<span class="bold-font">
										Fall: $<?php echo $course['fall_price']; ?> per <?php echo $course['fall_semester_duration'];?> semester
										 | plus $<?php echo $course['fall_materials_fee']; ?> materials fee |
										<?php echo $course['fall_class_duration']; ?> class
									</span>
									<br/>
									<span class="bold-font">
										Summer: $<?php echo $course['summer_price']; ?> per <?php echo $course['summer_semester_duration'];?> semester
										 | plus $<?php echo $course['summer_materials_fee']; ?> materials fee |
										<?php echo $course['summer_class_duration']; ?> class
									</span>
									<br/>
									<span class="bold-font">
										Spring: $<?php echo $course['spring_price']; ?> per <?php echo $course['spring_semester_duration'];?> semester
										 | plus $<?php echo $course['spring_materials_fee']; ?> materials fee |
										<?php echo $course['spring_class_duration']; ?> class
									</span>
									<br/>

								<?php endif; ?>

								<?php if(count($course['classes']) > 0): ?>
									<br/><br/>
									<table cellspacing="1">
										<tr>
											<th width="15%" class="bold-font">Day</th>
											<th width="15%" class="bold-font">Time</th>
											<th width="15%" class="bold-font">Start Date</th>
											<th width="20%" class="bold-font">Location</th>
											<th width="15%" class="bold-font">Instructor</th>
											<th width="20%" class="bold-font"></th>
										</tr>
										<?php foreach($course['classes'] as $class): ?>
											<?php if($class[5] == 'At Capacity' || $class[5] == 'Cancelled'): ?>
											    <tr>
											    	<td width="20%" class="italics-font"><?php echo $class[0]; ?></td>
											    	<td width="20%" class="italics-font"><?php echo $class[1]; ?></td>
											    	<td width="20%" class="italics-font"><?php echo date('n/j/Y', $class[2]); ?></td>
											    	<td width="20%" class="italics-font"><?php echo $class[3]; ?></td>
											    	<td width="20%" class="italics-font"><?php echo $class[4]; ?></td>
											    	<td width="20%" class="italics-font"><?php echo $class[8]; ?></td>
											    </tr>
											    <tr>
											    	<td colspan="5" class="bold-font"><div style="margin:7px 0px 7px 15px;"><?php echo $class[5]; ?></div></td>
											    </tr>
											<?php else: ?>
											    <tr>
											    	<td width="20%"><?php echo $class[0]; ?></td>
											    	<td width="20%" ><?php echo $class[1]; ?></td>
											    	<td width="20%"><?php echo date('n/j/Y', $class[2]); ?></td>
											    	<td width="20%"><?php echo $class[3]; ?></td>
											    	<td width="20%"><?php echo $class[4]; ?></td>
											    	<td width="20%"><?php echo $class[8]; ?></td>
											    </tr>
											<?php endif; ?>

											<?php if($class[6]): ?>
												<tr>
													<td class="italics-font" colspan="5"><div style="margin:7px 0px 7px 15px;"><?php echo $class[7]; ?></div></td>
												</tr>
											<?php endif; ?>
										<?php endforeach; ?>
									</table>

								<?php endif; ?>

								<?php echo $course['signup_url']; ?>

				    		</div>

				    	</div> <!-- end middle-column -->

				    	<div class="right-column">

				    		<div class="inner-wrapper">

								<?php if(!empty($taxonomy_blocks['feature_story'])): ?>

				    	    		<div class="listing-block-item first">

				    	    			<div class="listing-block-item-inner-wrapper">

				    	    				<?php echo $taxonomy_blocks['feature_story']; ?>

				    	    			</div> <!-- end listing-block-item-inner-wrapper -->

				    	    		</div>  <!-- end listing-block-item -->

				    	    	<?php endif; ?>

								<?php if(!empty($taxonomy_blocks['feature_video'])): ?>

								    <div class="listing-block-item">

								        <div class="listing-block-item-inner-wrapper">

								    		<?php echo $taxonomy_blocks['feature_video']; ?>

								        </div>

								    </div>

								<?php endif; ?>

				        	</div>

				    	</div> <!-- end right-column -->

				    	<div class="clear"></div>

				    </div> <!-- end body-inner-wrapper -->

				</div> <!-- end body-wrapper -->

		    	<div class="clear"></div>

		    </div> <!-- end content-inner-wrapper -->

		</div> <!-- end content-wrapper -->

    </div>  <!-- end primary-inner-wrapper -->

</div>  <!-- end primary-wrapper -->

<div class="secondary-wrapper">

    <div class="secondary-wrapper-inner-wrapper">

    	<div class="footer-wrapper">

    		<div class="footer-inner-wrapper">

    			<?php include('includes/footer.inc'); ?>

    		</div>

    	</div>

    </div>

</div>

