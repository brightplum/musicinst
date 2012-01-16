<div class="listing-block-top">

    <span class="title left green-font"><?php echo $listings['title']; ?></span>									
    
</div>

<div class="listing-block-bottom">
			 
	<?php if(count($listings['listings']) > 0): ?>
	   	
	   	<?php $i = 0; ?>
	   	<?php foreach($listings['listings'] as $item): ?>
		
			<div class="listing-block-item">
			
			    <div class="listing-block-item-inner-wrapper">
			    	
			    	<?php if($i == 0): ?>
			    		<?php echo $item['media']; ?>
			    	<?php endif; ?>
			    	
			    	<div class="item-blurb">
			
			    		<?php if($item['type'] == 'video'): ?>
			    			<span class="call-out left">Video:</span>
			    			<span class="title left margin-left-tiny"><?php echo $item['title']; ?></span>
			    			<div class="clear"></div>
			    		<?php else: ?>
			    			<span class="title"><?php echo $item['title']; ?></span>
			    		<?php endif; ?>
			    		
			    		
			    		<?php echo $item['body']; ?>
			
			    	</div>											
			    	
			    </div> <!-- end listing-block-item-inner-wrapper -->
			    
			</div> <!-- end listing-block-item -->
	
			<?php $i++; ?>
			
		<?php endforeach; ?>
		
	<?php else: ?>
		
		<p>There are currently no features to display.</p>
		
	<?php endif; ?>
	
</div> <!-- end listing-block-bottom -->