<?php
// $Id: search-results.tpl.php,v 1.7 2010/08/18 18:40:50 dries Exp $

/**
 * @file
 * Default theme implementation for displaying search results.
 *
 * This template collects each invocation of theme_search_result(). This and
 * the child template are dependent to one another sharing the markup for
 * definition lists.
 *
 * Note that modules may implement their own search type and theme function
 * completely bypassing this template.
 *
 * Available variables:
 * - $search_results: All results as it is rendered through
 *   search-result.tpl.php
 * - $module: The machine-readable name of the module (tab) being searched, such
 *   as "node" or "user".
 *
 *
 * @see template_preprocess_search_results()
 */
 //print_r($results);
?>

<?php if($search_results): ?>

	<div class="search-results <?php print $module; ?>-results">
		
		<h2>Search Results</h2>
		
		<?php for ($i = 0; $i < sizeof($results); $i++): ?>
			
			<?php if($results[$i]['type'] != 'Item - Banner'): ?>
			
				<div class="item<?php echo (($i == 0) ? ' first' : ''); ?><?php echo (($i == sizeof($results) - 1) ? ' last' : ''); ?>">
					
					<?php 
						$type = 'Page';
						switch($results[$i]['type']) {
							case 'Page - Standard':
							case 'Page - Landing':
							case 'Page - Audience Gateway': 
								$type = 'Page';
								break;
							case 'Page - Feature':
								$type = 'Feature';
								break;
							case 'Page - Video':
								$type = 'Video';
								break;
							case 'Page - Article':
								$type = 'Article';
								break;
							case 'Page - Event':
								$type = 'Event';
								break;
						}
					?>
					<span class="type"><?php print $type; ?></span>
					<span class="title">
						<a href="<?php print $results[$i]['link']; ?>"><?php print $results[$i]['title']; ?></a>
					</span>
					<?php if($results[$i]['node']->type != 'feature_video' && $results[$i]['node']->type != 'feature_story'): ?>
						<span class="snippet"><?php print $results[$i]['snippet']; ?></span>
					<?php else: ?>
						<span class="snippet"><?php print mic_get_display_body($results[$i]['node']->body['und'][0]).' ...'; ?></span>
					<?php endif; ?>
				
				</div>
			
			<?php endif; ?>
			
		<?php endfor; ?>
	
	</div>
	
	<?php echo $pager; ?>

<?php endif; ?>

