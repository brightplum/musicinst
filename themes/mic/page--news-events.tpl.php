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
		    	    		
		    	    	</div>  <!-- end left-column -->
		    	    	
		    	    	<div class="news-middle-column">						    						    	
		    	    		
		    	    		<div class="main-content-wrapper">
		    	    			<?//php if ($messages): echo $messages; endif; ?>
		    					<?php echo $news_queue; ?>
		    	    		
		    	    		</div> <!-- news-middle-column -->
		    	    		
		    	    	</div> <!-- end middle-column -->
		    	    	
		    	    	<div class="news-right-column">
		    	    	
		    	    		<div class="inner-wrapper">
		    	    		
		    					<div class="listing-block-wrapper">
		    					
		    					    <div class="listing-block-top">
		    					    
		    					    	<span class="title left flat-blue-font">Upcoming Events</span>
		    					    	
		    							<div class="actions">
		    							    
		    							    <span class="see-all bold-font"><a href="<?php echo base_path(); ?>event-listings">See all</a></span>
		    							    <span class="rss">
		    							    	<a href="<?php echo base_path(); ?>rss" class="rss">Rss</a>
		    							    </span>
		    							    
		    							    <div class="clear"></div>
		    							    
		    							</div>
		    					    	
		    					    	<div class="clear"></div>
		    					    	
		    					    </div> <!-- end listing-block-top -->
		    					    
		    					    <div class="listing-block-bottom">
		    					    
										<?php echo $events_queue; ?>						    	
		    					    	
		    					    </div>  <!-- end listing-block-bottom -->
		    					
		    					</div>  <!-- end listing-block-wrapper -->
		
		    			    	<div class="news-feature-block-wrapper">
		    			    	
		    			    		<div class="listing-block-item first">
		    			    		
		    			    			<div class="listing-block-item-inner-wrapper">						
		    			    				
		    			    				<?php echo $taxonomy_blocks['feature_story']; ?>
		    			    				
		    			    			</div> <!-- end listing-block-item-inner-wrapper -->
		    			    			
		    			    		</div>  <!-- end listing-block-item -->
		    			    		
		    		    			<div class="listing-block-item">
		    		    			
		    		    			    <div class="listing-block-item-inner-wrapper">
		    		    			    	
		    								<?php echo $taxonomy_blocks['feature_video']; ?>
		    		    			    	
		    		    			    </div> <!-- end listing-block-item-inner-wrapper -->
		    						
		    						</div>  <!-- end listing-block-item -->	
		    						
		    						<div class="static-block-wrapper">
		    							
		    							<?php echo render($page['static_blocks']); ?>
		    							
		    						</div> <!-- end static-block-wrapper -->
		    					
		    			    	</div>
		        		
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