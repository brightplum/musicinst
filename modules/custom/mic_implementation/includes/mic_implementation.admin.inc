<?php

function miscellaneous_admin($form_type) {

	switch($form_type) {
		case 'edit':
			return drupal_get_form('miscellaneous_admin_edit_form');		
			break;
	}
}

function miscellaneous_admin_edit_form($form, &$form_state) {

	$queues = mic_implementation_model('node-queues');

	$settings = variable_get('miscellaneous_settings', null);
	
	$form['header_settings'] = array (
		'#type' => 'fieldset',
		'#title' => 'Header Settings',
		'#collapsible' => true,
		'#collapsed' => false,
	);
	$form['header_settings']['social_links_label_header'] = array (
	    '#type' => 'textfield',
	    '#title' => 'Social Links Label',
	    '#required' => true,
	    '#default_value' => (isset($settings['social_links_label_header']) ? $settings['social_links_label_header'] : ''),		
	    '#description' => t('The label to appear next to the social links in the header'),			
	);
	$form['header_settings']['search_label_header'] = array (
	    '#type' => 'textfield',
	    '#title' => 'Search Label',
	    '#required' => true,
	    '#default_value' => (isset($settings['search_label_header']) ? $settings['search_label_header'] : ''),		
	    '#description' => t('The label to appear above the search box in the header'),			
	);
	
	$form['footer_settings'] = array (
		'#type' => 'fieldset',
		'#title' => 'Footer Settings',
		'#collapsible' => true,
		'#collapsed' => false,
	);
	$form['footer_settings']['social_links_label_footer'] = array (
	    '#type' => 'textfield',
	    '#title' => 'Social Links Label',
	    '#required' => true,
	    '#default_value' => (isset($settings['social_links_label_footer']) ? $settings['social_links_label_footer'] : ''),		
	    '#description' => t('The label to appear next to the social links in the footer'),			
	);
	
	$form['social_links_settings'] = array (
		'#type' => 'fieldset',
		'#title' => 'Social Links Settings',
		'#collapsible' => true,
		'#collapsed' => false,
	);
	$form['social_links_settings']['facebook_url'] = array (
	    '#type' => 'textfield',
	    '#title' => 'Facebook Url',
	    '#required' => true,
	    '#default_value' => (isset($settings['facebook_url']) ? $settings['facebook_url'] : ''),		
	    '#description' => t('The url for MIC\'s Facebook page'),			
	);
	
	$form['social_links_settings']['youtube_url'] = array (
	    '#type' => 'textfield',
	    '#title' => 'Youtube Url',
	    '#required' => true,
	    '#default_value' => (isset($settings['youtube_url']) ? $settings['youtube_url'] : ''),		
	    '#description' => t('The url for MIC\'s Youtube page'),			
	);
	
	$form['social_links_settings']['twitter_url'] = array (
	    '#type' => 'textfield',
	    '#title' => 'Twitter Url',
	    '#required' => true,
	    '#default_value' => (isset($settings['twitter_url']) ? $settings['twitter_url'] : ''),		
	    '#description' => t('The url for MIC\'s Twitter page'),			
	);
	
	$form['social_links_settings']['flickr_url'] = array (
	    '#type' => 'textfield',
	    '#title' => 'Flickr Url',
	    '#required' => true,
	    '#default_value' => (isset($settings['flickr_url']) ? $settings['flickr_url'] : ''),		
	    '#description' => t('The url for MIC\'s Flickr page'),			
	);
	
	$form['social_links_settings']['linkedin_url'] = array (
	    '#type' => 'textfield',
	    '#title' => 'LinkedIn Url',
	    '#required' => true,
	    '#default_value' => (isset($settings['linkedin_url']) ? $settings['flickr_url'] : ''),		
	    '#description' => t('The url for MIC\'s LinkedIn page'),			
	);

  	$form['actions'] = array('#type' => 'actions');
	$form['actions']['submit'] = array(
		'#type' => 'submit',
		'#value' => t('Save'),
	);	
			
	return $form;

}

function miscellaneous_admin_edit_form_validate($form, &$form_state) {

}

function miscellaneous_admin_edit_form_submit($form, &$form_state) {

	$values = array();
	
	foreach($form_state['values'] as $key => $value) {
		$values[$key] = $value;
	}
	
	variable_set('miscellaneous_settings', $values);	
	
	drupal_set_message(t('Your settings have been saved.'), 'status');
}


function homepage_admin($form_type) {

	switch($form_type) {
		case 'edit':
			return drupal_get_form('homepage_admin_edit_form');		
			break;
	}
}

function homepage_admin_edit_form($form, &$form_state) {

	$queues = mic_implementation_model('node-queues');

	$settings = variable_get('homepage_settings', null);
	
	$form['slideshow_block'] = array (
		'#type' => 'fieldset',
		'#title' => 'Slideshow',
		'#collapsible' => true,
		'#collapsed' => false,
	);

	$form['slideshow_block']['slideshow_queue'] = array (
		'#type' => 'select',
		'#title' => 'Slideshow Queue',
		'#multiple' => false,
		'#options' => $queues,
		'#default_value' => (isset($settings['slideshow_queue']) ? $settings['slideshow_queue'] : ''),	
		'#description' => t('Select the nodequeue containing the slideshow items'),			
	);
	
	$form['news_block'] = array (
		'#type' => 'fieldset',
		'#title' => 'News Block',
		'#collapsible' => true,
		'#collapsed' => false,
	);
	
	$form['news_block']['news_name'] = array (
	    '#type' => 'textfield',
	    '#title' => 'Title',
	    '#required' => true,
	    '#default_value' => (isset($settings['news_name']) ? $settings['news_name'] : ''),		
	    '#description' => t('The title to appear for the News block on the homepage'),			
	);

	$form['news_block']['news_queue'] = array (
		'#type' => 'select',
		'#title' => 'News Queue',
		'#multiple' => false,
		'#options' => $queues,
		'#default_value' => (isset($settings['news_queue']) ? $settings['news_queue'] : ''),	
		'#description' => t('Select the nodequeue containing the news items'),			
	);

	$form['feature_block'] = array (
		'#type' => 'fieldset',
		'#title' => 'Feature Block',
		'#collapsible' => true,
		'#collapsed' => false,
	);
	
	$form['feature_block']['feature_name'] = array (
	    '#type' => 'textfield',
	    '#title' => 'Title',
	    '#required' => true,
	    '#default_value' => (isset($settings['feature_name']) ? $settings['feature_name'] : ''),		
	    '#description' => t('The title to appear for the Feature block on the homepage'),			
	);

	$form['feature_block']['feature_queue'] = array (
		'#type' => 'select',
		'#title' => 'Feature Queue',
		'#multiple' => false,
		'#options' => $queues,
		'#default_value' => (isset($settings['feature_queue']) ? $settings['feature_queue'] : ''),	
		'#description' => t('Select the nodequeue containing the feature items'),			
	);		

  	$form['actions'] = array('#type' => 'actions');
	$form['actions']['submit'] = array(
		'#type' => 'submit',
		'#value' => t('Save'),
	);	
			
	return $form;

}

function homepage_admin_edit_form_validate($form, &$form_state) {

}

function homepage_admin_edit_form_submit($form, &$form_state) {

	$values = array();
	
	foreach($form_state['values'] as $key => $value) {
		$values[$key] = $value;
	}
	
	variable_set('homepage_settings', $values);	
	
	drupal_set_message(t('Your settings have been saved.'), 'status');
}

function news_events_admin($form_type) {

	switch($form_type) {
		case 'edit':
			return drupal_get_form('news_events_admin_edit_form');		
			break;
	}
}

function news_events_admin_edit_form($form, &$form_state) {

	$queues = mic_implementation_model('node-queues');
	$tags = mic_implementation_model('tags');

	$settings = variable_get('news_events_settings', null);
	
	$form['name'] = array (
	    '#type' => 'textfield',
	    '#title' => 'Title',
	    '#required' => true,
	    '#default_value' => (isset($settings['name']) ? $settings['name'] : ''),		
	    '#description' => t('The title to appear on the News & Events page'),			
	);

	$form['news_queue'] = array (
		'#type' => 'select',
		'#title' => 'News Queue',
		'#multiple' => false,
		'#options' => $queues,
		'#default_value' => (isset($settings['news_queue']) ? $settings['news_queue'] : ''),	
		'#description' => t('Select the nodequeue containing the news items'),			
	);

	$form['events_queue'] = array (
		'#type' => 'select',
		'#title' => 'Events Queue',
		'#multiple' => false,
		'#options' => $queues,	
		'#default_value' => (isset($settings['events_queue']) ? $settings['events_queue'] : ''),
		'#description' => t('Select the nodequeue containing the events to display'),			
	);			

	$form['feature_story_block'] = array (
		'#type' => 'fieldset',
		'#title' => 'Feature Story Block',
		'#collapsible' => true,
		'#collapsed' => true,
	);
	
	$form['feature_story_block']['story_display'] = array (
		'#type' => 'checkbox',
		'#title' => 'Display on Page',
		'#default_value' => (isset($settings['story_display']) ? $settings['story_display'] : '1'),
		
	);
	
	$form['feature_story_block']['story_tags'] = array (
		'#type' => 'checkboxes',
		'#title' => 'Tags',
		'#options' => $tags,
		'#default_value' => (isset($settings['story_tags']) ? $settings['story_tags'] : ''),
	);
	
	$form['feature_video_block'] = array (
		'#type' => 'fieldset',
		'#title' => 'Feature Video Block',
		'#collapsible' => true,
		'#collapsed' => true,
	);
	
	$form['feature_video_block']['video_display'] = array (
		'#type' => 'checkbox',
		'#title' => 'Display on Page',
		'#default_value' => (isset($settings['video_display']) ? $settings['video_display'] : '1'),
		
	);
	
	$form['feature_video_block']['video_tags'] = array (
		'#type' => 'checkboxes',
		'#title' => 'Tags',
		'#options' => $tags,
		'#default_value' => (isset($settings['video_tags']) ? $settings['video_tags'] : ''),
	);
		
  	$form['actions'] = array('#type' => 'actions');
	$form['actions']['submit'] = array(
		'#type' => 'submit',
		'#value' => t('Save'),
	);	
			
	return $form;

}

function news_events_admin_edit_form_validate($form, &$form_state) {

}

function news_events_admin_edit_form_submit($form, &$form_state) {

	$values = array();
	
	foreach($form_state['values'] as $key => $value) {
		$values[$key] = $value;
	}
	
	variable_set('news_events_settings', $values);	
	
	drupal_set_message(t('Your settings have been saved.'), 'status');
}

?>