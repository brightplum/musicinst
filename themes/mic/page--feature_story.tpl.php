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
				    	    
				    	    <!--
				    	    <div class="related-links-wrapper">
				    	    
				    	    	<span class="title">Related Links</span>
				    	    	
				    	    	<a href="#">Lorem ipsum dolor sit amet allda peepo say...</a>
				    	    	<a href="#">Nulla turpis nibh, accumsan at euismod in...</a>
				    	    	<a href="#">In at eros vitae mauris consectetur consequat...</a>								    									    	
				    	    
				    	    </div>
				    		-->
				    		
				    	</div>  <!-- end left-column -->
				    	
				    	<div class="middle-column">						    						    	
				    		
				    		<div class="main-content-wrapper">
				    				    			
								<?php if ($title): echo '<h1>'.$title.'</h1>'; endif; ?>
		    	    			<?php if ($tabs): echo render($tabs); endif; ?>
		    	    			
		    	    			<div class="banner-image-wrapper">
			    	    			<?php echo $feature_story['img']; ?>
		    	    			</div>
		    	    			
		    	    			<?php echo $feature_story['subtitle']; ?>
		    	    			<?php echo $feature_story['body']; ?>
				    		
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