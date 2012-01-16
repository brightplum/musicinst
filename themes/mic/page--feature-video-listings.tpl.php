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
				    	
				    	<div class="middle-column">						    						    	
				    		
				    		<div class="main-content-wrapper">
		    	    			
		    	    			<div class="listings-wrapper">
									
									<?php if (!empty($title)): echo '<h1>'. $title .'</h1>'; endif; ?>
									<?php echo views_embed_view('listings', 'feature_video_listings_page'); ?>
									
		    	    			</div>
		    	    			
				    		
				    		</div>
				    		
				    	</div> <!-- end middle-column -->
				    	
				    	<div class="right-column">
				    	
				    		<div class="inner-wrapper">
				        		
				        		<div class="static-block-wrapper">
				        		
									<?php echo render($page['static_blocks']); ?>
									
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
		    	
