<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML+RDFa 1.0//EN"
  "http://www.w3.org/MarkUp/DTD/xhtml-rdfa-1.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="<?php print $language->language; ?>" version="XHTML+RDFa 1.0" dir="<?php print $language->dir; ?>"<?php print $rdf_namespaces; ?>>

<head profile="<?php print $grddl_profile; ?>">
	
	<?php print $head; ?>
	
	<title><?php print $head_title; ?></title>
	
	<link type="image/x-icon" href="<?php echo base_path() . $directory ?>/musicinstitute-v2.ico" rel="shortcut icon">
	
	<?php print $styles; ?>
	
	<?php print $scripts; ?>
	
</head>

	<body class="<?php print $classes; ?>" <?php print $attributes;?>>

		<?php print $page_top; ?>
		    			    			  
		<?php print $page; ?>
		
		<?php print $page_bottom; ?>
			
	</body>

<script>
  (function(i,s,o,g,r,a,m){i['GoogleAnalyticsObject']=r;i[r]=i[r]||function(){
    (i[r].q=i[r].q||[]).push(arguments)},i[r].l=1*new Date();a=s.createElement(o),
    m=s.getElementsByTagName(o)[0];a.async=1;a.src=g;m.parentNode.insertBefore(a,m)
  })(window,document,'script','//www.google-analytics.com/analytics.js','ga');

  ga('create', 'UA-52343846-1', 'auto');
  ga('send', 'pageview');

</script>
	
</html>
