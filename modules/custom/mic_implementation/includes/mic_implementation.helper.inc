<?php

function mic_implementation_parse_listings_request($get) {

	# We could issue an error below, but we will just omit the filter if its invalid and let the sequence proceed.

	$filter = '';
	if(isset($get['tid'])) {
		if(mic_implementation_check_valid_filter($get['tid']))
			$filter = $get['tid'];
		else
			$filter = NULL;
	}

	$request = array();


	if(isset($filter) && strlen($filter) > 0)
		$request['filter'] = $filter;

	if(!empty($request))
		return $request;
	else
		return NULL;

}

function mic_implementation_get_listings($type, $request) {

	switch($type) {
		case 'event':
			$events = mic_implementation_get_taxonomy_events($request, 'listings');
			return theme('mic_listings', array('type' => 'event', 'data' => $events));
			break;
		case 'article':
			$articles = mic_implementation_get_taxonomy_news_articles($request, 'listings');
			return theme('mic_listings', array('type' => 'article', 'data' => $articles));
			break;

	}
}

function mic_implementation_get_taxonomy_blocks($type, $args) {

	switch($type) {
		case 'standard_template_page':
		case 'feature_story':
		case 'feature_video':
		case 'news_article':
		case 'profile':
		case 'item_course':
		case 'event':
			$node = $args['node'];

			$banner = mic_implementation_get_taxonomy_banner($node);
			$events = mic_implementation_get_taxonomy_events($node);
			$feature_story = mic_implementation_get_taxonomy_feature_story($node);
			$feature_video = mic_implementation_get_taxonomy_feature_video($node);

			return array(
					'banner' => theme('mic_banner', array('node' => $node, 'data' => $banner, 'size' => 'small')),
					'events' => theme('mic_events_block', array('node' => $node, 'data' => $events)),
					'feature_story' => theme('mic_feature_story_block', array('node' => $node, 'data' => $feature_story, 'size' => 'small')),
					'feature_video' => theme('mic_feature_video_block', array('node' => $node, 'data' => $feature_video)),
				);
			break;

		case 'landing_page':
			$node = $args['node'];

			$events = mic_implementation_get_taxonomy_events($node);
			$feature_story = mic_implementation_get_taxonomy_feature_story($node);
			$feature_video = mic_implementation_get_taxonomy_feature_video($node);
			$articles = mic_implementation_get_taxonomy_news_articles($node);

			if($node->field_show_banner_slideshow['und'][0]['value']) {
				$slideshow = mic_implementation_get_taxonomy_slideshow($node);
				return array(
						'slideshow' => theme('mic_slideshow', array('node' => $node, 'data' => $slideshow)),
						'events' => theme('mic_events_block', array('node' => $node, 'data' => $events)),
						'events-see-all' => mic_implementation_get_see_all_link('event', $node),
						'feature_story' => theme('mic_feature_story_block', array('node' => $node, 'data' => $feature_story, 'size' => 'small')),
						'news_articles' => theme('mic_news_articles_block', array('node' => $node, 'data' => $articles)),
						'news-articles-see-all' => mic_implementation_get_see_all_link('article', $node),
						'feature_video' => theme('mic_feature_video_block', array('node' => $node, 'data' => $feature_video)),
					);
			} else {
				$banner = mic_implementation_get_taxonomy_banner($node);
				return array(
						'banner' => theme('mic_banner', array('node' => $node, 'data' => $banner, 'size' => 'large')),
						'events' => theme('mic_events_block', array('node' => $node, 'data' => $events)),
						'events-see-all' => mic_implementation_get_see_all_link('event', $node),
						'feature_story' => theme('mic_feature_story_block', array('node' => $node, 'data' => $feature_story, 'size' => 'small')),
						'news_articles' => theme('mic_news_articles_block', array('node' => $node, 'data' => $articles)),
						'news-articles-see-all' => mic_implementation_get_see_all_link('article', $node),
						'feature_video' => theme('mic_feature_video_block', array('node' => $node, 'data' => $feature_video)),
					);
			}

			break;

		case 'audience_gateway_page':

			$node = $args['node'];

			$banner = mic_implementation_get_taxonomy_banner($node);
			$feature_story = mic_implementation_get_taxonomy_feature_story($node);

			return array(
					'banner' => theme('mic_banner', array('node' => $node, 'data' => $banner, 'size' => 'large')),
					'feature_story' => theme('mic_feature_story_block', array('node' => $node, 'data' => $feature_story, 'size' => 'large')),
				);

			break;

		case 'news_events_page':

			$node = variable_get('news_events_settings', NULL);

			$feature_story = mic_implementation_get_taxonomy_feature_story($node);
			$feature_video = mic_implementation_get_taxonomy_feature_video($node);

			return array(
				'feature_story' => theme('mic_feature_story_block', array('node' => $node, 'data' => $feature_story, 'size' => 'large')),
				'feature_video' => theme('mic_feature_video_block', array('node' => $node, 'data' => $feature_video)),
			);
			break;
	}
}

function mic_implementation_get_taxonomy_slideshow($node) {

	$today = strtotime(date('n/j/Y', time()));

	if(!empty($node->field_banner_slideshow_tags)) {

		$result = db_query("SELECT DISTINCT n.nid FROM {node} n
			INNER JOIN {taxonomy_index} ti ON n.nid = ti.nid
 			INNER JOIN {field_data_field_sunrise_date} srd ON n.nid = srd.entity_id
			INNER JOIN {field_data_field_sunset_date} ssd ON n.nid = ssd.entity_id
			WHERE n.type = 'feature_story'
			AND ti.tid in (".mic_implementation_get_taxonomy_term_list_from_array($node->field_banner_slideshow_tags['und']).")
			AND (srd.field_sunrise_date_value <= ".$today." AND ssd.field_sunset_date_value > ".$today.")
			ORDER BY n.created ASC
			LIMIT 0, 6");

	} else {

		if(!empty($node->field_tags)) {
			// use page level tags
			$result = db_query("SELECT DISTINCT n.nid FROM {node} n
				INNER JOIN {taxonomy_index} ti ON n.nid = ti.nid
 				INNER JOIN {field_data_field_sunrise_date} srd ON n.nid = srd.entity_id
				INNER JOIN {field_data_field_sunset_date} ssd ON n.nid = ssd.entity_id
				WHERE n.type = 'feature_story'
				AND ti.tid in (".mic_implementation_get_taxonomy_term_list_from_array($node->field_tags['und']).")
				AND (srd.field_sunrise_date_value <= ".$today." AND ssd.field_sunset_date_value > ".$today.")
				ORDER BY n.created ASC
				LIMIT 0, 6");
		} else {
			return NULL;
		}
	}
	$slideshow = array();
	foreach($result as $row) {
		$slideshow[] = node_load($row->nid);
	}
	return $slideshow;
}

function mic_implementation_get_taxonomy_banner($node) {

	switch($node->type) {
		case 'standard_template_page':
		case 'audience_gateway_page':
		case 'event':

			if(!empty($node->field_banner_tags)) {

				$result = db_query("SELECT DISTINCT n.nid FROM {node} n
					INNER JOIN {taxonomy_index} ti ON n.nid = ti.nid
					WHERE n.type = 'banner'
					AND ti.tid in (".mic_implementation_get_taxonomy_term_list_from_array($node->field_banner_tags['und']).")
					ORDER BY RAND()
					LIMIT 0, 1");

			} else {

				if(!empty($node->field_tags)) {
					// use page level tags
					$result = db_query("SELECT DISTINCT n.nid FROM {node} n
						INNER JOIN {taxonomy_index} ti ON n.nid = ti.nid
						WHERE n.type = 'banner'
						AND ti.tid in (".mic_implementation_get_taxonomy_term_list_from_array($node->field_tags['und']).")
						ORDER BY RAND()
						LIMIT 0, 1");
				} else {
					return NULL;
				}
			}
			break;
		case 'landing_page':

			if(!empty($node->field_banner_slideshow_tags)) {

				$result = db_query("SELECT DISTINCT n.nid FROM {node} n
					INNER JOIN {taxonomy_index} ti ON n.nid = ti.nid
					WHERE n.type = 'banner'
					AND ti.tid in (".mic_implementation_get_taxonomy_term_list_from_array($node->field_banner_slideshow_tags['und']).")
					ORDER BY RAND()
					LIMIT 0, 1");

			} else {

				if(!empty($node->field_tags)) {
					// use page level tags
					$result = db_query("SELECT DISTINCT n.nid FROM {node} n
						INNER JOIN {taxonomy_index} ti ON n.nid = ti.nid
						WHERE n.type = 'banner'
						AND ti.tid in (".mic_implementation_get_taxonomy_term_list_from_array($node->field_tags['und']).")
						ORDER BY RAND()
						LIMIT 0, 1");
				} else {
					return NULL;
				}
			}
			break;
	}

	foreach($result as $row) {
		return node_load($row->nid);
	}
}

function mic_implementation_get_taxonomy_news_articles($node, $type = 'node') {

	switch($type) {
		case 'listings':
			if(array_key_exists('filter', $node)) {
				$result = db_query("SELECT DISTINCT n.nid FROM {node} n
					INNER JOIN {taxonomy_index} ti ON n.nid = ti.nid
					WHERE n.type = 'news_article'
					AND ti.tid in (".$node['filter'].")
					ORDER BY n.created DESC
					LIMIT 0, 2");
			} else {
				$result = db_query("SELECT DISTINCT n.nid FROM {node} n
					INNER JOIN {taxonomy_index} ti ON n.nid = ti.nid
					WHERE n.type = 'news_article'
					ORDER BY n.created DESC
					LIMIT 0, 2");
			}
			break;
		case 'node':

			if(!empty($node->field_news_articles_tags)) {

				$result = db_query("SELECT DISTINCT n.nid FROM {node} n
					INNER JOIN {taxonomy_index} ti ON n.nid = ti.nid
					WHERE n.type = 'news_article'
					AND ti.tid in (".mic_implementation_get_taxonomy_term_list_from_array($node->field_news_articles_tags['und']).")
					AND n.nid != ".$node->nid."
					ORDER BY n.created DESC
					LIMIT 0, 2");

			} else {

				if(!empty($node->field_tags)) {
					// use page level tags
					$result = db_query("SELECT DISTINCT n.nid FROM {node} n
						INNER JOIN {taxonomy_index} ti ON n.nid = ti.nid
						WHERE n.type = 'news_article'
						AND ti.tid in (".mic_implementation_get_taxonomy_term_list_from_array($node->field_tags['und']).")
						AND n.nid != ".$node->nid."
						ORDER BY n.created DESC
						LIMIT 0, 2");
				} else {
					return NULL;
				}
			}
			break;
	}

	$articles = array();
	foreach($result as $row) {
		$articles[] = node_load($row->nid);
	}
	return $articles;
}

function mic_implementation_get_taxonomy_events($node, $type = 'node') {

	$today = strtotime(date('n/j/Y', time()));

	switch($type) {
		case 'listings':
			if(array_key_exists('filter', $node)) {
				$result = db_query(
				    "SELECT DISTINCT e2.nid, e2.field_event_date_value FROM
				    (
				    	SELECT DISTINCT e1.nid, e1.field_event_date_value FROM
				    	(
				    		SELECT DISTINCT n.nid, fd.field_event_date_value, fd.field_event_date_value2 FROM {node} n
				    		INNER JOIN {taxonomy_index} ti ON n.nid = ti.nid
				    		INNER JOIN {field_data_field_event_date} fd ON n.nid = fd.entity_id
				    		WHERE n.type = 'event'
				    		AND ti.tid in (".$node['filter'].")
				    		AND (fd.field_event_date_value >= ".$today." OR fd.field_event_date_value2 >= ".$today.")
				    		ORDER BY fd.field_event_date_value ASC
				    	) e1
				    	ORDER BY RAND()
				    ) e2
				    ORDER BY e2.field_event_date_value ASC
				    LIMIT 0, 2");
			} else {
				$result = db_query(
				    "SELECT DISTINCT e2.nid, e2.field_event_date_value FROM
				    (
				    	SELECT DISTINCT e1.nid, e1.field_event_date_value FROM
				    	(
				    		SELECT DISTINCT n.nid, fd.field_event_date_value, fd.field_event_date_value2 FROM {node} n
				    		INNER JOIN {taxonomy_index} ti ON n.nid = ti.nid
				    		INNER JOIN {field_data_field_event_date} fd ON n.nid = fd.entity_id
				    		WHERE n.type = 'event'
				    		AND (fd.field_event_date_value >= ".$today." OR fd.field_event_date_value2 >= ".$today.")
				    		ORDER BY fd.field_event_date_value ASC
				    	) e1
				    	ORDER BY RAND()
				    ) e2
				    ORDER BY e2.field_event_date_value ASC
				    LIMIT 0, 2");
			}

			break;
		case 'node':
			if(!empty($node->field_events_tags)) {

			    $result = db_query(
			    	"SELECT DISTINCT e2.nid, e2.field_event_date_value FROM
			    	(
			    		SELECT DISTINCT e1.nid, e1.field_event_date_value FROM
			    		(
			    			SELECT DISTINCT n.nid, fd.field_event_date_value, fd.field_event_date_value2 FROM {node} n
			    			INNER JOIN {taxonomy_index} ti ON n.nid = ti.nid
			    			INNER JOIN {field_data_field_event_date} fd ON n.nid = fd.entity_id
			    			WHERE n.type = 'event'
			    			AND ti.tid in (".mic_implementation_get_taxonomy_term_list_from_array($node->field_events_tags['und']).")
			    			AND n.nid != ".$node->nid."
			    			AND (fd.field_event_date_value >= ".$today." OR fd.field_event_date_value2 >= ".$today.")
			    			ORDER BY fd.field_event_date_value ASC
			    		) e1
			    		ORDER BY RAND()
			    	) e2
			    	ORDER BY e2.field_event_date_value ASC
			    	LIMIT 0, 2");

			} else {
			    if(!empty($node->field_tags)) {
			    	// use page level tags
			    	$result = db_query(
			    		"SELECT DISTINCT e2.nid, e2.field_event_date_value FROM
			    		(
			    			SELECT DISTINCT e1.nid, e1.field_event_date_value FROM
			    			(
			    				SELECT DISTINCT n.nid, fd.field_event_date_value, fd.field_event_date_value2 FROM {node} n
			    				INNER JOIN {taxonomy_index} ti ON n.nid = ti.nid
			    				INNER JOIN {field_data_field_event_date} fd ON n.nid = fd.entity_id
			    				WHERE n.type = 'event'
			    				AND ti.tid in (".mic_implementation_get_taxonomy_term_list_from_array($node->field_tags['und']).")
			    				AND n.nid != ".$node->nid."
			    				AND (fd.field_event_date_value >= ".$today." OR fd.field_event_date_value2 >= ".$today.")
			    				ORDER BY fd.field_event_date_value ASC
			    			) e1
			    			ORDER BY RAND()
			    		) e2
			    		ORDER BY e2.field_event_date_value ASC
			    		LIMIT 0, 2");
			    } else {
			    	return NULL;
			    }
			}

			break;
	}

	$events = array();
	foreach($result as $row) {
		$events[] = node_load($row->nid);
	}

	return $events;
}

function mic_implementation_get_taxonomy_feature_story($node) {

	$today = strtotime(date('n/j/Y', time()));

	if(is_array($node)) {
		// this is the news & events page
		if(isset($node['story_tags'])) {
			$result = db_query("SELECT DISTINCT n.nid FROM {node} n
			    INNER JOIN {taxonomy_index} ti ON n.nid = ti.nid
			    INNER JOIN {field_data_field_sunrise_date} srd ON n.nid = srd.entity_id
			    INNER JOIN {field_data_field_sunset_date} ssd ON n.nid = ssd.entity_id
			    WHERE n.type = 'feature_story'
			    AND ti.tid in (".mic_implementation_get_taxonomy_term_list_from_array($node['story_tags'], 'news-events').")
			    AND (srd.field_sunrise_date_value <= ".$today." AND ssd.field_sunset_date_value > ".$today.")
			    ORDER BY RAND()
			    LIMIT 0, 1");
		} else {
			return NULL;
		}

	} else {

		if(!empty($node->field_feature_story_tags)) {

			$result = db_query("SELECT DISTINCT n.nid FROM {node} n
				INNER JOIN {taxonomy_index} ti ON n.nid = ti.nid
				INNER JOIN {field_data_field_sunrise_date} srd ON n.nid = srd.entity_id
				INNER JOIN {field_data_field_sunset_date} ssd ON n.nid = ssd.entity_id
				WHERE n.type = 'feature_story'
				AND ti.tid in (".mic_implementation_get_taxonomy_term_list_from_array($node->field_feature_story_tags['und']).")
				AND n.nid != ".$node->nid."
				AND (srd.field_sunrise_date_value <= ".$today." AND ssd.field_sunset_date_value > ".$today.")
				ORDER BY RAND()
				LIMIT 0, 1");

		} else {
			if(!empty($node->field_tags)) {
				// use page level tags
				$result = db_query("SELECT DISTINCT n.nid FROM {node} n
					INNER JOIN {taxonomy_index} ti ON n.nid = ti.nid
					INNER JOIN {field_data_field_sunrise_date} srd ON n.nid = srd.entity_id
					INNER JOIN {field_data_field_sunset_date} ssd ON n.nid = ssd.entity_id
					WHERE n.type = 'feature_story'
					AND ti.tid in (".mic_implementation_get_taxonomy_term_list_from_array($node->field_tags['und']).")
					AND n.nid != ".$node->nid."
					AND (srd.field_sunrise_date_value <= ".$today." AND ssd.field_sunset_date_value > ".$today.")
					ORDER BY RAND()
					LIMIT 0, 1");
			} else {
				return NULL;
			}
		}
	}

	foreach($result as $row) {
		return node_load($row->nid);
	}
}

function mic_implementation_get_taxonomy_feature_video($node) {

	$today = strtotime(date('n/j/Y', time()));

	if(is_array($node)) {
		// this is the news & events page
		if(isset($node['video_tags'])) {
			$result = db_query("SELECT DISTINCT n.nid FROM {node} n
			    INNER JOIN {taxonomy_index} ti ON n.nid = ti.nid
			    INNER JOIN {field_data_field_sunrise_date} srd ON n.nid = srd.entity_id
			    INNER JOIN {field_data_field_sunset_date} ssd ON n.nid = ssd.entity_id
			    WHERE n.type = 'feature_video'
			    AND ti.tid in (".mic_implementation_get_taxonomy_term_list_from_array($node['video_tags'], 'news-events').")
			    AND (srd.field_sunrise_date_value <= ".$today." AND ssd.field_sunset_date_value > ".$today.")
			    ORDER BY RAND()
			    LIMIT 0, 1");
		} else {
			return NULL;
		}

	} else {

		if(!empty($node->field_feature_video_tags)) {

		   $result = db_query("SELECT DISTINCT n.nid FROM {node} n
		   	INNER JOIN {taxonomy_index} ti ON n.nid = ti.nid
		   	INNER JOIN {field_data_field_sunrise_date} srd ON n.nid = srd.entity_id
		   	INNER JOIN {field_data_field_sunset_date} ssd ON n.nid = ssd.entity_id
		   	WHERE n.type = 'feature_video'
		   	AND ti.tid in (".mic_implementation_get_taxonomy_term_list_from_array($node->field_feature_video_tags['und']).")
		   	AND n.nid != ".$node->nid."
		   	AND (srd.field_sunrise_date_value <= ".$today." AND ssd.field_sunset_date_value > ".$today.")
		   	ORDER BY RAND()
		   	LIMIT 0, 1");

		} else {
		   if(!empty($node->field_tags)) {
		   	// use page level tags
		   	$result = db_query("SELECT DISTINCT n.nid FROM {node} n
		   		INNER JOIN {taxonomy_index} ti ON n.nid = ti.nid
		   		INNER JOIN {field_data_field_sunrise_date} srd ON n.nid = srd.entity_id
		   		INNER JOIN {field_data_field_sunset_date} ssd ON n.nid = ssd.entity_id
		   		WHERE n.type = 'feature_video'
		   		AND ti.tid in (".mic_implementation_get_taxonomy_term_list_from_array($node->field_tags['und']).")
		   		AND n.nid != ".$node->nid."
		   		AND (srd.field_sunrise_date_value <= ".$today." AND ssd.field_sunset_date_value > ".$today.")
		   		ORDER BY RAND()
		   		LIMIT 0, 1");
		   } else {
		   	return NULL;
		   }
		}
	}

	foreach($result as $row) {
		return node_load($row->nid);
	}
}

function mic_implementation_get_classes($post) {
	$today = strtotime(date('n/j/Y', time()));
	$courses = array();

  if(valid_post($post)) {

    $query = new EntityFieldQuery();
    $query
      ->entityCondition('entity_type', 'node')
      ->entityCondition('bundle', 'item_course')
      ->propertyCondition('status', 1);

    $course_conditions = array(
      'age',
      'instrument',
      'program_area',
    );
    $class_conditions = array(
      'semester',
      'campus',
    );

    foreach ($course_conditions as $condition) {
      if (isset($post[$condition]) && is_numeric($post[$condition])) {
        $query->fieldCondition('field_' . $condition, 'tid', $post[$condition]);
      }
    }

    $query->propertyOrderBy('title');
    $result = $query->execute();

    if (empty($result['node'])) {
      $courses = t('There are no classes that match your criteria.');
    }
    else {
      $nids = array_keys($result['node']);
      //check class conditions
      foreach ($class_conditions as $condition) {
        if (isset($post[$condition]) && is_numeric($post[$condition])) {

          //setup keys to unset later
          $nids = array_combine(array_values($nids), array_values($nids));
          $value = $post[$condition];

          //edge case for campus
          $condition = ($condition == 'campus') ? 'location' : $condition;

          foreach ($nids as $nid) {
            if (!mic_implementation_classes_subquery($nid, $condition, $value)) {
              unset($nids[$nid]);
            }
          }

        }
      }
      $nodes = node_load_multiple($nids);
      $courses = node_view_multiple($nodes);
    }
  }

  return $courses;
}

/**
 * Sub-query to check class conditions
 *
 * @param int $nid
 * @param string $condition
 * @param mixed $value
 * @return bool
 */
function mic_implementation_classes_subquery($nid, $condition, $value) {
  $query = new EntityFieldQuery;
  $query
    ->entityCondition('entity_type', 'commerce_product')
    ->entityCondition('bundle', 'product_class')
    ->propertyCondition('status', 1);

  $query
    ->fieldCondition('field_' . $condition . '_reference', 'tid', $value)
    ->fieldCondition('field_course_reference', 'nid', $nid);

  $result = $query->execute();

  return (!empty($result)) ? TRUE : FALSE;

}

function mic_implementation_get_nodequeues() {

	$result = db_query("SELECT qid, title FROM {nodequeue_queue} ORDER BY title");

	$queues = array();
	foreach($result as $row) {
		$queues[$row->qid] = $row->title;
	}
	return $queues;
}

function mic_implementation_get_tags() {

    $terms = taxonomy_get_tree(1);
    if ($terms) {
		foreach ($terms as $term) {
			$options[$term->tid] = str_repeat('-', $term->depth) . $term->name;
		}
		return $options;
    }
    return NULL;

}

function mic_implementation_get_nodequeue_nodes($qid) {

	$result = db_query("SELECT nid FROM {nodequeue_nodes} WHERE qid = :qid ORDER BY position ASC", array(':qid' => $qid));

	$nodes = array();
	foreach($result as $row) {
		$nodes[] = node_load($row->nid);
	}
	return $nodes;
}

function mic_implementation_get_taxomony_terms($vocab) {

  $vid = 1;

  switch($vocab) {
    case 'ages':
      $vid = 5;
      break;
    case 'program_areas':
      $vid = 3;
      break;
    case 'instruments':
      $vid = 4;
      break;
    case 'campuses':
      $vid = 7;
      break;
    case 'semesters':
      $vid = 6;
      break;
  }

  $terms = taxonomy_get_tree($vid);
  $vocab = taxonomy_vocabulary_load($vid);
  if ($terms) {
    foreach ($terms as $term) {
      // Exclude terms in classfinder where checked.
      if (_mic_implementation_check_classfinder($term->tid, $vocab->machine_name)) {
        continue;
      }
      else {
        $options[$term->tid] = str_repeat('-', $term->depth) . $term->name;
      }
    }
    return $options;
  }
  return NULL;
}

/**
 * Check if term should show in classfinder widget list.
 *
 * @param $tid
 * @return bool
 */
function _mic_implementation_check_classfinder($tid, $vocab) {
  $query = db_select('field_data_field_exclude_listing', 'el');
  $query
    ->condition('entity_id', $tid)
    ->condition('entity_type', 'taxonomy_term')
    ->condition('bundle', $vocab)
    ->fields('el', array('field_exclude_listing_value'));
  $result = $query->execute()->fetchAssoc();
  $value = (isset($result['field_exclude_listing_value'])) ? $result['field_exclude_listing_value'] : NULL;

  return (isset($value) && ($value == 'classfinder')) ? TRUE : FALSE;
}

function mic_implementation_get_taxonomy_term_list_from_array($term_array, $type = 'node') {

	switch($type) {
		case 'node':

			foreach($term_array as $term) {
				if(isset($list))
					$list .= ','.$term['tid'];
				else
					$list = $term['tid'];
			}
			return $list;
			break;

		case 'news-events':
			foreach($term_array as $term) {
				if($term != '0') {
					if(isset($list))
						$list .= ','.$term;
					else
						$list = $term;
				}
			}
			return $list;
			break;
	}
}

function mic_implementation_get_taxonomy_term_list_string_from_array($term_array, $type = 'node') {

	switch($type) {
		case 'node':

			foreach($term_array as $term) {
				$term = taxonomy_term_load($term['tid']);
				$terms[] = $term->name;
			}
			sort($terms);
			foreach($terms as $term) {
				if(isset($list))
					$list .= ', '.$term;
				else
					$list = $term;

			}
			return $list;

			break;
		case 'class-finder':

			foreach($term_array as $tid) {
				$term = taxonomy_term_load($tid);
				$terms[] = $term->name;
			}
			sort($terms);
			foreach($terms as $term) {
				if(isset($list))
					$list .= ', '.$term;
				else
					$list = $term;

			}
			return $list;

			break;

	}
}

function mic_implementation_get_see_all_link($type, $node) {

	switch($type) {
		case 'event':
			if(!empty($node->field_events_tags))
				return base_path().'event-listings?tid='.mic_implementation_get_taxonomy_term_list_from_array($node->field_events_tags['und']);
			else
				return base_path().'event-listings?tid='.mic_implementation_get_taxonomy_term_list_from_array($node->field_tags['und']);
			break;
		case 'article':
			if(!empty($node->field_articles_tags))
				return base_path().'article-listings?tid='.mic_implementation_get_taxonomy_term_list_from_array($node->field_articles_tags['und']);
			else
				return base_path().'article-listings?tid='.mic_implementation_get_taxonomy_term_list_from_array($node->field_tags['und']);
			break;
	}
}

function mic_implementation_get_display_body($body, $trim_length = 200) {

	if(strlen($body['summary']) > 0)
		return $body['summary'];
	else
		return substr(strip_tags($body['safe_value']), 0, $trim_length);
}

function mic_implementation_check_valid_type($type) {

	$types = array('event','feature_story','feature_video','news_article', 'profile');

	if(in_array($type, $types))
		return TRUE;

}

function mic_implementation_check_valid_filter($filter) {

	# These filters should only be taxonomy terms, so lets check if we get anything back.
	$terms = split(',', $filter);

	foreach($terms as $tid) {
		$t = taxonomy_term_load($tid);
		if(!$t)
			return FALSE;
	}

	return TRUE;

}

function valid_post($post) {

	if(strlen($post['age']) == 0 && strlen($post['program_area']) == 0 && strlen($post['instrument']) == 0 && strlen($post['campus']) == 0 && strlen($post['semester']) == 0)
		return FALSE;
	else
		return TRUE;
}

?>