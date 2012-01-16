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
    	    	    
    	    	    	<div class="main-content-wrapper">
    	      				<?php if (($messages) && (arg(0) != 'search')): echo $messages; endif; ?>      				
    	    	    		<?php if ($title): echo '<h1 style="margin: 20px 0px; color: #455561;">'.$title.'</h1>'; endif; ?>
    	    	    		<?php if ($tabs): echo render($tabs); endif; ?>
    	    	    		<ul class="action-links"><?php print render($action_links); ?></ul>
    	    	    		<?php echo render($page['content']); ?>
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
