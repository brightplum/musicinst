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

		    		<?php if(array_key_exists('slideshow', $taxonomy_blocks)): ?>
		    			<?php echo $taxonomy_blocks['slideshow']; ?>
		    		<?php else: ?>
		    			<?php if($taxonomy_blocks['banner']): echo '<div style="margin:1px 0px 0px;">'.$taxonomy_blocks['banner'].'</div>'; endif; ?>
		    		<?php endif; ?>

		    	</div>

		    	<div class="right-column">

		    		<div class="listing-block-wrapper">

		    		    <div class="listing-block-top">

		    		    	<span class="title left blue-font">Upcoming Events</span>

		    				<div class="actions">

		    				    <span class="see-all bold-font"><a href="<?php echo $taxonomy_blocks['events-see-all']; ?>">See all</a></span>
		    				    <span class="rss">
		    				    	<a href="<?php echo base_path(); ?>rss" class="rss">Rss</a>
		    				    </span>

		    				    <div class="clear"></div>

		    				</div>

		    		    	<div class="clear"></div>

		    		    </div> <!-- end listing-block-top -->

		    		    <div class="listing-block-bottom">

		    		    	<?php echo $taxonomy_blocks['events']; ?>

		    		    </div>  <!-- end listing-block-bottom -->

		    		</div>  <!-- end listing-block-wrapper -->

		    	</div>

		    	<div class="clear"></div>

		    </div> <!-- end banner-inner-wrapper -->

		</div>  <!-- end banner-wrapper -->

		<div class="content-wrapper">

		    <div class="content-inner-wrapper">

		    	<div class="breadcrumb-wrapper">

		    		<?php echo $breadcrumb; ?>

		    	</div>

		    	<div class="primary-column-wrapper">

		    	    <div class="left-column">

		    	    	<div class="secondary-navigation-wrapper">

		    				<?php if($page['left_navigation']): echo render($page['left_navigation']); endif; ?>

		    	    	</div>

		    			<?php if(!empty($related_links)): ?>
		    				<div class="related-links-wrapper">

		    					<?php echo $related_links; ?>

		    			    </div>
		    			<?php endif; ?>

		    	    </div>

		    	    <div class="right-column">

		    	    	<div class="main-content-wrapper">

		    	    		<?php if ($title): echo '<h1>'.$title.'</h1>'; endif; ?>
		    				<?php if ($tabs): echo render($tabs); endif; ?>
		    				<?php echo render($page['content']); ?>

		    	    	</div>

		    	    </div>

		    	    <div class="clear"></div>

		    	</div> <!-- end primary-column-wrapper -->

		    	<div class="secondary-column-wrapper">

		    		<div class="static-block-wrapper">

		    			<?php echo render($page['static_blocks']); ?>

		    		</div>

		    		<div class="listing-block-wrapper">

		    			<?php if($node->field_show_feature_story['und'][0]['value'] && !empty($taxonomy_blocks['feature_story'])): ?>

		    			    <div class="listing-block-item first">

		    			    	<div class="listing-block-item-inner-wrapper">

		    			    		<?php echo $taxonomy_blocks['feature_story']; ?>

		    			    	</div> <!-- end listing-block-item-inner-wrapper -->

		    			    </div>  <!-- end listing-block-item -->

		    			<?php endif; ?>

		    		    <?php if($node->field_show_feature_video['und'][0]['value'] && !empty($taxonomy_blocks['feature_video'])): ?>

		    		    	<div class="listing-block-item">

		    		    	    <div class="listing-block-item-inner-wrapper">

		    						<?php echo $taxonomy_blocks['feature_video']; ?>

		    		    	    </div>

		    		    	</div>

		    		    <?php endif; ?>

		    		</div>  <!-- end listing-block-wrapper -->

		    	</div> <!-- end right-column -->

		    	<div class="clear"></div>

		    	<?php if($node->field_show_news_articles['und'][0]['value'] && !empty($taxonomy_blocks['news_articles'])): ?>

		    		<div class="content-listing-wrapper">

		    			<div class="content-listing-inner-wrapper">

		    				<div class="content-listing-top">

		    					<span class="title left red-font">News</span>

		    					<div class="actions">

		    					    <span class="see-all bold-font"><a href="<?php echo $taxonomy_blocks['news-articles-see-all']; ?>">See all</a></span>
		    					    <span class="rss">
		    					    	<a href="<?php echo base_path(); ?>rss" class="rss">Rss</a>
		    					    </span>

		    					    <div class="clear"></div>

		    					</div>

		    					<div class="clear"></div>

		    				</div>

		    				<div class="content-listing-bottom">

		    					<?php echo $taxonomy_blocks['news_articles']; ?>

		    					<div class="clear"></div>

		    				</div>

		    			</div>

		    		</div> <!-- end content-listing-wrapper -->

		    	<?php endif; ?>

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