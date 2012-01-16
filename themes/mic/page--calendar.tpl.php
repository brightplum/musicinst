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
		    	
		    	<div class="margin-top-small"></div>
		    	
		    	<div class="body-wrapper-no-border">
		    	    
		    	    <div class="body-inner-wrapper">
		    	    
		    	    	<div class="calendar-wrapper">
		      				
		      				<?//php if ($messages): echo $messages; endif; ?>      				
							
							<div class="top">
								
								<?php echo render($page['content']); ?>	
								
							</div>
							
		    	    	</div>
		    	    
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
					
    	
