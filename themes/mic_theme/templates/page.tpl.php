<?php
/**
 * @file
 * MIC Theme template to display a single Drupal page.
 *
 * Available variables:
 *
 * General utility variables:
 * - $base_path: The base URL path of the Drupal installation. At the very
 *   least, this will always default to /.
 * - $directory: The directory the template is located in, e.g. modules/system
 *   or themes/bartik.
 * - $is_front: TRUE if the current page is the front page.
 * - $logged_in: TRUE if the user is registered and signed in.
 * - $is_admin: TRUE if the user has permission to access administration pages.
 *
 * Site identity:
 * - $front_page: The URL of the front page. Use this instead of $base_path,
 *   when linking to the front page. This includes the language domain or
 *   prefix.
 * - $logo: The path to the logo image, as defined in theme configuration.
 * - $site_name: The name of the site, empty when display has been disabled
 *   in theme settings.
 * - $site_slogan: The slogan of the site, empty when display has been disabled
 *   in theme settings.
 *
 * Navigation:
 * - $main_menu (array): An array containing the Main menu links for the
 *   site, if they have been configured.
 * - $secondary_menu (array): An array containing the Secondary menu links for
 *   the site, if they have been configured.
 * - $breadcrumb: The breadcrumb trail for the current page.
 *
 * Page content (in order of occurrence in the default page.tpl.php):
 * - $title_prefix (array): An array containing additional output populated by
 *   modules, intended to be displayed in front of the main title tag that
 *   appears in the template.
 * - $title: The page title, for use in the actual HTML content.
 * - $title_suffix (array): An array containing additional output populated by
 *   modules, intended to be displayed after the main title tag that appears in
 *   the template.
 * - $messages: HTML for status and error messages. Should be displayed
 *   prominently.
 * - $tabs (array): Tabs linking to any sub-pages beneath the current page
 *   (e.g., the view and edit tabs when displaying a node).
 * - $action_links (array): Actions local to the page, such as 'Add menu' on the
 *   menu administration interface.
 * - $feed_icons: A string of all feed icons for the current page.
 * - $node: The node object, if there is an automatically-loaded node
 *   associated with the page, and the node ID is the second argument
 *   in the page's path (e.g. node/12345 and node/12345/revisions, but not
 *   comment/reply/12345).
 *
 *
 * @see template_preprocess()
 * @see template_preprocess_page()
 * @see template_process()
 */
?>

<div class="primary-wrapper">
  <div class="primary-wrapper-inner-wrapper">
    <div class="top-bar"></div>
      <div class="header-wrapper">
        <div class="header-inner-wrapper">
          <div class="top">
    				<div class="header-logo">
    					<a href="<?php print $base_path; ?>"><img src="<?php print $logo; ?>" /></a>
    				</div><!-- /header-logo -->
    				<div class="header-section-wrapper">
    					<div class="header-section first">
    					  <?php print render($page['header1']); ?>
    					</div>
    					<div class="header-section">
    					  <?php print render($page['header2']); ?>
    					</div>
    					<div class="header-section">
    					  <?php print render($page['header3']); ?>
    					</div>
    					<div class="header-section">
  					    <?php $settings = variable_get('miscellaneous_settings', null); ?>
						    <ul class="social-links-horizontal">
								  <li class="facebook"><a href="<?php echo $settings['facebook_url']; ?>"><span>FaceBook</span></a></li>
							    <li class="youtube"><a href="<?php echo $settings['youtube_url']; ?>"><span>YouTube</span></a></li>
							    <li class="twitter"><a href="<?php echo $settings['twitter_url']; ?>"><span>Twitter</span></a></li>
									<li class="flickr"><a href="<?php echo $settings['flickr_url']; ?>"><span>Flickr</span></a></li>
							    <li class="linkedin last"><a href="<?php echo $settings['linkedin_url']; ?>"><span>LinkedIn</span></a></li>
								</ul>
								<br />
    					  <?php print render($page['header4']); ?>
    					</div>
    					<div class="header-section last">
    					  <?php print render($page['header5']); ?>
    					</div>
    					<div class="clear"></div>
    				</div><!-- /header-section-wrapper -->
    				<div class="clear"></div>
          </div><!-- /top -->
		    	<div class="bottom">
            <div class="primary-navigation-wrapper">
              <div class="primary-navigation-inner-wrapper">
                <div class="primary-navigation">
                  <?php print render($navigation); ?>
		    				</div>
		    			</div> <!-- end primary-navigation-inner-wrapper -->
		    		</div> <!-- end primary-navigation-wrapper -->
		    	</div> <!-- end bottom -->
    		</div> <!-- end header-inner-wrapper -->
    	</div>  <!-- end header-wrapper -->

    	<?php if ($page['banner_left'] || $page['banner_right']): ?>
    	<!-- space for banner -->
      <div class="home-banner-wrapper">
        <div class="home-banner-inner-wrapper">

          <?php if ($page['banner_left']): ?>
            <div><?php print render($page['banner_left']); ?></div>
          <?php endif; ?>

          <?php if ($page['banner_right']): ?>
            <div><?php print render($page['banner_right']); ?></div>
          <?php endif; ?>

        	<div class="clear"></div>
        </div> <!-- /home-banner-inner-wrapper -->
      </div>  <!-- /home-banner-wrapper -->
      <?php endif; ?>

    	<div class="content-wrapper">
        <div class="content-inner-wrapper">
          <?php if ($breadcrumb): ?>
            <div class="breadcrumb-wrapper margin-top-large">
      	    <?php print $breadcrumb; ?>
      	    </div>
      	  <?php endif ; ?>
      	  <div class="body-wrapper">
            <div class="body-inner-wrapper">

              <?php if ($page['top']): ?>
                <?php print render($page['top']); ?>
              <?php endif; ?>

              <?php if ($page['sidebar_left']): ?>
              <div class="left-column">
			    <div class="secondary-navigation-wrapper">
                  <?php print render($page['sidebar_left']); ?>
                </div>
			  </div>  <!-- end left-column -->
			  <?php endif; ?>

				    	<?php if ($page['sidebar_left'] || $page['sidebar_right']) print '<div class="middle-column ' . $middle_column . '">'; ?>
                <div class="main-content-wrapper">
  	    	    		<?php if ($title): echo '<h1>'.$title.'</h1>'; endif; ?>
  	    	    		<?php if ($page['help'] || ($show_messages && $messages)): ?>
                    <div id="console">
                      <?php print render($page['help']); ?>
                      <?php if ($show_messages && $messages): print $messages; endif; ?>
                    </div>
                  <?php endif; ?>
  	    	    		<?php if ($tabs): echo render($tabs); endif; ?>
  	    	    		<?php echo render($page['content']); ?>
      	    	  </div><!-- /main-content-wrapper -->
      	    	<?php if ($page['sidebar_left'] || $page['sidebar_right']) print '</div><!-- /middle-column -->' ; ?>
      	    	<?php if ($page['sidebar_right']): ?>
      	    	<div class="right-column">
				    		<div class="inner-wrapper">
				    		  <?php print render($page['sidebar_right']); ?>
				        </div>
				    	</div> <!-- end right-column -->
				    	<?php endif; ?>
				    	<div class="clear"></div>
    	    	</div> <!-- end body-inner-wrapper -->
    	    </div> <!-- end body-wrapper -->
   	    	<div class="clear"></div>
   	    </div> <!-- end content-inner-wrapper -->
    	</div> <!-- end content-wrapper -->
    </div>  <!-- end primary-inner-wrapper -->
  </div>  <!-- end primary-wrapper -->

<div class="secondary-wrapper">
  <div class="secondary-wrapper-inner-wrapper">
   	<div class="footer-wrapper">
   		<div class="footer-inner-wrapper">
   			<div class="top">
          <div class="left">
          <?php print render($page['footer_left']); ?>
          </div>
          <div class="right">
            <div class="top">
              <div class="footer-navigation">
              <?php print render($page['footer_nav']); ?>
            	</div>
            	<div class="social-links-horizontal">
            	<?php print render($page['footer_social']); ?>
            	</div>
            	<div class="clear"></div>
            </div>
          </div>
          <div class="clear"></div>
        </div>
        <div class="bottom">
        <?php print render($page['footer_bottom']); ?>
        </div>
    	</div>
    </div>
  </div>
</div>