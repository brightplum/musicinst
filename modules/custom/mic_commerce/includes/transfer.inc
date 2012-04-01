<?php

function mic_commerce_get_course($class_node) {
  $course_node = field_get_items('node', $class_node, 'field_course_reference');
  $course_node = reset($course_node);
  $course_node = node_load($course_node);

  return $course_node;
}

function mic_commerce_get_price($class_node) {
  $course_node = mic_commerce_get_course($class_node);
  $semester = mic_commerce_get_semester($class_node);

  //calculate fees
  $fees = field_get_items('node', $course_node, 'field_' . $semester . '_materials_fees');
  $fees = reset($fees);
  $fees = (isset($fees['value']))
    ? $fees['value']: 0;

  $price = field_get_items('node', $course_node, 'field_' . $semester . '_price');
  $price = reset($price);
  $price = ($price['value'] + $fees) * 100;
  $price = array(
    'amount' => str_replace('.', '', $price),
    'currency_code' => 'USD',
    'data' => array('components' => array()),
  );

  return $price;
}

function mic_commerce_get_field_value($class_node, $field_name) {
  $value = field_get_items('node', $class_node, $field_name);
  $value = reset($value);
  return $value;
}

function mic_commerce_get_semester($class_node) {
  $semester = mic_commerce_get_field_value($class_node, 'field_semester_reference');
  $semester = mic_commerce_price_reference($semester);
  return $semester;
}

function mic_commerce_get_semester_string($class_node) {
  $semester = mic_commerce_get_field_value($class_node, 'field_semester_reference');
  $tid = $semester['tid'];
  $term = taxonomy_term_load($tid);
  $semester = strtolower(str_replace(' ', '', $term->name));
  return $semester;
}

function mic_commerce_get_instructor_string($class_node) {
  $instructor = mic_commerce_get_field_value($class_node, 'field_instructor_reference');
  if ($nid = $instructor['nid']) {
    $node = node_load($nid);
    $instructor = strtolower(str_replace(' ', '', $node->title));
  }
  else {
    $instructor = 'none';
  }
  return $instructor;
}

/**
 * Helper to get the semester the price relates to
 *
 * @param int $tid
 * @return string
 */
function mic_commerce_price_reference($tid) {
  $term = taxonomy_term_load($tid['tid']);
  $semester = strtolower(substr($term->name, 0, strpos($term->name, ' ')));
  return $semester;
}