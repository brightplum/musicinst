<?php if(isset($articles)): ?>

	<?php foreach($articles as $a): ?>
	
		<div class="listing-block-item">
		
		    <div class="listing-block-item-inner-wrapper">
		        
		        <?php echo $a['img']; ?>		
		        
		        <div class="item-blurb">
		        
		        	<span class="title"><?php echo $a['title']; ?></span>
		        	
		        	<span class="sub-title"><?php echo $a['date']; ?></span>
		        	
		        	<?php echo $a['body']; ?>
		        
		        </div>
		        
		        <div class="clear"></div>
		        
		    </div> <!-- end listing-block-item-inner-wrapper -->
		
		</div> <!-- end listing-block-item -->
		
	<?php endforeach; ?>

<?php endif; ?>