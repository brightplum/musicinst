<div class="primary-wrapper">
    
    <div class="primary-wrapper-inner-wrapper">
    	
    	<div class="top-bar"></div>

    	<div class="header-wrapper">
    		
    		<div class="header-inner-wrapper">
    		
    			<?php include('includes/header.inc'); ?>
    			
    		</div> <!-- end header-inner-wrapper -->
    		
    	</div>  <!-- end header-wrapper -->
    	
		<div class="banner-wrapper">
		
		    <div class="banner-inner-wrapper">											
		    	
		    	<div class="left-column">
		    	
		    		<?php if($taxonomy_blocks['banner']): echo '<div style="margin:1px 0px 0px;">'.$taxonomy_blocks['banner'].'</div>'; endif; ?> 
		    		
		    	</div>
		    	
		    	<div class="audience-right-column">
		    	
		    		<div class="listing-block-wrapper">
		    									    
		    		    <?php if($node->field_show_feature_story['und'][0]['value'] && !empty($taxonomy_blocks['feature_story'])): ?>
		    		    
		    		    	<div class="listing-block-item">
		    		    	
		    		    	    <div class="listing-block-item-inner-wrapper">
		    		    	    	
		    						<?php echo $taxonomy_blocks['feature_story']; ?>
		    		    	    	
		    		    	    </div> <!-- end listing-block-item-inner-wrapper -->
		    		    	    
		    		    	</div>  <!-- end listing-block-item -->
		    		    
		    		    <?php endif; ?>
		    		
		    		</div>  <!-- end listing-block-wrapper -->					
		    	
		    	</div>
		    	
		    	<div class="clear"></div>
		    	
		    </div> <!-- end banner-inner-wrapper -->
		
		</div>  <!-- end banner-wrapper -->
		
		<div class="content-wrapper">
		
		    <div class="content-inner-wrapper">					
		    	
		    	<div class="audience-primary-column-wrapper">
		    	
		    		<div class="audience-breadcrumb-wrapper">
		    		
		    			<?php echo $breadcrumb; ?>
		    			
		    		</div> <!-- end audience-breadcrumb-wrapper -->
		    		
		    	    <div class="main-content-wrapper">
		    	    
		    	    	<?php if ($title): echo '<h1>'.$title.'</h1>'; endif; ?>						    		
		    			<?php if ($tabs): echo render($tabs); endif; ?>
		    			<?php echo render($page['content']); ?>
		    	    
		    	    </div>
		    	
		    	</div> <!-- end audience-primary-column-wrapper -->
		    	
		    	<div class="audience-secondary-column-wrapper">
		
		    		<div class="announcements-static-block-wrapper">
		    		
		    		    <?php echo render($page['static_blocks']); ?>
		    		
		    		</div> <!-- end announcements-wrapper --> 
		    		
		    	</div> <!-- end audience-secondary-column-wrapper -->
		    	
		    	<div class="clear"></div>
		    	
		    	<?php if(!empty($gateway_links)): echo $gateway_links; endif; ?>
		    	
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