<?php

function mic_implementation_model($op = 'taxonomy-blocks', $type = 'standard_template_page', $args = array()) {
	
	switch($op) {
		
		case 'taxonomy-terms':
			return mic_implementation_get_taxomony_terms($args['type']);
			break;
		case 'taxonomy-blocks':
			return mic_implementation_get_taxonomy_blocks($type, $args);			
			break;
		case 'node-queues':
			return mic_implementation_get_nodequeues();			
			break;	
		case 'tags':
			return mic_implementation_get_tags();			
			break;
		case 'node-queue-nodes':
			return mic_implementation_get_nodequeue_nodes($args['qid']);			
			break;
		case 'listings':
			return mic_implementation_get_listings($type, $args['request']);
			break;
		case 'classes':
			return mic_implementation_get_classes($args);
			break;
		
	}
}

?>