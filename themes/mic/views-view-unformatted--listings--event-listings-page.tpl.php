<?php
// $Id: views-view-unformatted.tpl.php,v 1.6.6.1 2010/03/29 20:05:38 dereine Exp $
/**
 * @file views-view-unformatted.tpl.php
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 */

?>

<?php foreach ($rows as $id => $row): ?>
	<div class="listing-block-item">
	
	    <div class="listing-block-item-inner-wrapper">	
		    
			<div class="item-blurb">
			
		    	<?php print $row; ?>
		    
		    </div>
		    
  		</div>
  		
  	</div>
<?php endforeach; ?>
