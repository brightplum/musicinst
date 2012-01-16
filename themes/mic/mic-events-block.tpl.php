<?php if(isset($events)): ?>
	
	<?php foreach($events as $event): ?>
	    				    		
	    <div class="listing-block-item">
	    
	        <div class="listing-block-item-inner-wrapper">						
	        	
	        	<div class="item-blurb">
	        	
	        		<span class="title"><?php echo $event['title']; ?></span>
	        		
	        		<span class="sub-title"><?php echo $event['date']; ?></span>
	        									    				
	        		<?php echo $event['body']; ?>
	        	
	        	</div>
	        	
	        </div> <!-- end listing-block-item-inner-wrapper -->
	        
	    </div>  <!-- end listing-block-item -->
	
	<?php endforeach; ?>
	
<?php endif; ?>