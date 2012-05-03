<?php

/**
 * Override or insert variables into the page template.
 */
function mic_preprocess_page(&$vars) {

	if(!empty($vars['page']['left_navigation'])) {

		$links = mic_build_left_navigation($vars['page']['left_navigation']);

		if(!empty($links)) {
			$vars['left_navigation'] = '<ul class="menu">';
			foreach($links as $link) {
				$vars['left_navigation'] .= $link;
			}
			$vars['left_navigation'] .= '</ul>';
		}
	}
	//print_r($vars);
	//$variables['primary_navigation'] = mic_set_active_menu();
}


/**
 * Template override for theme_breadcrumb().
 */
function mic_breadcrumb($breadcrumb) {

	if (!empty($breadcrumb)) {

		$lastitem = sizeof($breadcrumb['breadcrumb']);
		$crumbs = '<ul>';
		$a=1;

		foreach ($breadcrumb['breadcrumb'] as $value) {

			if ($a == 1) {

				if ($a == sizeof($breadcrumb['breadcrumb']))
					$crumbs .= '<li class="first last">'.$value.'</li>';
				else
					$crumbs .= '<li class="first">'.$value.'</li>';

				$a++;

			} elseif ($a == $lastitem) {

				$crumbs .= '<li class="last">'.$value.'</li>';

			} else {

				$crumbs .= '<li>'.$value.'</li>';
				$a++;

			}

		}

		$crumbs .= '</ul>';

	}

	return $crumbs;

}

function mic_get_display_body($body, $trim_length = 200) {

	if(strlen($body['summary']) > 0)
		return $body['summary'];
	else
		return substr(strip_tags($body['safe_value']), 0, $trim_length);
}


function mic_build_left_navigation($nav) {

	$links = array();

	if(isset($nav['menu_block_1'])) {
		foreach($nav['menu_block_1']['#content'] as $key => $item) {
			if(is_integer($key)) {
				$link = array('element' => $item);
				$links[] = theme('menu_link', $link);
			}
		}
	}

	if(isset($nav['menu_block_2'])) {
		foreach($nav['menu_block_2']['#content'] as $key => $item) {
			if(is_integer($key)) {
				$link = array('element' => $item);
				$links[] = theme('menu_link', $link);
			}
		}
	}

	if(isset($nav['menu_block_3'])) {
		foreach($nav['menu_block_3']['#content'] as $key => $item) {
			if(is_integer($key)) {
				$link = array('element' => $item);
				$links[] = theme('menu_link', $link);
			}
		}
	}

	if(isset($nav['menu_block_4'])) {
		foreach($nav['menu_block_4']['#content'] as $key => $item) {
			if(is_integer($key)) {
				$link = array('element' => $item);
				$links[] = theme('menu_link', $link);
			}
		}
	}

	if(isset($nav['menu_block_5'])) {
		foreach($nav['menu_block_5']['#content'] as $key => $item) {
			if(is_integer($key)) {
				$link = array('element' => $item);
				$links[] = theme('menu_link', $link);
			}
		}
	}

	if(isset($nav['menu_block_6'])) {
		foreach($nav['menu_block_6']['#content'] as $key => $item) {
			if(is_integer($key)) {
				$link = array('element' => $item);
				$links[] = theme('menu_link', $link);
			}
		}
	}

	if(isset($nav['menu_block_7'])) {
		foreach($nav['menu_block_7']['#content'] as $key => $item) {
			if(is_integer($key)) {
				$link = array('element' => $item);
				$links[] = theme('menu_link', $link);
			}
		}
	}

	if(isset($nav['menu_block_8'])) {
		foreach($nav['menu_block_8']['#content'] as $key => $item) {
			if(is_integer($key)) {
				$link = array('element' => $item);
				$links[] = theme('menu_link', $link);
			}
		}
	}

	return $links;
}

/**
 * Display a day view.
 */
function mic_preprocess_calendar_day(&$vars) {
	//print_r($vars);
	$i = 0;
	$rows = $vars['rows'];
	$start_times = array_keys($rows['items']);
	foreach ($start_times as $start_time) {

		$next_start_time = array_key_exists($i + 1, $start_times) ? $start_times[$i + 1] : '23:59:59';
		$variables = array(
			'start_time' => $start_time,
			'next_start_time' => $next_start_time,
			'curday_date' => $rows['date'],
		);
		$heading = mic_calendar_time_row_heading($variables);

		$grouped_items[$start_time]['hour'] = $heading['hour'];
		$grouped_items[$start_time]['ampm'] = $heading['ampm'];
		$grouped_items[$start_time]['values']  = $rows['items'][$start_time]['values'];
		$i++;
	}

	if(isset($grouped_items)) {
		ksort($grouped_items);
	  	$vars['rows']['items'] = $grouped_items;
	}

}

function mic_calendar_time_row_heading($vars) {

	$start_time = $vars['start_time'];
	$next_start_time = $vars['next_start_time'];
	$curday_date = $vars['curday_date'];

	static $format_hour, $format_ampm;
	if (empty($format_hour)) {
	    $format = variable_get('date_format_short', 'm/d/Y - H:i');
	    $format_hour = 'g:i'; //str_replace(array('a', 'A'), '', date_limit_format($format, array('hour', 'minute')));
	    $format_ampm = 'a';//strstr($format, 'a') ? 'a' : (strstr($format, 'A') ? 'A' : '');
	}
	if ($start_time == '00:00:00' && $next_start_time == '23:59:59') {
		$hour = t('All times');
	} elseif ($start_time == '00:00:00') {
		$date = date_create($curday_date . ' ' . $next_start_time);
		$hour = t('Before @time', array('@time' => date_format($date, $format_hour)));
	} else {
		$date = date_create($curday_date . ' ' . $start_time);
		$hour = date_format($date, $format_hour);
	}
	if (!empty($date)) {
		$ampm = date_format($date, $format_ampm);
	} else {
		$ampm = '';
	}
	return array('hour' => $hour, 'ampm' => $ampm);
}

?>