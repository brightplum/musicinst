<div class="mBanner">
    
    <div class="loading">
        
        <div class="logo"></div>
        
        <div class="message"></div>
        
    </div>
    
    <div class="context">
        
        <div class="images"></div>
        
        <div class="box">
        
        	<div class="content"></div>
        	
        	<?php if(count($slideshow) > 1): ?>
	        	<div class="pager"></div>
	        <?php endif; ?>
        	
        </div>
        
    </div>
    
</div>							

<script type="text/javascript">
    
    jQuery(document).ready(function() {
    	
    	jQuery('.mBanner').mBanner(Array(
    		<?php $i = 0; ?>
    		<?php foreach($slideshow as $img): ?>							    		
        		{
        			image: '<?php echo $img['path']; ?>',
        			title: '<?php echo $img['title']; ?>',
        			message: '<?php echo str_replace("'","\'",$img['slideshow']); ?>'
        		}
        		<?php if($i < count($slideshow)-1): ?>
        		,
        		<?php endif; ?>
    		<?php $i++; endforeach; ?>
    	), 8000);
    	
    });
    
</script>