<?php foreach($listings['events'] as $item): ?>

	<div class="listing-block-item">
	
	    <div class="listing-block-item-inner-wrapper">						
	    	
	    	<div class="item-blurb">
	    	
	    		<span class="title"><?php echo $item['title']; ?></span>
	    		
	    		<span class="sub-title"><?php echo $item['date']; ?></span>
	    									    				
	    		<?php echo $item['body']; ?>
	    	
	    	</div>
	    	
	    	<div class="clear"></div>
	    	
	    </div> <!-- end listing-block-item-inner-wrapper -->
	    
	</div>  <!-- end listing-block-item -->

<?php endforeach; ?>
