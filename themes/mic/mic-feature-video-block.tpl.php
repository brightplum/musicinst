<?php if($video): ?>
	
	
	<div class="img">
		<?php echo $video['img']; ?>
	</div>
	
	<a class="overlay" href="<?php echo base_path().$video['overlay_link']; ?>"></a>
	
	<div class="item-blurb">

    	<span class="call-out left">Video:</span>
    
	    <span class="video-title left margin-left-tiny"><?php echo $video['title']; ?></span>
    
    	<div class="clear"></div>
    
	    <p><?php echo $video['summary']; ?></p>

	</div>
	
<?php endif;