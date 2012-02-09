<?php

function mic_implementation_preprocess_page(&$variables) {

    if($variables['is_front']) {

    	$settings = variable_get('homepage_settings', null);

    	// class finder widget
    	$ages = mic_implementation_model('taxonomy-terms', 'homepage_classfinder', array('type'=>'ages'));
    	$program_areas = mic_implementation_model('taxonomy-terms', 'homepage_classfinder', array('type'=>'program_areas'));
    	$instruments = mic_implementation_model('taxonomy-terms', 'homepage_classfinder', array('type'=>'instruments'));
    	$campuses = mic_implementation_model('taxonomy-terms', 'homepage_classfinder', array('type'=>'campuses'));
    	$semesters = mic_implementation_model('taxonomy-terms', 'homepage_classfinder', array('type'=>'semesters'));

    	// feature / news lists
	    $news_queue_nodes = mic_implementation_model('node-queue-nodes', 'homepage_news', array('qid' => $settings['news_queue']));
	    $slideshow_queue_nodes = mic_implementation_model('node-queue-nodes', 'homepage_slideshow', array('qid' => $settings['slideshow_queue']));
	    $feature_queue_nodes = mic_implementation_model('node-queue-nodes', 'homepage_feature', array('qid' => $settings['feature_queue']));

	    $variables['classfinder_widget'] = theme('mic_homepage_classfinder', array('ages'=>$ages, 'program_areas'=>$program_areas, 'instruments'=>$instruments, 'campuses'=>$campuses, 'semesters'=>$semesters));
	    $variables['news_queue'] = theme('mic_homepage_news_list', array('news_queue_nodes' => $news_queue_nodes, 'title' => $settings['news_name']));
	    $variables['slideshow_queue'] = theme('mic_homepage_slideshow', array('slideshow_queue_nodes' => $slideshow_queue_nodes));
	    $variables['feature_queue'] = theme('mic_homepage_feature_list', array('feature_queue_nodes' => $feature_queue_nodes, 'title' => $settings['feature_name']));

    }

	// set node type template pages
	if (isset($variables['node']) && !arg(2) == 'edit') {
    	$variables['theme_hook_suggestions'][] = 'page__'. $variables['node']->type;

    	// return taxonomy blocks
    	switch($variables['node']->type) {

    		case 'standard_template_page':
    			$variables['taxonomy_blocks'] = mic_implementation_model('taxonomy-blocks', $variables['node']->type, array('node'=>$variables['node']));
    			$variables['related_links'] = theme('mic_related_links', array('node' => $variables['node']));
    			break;
    		case 'landing_page':
    			$variables['taxonomy_blocks'] = mic_implementation_model('taxonomy-blocks', $variables['node']->type, array('node'=>$variables['node']));
    			$variables['related_links'] = theme('mic_related_links', array('node' => $variables['node']));
    			break;
			case 'audience_gateway_page':
				$variables['taxonomy_blocks'] = mic_implementation_model('taxonomy-blocks', $variables['node']->type, array('node'=>$variables['node']));
				$variables['gateway_links'] = theme('mic_gateway_links', array('node' => $variables['node']));
				break;
    		case 'feature_story':
    			$variables['feature_story'] = theme('mic_feature_story', array('node' => $variables['node']));
    			$variables['taxonomy_blocks'] = mic_implementation_model('taxonomy-blocks', $variables['node']->type, array('node'=>$variables['node']));
    			break;
    		case 'feature_video':
    			$variables['feature_video'] = theme('mic_feature_video', array('node' => $variables['node']));
    			$variables['taxonomy_blocks'] = mic_implementation_model('taxonomy-blocks', $variables['node']->type, array('node'=>$variables['node']));
    			break;
    		case 'event':
				$variables['event'] = theme('mic_event', array('node' => $variables['node']));
    			$variables['taxonomy_blocks'] = mic_implementation_model('taxonomy-blocks', $variables['node']->type, array('node'=>$variables['node']));
    			break;
    		case 'news_article':
    			$variables['news_article'] = theme('mic_news_article', array('node' => $variables['node']));
    			$variables['taxonomy_blocks'] = mic_implementation_model('taxonomy-blocks', $variables['node']->type, array('node'=>$variables['node']));
    			break;
    		case 'profile':
				$variables['profile'] = theme('mic_profile', array('node' => $variables['node']));
    			$variables['taxonomy_blocks'] = mic_implementation_model('taxonomy-blocks', $variables['node']->type, array('node'=>$variables['node']));
    			break;
    		case 'item_course':
    			$variables['course'] = theme('mic_course', array('node' => $variables['node']));
    			$variables['taxonomy_blocks'] = mic_implementation_model('taxonomy-blocks', $variables['node']->type, array('node'=>$variables['node']));
    			break;
    	}
    }

    if(arg(0) == 'class-finder') {

    	$variables['theme_hook_suggestions'][] = 'page__class_finder';

		$classes = mic_implementation_model('classes', 'homepage_classfinder', $_GET);

		foreach($classes as $class) {
			$variables['class_listings'][] = theme('mic_class_listing', array('data' => $class));
		}

		$variables['pager'] = theme('pager');

    	// class finder widget
    	$ages = mic_implementation_model('taxonomy-terms', 'homepage_classfinder', array('type'=>'ages'));
    	$program_areas = mic_implementation_model('taxonomy-terms', 'homepage_classfinder', array('type'=>'program_areas'));
    	$instruments = mic_implementation_model('taxonomy-terms', 'homepage_classfinder', array('type'=>'instruments'));
    	$campuses = mic_implementation_model('taxonomy-terms', 'homepage_classfinder', array('type'=>'campuses'));
    	$semesters = mic_implementation_model('taxonomy-terms', 'homepage_classfinder', array('type'=>'semesters'));

		$variables['classfinder_widget'] = theme('mic_classfinder_widget', array('ages'=>$ages, 'program_areas'=>$program_areas, 'instruments'=>$instruments, 'campuses'=>$campuses, 'semesters'=>$semesters));

    }

    if(arg(0) == 'news-events' && arg(1) == '') {
        $settings = variable_get('news_events_settings', null);
	    $variables['taxonomy_blocks'] = mic_implementation_model('taxonomy-blocks', 'news_events_page', null);

	    $news_queue_nodes = mic_implementation_model('node-queue-nodes', 'news_events_page', array('qid' => $settings['news_queue']));
	    $events_queue_nodes = mic_implementation_model('node-queue-nodes', 'news_events_page', array('qid' => $settings['events_queue']));

	    $variables['news_queue'] = theme('mic_news_list', array('news_queue_nodes' => $news_queue_nodes, 'title' => $settings['name']));
	    $variables['events_queue'] = theme('mic_events_list', array('events_queue_nodes' => $events_queue_nodes));
    }

    if(arg(0) == 'event-listings') {

    	$variables['theme_hook_suggestions'][] = 'page__event_listings';

    }

    if(arg(0) == 'article-listings') {

    	$variables['theme_hook_suggestions'][] = 'page__article_listings';

    }

    if(arg(0) == 'calendar') {
    	$variables['theme_hook_suggestions'][] = 'page__calendar';
    }

    if(arg(0) == 'search') {
    	$variables['title'] = 'Search MIC';
    }

}

function mic_implementation_theme_mic_feature_story(&$variables) {

	$node = $variables['node'];
	$path = image_style_url('banner-small-node', $node->field_image['und'][0]['uri']);
	return array(
		'subtitle' => (!empty($node->field_sub_title) ? '<span class="sub-title">'.$node->field_sub_title['und'][0]['value'].'</span>' : ''),
		'body' => $node->body['und'][0]['safe_value'],
		'img' => '<img src="'.$path.'" alt="'.$node->field_image['und'][0]['alt'].'" />',
	);
}

function mic_implementation_theme_mic_feature_video(&$variables) {

	$node = $variables['node'];
	//$path = image_style_url('banner-small', $node->field_image['und'][0]['uri']);
	return array(
		'subtitle' => (!empty($node->field_sub_title) ? '<span class="sub-title">'.$node->field_sub_title['und'][0]['value'].'</span>' : ''),
		'body' => $node->body['und'][0]['safe_value'],
		'summary' => $node->body['und'][0]['summary'],
	);
}

function mic_implementation_theme_mic_profile(&$variables) {

	$node = $variables['node'];

	//print_r($node);

	$path = image_style_url('profile', $node->field_image['und'][0]['uri']);
	return array(
		'prefix' => $node->field_prefix['und'][0]['safe_value'],
		'first_name' => $node->field_first_name['und'][0]['safe_value'],
		'last_name' => $node->field_last_name['und'][0]['safe_value'],
		'suffix' => $node->field_suffix['und'][0]['safe_value'],
		'title' => $node->field_job_title['und'][0]['safe_value'],
		'body' => $node->body['und'][0]['safe_value'],
		'img' => '<img src="'.$path.'" alt="'.$node->field_image['und'][0]['alt'].'" />',
		'phone' => $node->field_phone['und'][0]['safe_value'],
		'fax' => $node->field_fax['und'][0]['safe_value'],
		'email' => $node->field_email['und'][0]['safe_value'],
		'tags' => mic_implementation_get_taxonomy_term_list_string_from_array($node->field_tags['und']),
	);
}

function mic_implementation_theme_mic_course(&$variables) {

	$node = $variables['node'];

	$today = strtotime(date('n/j/Y', time()));
	//print_r($node);

	// get all class info
	$query = db_select('node', 'cls');

	$query->fields('cls', array('nid', 'title'));
	$query->fields('sd', array('field_start_date_value'));
	$query->fields('td_camp', array('name'));
	$query->fields('dow', array('field_day_of_week_value'));
	$query->fields('time', array('field_time_value'));
	$query->fields('st', array('field_status_value'));
	$query->fields('instr', array('nid', 'title'));
	$query->fields('ln', array('field_last_name_value'));
	$query->fields('ce', array('field_custom_enrollment_value'));
	$query->fields('cem', array('field_custom_enrollment_message_value'));

	$query->innerJoin('field_data_field_course_reference', 'crs', 'cls.nid = crs.entity_id');
	$query->innerJoin('field_data_field_status', 'st', 'st.entity_id = cls.nid');
	$query->innerJoin('field_data_field_start_date', 'sd', 'sd.entity_id = cls.nid');
	$query->innerJoin('field_data_field_day_of_week', 'dow', 'dow.entity_id = cls.nid');
	$query->innerJoin('field_data_field_time', 'time', 'time.entity_id = cls.nid');
	$query->innerJoin('taxonomy_index', 'ti_camp', 'cls.nid = ti_camp.nid');
	$query->innerJoin('taxonomy_term_data', 'td_camp', 'ti_camp.tid = td_camp.tid AND td_camp.vid = 7');

	$query->leftJoin('field_data_field_instructor_reference', 'ir', 'ir.entity_id = cls.nid');
	$query->leftJoin('node', 'instr', 'instr.nid = ir.field_instructor_reference_nid');
	$query->leftJoin('field_data_field_last_name', 'ln', 'ln.entity_id = instr.nid');

	$query->leftJoin('field_data_field_custom_enrollment', 'ce', 'ce.entity_id = cls.nid');
	$query->leftJoin('field_data_field_custom_enrollment_message', 'cem', 'cem.entity_id = cls.nid');

	$query->leftJoin('field_data_field_sunrise_date', 'srd', 'srd.entity_id = cls.nid');
	$query->leftJoin('field_data_field_sunset_date', 'ssd', 'ssd.entity_id = cls.nid');

	$query->condition('crs.field_course_reference_nid', $node->nid);
	$query->condition('srd.field_sunrise_date_value', $today, '<=');
	$query->condition('ssd.field_sunset_date_value', $today, '>=');

	$query->orderBy('sd.field_start_date_value', 'ASC');
	$query->orderBy('dow.field_day_of_week_value', 'ASC');
	$query->orderBy('time.field_time_value', 'ASC');
	$query->orderBy('instr.title', 'ASC');

	$results = $query->execute();

	$rows = array();

	foreach($results as $row) {
	  $class = node_load($row->nid);
	  $add_to_cart = drupal_render(field_view_field('node', $class, 'field_class_product', 'commerce_cart_add_to_cart_form'));
		$rows[] = array(
		  $row->field_day_of_week_value,
		  $row->field_time_value,
		  $row->field_start_date_value,
		  $row->name,
		  l($row->field_last_name_value, drupal_lookup_path('alias', 'node/'.$row->instr_nid)),
		  $row->field_status_value,
		  $row->field_custom_enrollment_value,
		  $row->field_custom_enrollment_message_value,
		  $add_to_cart,
		);
	}

	return array(
		'body' => $node->body['und'][0]['safe_value'],
		'ages' => mic_implementation_get_taxonomy_term_list_string_from_array($node->field_age['und']),
		'interests' => mic_implementation_get_taxonomy_term_list_string_from_array($node->field_program_area['und']),
		'instruments' => mic_implementation_get_taxonomy_term_list_string_from_array($node->field_instrument['und']),
		'requirements' => $node->field_requirements['und'][0]['safe_value'],
		'show_semester' => $node->field_show_semester_details['und'][0]['value'],
		'fall_price' => $node->field_fall_price['und'][0]['value'],
		'fall_materials_fee' => $node->field_fall_materials_fees['und'][0]['value'],
		'fall_semester_duration' => $node->field_fall_semester_duration['und'][0]['safe_value'],
		'fall_class_duration' => $node->field_fall_class_duration['und'][0]['value'],
		'spring_price' => $node->field_spring_price['und'][0]['value'],
		'spring_materials_fee' => $node->field_spring_materials_fees['und'][0]['value'],
		'spring_semester_duration' => $node->field_spring_semester_duration['und'][0]['safe_value'],
		'spring_class_duration' => $node->field_spring_class_duration['und'][0]['value'],
		'summer_price' => $node->field_summer_price['und'][0]['value'],
		'summer_materials_fee' => $node->field_summer_materials_fees['und'][0]['value'],
		'summer_semester_duration' => $node->field_summer_semester_duration['und'][0]['safe_value'],
		'summer_class_duration' => $node->field_summer_class_duration['und'][0]['value'],
		'signup_url' => isset($node->field_signup_url['und'][0]['attributes']) ? l('Click Here to Register!', $node->field_signup_url['und'][0]['display_url'], array('attributes' => $node->field_signup_url['und'][0]['attributes'])) : '',
		'classes' => $rows
	);
}

function mic_implementation_theme_mic_event(&$variables) {

	$node = $variables['node'];

	if(date('F j', $node->field_event_date['und'][0]['value']) != date('F j', $node->field_event_date['und'][0]['value2']))
	    $date = format_date($node->field_event_date['und'][0]['value'], 'custom', 'F j, Y g:i a') . ' - ' . format_date($node->field_event_date['und'][0]['value2'], 'custom', 'F j, Y g:i a');
	else
	    $date = format_date($node->field_event_date['und'][0]['value'], 'custom', 'F j, Y g:i a');

	return array(
		'body' => $node->body['und'][0]['safe_value'],
		'date' => $date,
		'cost' => (!empty($node->field_cost) ? $node->field_cost['und'][0]['value'] : 0),
		'location' => (!empty($node->field_location) ? $node->field_location['und'][0]['value'] : ''),
		'contact' => (!empty($node->field_contact) ? $node->field_contact['und'][0]['value'] : '')
	);
}

function mic_implementation_theme_mic_news_article(&$variables) {

	$node = $variables['node'];
	$path = image_style_url('banner-small-node', $node->field_image['und'][0]['uri']);
	return array(
		'subtitle' => (!empty($node->field_sub_title) ? '<span class="sub-title">'.$node->field_sub_title['und'][0]['value'].'</span>' : ''),
		'body' => $node->body['und'][0]['safe_value'],
		'img' => '<img src="'.$path.'" alt="'.$node->field_image['und'][0]['alt'].'" />'
	);
}

function mic_implementation_theme_mic_banner(&$variables) {

	$node = $variables['node'];
	$data = $variables['data'];
	$size = $variables['size'];

	switch($node->type) {
		case 'audience_gateway_page':
		case 'landing_page':
			if(isset($data) && !empty($data)) {
				if($size == 'small')
					$preset = 'banner-small';
				else
					$preset = 'banner-large';

				$path = image_style_url($preset, $data->field_image['und'][0]['uri']);
				return '<img src="'.$path.'" alt="'.$data->field_image['und'][0]['alt'].'" />';
			} else {
				if($size == 'small')
					$preset = 'banner-small';
				else
					$preset = 'banner-large';

				$path = image_style_url($preset, 'public://defaults/banner/default.jpg');
				return '<img src="'.$path.'" alt="" />';
			}
			break;
		case 'standard_template_page':
		case 'feature_story':
		case 'feature_video':
		case 'event':
			if(isset($data) && !empty($data)) {
				if($size == 'small')
					$preset = 'banner-small';
				else
					$preset = 'banner-large';

				$path = image_style_url($preset, $data->field_image['und'][0]['uri']);
				return '<img src="'.$path.'" alt="'.$data->field_image['und'][0]['alt'].'" />';
			} else {
				return null;
			}
			break;

	}

}

function mic_implementation_preprocess_mic_slideshow(&$variables) {

	$node = $variables['node'];
	$data = $variables['data'];

	switch($node->type) {
		case 'landing_page':
			if(isset($data) && !empty($data)) {
				$imgs = array();
				foreach($data as $img) {
					$imgs[] = array(
							'path' => image_style_url('slideshow', $img->field_image['und'][0]['uri']),
							'title' =>  l($img->title, drupal_lookup_path('alias', 'node/'.$img->nid)),
							'body' => mic_implementation_get_display_body($img->body['und'][0]),
							'slideshow' => str_replace(array("\r", "\r\n", "\n"), '', nl2br(mic_implementation_get_display_body($img->body['und'][0]))),
						);
				}
				$variables['imgs'] = $imgs;
			} else {
				$variables['imgs'] = null;
			}
			break;
	}

}

function mic_implementation_preprocess_mic_events_block(&$variables) {

	$node = $variables['node'];
	$data = $variables['data'];

	switch($node->type) {
		case 'landing_page':
		case 'standard_template_page':
		case 'feature_video':
		case 'feature_story':
		case 'news_article':
		case 'event':
			if(isset($data) && !empty($data)) {
				$upcoming = array();
				foreach($data as $event) {
					if(date('F j', $event->field_event_date['und'][0]['value']) != date('F j', $event->field_event_date['und'][0]['value2']))
						$date = format_date($event->field_event_date['und'][0]['value'], 'custom', 'F j, Y') . ' - ' . format_date($event->field_event_date['und'][0]['value2'], 'custom', 'F j, Y');
					else
						$date = format_date($event->field_event_date['und'][0]['value'], 'custom', 'F j, Y g:i a');

				    $upcoming[] = array(
				    	'title' => l($event->title, drupal_lookup_path('alias', 'node/'.$event->nid)),
				    	'date' => $date,
				    	'body' => mic_implementation_get_display_body($event->body['und'][0]),
				    );
				}
				$variables['events'] = $upcoming;
			} else {
				$variables['events'] = null;
			}
			break;
	}

}

function mic_implementation_preprocess_mic_news_articles_block(&$variables) {

	$node = $variables['node'];
	$data = $variables['data'];

	switch($node->type) {
		case 'landing_page':
			if(isset($data) && !empty($data)) {
				$upcoming = array();
				foreach($data as $a) {
					$path = image_style_url('news-articles-block', $a->field_image['und'][0]['uri']);
				    $articles[] = array(
				    	'title' => l($a->title, drupal_lookup_path('alias', 'node/'.$a->nid)),
				    	'date' => format_date($a->created, 'custom', 'F j, Y'),
				    	'body' => mic_implementation_get_display_body($a->body['und'][0]),
				    	'img' => l('<img class="left" src="'.$path.'" alt="'.$a->field_image['und'][0]['alt'].'" />', drupal_lookup_path('alias', 'node/'.$a->nid), array('html' => TRUE))
				    );
				}
				$variables['articles'] = $articles;
			} else {
				$variables['articles'] = null;
			}
			break;
	}

}

function mic_implementation_preprocess_mic_feature_story_block(&$variables) {

	$node = $variables['node'];
	$data = $variables['data'];
	$size = $variables['size'];

	if(is_array($node)) {
		// this is the news & events settings
		if(isset($data) && !empty($data) && $node['story_display'] == '1') {

		    $path = image_style_url('feature-story-block-large', $data->field_image['und'][0]['uri']);
		    $variables['story'] = array(
		        'title' => l($data->title, drupal_lookup_path('alias', 'node/'.$data->nid)),
		        'img' => l('<img src="'.$path.'" alt="'.$data->field_image['und'][0]['alt'].'" />', drupal_lookup_path('alias', 'node/'.$data->nid), array('html' => TRUE)),
		        'body' =>  mic_implementation_get_display_body($data->body['und'][0]),
		    );
		} else {
		    $variables['story'] = null;
		}
	} else {

		switch($node->type) {
			case 'standard_template_page':
			case 'landing_page':
			case 'audience_gateway_page':
			case 'feature_video':
			case 'feature_story':
			case 'news_article':
			case 'event':
				if(isset($data) && !empty($data)) {

					if($size == 'large')
					    $preset = 'feature-story-block-large';
					else
					    $preset = 'feature-story-block';

					$path = image_style_url($preset, $data->field_image['und'][0]['uri']);
					$variables['story'] = array(
					    'title' => l($data->title, drupal_lookup_path('alias', 'node/'.$data->nid)),
					    'img' => l('<img src="'.$path.'" alt="'.$data->field_image['und'][0]['alt'].'" />', drupal_lookup_path('alias', 'node/'.$data->nid), array('html' => TRUE)),
					    'body' =>  mic_implementation_get_display_body($data->body['und'][0]),
					);
				} else {
					$variables['story'] = null;
				}
				break;
		}

	}


}

function mic_implementation_preprocess_mic_feature_video_block(&$variables) {

	$node = $variables['node'];
	$data = $variables['data'];


	if(is_array($node)) {
		// this is the news & events settings
		if(isset($data) && !empty($data) && $node['video_display'] == '1') {
		    $path = image_style_url('feature-video-block-large', $data->field_image['und'][0]['uri']);
			$variables['video'] = array(
				'title' => l($data->title, drupal_lookup_path('alias', 'node/'.$data->nid), array('attributes' => array('class' => 'green-font'))),
				'overlay_link' => drupal_lookup_path('alias', 'node/'.$data->nid),
				'img' => '<img src="'.$path.'" alt="'.$data->field_image['und'][0]['alt'].'" />',
				'body' => $data->body['und'][0]['value'],
				'summary' => mic_implementation_get_display_body($data->body['und'][0]),
		    );
		} else {
		    $variables['video'] = null;
		}

	} else {

		switch($node->type) {
			case 'standard_template_page':
			case 'landing_page':
			case 'feature_video':
			case 'feature_story':
			case 'news_article':
			case 'event':
				if(isset($data) && !empty($data)) {
					$path = image_style_url('feature-video-block', $data->field_image['und'][0]['uri']);
					$variables['video'] = array(
					    'title' => l($data->title, drupal_lookup_path('alias', 'node/'.$data->nid), array('attributes' => array('class' => 'green-font'))),
					    'overlay_link' => drupal_lookup_path('alias', 'node/'.$data->nid),
					    'img' => '<img src="'.$path.'" alt="'.$data->field_image['und'][0]['alt'].'" />',
					    'body' => $data->body['und'][0]['value'],
					    'summary' => mic_implementation_get_display_body($data->body['und'][0]),
					);
				} else {
					$variables['video'] = null;
				}
				break;
		}
	}

}

function mic_implementation_preprocess_mic_news_list(&$variables) {

	$nodes = $variables['news_queue_nodes'];

	$list = array();
	$list['title'] = $variables['title'];

	$i = 0;
	foreach($nodes as $n) {
		if($i == 0) {
			//main story
			$path = image_style_url('news-list-main-story', $n->field_image['und'][0]['uri']);
			$list['main_story'] = array(
				'title' => l($n->title, drupal_lookup_path('alias', 'node/'.$n->nid)),
				'date' => format_date($n->created, 'custom', 'F j, Y'),
				'body' => mic_implementation_get_display_body($n->body['und'][0]),
				'img' => l('<img src="'.$path.'" alt="'.$n->field_image['und'][0]['alt'].'" />', drupal_lookup_path('alias', 'node/'.$n->nid), array('html' => TRUE))
			);
		} else {
			$path = image_style_url('news-list-small', $n->field_image['und'][0]['uri']);
			$list['listings'][] = array(
				'title' => l($n->title, drupal_lookup_path('alias', 'node/'.$n->nid)),
				'date' => format_date($n->created, 'custom', 'F j, Y'),
				'body' => mic_implementation_get_display_body($n->body['und'][0]),
				'img' => l('<img class="left" src="'.$path.'" alt="'.$n->field_image['und'][0]['alt'].'" />', drupal_lookup_path('alias', 'node/'.$n->nid), array('html' => TRUE))
			);
		}
		$i++;
	}

	$variables['listings'] = $list;
}

function mic_implementation_preprocess_mic_events_list(&$variables) {

	$nodes = $variables['events_queue_nodes'];
	$list = array();

	foreach($nodes as $n) {
		$list['events'][] = array(
		    'title' => l($n->title, drupal_lookup_path('alias', 'node/'.$n->nid)),
		    'date' => format_date($n->field_event_date['und'][0]['value'], 'custom', 'F j, Y'),
		    'body' => mic_implementation_get_display_body($n->body['und'][0]),
		);
	}

	$variables['listings'] = $list;
}

function mic_implementation_preprocess_mic_homepage_classfinder(&$variables) {
	$variables['filters']['ages'] = $variables['ages'];
	$variables['filters']['program_areas'] = $variables['program_areas'];
	$variables['filters']['instruments'] = $variables['instruments'];
	$variables['filters']['campuses'] = $variables['campuses'];
	$variables['filters']['semesters'] = $variables['semesters'];
}

function mic_implementation_preprocess_mic_homepage_slideshow(&$variables) {

	$nodes = $variables['slideshow_queue_nodes'];
	$slideshow = array();

	foreach($nodes as $n) {
		$slideshow[] = array(
			'path' => image_style_url('slideshow-homepage', $n->field_image['und'][0]['uri']),
			'title' =>  l($n->title, drupal_lookup_path('alias', 'node/'.$n->nid)),
			'body' => mic_implementation_get_display_body($n->body['und'][0]),
			'slideshow' => str_replace(array("\r", "\r\n", "\n"), '', nl2br(mic_implementation_get_display_body($n->body['und'][0]))),
		);
	}

	$variables['slideshow'] = $slideshow;
}

function mic_implementation_preprocess_mic_homepage_news_list(&$variables) {

	$nodes = $variables['news_queue_nodes'];

	$list = array();
	$list['title'] = $variables['title'];

	foreach($nodes as $n) {
		$path = image_style_url('news-list-small', $n->field_image['und'][0]['uri']);
		$list['listings'][] = array(
		    'title' => l($n->title, drupal_lookup_path('alias', 'node/'.$n->nid)),
		    'date' => format_date($n->created, 'custom', 'F j, Y'),
		    'body' => (!empty($n->body) ? mic_implementation_get_display_body($n->body['und'][0]) : ''),
		    'img' => l('<img class="left" src="'.$path.'" alt="'.$n->field_image['und'][0]['alt'].'" />', drupal_lookup_path('alias', 'node/'.$n->nid), array('html' => TRUE))
		);
	}

	$variables['listings'] = $list;
}

function mic_implementation_preprocess_mic_homepage_feature_list(&$variables) {

	$nodes = $variables['feature_queue_nodes'];

	$list = array();
	$list['title'] = $variables['title'];

	foreach($nodes as $n) {

		switch($n->type) {
		    case "feature_story":
		    	$path = image_style_url('homepage-feature', $n->field_image['und'][0]['uri']);
		    	$list['listings'][] = array(
		    	    'title' => l($n->title, drupal_lookup_path('alias', 'node/'.$n->nid)),
		    	    'body' => mic_implementation_get_display_body($n->body['und'][0]),
		    	    'media' => l('<img src="'.$path.'" alt="'.$n->field_image['und'][0]['alt'].'" />', drupal_lookup_path('alias', 'node/'.$n->nid), array('html' => TRUE)),
		    	    'type' => 'story'
		    	);
		    	break;
		    case "feature_video":
		    	$media = preg_replace('/\swidth=\"(.*?)\"/', 'width="375"', $n->body['und'][0]['value']);
		    	$media = preg_replace('/\sheight=\"(.*?)\"/', 'height="195"', $media);
		    	$list['listings'][] = array(
		    	    'title' => l($n->title, drupal_lookup_path('alias', 'node/'.$n->nid)),
		    	    'body' => $n->body['und'][0]['summary'],
		    	    'media' => $media,
		    	    'type' => 'video'
		    	);
		    	break;
		}
	}

	$variables['listings'] = $list;
}

function mic_implementation_preprocess_mic_related_links(&$variables) {

	$node = $variables['node'];
	$links = array();

	if(!empty($node->field_related_links_header))
		$links['title'] = $node->field_related_links_header['und'][0]['safe_value'];
	else
		$links['title'] = 'Related Links';

	$links['links'] = array();
	foreach($node->field_related_links_link['und'] as $l) {
		$links['links'][] = l($l['title'], $l['display_url'], array('attributes'=>$l['attributes'], 'html'=>$l['html']));
	}
	if(!empty($links['links']))
		$variables['links'] = $links;
}

function mic_implementation_preprocess_mic_gateway_links(&$variables) {

	$node = $variables['node'];
	$links = array();
	if(!empty($node->field_section1_header)) {

		$links['section1']['title'] = $node->field_section1_header['und'][0]['safe_value'];
		$links['section1']['links'] = array();
		foreach($node->field_section1_links['und'] as $l) {
			$links['section1']['links'][] = l($l['title'], $l['display_url'], array('attributes'=>$l['attributes'], 'html'=>$l['html']));
		}
	}

	if(!empty($node->field_section2_header)) {

		$links['section2']['title'] = $node->field_section2_header['und'][0]['safe_value'];
		$links['section2']['links'] = array();
		foreach($node->field_section2_links['und'] as $l) {
			$links['section2']['links'][] = l($l['title'], $l['display_url'], array('attributes'=>$l['attributes'], 'html'=>$l['html']));
		}
	}

	if(!empty($node->field_section3_header)) {

		$links['section3']['title'] = $node->field_section3_header['und'][0]['safe_value'];
		$links['section3']['links'] = array();
		foreach($node->field_section3_links['und'] as $l) {
			$links['section3']['links'][] = l($l['title'], $l['display_url'], array('attributes'=>$l['attributes'], 'html'=>$l['html']));
		}
	}

	if(!empty($node->field_section4_header)) {

		$links['section4']['title'] = $node->field_section4_header['und'][0]['safe_value'];
		$links['section4']['links'] = array();
		foreach($node->field_section4_links['und'] as $l) {
			$links['section4']['links'][] = l($l['title'], $l['display_url'], array('attributes'=>$l['attributes'], 'html'=>$l['html']));
		}
	}

	if(!empty($node->field_section5_header)) {

		$links['section5']['title'] = $node->field_section5_header['und'][0]['safe_value'];
		$links['section5']['links'] = array();
		foreach($node->field_section5_links['und'] as $l) {
			$links['section5']['links'][] = l($l['title'], $l['display_url'], array('attributes'=>$l['attributes'], 'html'=>$l['html']));
		}
	}

	if(!empty($node->field_section6_header)) {

		$links['section6']['title'] = $node->field_section6_header['und'][0]['safe_value'];
		$links['section6']['links'] = array();
		foreach($node->field_section6_links['und'] as $l) {
			$links['section6']['links'][] = l($l['title'], $l['display_url'], array('attributes'=>$l['attributes'], 'html'=>$l['html']));
		}
	}

	if(!empty($node->field_section7_header)) {

		$links['section7']['title'] = $node->field_section7_header['und'][0]['safe_value'];
		$links['section7']['links'] = array();
		foreach($node->field_section7_links['und'] as $l) {
			$links['section7']['links'][] = l($l['title'], $l['display_url'], array('attributes'=>$l['attributes'], 'html'=>$l['html']));
		}
	}

	if(!empty($node->field_section8_header)) {

		$links['section8']['title'] = $node->field_section8_header['und'][0]['safe_value'];
		$links['section8']['links'] = array();
		foreach($node->field_section8_links['und'] as $l) {
			$links['section8']['links'][] = l($l['title'], $l['display_url'], array('attributes'=>$l['attributes'], 'html'=>$l['html']));
		}
	}

	if(!empty($node->field_section9_header)) {

		$links['section9']['title'] = $node->field_section9_header['und'][0]['safe_value'];
		$links['section9']['links'] = array();
		foreach($node->field_section9_links['und'] as $l) {
			$links['section9']['links'][] = l($l['title'], $l['display_url'], array('attributes'=>$l['attributes'], 'html'=>$l['html']));
		}
	}

	$variables['links'] = $links;
}

function mic_implementation_preprocess_mic_listings(&$variables) {

	$data = $variables['data'];

	switch($variables['type']) {
		case 'event':
			if(isset($data) && !empty($data)) {
				$listings = array();
				foreach($data as $item) {
				    $listings[] = array(
				    	'title' => l($item->title, drupal_lookup_path('alias', 'node/'.$item->nid)),
				    	'date' => format_date($item->field_event_date['und'][0]['value'], 'custom', 'F j, Y'),
				    	'body' => mic_implementation_get_display_body($item->body['und'][0], 252),
				    );
				}
				$variables['items'] = $listings;
			} else {
				$variables['items'] = null;
			}
			break;
		case 'article':
			if(isset($data) && !empty($data)) {
				$listings = array();
				foreach($data as $item) {
				    $listings[] = array(
				    	'title' => l($item->title, drupal_lookup_path('alias', 'node/'.$item->nid)),
				    	'date' => format_date($item->created, 'custom', 'F j, Y'),
				    	'body' => mic_implementation_get_display_body($item->body['und'][0], 252),
				    );
				}
				$variables['items'] = $listings;
			} else {
				$variables['items'] = null;
			}
			break;
	}
}

function mic_implementation_preprocess_mic_class_listing(&$variables) {

	$data = $variables['data'];

	$class = array();

	$class['course'] = l($data->crs_title, drupal_lookup_path('alias', 'node/'.$data->crs_nid));
	$class['campus'] = $data->name;
	$class['start_date'] = $data->field_start_date_value;
	$class['day_of_week'] = $data->field_day_of_week_value;
	$class['time'] = $data->field_time_value;
	$class['status'] = ($data->field_status_value) != 'Open' ? '<span class="bold-font">'.$data->field_status_value.'</span>' : $data->field_status_value;

	if(stristr($data->td_sem_name, 'Fall') !== false) {
		$class['price'] = $data->field_fall_price_value;
		$class['duration'] = $data->field_fall_semester_duration_value;
	}

	if(stristr($data->td_sem_name, 'Spring') !== false) {
		$class['price'] = $data->field_spring_price_value;
		$class['duration'] = $data->field_spring_semester_duration_value;
	}

	if(stristr($data->td_sem_name, 'Summer') !== false) {
		$class['price'] = $data->field_summer_price_value;
		$class['duration'] = $data->field_summer_semester_duration_value;
	}

	if(!empty($data->instr_nid))
		$class['instructor'] = l($data->instr_title, drupal_lookup_path('alias', 'node/'.$data->instr_nid));

	// get ages list
	$query = db_select('node', 'crs');
	$query->fields('td', array('tid', 'name'));
	$query->innerJoin('taxonomy_index', 'ti', 'crs.nid = ti.nid');
	$query->innerJoin('taxonomy_term_data', 'td', 'ti.tid = td.tid');
	$query->condition('crs.nid', $data->crs_nid);
	$query->condition('td.vid', 5);

	$results = $query->execute();

	$ages = array();
	foreach($results as $row)
		$ages[] = $row->tid;

	$class['ages'] = mic_implementation_get_taxonomy_term_list_string_from_array($ages, 'class-finder');

	// get interests list
	$query = db_select('node', 'crs');
	$query->fields('td', array('tid', 'name'));
	$query->innerJoin('taxonomy_index', 'ti', 'crs.nid = ti.nid');
	$query->innerJoin('taxonomy_term_data', 'td', 'ti.tid = td.tid');
	$query->condition('crs.nid', $data->crs_nid);
	$query->condition('td.vid', 3);

	$results = $query->execute();

	$interests = array();
	foreach($results as $row)
		$interests[] = $row->tid;

	$class['interests'] = mic_implementation_get_taxonomy_term_list_string_from_array($interests, 'class-finder');

	// get instruments list
	$query = db_select('node', 'crs');
	$query->fields('td', array('tid', 'name'));
	$query->innerJoin('taxonomy_index', 'ti', 'crs.nid = ti.nid');
	$query->innerJoin('taxonomy_term_data', 'td', 'ti.tid = td.tid');
	$query->condition('crs.nid', $data->crs_nid);
	$query->condition('td.vid', 4);

	$results = $query->execute();

	$instruments = array();
	foreach($results as $row)
		$instruments[] = $row->tid;

	$class['instruments'] = mic_implementation_get_taxonomy_term_list_string_from_array($instruments, 'class-finder');

	$variables['class'] = $class;

}

function mic_implementation_preprocess_mic_classfinder_widget(&$variables) {
	$variables['filters']['ages'] = $variables['ages'];
	$variables['filters']['program_areas'] = $variables['program_areas'];
	$variables['filters']['instruments'] = $variables['instruments'];
	$variables['filters']['campuses'] = $variables['campuses'];
	$variables['filters']['semesters'] = $variables['semesters'];
}

?>