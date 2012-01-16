<div class="listing-block-top">

    <span class="title left red-font"><?php echo $listings['title']; ?></span>
    
    <div class="actions">
    	
    	<span class="see-all bold-font"><a href="<?php echo base_path(); ?>article-listings">See all</a></span>
    	<span class="rss">
    		<a href="<?php echo base_path(); ?>rss" class="rss">Rss</a>
    	</span>
    	
    	<div class="clear"></div>
    	
    </div>
    
    <div class="clear"></div>
    
</div> <!-- end listing-block-top -->

<div class="listing-block-bottom">
	
	<?php if(count($listings['listings']) > 0): ?>
		
		<?php foreach($listings['listings'] as $item): ?>
		
			<div class="listing-block-item">
			
			    <div class="listing-block-item-inner-wrapper">
			    	
			    	<?php echo $item['img']; ?>																						
			    	
			    	<div class="item-blurb">
			    	
			    		<span class="title"><?php echo $item['title']; ?></span>
			    		
			    		<span class="sub-title"><?php echo $item['date']; ?></span>
			    		
			    		<?php echo $item['body']; ?>
			    	
			    	</div>
			    	
			    	<div class="clear"></div>
			    	
			    </div> <!-- end listing-block-item-inner-wrapper -->
			    									
			</div> <!-- end listing-block-item -->
		
		<?php endforeach; ?>
		
	<?php else: ?>
		
		<p>There are currently no news listings to display.</p>
		
	<?php endif; ?>
	
</div>  <!-- end listing-block-bottom -->