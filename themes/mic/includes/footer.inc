<div class="top">

    <div class="left">
    	
    	<div class="footer-logo"><a href="<?php echo base_path(); ?>">Music Institute of Chicago</a></div>							
    	
    </div>
    
    <div class="right">
    	
    	<div class="top">
    		
    		<div class="footer-navigation">
    			
    			<?php 
    				$settings = variable_get('miscellaneous_settings', null);
    				$links = menu_navigation_links('menu-footer-menu'); 

    				if(isset($settings['social_links_label_footer']))
	    				$links[] = array('title' => $settings['social_links_label_footer']);
    			?>
    			<?php print theme('links', array(
    				'links' => $links,
    				'attributes' => array(
    					'id' => 'menu-footer-menu',
    					'class' => array('links'),
    				),
    			)); ?>
    		
    			
    		</div>
    		
    		<div class="social-links-horizontal">
    			
    			<ul>
                  <li class="facebook"><a href="<?php echo $settings['facebook_url']; ?>">FaceBook</a></li>
    			  <li class="youtube"><a href="<?php echo $settings['youtube_url']; ?>">YouTube</a></li>
    			  <li class="twitter"><a href="<?php echo $settings['twitter_url']; ?>">Twitter</a></li>
                  <li class="pinterest"><a href="http://www.pinterest.com/miccommunity/">Pinterest</a></li>
                  <li class="linkedin last"><a href="<?php echo $settings['linkedin_url']; ?>">LinkedIn</a></li>
    			</ul>
    												
    		</div>
    		
    		<div class="clear"></div>																
    	
    	</div>
    	
    </div>
    
    <div class="clear"></div>
    
</div>

<div class="bottom">												
    	
    <div class="footer-copyright">&copy; 2012 Music Institute of Chicago</div>					
    
</div>
