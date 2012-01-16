<?php if(isset($listings['main_story'])): ?>

	<div class="main-story-wrapper">
	
	    <h1 class="left"><?php echo $listings['title']; ?></h1>
	    
	    <div class="actions">
	        
	        <span class="see-all bold-font"><a href="<?php echo base_path(); ?>article-listings">See all</a></span>
	        <span class="rss">
	        	<a href="<?php echo base_path(); ?>rss" class="rss">Rss</a>
	        </span>
	        
	        <div class="clear"></div>
	        
	    </div>
	    
	    <div class="clear"></div>
	    
	    <?php echo $listings['main_story']['img']; ?>
	    
	    <span class="call-out">Main Story</span>
	    
	    <span class="title"><?php echo $listings['main_story']['title']; ?></span>
	    
		<?php echo $listings['main_story']['body']; ?>
	    
	</div>  <!-- end main-story-wrapper -->
	
<?php endif; ?>

<?php if(isset($listings['listings'])): ?>
	
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