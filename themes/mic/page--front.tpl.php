<div class="primary-wrapper">
    
    <div class="primary-wrapper-inner-wrapper">
    	
    	<div class="top-bar"></div>

    	<div class="header-wrapper">
    		
    		<div class="header-inner-wrapper">
    		
    			<?php include('includes/header.inc'); ?>
    			
    		</div> <!-- end header-inner-wrapper -->
    		
    	</div>  <!-- end header-wrapper -->
    	
		<div class="home-banner-wrapper">
		
		    <div class="home-banner-inner-wrapper">
		    
		    	<div class="home-banner-jquery-wrapper">
		    		
		    		<div class="home-banner-jquery-wrapper">
		    			
		    			<?php echo $slideshow_queue; ?>
		    			
		    		</div>
		    		
		    	</div>
		    	
		    	<div class="calendar-wrapper">
		    	
					<?php echo render($page['homepage_calendar_block']); ?>		    
		    		
		    	</div>
		    	
		    	<div class="clear"></div>
		    	
		    </div> <!-- end banner-inner-wrapper -->
		
		</div>  <!-- end banner-wrapper -->
		
		<div class="content-wrapper">
		
		    <div class="content-inner-wrapper">
		    	
				<div class="home-body-wrapper">
								
					<div class="left-column">
					    
					    <div class="listing-block-wrapper">
					    
							<?php echo $news_queue; ?>	
					    
					    </div>  <!-- end listing-block-wrapper -->
					    
					</div> <!-- end left-column -->
					
					<div class="middle-column">
					
					    <div class="listing-block-wrapper">
					    	<?//php if ($messages): echo $messages; endif; ?>
					    	<?php echo $feature_queue; ?>
					    	
					    </div>	<!-- end listing-block-wrapper -->				
					    
					</div> <!-- end middle-column -->
					
					<div class="right-column">
					
					    <div class="inner-wrapper">
					    	
					    	<div class="inner-top">
					    		
					    		<span class="title">Private Lessons and Group Classes</span>
					    	
					    	</div>
					    	
					    	<div class="inner-bottom">

                              <?php print theme('links', array(
                                'links' => menu_navigation_links('menu-group-classes'),
                                'attributes' => array(
                                  'id' => 'group-classes',
                                  'class' => array('links'),
                                ),
                              )); ?>
					    	
					    	</div>
					    	
					    </div>								
					    
					</div> <!-- end right-column -->
					
					<div class="clear"></div>
								
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
