		    			<div class="top">

		    				<div class="header-logo">
		    					<a href="<?php echo base_path(); ?>">Music Institute of Chicago</a>
		    				</div>

		    				<div class="header-section-wrapper">

		    					<div class="header-section first">

		    						<div class="header-section-inner-wrapper">
										<?php print theme('links', array(
											'links' => menu_navigation_links('menu-audience-navigation'),
		          							'attributes' => array(
		            							'id' => 'audience-navigation',
		            							'class' => array('links'),
		          							),
		        						)); ?>

		    						</div>

		    					</div>

		    					<div class="header-section">

		    						<div class="header-section-inner-wrapper">
										<?php print theme('links', array(
											'links' => menu_navigation_links('menu-tactical-navigation'),
		          							'attributes' => array(
		            							'id' => 'menu-tactical-navigation-1',
		            							'class' => array('links'),
		          							),
		        						)); ?>
		    						</div>

		    					</div>

		    					<div class="header-section">

		    						<div class="header-section-inner-wrapper">
										<?php print theme('links', array(
											'links' => menu_navigation_links('menu-tactical-navigation-2'),
		          							'attributes' => array(
		            							'id' => 'menu-tactical-navigation-2',
		            							'class' => array('links'),
		          							),
		        						)); ?>
		    						</div>

		    					</div>

		    					<div class="header-section">

		    						<div class="header-section-inner-wrapper">

		    							<div class="social-wrapper">

											<?php $settings = variable_get('miscellaneous_settings', null); ?>
											<?php if(isset($settings['social_links_label_header'])): ?>
		    									<!--<span class="bold-font"><?php echo $settings['social_links_label_header']; ?></span>-->
		    								<?php else: ?>
		    									<!--<span class="bold-font">Connect with MIC</span>-->
		    								<?php endif; ?>

		    								<div class="social-links-horizontal">

		    									<?php $settings = variable_get('miscellaneous_settings', null); ?>
		    									<ul>

		    									    <li class="facebook"><a href="<?php echo $settings['facebook_url']; ?>">FaceBook</a></li>

		    									    <li class="youtube"><a href="<?php echo $settings['youtube_url']; ?>">YouTube</a></li>

		    									    <li class="twitter"><a href="<?php echo $settings['twitter_url']; ?>">Twitter</a></li>

		    									<!--</ul>

		    									<ul>-->

		    										<li class="flickr"><a href="<?php echo $settings['flickr_url']; ?>">Flickr</a></li>

		    									    <li class="linkedin last"><a href="<?php echo $settings['linkedin_url']; ?>">LinkedIn</a></li>

		    									</ul>

		    								</div>

		    							</div>

		    							<div class="search">

											<?php if(isset($settings['search_label_header'])): ?>
		    									<!--<span><?php echo $settings['search_label_header']; ?></span>-->
		    								<?php else: ?>
		    									<span>Site Map</span>
		    								<?php endif; ?>

		    								<div class="search-form-wrapper">

		    									<?php echo render($page['header_search']); ?>
		    									<!--<form method="post" accept-charset="UTF-8" action="#">

		    										<input class="form-text" type="text" name="search" value="" />
		    										<input type="image" name="submit" value="Submit" src="<?php echo base_path() . $directory ?>/images/structure/header/search/search-btn.jpg" />
		    									</form>-->

		    								</div>

		    							</div>

		    						</div>

		    					</div>

		    					<div class="header-section last">

		    						<div class="header-section-inner-wrapper region">

		    						<?php if (module_exists('mic_commerce')): ?>

		    						<?php print mic_commerce_cart(); ?>

		    						<?php endif; ?>

		    						</div>

		    					</div>

		    					<div class="clear"></div>

		    				</div>

		    				<div class="clear"></div>

		    			</div>

		    			<div class="bottom">

		    				<div class="primary-navigation-wrapper">

		    					<div class="primary-navigation-inner-wrapper">

		    						<div class="primary-navigation">


<?php
	// THE GHETTONESS IS UNREAL!

    $link = menu_get_item();

	//if($link['href'] == 'search/node/\'');
	//	$link['href'] = 'node';

    $result = db_query("SELECT p1 FROM menu_links WHERE link_path='".check_plain($link['href'])."'");
    foreach($result as $parent) {

        if(isset($parent->p1)) {
            $m = menu_link_load($parent->p1);
//            print_r($m);
        }
    }
    if(isset($m)) {
    $primary_nav =
'
<ul>
	<li class="about-mic first"><a '.($m['link_path'] == 'node/85' ? ' class="active"' : ''). ' href="'. base_path().'about-music-institute-chicago">About MIC</a></li>
	<li class="community-music-school"><a '.($m['link_path'] == 'node/360' ? ' class="active"' : ''). ' href="'. base_path().'community-music-school">Community Music School</a></li>
	<li class="academy"><a '.($m['link_path'] == 'node/53' ? ' class="active"' : ''). ' href="'. base_path().'academy">Academy</a></li>
	<li class="creative-arts-therapy"><a '.($m['link_path'] == 'node/54' ? ' class="active"' : ''). ' href="'. base_path().'institute-therapy-through-arts">Creative Arts Therapy</a></li>
	<li class="nichols-concert-hall"><a '.($m['link_path'] == 'node/55' ? ' class="active"' : ''). ' href="'. base_path().'nichols-concert-hall">Nichols Concert Hall</a></li>
	<li class="alumni-association"><a '.($m['link_path'] == 'node/56' ? ' class="active"' : ''). ' href="'. base_path().'alumni-association">Alumni Association</a></li>
	<li class="giving last"><a '.($m['link_path'] == 'node/57' ? ' class="active"' : ''). ' href="'. base_path().'giving">Giving</a></li>
</ul>
';
	} else {
		$primary_nav =
'
<ul>
    <li class="about-mic first"><a href="'. base_path().'about-music-institute-chicago">About MIC</a></li>
    <li class="community-music-school"><a href="'. base_path().'community-music-school">Community Music School</a></li>
    <li class="academy"><a href="'. base_path().'academy">Academy</a></li>
    <li class="creative-arts-therapy"><a href="'. base_path().'institute-therapy-through-arts">Creative Arts Therapy</a></li>
    <li class="nichols-concert-hall"><a href="'. base_path().'nichols-concert-hall">Nichols Concert Hall</a></li>
    <li class="alumni-association"><a href="'. base_path().'alumni-association">Alumni Association</a></li>
    <li class="giving last"><a href="'. base_path().'giving">Giving</a></li>
</ul>
';

	}

?>
		    							<?php echo $primary_nav; ?>

		    						</div>

		    					</div> <!-- end primary-navigation-inner-wrapper -->

		    				</div> <!-- end primary-navigation-wrapper -->

		    			</div> <!-- end bottom -->