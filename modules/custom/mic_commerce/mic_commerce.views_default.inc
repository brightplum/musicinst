<?php
/**
 * @file
 * Default Views functionality.
 */

/**
 * hook_views_default_views().
 */
function mic_commerce_views_default_views_alter(&$views) {
  $export = array();
  if (isset($views['commerce_cart_form'])) {
    $view = new view;
    $view->name = 'commerce_cart_form';
    $view->description = 'Display a shopping cart update form.';
    $view->tag = 'commerce';
    $view->base_table = 'commerce_order';
    $view->human_name = 'Shopping cart form';
    $view->core = 0;
    $view->api_version = '3.0';
    $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

    /* Display: Defaults */
    $handler = $view->new_display('default', 'Defaults', 'default');
    $handler->display->display_options['title'] = 'Shopping cart';
    $handler->display->display_options['access']['type'] = 'none';
    $handler->display->display_options['cache']['type'] = 'none';
    $handler->display->display_options['query']['type'] = 'views_query';
    $handler->display->display_options['query']['options']['query_comment'] = FALSE;
    $handler->display->display_options['exposed_form']['type'] = 'basic';
    $handler->display->display_options['pager']['type'] = 'none';
    $handler->display->display_options['style_plugin'] = 'table';
    $handler->display->display_options['style_options']['columns'] = array(
      'commerce_display_path' => 'commerce_display_path',
      'product_attributes' => 'product_attributes',
      'field_class_lineitem_detail' => 'field_class_lineitem_detail',
      'field_lineitem_tkt_eventname' => 'field_class_lineitem_detail',
      'commerce_unit_price' => 'commerce_unit_price',
      'edit_quantity' => 'edit_quantity',
      'edit_delete' => 'edit_delete',
      'commerce_total' => 'commerce_total',
    );
    $handler->display->display_options['style_options']['default'] = '-1';
    $handler->display->display_options['style_options']['info'] = array(
      'commerce_display_path' => array(
        'sortable' => 0,
        'default_sort_order' => 'asc',
        'align' => '',
        'separator' => '',
        'empty_column' => 0,
      ),
      'product_attributes' => array(
        'align' => '',
        'separator' => '',
        'empty_column' => 0,
      ),
      'field_class_lineitem_detail' => array(
        'sortable' => 0,
        'default_sort_order' => 'asc',
        'align' => '',
        'separator' => '',
        'empty_column' => 0,
      ),
      'field_lineitem_tkt_eventname' => array(
        'sortable' => 0,
        'default_sort_order' => 'asc',
        'align' => '',
        'separator' => '',
        'empty_column' => 0,
      ),
      'commerce_unit_price' => array(
        'sortable' => 0,
        'default_sort_order' => 'asc',
        'align' => '',
        'separator' => '',
        'empty_column' => 0,
      ),
      'edit_quantity' => array(
        'align' => '',
        'separator' => '',
        'empty_column' => 0,
      ),
      'edit_delete' => array(
        'align' => '',
        'separator' => '',
        'empty_column' => 0,
      ),
      'commerce_total' => array(
        'sortable' => 0,
        'default_sort_order' => 'asc',
        'align' => '',
        'separator' => '',
        'empty_column' => 0,
      ),
    );
    $handler->display->display_options['style_options']['override'] = 1;
    $handler->display->display_options['style_options']['sticky'] = 0;
    $handler->display->display_options['style_options']['empty_table'] = 0;
    /* Footer: Commerce Line Item: Line item summary */
    $handler->display->display_options['footer']['line_item_summary']['id'] = 'line_item_summary';
    $handler->display->display_options['footer']['line_item_summary']['table'] = 'commerce_line_item';
    $handler->display->display_options['footer']['line_item_summary']['field'] = 'line_item_summary';
    $handler->display->display_options['footer']['line_item_summary']['label'] = 'Cart summary';
    $handler->display->display_options['footer']['line_item_summary']['info'] = array(
      'quantity' => 0,
      'total' => 'total',
    );
    /* Relationship: Commerce Order: Referenced line item */
    $handler->display->display_options['relationships']['commerce_line_items_line_item_id']['id'] = 'commerce_line_items_line_item_id';
    $handler->display->display_options['relationships']['commerce_line_items_line_item_id']['table'] = 'field_data_commerce_line_items';
    $handler->display->display_options['relationships']['commerce_line_items_line_item_id']['field'] = 'commerce_line_items_line_item_id';
    $handler->display->display_options['relationships']['commerce_line_items_line_item_id']['required'] = 1;
    /* Field: Commerce Line item: Display path */
    $handler->display->display_options['fields']['commerce_display_path']['id'] = 'commerce_display_path';
    $handler->display->display_options['fields']['commerce_display_path']['table'] = 'field_data_commerce_display_path';
    $handler->display->display_options['fields']['commerce_display_path']['field'] = 'commerce_display_path';
    $handler->display->display_options['fields']['commerce_display_path']['relationship'] = 'commerce_line_items_line_item_id';
    $handler->display->display_options['fields']['commerce_display_path']['label'] = '';
    $handler->display->display_options['fields']['commerce_display_path']['exclude'] = TRUE;
    $handler->display->display_options['fields']['commerce_display_path']['alter']['alter_text'] = 0;
    $handler->display->display_options['fields']['commerce_display_path']['alter']['make_link'] = 0;
    $handler->display->display_options['fields']['commerce_display_path']['alter']['absolute'] = 0;
    $handler->display->display_options['fields']['commerce_display_path']['alter']['external'] = 0;
    $handler->display->display_options['fields']['commerce_display_path']['alter']['nl2br'] = 0;
    $handler->display->display_options['fields']['commerce_display_path']['alter']['word_boundary'] = 1;
    $handler->display->display_options['fields']['commerce_display_path']['alter']['ellipsis'] = 1;
    $handler->display->display_options['fields']['commerce_display_path']['alter']['strip_tags'] = 0;
    $handler->display->display_options['fields']['commerce_display_path']['alter']['trim'] = 0;
    $handler->display->display_options['fields']['commerce_display_path']['alter']['html'] = 0;
    $handler->display->display_options['fields']['commerce_display_path']['element_label_colon'] = 1;
    $handler->display->display_options['fields']['commerce_display_path']['element_default_classes'] = 1;
    $handler->display->display_options['fields']['commerce_display_path']['hide_empty'] = 0;
    $handler->display->display_options['fields']['commerce_display_path']['empty_zero'] = 0;
    $handler->display->display_options['fields']['commerce_display_path']['field_api_classes'] = 0;
    /* Field: Commerce Line Item: Product Attributes */
    $handler->display->display_options['fields']['product_attributes']['id'] = 'product_attributes';
    $handler->display->display_options['fields']['product_attributes']['table'] = 'commerce_line_item';
    $handler->display->display_options['fields']['product_attributes']['field'] = 'product_attributes';
    $handler->display->display_options['fields']['product_attributes']['relationship'] = 'commerce_line_items_line_item_id';
    $handler->display->display_options['fields']['product_attributes']['label'] = '';
    $handler->display->display_options['fields']['product_attributes']['alter']['alter_text'] = 0;
    $handler->display->display_options['fields']['product_attributes']['alter']['make_link'] = 0;
    $handler->display->display_options['fields']['product_attributes']['alter']['absolute'] = 0;
    $handler->display->display_options['fields']['product_attributes']['alter']['external'] = 0;
    $handler->display->display_options['fields']['product_attributes']['alter']['replace_spaces'] = 0;
    $handler->display->display_options['fields']['product_attributes']['alter']['trim_whitespace'] = 0;
    $handler->display->display_options['fields']['product_attributes']['alter']['nl2br'] = 0;
    $handler->display->display_options['fields']['product_attributes']['alter']['word_boundary'] = 1;
    $handler->display->display_options['fields']['product_attributes']['alter']['ellipsis'] = 1;
    $handler->display->display_options['fields']['product_attributes']['alter']['strip_tags'] = 0;
    $handler->display->display_options['fields']['product_attributes']['alter']['trim'] = 0;
    $handler->display->display_options['fields']['product_attributes']['alter']['html'] = 0;
    $handler->display->display_options['fields']['product_attributes']['element_label_colon'] = FALSE;
    $handler->display->display_options['fields']['product_attributes']['element_default_classes'] = 1;
    $handler->display->display_options['fields']['product_attributes']['hide_empty'] = 0;
    $handler->display->display_options['fields']['product_attributes']['empty_zero'] = 0;
    $handler->display->display_options['fields']['product_attributes']['hide_alter_empty'] = 1;
    $handler->display->display_options['fields']['product_attributes']['show_link'] = 1;
    $handler->display->display_options['fields']['product_attributes']['link_with_line_item'] = 1;
    /* Field: Commerce Line item: Additional Details */
    $handler->display->display_options['fields']['field_class_lineitem_detail']['id'] = 'field_class_lineitem_detail';
    $handler->display->display_options['fields']['field_class_lineitem_detail']['table'] = 'field_data_field_class_lineitem_detail';
    $handler->display->display_options['fields']['field_class_lineitem_detail']['field'] = 'field_class_lineitem_detail';
    $handler->display->display_options['fields']['field_class_lineitem_detail']['relationship'] = 'commerce_line_items_line_item_id';
    $handler->display->display_options['fields']['field_class_lineitem_detail']['alter']['alter_text'] = 0;
    $handler->display->display_options['fields']['field_class_lineitem_detail']['alter']['make_link'] = 0;
    $handler->display->display_options['fields']['field_class_lineitem_detail']['alter']['absolute'] = 0;
    $handler->display->display_options['fields']['field_class_lineitem_detail']['alter']['external'] = 0;
    $handler->display->display_options['fields']['field_class_lineitem_detail']['alter']['replace_spaces'] = 0;
    $handler->display->display_options['fields']['field_class_lineitem_detail']['alter']['trim_whitespace'] = 0;
    $handler->display->display_options['fields']['field_class_lineitem_detail']['alter']['nl2br'] = 0;
    $handler->display->display_options['fields']['field_class_lineitem_detail']['alter']['word_boundary'] = 1;
    $handler->display->display_options['fields']['field_class_lineitem_detail']['alter']['ellipsis'] = 1;
    $handler->display->display_options['fields']['field_class_lineitem_detail']['alter']['strip_tags'] = 0;
    $handler->display->display_options['fields']['field_class_lineitem_detail']['alter']['trim'] = 0;
    $handler->display->display_options['fields']['field_class_lineitem_detail']['alter']['html'] = 0;
    $handler->display->display_options['fields']['field_class_lineitem_detail']['element_label_colon'] = 1;
    $handler->display->display_options['fields']['field_class_lineitem_detail']['element_default_classes'] = 1;
    $handler->display->display_options['fields']['field_class_lineitem_detail']['hide_empty'] = 0;
    $handler->display->display_options['fields']['field_class_lineitem_detail']['empty_zero'] = 0;
    $handler->display->display_options['fields']['field_class_lineitem_detail']['hide_alter_empty'] = 1;
    $handler->display->display_options['fields']['field_class_lineitem_detail']['field_api_classes'] = 0;
    /* Field: Commerce Line item: Event Name */
    $handler->display->display_options['fields']['field_lineitem_tkt_eventname']['id'] = 'field_lineitem_tkt_eventname';
    $handler->display->display_options['fields']['field_lineitem_tkt_eventname']['table'] = 'field_data_field_lineitem_tkt_eventname';
    $handler->display->display_options['fields']['field_lineitem_tkt_eventname']['field'] = 'field_lineitem_tkt_eventname';
    $handler->display->display_options['fields']['field_lineitem_tkt_eventname']['relationship'] = 'commerce_line_items_line_item_id';
    $handler->display->display_options['fields']['field_lineitem_tkt_eventname']['alter']['alter_text'] = 0;
    $handler->display->display_options['fields']['field_lineitem_tkt_eventname']['alter']['make_link'] = 0;
    $handler->display->display_options['fields']['field_lineitem_tkt_eventname']['alter']['absolute'] = 0;
    $handler->display->display_options['fields']['field_lineitem_tkt_eventname']['alter']['external'] = 0;
    $handler->display->display_options['fields']['field_lineitem_tkt_eventname']['alter']['replace_spaces'] = 0;
    $handler->display->display_options['fields']['field_lineitem_tkt_eventname']['alter']['trim_whitespace'] = 0;
    $handler->display->display_options['fields']['field_lineitem_tkt_eventname']['alter']['nl2br'] = 0;
    $handler->display->display_options['fields']['field_lineitem_tkt_eventname']['alter']['word_boundary'] = 1;
    $handler->display->display_options['fields']['field_lineitem_tkt_eventname']['alter']['ellipsis'] = 1;
    $handler->display->display_options['fields']['field_lineitem_tkt_eventname']['alter']['strip_tags'] = 0;
    $handler->display->display_options['fields']['field_lineitem_tkt_eventname']['alter']['trim'] = 0;
    $handler->display->display_options['fields']['field_lineitem_tkt_eventname']['alter']['html'] = 0;
    $handler->display->display_options['fields']['field_lineitem_tkt_eventname']['element_label_colon'] = 1;
    $handler->display->display_options['fields']['field_lineitem_tkt_eventname']['element_default_classes'] = 1;
    $handler->display->display_options['fields']['field_lineitem_tkt_eventname']['hide_empty'] = 0;
    $handler->display->display_options['fields']['field_lineitem_tkt_eventname']['empty_zero'] = 0;
    $handler->display->display_options['fields']['field_lineitem_tkt_eventname']['hide_alter_empty'] = 1;
    $handler->display->display_options['fields']['field_lineitem_tkt_eventname']['field_api_classes'] = 0;
    /* Field: Commerce Line item: Unit price */
    $handler->display->display_options['fields']['commerce_unit_price']['id'] = 'commerce_unit_price';
    $handler->display->display_options['fields']['commerce_unit_price']['table'] = 'field_data_commerce_unit_price';
    $handler->display->display_options['fields']['commerce_unit_price']['field'] = 'commerce_unit_price';
    $handler->display->display_options['fields']['commerce_unit_price']['relationship'] = 'commerce_line_items_line_item_id';
    $handler->display->display_options['fields']['commerce_unit_price']['label'] = 'Price';
    $handler->display->display_options['fields']['commerce_unit_price']['alter']['alter_text'] = 0;
    $handler->display->display_options['fields']['commerce_unit_price']['alter']['make_link'] = 0;
    $handler->display->display_options['fields']['commerce_unit_price']['alter']['absolute'] = 0;
    $handler->display->display_options['fields']['commerce_unit_price']['alter']['external'] = 0;
    $handler->display->display_options['fields']['commerce_unit_price']['alter']['nl2br'] = 0;
    $handler->display->display_options['fields']['commerce_unit_price']['alter']['word_boundary'] = 1;
    $handler->display->display_options['fields']['commerce_unit_price']['alter']['ellipsis'] = 1;
    $handler->display->display_options['fields']['commerce_unit_price']['alter']['strip_tags'] = 0;
    $handler->display->display_options['fields']['commerce_unit_price']['alter']['trim'] = 0;
    $handler->display->display_options['fields']['commerce_unit_price']['alter']['html'] = 0;
    $handler->display->display_options['fields']['commerce_unit_price']['element_class'] = 'price';
    $handler->display->display_options['fields']['commerce_unit_price']['element_label_colon'] = 1;
    $handler->display->display_options['fields']['commerce_unit_price']['element_default_classes'] = 1;
    $handler->display->display_options['fields']['commerce_unit_price']['hide_empty'] = 0;
    $handler->display->display_options['fields']['commerce_unit_price']['empty_zero'] = 0;
    $handler->display->display_options['fields']['commerce_unit_price']['click_sort_column'] = 'amount';
    $handler->display->display_options['fields']['commerce_unit_price']['type'] = 'commerce_price_formatted_amount';
    $handler->display->display_options['fields']['commerce_unit_price']['field_api_classes'] = 0;
    /* Field: Commerce Line Item: Quantity text field */
    $handler->display->display_options['fields']['edit_quantity']['id'] = 'edit_quantity';
    $handler->display->display_options['fields']['edit_quantity']['table'] = 'commerce_line_item';
    $handler->display->display_options['fields']['edit_quantity']['field'] = 'edit_quantity';
    $handler->display->display_options['fields']['edit_quantity']['relationship'] = 'commerce_line_items_line_item_id';
    $handler->display->display_options['fields']['edit_quantity']['label'] = 'Quantity';
    $handler->display->display_options['fields']['edit_quantity']['alter']['alter_text'] = 0;
    $handler->display->display_options['fields']['edit_quantity']['alter']['make_link'] = 0;
    $handler->display->display_options['fields']['edit_quantity']['alter']['absolute'] = 0;
    $handler->display->display_options['fields']['edit_quantity']['alter']['external'] = 0;
    $handler->display->display_options['fields']['edit_quantity']['alter']['nl2br'] = 0;
    $handler->display->display_options['fields']['edit_quantity']['alter']['word_boundary'] = 0;
    $handler->display->display_options['fields']['edit_quantity']['alter']['ellipsis'] = 0;
    $handler->display->display_options['fields']['edit_quantity']['alter']['strip_tags'] = 0;
    $handler->display->display_options['fields']['edit_quantity']['alter']['trim'] = 0;
    $handler->display->display_options['fields']['edit_quantity']['alter']['html'] = 0;
    $handler->display->display_options['fields']['edit_quantity']['element_label_colon'] = 0;
    $handler->display->display_options['fields']['edit_quantity']['element_default_classes'] = 0;
    $handler->display->display_options['fields']['edit_quantity']['hide_empty'] = 0;
    $handler->display->display_options['fields']['edit_quantity']['empty_zero'] = 0;
    /* Field: Commerce Line Item: Delete button */
    $handler->display->display_options['fields']['edit_delete']['id'] = 'edit_delete';
    $handler->display->display_options['fields']['edit_delete']['table'] = 'commerce_line_item';
    $handler->display->display_options['fields']['edit_delete']['field'] = 'edit_delete';
    $handler->display->display_options['fields']['edit_delete']['relationship'] = 'commerce_line_items_line_item_id';
    $handler->display->display_options['fields']['edit_delete']['label'] = 'Remove';
    $handler->display->display_options['fields']['edit_delete']['alter']['alter_text'] = 0;
    $handler->display->display_options['fields']['edit_delete']['alter']['make_link'] = 0;
    $handler->display->display_options['fields']['edit_delete']['alter']['absolute'] = 0;
    $handler->display->display_options['fields']['edit_delete']['alter']['external'] = 0;
    $handler->display->display_options['fields']['edit_delete']['alter']['nl2br'] = 0;
    $handler->display->display_options['fields']['edit_delete']['alter']['word_boundary'] = 1;
    $handler->display->display_options['fields']['edit_delete']['alter']['ellipsis'] = 1;
    $handler->display->display_options['fields']['edit_delete']['alter']['strip_tags'] = 0;
    $handler->display->display_options['fields']['edit_delete']['alter']['trim'] = 0;
    $handler->display->display_options['fields']['edit_delete']['alter']['html'] = 0;
    $handler->display->display_options['fields']['edit_delete']['element_label_colon'] = 1;
    $handler->display->display_options['fields']['edit_delete']['element_default_classes'] = 1;
    $handler->display->display_options['fields']['edit_delete']['hide_empty'] = 0;
    $handler->display->display_options['fields']['edit_delete']['empty_zero'] = 0;
    /* Field: Commerce Line item: Total */
    $handler->display->display_options['fields']['commerce_total']['id'] = 'commerce_total';
    $handler->display->display_options['fields']['commerce_total']['table'] = 'field_data_commerce_total';
    $handler->display->display_options['fields']['commerce_total']['field'] = 'commerce_total';
    $handler->display->display_options['fields']['commerce_total']['relationship'] = 'commerce_line_items_line_item_id';
    $handler->display->display_options['fields']['commerce_total']['alter']['alter_text'] = 0;
    $handler->display->display_options['fields']['commerce_total']['alter']['make_link'] = 0;
    $handler->display->display_options['fields']['commerce_total']['alter']['absolute'] = 0;
    $handler->display->display_options['fields']['commerce_total']['alter']['external'] = 0;
    $handler->display->display_options['fields']['commerce_total']['alter']['nl2br'] = 0;
    $handler->display->display_options['fields']['commerce_total']['alter']['word_boundary'] = 1;
    $handler->display->display_options['fields']['commerce_total']['alter']['ellipsis'] = 1;
    $handler->display->display_options['fields']['commerce_total']['alter']['strip_tags'] = 0;
    $handler->display->display_options['fields']['commerce_total']['alter']['trim'] = 0;
    $handler->display->display_options['fields']['commerce_total']['alter']['html'] = 0;
    $handler->display->display_options['fields']['commerce_total']['element_class'] = 'price';
    $handler->display->display_options['fields']['commerce_total']['element_label_colon'] = 1;
    $handler->display->display_options['fields']['commerce_total']['element_default_classes'] = 1;
    $handler->display->display_options['fields']['commerce_total']['hide_empty'] = 0;
    $handler->display->display_options['fields']['commerce_total']['empty_zero'] = 0;
    $handler->display->display_options['fields']['commerce_total']['click_sort_column'] = 'amount';
    $handler->display->display_options['fields']['commerce_total']['type'] = 'commerce_price_formatted_amount';
    $handler->display->display_options['fields']['commerce_total']['field_api_classes'] = 0;
    /* Sort criterion: Commerce Line Item: Line item ID */
    $handler->display->display_options['sorts']['line_item_id']['id'] = 'line_item_id';
    $handler->display->display_options['sorts']['line_item_id']['table'] = 'commerce_line_item';
    $handler->display->display_options['sorts']['line_item_id']['field'] = 'line_item_id';
    $handler->display->display_options['sorts']['line_item_id']['relationship'] = 'commerce_line_items_line_item_id';
    /* Contextual filter: Commerce Order: Order ID */
    $handler->display->display_options['arguments']['order_id']['id'] = 'order_id';
    $handler->display->display_options['arguments']['order_id']['table'] = 'commerce_order';
    $handler->display->display_options['arguments']['order_id']['field'] = 'order_id';
    $handler->display->display_options['arguments']['order_id']['default_action'] = 'empty';
    $handler->display->display_options['arguments']['order_id']['default_argument_type'] = 'fixed';
    $handler->display->display_options['arguments']['order_id']['summary']['number_of_records'] = '0';
    $handler->display->display_options['arguments']['order_id']['summary']['format'] = 'default_summary';
    $handler->display->display_options['arguments']['order_id']['summary_options']['items_per_page'] = '25';
    $handler->display->display_options['arguments']['order_id']['break_phrase'] = 0;
    $handler->display->display_options['arguments']['order_id']['not'] = 0;
    /* Filter criterion: Commerce Line Item: Line item is of a product line item type */
    $handler->display->display_options['filters']['product_line_item_type']['id'] = 'product_line_item_type';
    $handler->display->display_options['filters']['product_line_item_type']['table'] = 'commerce_line_item';
    $handler->display->display_options['filters']['product_line_item_type']['field'] = 'product_line_item_type';
    $handler->display->display_options['filters']['product_line_item_type']['relationship'] = 'commerce_line_items_line_item_id';
    $handler->display->display_options['filters']['product_line_item_type']['value'] = '1';
    $handler->display->display_options['filters']['product_line_item_type']['group'] = 0;

    $views['commerce_cart_form'] = $view;
  }
  $export['commerce_cart_form'] = $view;

  if (isset($views['commerce_cart_summary'])) {
    $view = new view;
    $view->name = 'commerce_cart_summary';
    $view->description = 'Cart line item summary displayed during checkout.';
    $view->tag = 'commerce';
    $view->base_table = 'commerce_order';
    $view->human_name = 'Shopping cart summary';
    $view->core = 0;
    $view->api_version = '3.0';
    $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

    /* Display: Defaults */
    $handler = $view->new_display('default', 'Defaults', 'default');
    $handler->display->display_options['title'] = 'Shopping cart';
    $handler->display->display_options['access']['type'] = 'none';
    $handler->display->display_options['cache']['type'] = 'none';
    $handler->display->display_options['query']['type'] = 'views_query';
    $handler->display->display_options['query']['options']['query_comment'] = FALSE;
    $handler->display->display_options['exposed_form']['type'] = 'basic';
    $handler->display->display_options['pager']['type'] = 'none';
    $handler->display->display_options['style_plugin'] = 'table';
    $handler->display->display_options['style_options']['columns'] = array(
      'product_attributes' => 'product_attributes',
      'field_class_lineitem_detail' => 'field_class_lineitem_detail',
      'field_lineitem_tkt_eventname' => 'field_class_lineitem_detail',
      'commerce_unit_price' => 'commerce_unit_price',
      'quantity' => 'quantity',
      'commerce_total' => 'commerce_total',
    );
    $handler->display->display_options['style_options']['default'] = '-1';
    $handler->display->display_options['style_options']['info'] = array(
      'product_attributes' => array(
        'align' => '',
        'separator' => '',
        'empty_column' => 0,
      ),
      'field_class_lineitem_detail' => array(
        'sortable' => 0,
        'default_sort_order' => 'asc',
        'align' => '',
        'separator' => '',
        'empty_column' => 0,
      ),
      'field_lineitem_tkt_eventname' => array(
        'sortable' => 0,
        'default_sort_order' => 'asc',
        'align' => '',
        'separator' => '',
        'empty_column' => 0,
      ),
      'commerce_unit_price' => array(
        'sortable' => 0,
        'default_sort_order' => 'asc',
        'align' => '',
        'separator' => '',
        'empty_column' => 0,
      ),
      'quantity' => array(
        'sortable' => 0,
        'default_sort_order' => 'asc',
        'align' => '',
        'separator' => '',
        'empty_column' => 0,
      ),
      'commerce_total' => array(
        'sortable' => 0,
        'default_sort_order' => 'asc',
        'align' => 'views-align-right',
        'separator' => '',
        'empty_column' => 0,
      ),
    );
    $handler->display->display_options['style_options']['override'] = 1;
    $handler->display->display_options['style_options']['sticky'] = 0;
    $handler->display->display_options['style_options']['empty_table'] = 0;
    /* Footer: Commerce Order: Order total */
    $handler->display->display_options['footer']['order_total']['id'] = 'order_total';
    $handler->display->display_options['footer']['order_total']['table'] = 'commerce_order';
    $handler->display->display_options['footer']['order_total']['field'] = 'order_total';
    $handler->display->display_options['footer']['order_total']['empty'] = FALSE;
    /* Relationship: Commerce Order: Referenced line item */
    $handler->display->display_options['relationships']['commerce_line_items_line_item_id']['id'] = 'commerce_line_items_line_item_id';
    $handler->display->display_options['relationships']['commerce_line_items_line_item_id']['table'] = 'field_data_commerce_line_items';
    $handler->display->display_options['relationships']['commerce_line_items_line_item_id']['field'] = 'commerce_line_items_line_item_id';
    $handler->display->display_options['relationships']['commerce_line_items_line_item_id']['required'] = 1;
    /* Field: Commerce Line Item: Product Attributes */
    $handler->display->display_options['fields']['product_attributes']['id'] = 'product_attributes';
    $handler->display->display_options['fields']['product_attributes']['table'] = 'commerce_line_item';
    $handler->display->display_options['fields']['product_attributes']['field'] = 'product_attributes';
    /* Field: Commerce Line item: Additional Details */
    $handler->display->display_options['fields']['field_class_lineitem_detail']['id'] = 'field_class_lineitem_detail';
    $handler->display->display_options['fields']['field_class_lineitem_detail']['table'] = 'field_data_field_class_lineitem_detail';
    $handler->display->display_options['fields']['field_class_lineitem_detail']['field'] = 'field_class_lineitem_detail';
    $handler->display->display_options['fields']['field_class_lineitem_detail']['relationship'] = 'commerce_line_items_line_item_id';
    /* Field: Commerce Line item: Event Name */
    $handler->display->display_options['fields']['field_lineitem_tkt_eventname']['id'] = 'field_lineitem_tkt_eventname';
    $handler->display->display_options['fields']['field_lineitem_tkt_eventname']['table'] = 'field_data_field_lineitem_tkt_eventname';
    $handler->display->display_options['fields']['field_lineitem_tkt_eventname']['field'] = 'field_lineitem_tkt_eventname';
    $handler->display->display_options['fields']['field_lineitem_tkt_eventname']['relationship'] = 'commerce_line_items_line_item_id';
    $handler->display->display_options['fields']['field_lineitem_tkt_eventname']['alter']['alter_text'] = 0;
    $handler->display->display_options['fields']['field_lineitem_tkt_eventname']['alter']['make_link'] = 0;
    $handler->display->display_options['fields']['field_lineitem_tkt_eventname']['alter']['absolute'] = 0;
    $handler->display->display_options['fields']['field_lineitem_tkt_eventname']['alter']['external'] = 0;
    $handler->display->display_options['fields']['field_lineitem_tkt_eventname']['alter']['replace_spaces'] = 0;
    $handler->display->display_options['fields']['field_lineitem_tkt_eventname']['alter']['trim_whitespace'] = 0;
    $handler->display->display_options['fields']['field_lineitem_tkt_eventname']['alter']['nl2br'] = 0;
    $handler->display->display_options['fields']['field_lineitem_tkt_eventname']['alter']['word_boundary'] = 1;
    $handler->display->display_options['fields']['field_lineitem_tkt_eventname']['alter']['ellipsis'] = 1;
    $handler->display->display_options['fields']['field_lineitem_tkt_eventname']['alter']['strip_tags'] = 0;
    $handler->display->display_options['fields']['field_lineitem_tkt_eventname']['alter']['trim'] = 0;
    $handler->display->display_options['fields']['field_lineitem_tkt_eventname']['alter']['html'] = 0;
    $handler->display->display_options['fields']['field_lineitem_tkt_eventname']['element_label_colon'] = 1;
    $handler->display->display_options['fields']['field_lineitem_tkt_eventname']['element_default_classes'] = 1;
    $handler->display->display_options['fields']['field_lineitem_tkt_eventname']['hide_empty'] = 0;
    $handler->display->display_options['fields']['field_lineitem_tkt_eventname']['empty_zero'] = 0;
    $handler->display->display_options['fields']['field_lineitem_tkt_eventname']['hide_alter_empty'] = 1;
    $handler->display->display_options['fields']['field_lineitem_tkt_eventname']['field_api_classes'] = 0;
    /* Field: Commerce Line item: Unit price */
    $handler->display->display_options['fields']['commerce_unit_price']['id'] = 'commerce_unit_price';
    $handler->display->display_options['fields']['commerce_unit_price']['table'] = 'field_data_commerce_unit_price';
    $handler->display->display_options['fields']['commerce_unit_price']['field'] = 'commerce_unit_price';
    $handler->display->display_options['fields']['commerce_unit_price']['relationship'] = 'commerce_line_items_line_item_id';
    $handler->display->display_options['fields']['commerce_unit_price']['label'] = 'Price';
    $handler->display->display_options['fields']['commerce_unit_price']['alter']['alter_text'] = 0;
    $handler->display->display_options['fields']['commerce_unit_price']['alter']['make_link'] = 0;
    $handler->display->display_options['fields']['commerce_unit_price']['alter']['absolute'] = 0;
    $handler->display->display_options['fields']['commerce_unit_price']['alter']['external'] = 0;
    $handler->display->display_options['fields']['commerce_unit_price']['alter']['nl2br'] = 0;
    $handler->display->display_options['fields']['commerce_unit_price']['alter']['word_boundary'] = 1;
    $handler->display->display_options['fields']['commerce_unit_price']['alter']['ellipsis'] = 1;
    $handler->display->display_options['fields']['commerce_unit_price']['alter']['strip_tags'] = 0;
    $handler->display->display_options['fields']['commerce_unit_price']['alter']['trim'] = 0;
    $handler->display->display_options['fields']['commerce_unit_price']['alter']['html'] = 0;
    $handler->display->display_options['fields']['commerce_unit_price']['element_class'] = 'price';
    $handler->display->display_options['fields']['commerce_unit_price']['element_label_colon'] = 1;
    $handler->display->display_options['fields']['commerce_unit_price']['element_default_classes'] = 1;
    $handler->display->display_options['fields']['commerce_unit_price']['hide_empty'] = 0;
    $handler->display->display_options['fields']['commerce_unit_price']['empty_zero'] = 0;
    $handler->display->display_options['fields']['commerce_unit_price']['click_sort_column'] = 'amount';
    $handler->display->display_options['fields']['commerce_unit_price']['type'] = 'commerce_price_formatted_amount';
    $handler->display->display_options['fields']['commerce_unit_price']['settings'] = array(
      'calculation' => FALSE,
    );
    $handler->display->display_options['fields']['commerce_unit_price']['field_api_classes'] = 0;
    /* Field: Commerce Line Item: Quantity */
    $handler->display->display_options['fields']['quantity']['id'] = 'quantity';
    $handler->display->display_options['fields']['quantity']['table'] = 'commerce_line_item';
    $handler->display->display_options['fields']['quantity']['field'] = 'quantity';
    $handler->display->display_options['fields']['quantity']['relationship'] = 'commerce_line_items_line_item_id';
    $handler->display->display_options['fields']['quantity']['alter']['alter_text'] = 0;
    $handler->display->display_options['fields']['quantity']['alter']['make_link'] = 0;
    $handler->display->display_options['fields']['quantity']['alter']['absolute'] = 0;
    $handler->display->display_options['fields']['quantity']['alter']['external'] = 0;
    $handler->display->display_options['fields']['quantity']['alter']['nl2br'] = 0;
    $handler->display->display_options['fields']['quantity']['alter']['word_boundary'] = 1;
    $handler->display->display_options['fields']['quantity']['alter']['ellipsis'] = 1;
    $handler->display->display_options['fields']['quantity']['alter']['strip_tags'] = 0;
    $handler->display->display_options['fields']['quantity']['alter']['trim'] = 0;
    $handler->display->display_options['fields']['quantity']['alter']['html'] = 0;
    $handler->display->display_options['fields']['quantity']['element_label_colon'] = 1;
    $handler->display->display_options['fields']['quantity']['element_default_classes'] = 1;
    $handler->display->display_options['fields']['quantity']['hide_empty'] = 0;
    $handler->display->display_options['fields']['quantity']['empty_zero'] = 0;
    $handler->display->display_options['fields']['quantity']['set_precision'] = 0;
    $handler->display->display_options['fields']['quantity']['precision'] = '0';
    $handler->display->display_options['fields']['quantity']['format_plural'] = 0;
    /* Field: Commerce Line item: Total */
    $handler->display->display_options['fields']['commerce_total']['id'] = 'commerce_total';
    $handler->display->display_options['fields']['commerce_total']['table'] = 'field_data_commerce_total';
    $handler->display->display_options['fields']['commerce_total']['field'] = 'commerce_total';
    $handler->display->display_options['fields']['commerce_total']['relationship'] = 'commerce_line_items_line_item_id';
    $handler->display->display_options['fields']['commerce_total']['alter']['alter_text'] = 0;
    $handler->display->display_options['fields']['commerce_total']['alter']['make_link'] = 0;
    $handler->display->display_options['fields']['commerce_total']['alter']['absolute'] = 0;
    $handler->display->display_options['fields']['commerce_total']['alter']['external'] = 0;
    $handler->display->display_options['fields']['commerce_total']['alter']['replace_spaces'] = 0;
    $handler->display->display_options['fields']['commerce_total']['alter']['trim_whitespace'] = 0;
    $handler->display->display_options['fields']['commerce_total']['alter']['nl2br'] = 0;
    $handler->display->display_options['fields']['commerce_total']['alter']['word_boundary'] = 1;
    $handler->display->display_options['fields']['commerce_total']['alter']['ellipsis'] = 1;
    $handler->display->display_options['fields']['commerce_total']['alter']['strip_tags'] = 0;
    $handler->display->display_options['fields']['commerce_total']['alter']['trim'] = 0;
    $handler->display->display_options['fields']['commerce_total']['alter']['html'] = 0;
    $handler->display->display_options['fields']['commerce_total']['element_class'] = 'price';
    $handler->display->display_options['fields']['commerce_total']['element_label_colon'] = 1;
    $handler->display->display_options['fields']['commerce_total']['element_default_classes'] = 1;
    $handler->display->display_options['fields']['commerce_total']['hide_empty'] = 0;
    $handler->display->display_options['fields']['commerce_total']['empty_zero'] = 0;
    $handler->display->display_options['fields']['commerce_total']['hide_alter_empty'] = 0;
    $handler->display->display_options['fields']['commerce_total']['click_sort_column'] = 'amount';
    $handler->display->display_options['fields']['commerce_total']['type'] = 'commerce_price_formatted_amount';
    $handler->display->display_options['fields']['commerce_total']['settings'] = array(
      'calculation' => FALSE,
    );
    $handler->display->display_options['fields']['commerce_total']['field_api_classes'] = 0;
    /* Sort criterion: Commerce Line Item: Line item ID */
    $handler->display->display_options['sorts']['line_item_id']['id'] = 'line_item_id';
    $handler->display->display_options['sorts']['line_item_id']['table'] = 'commerce_line_item';
    $handler->display->display_options['sorts']['line_item_id']['field'] = 'line_item_id';
    $handler->display->display_options['sorts']['line_item_id']['relationship'] = 'commerce_line_items_line_item_id';
    /* Contextual filter: Commerce Order: Order ID */
    $handler->display->display_options['arguments']['order_id']['id'] = 'order_id';
    $handler->display->display_options['arguments']['order_id']['table'] = 'commerce_order';
    $handler->display->display_options['arguments']['order_id']['field'] = 'order_id';
    $handler->display->display_options['arguments']['order_id']['default_action'] = 'not found';
    $handler->display->display_options['arguments']['order_id']['default_argument_type'] = 'fixed';
    $handler->display->display_options['arguments']['order_id']['summary']['number_of_records'] = '0';
    $handler->display->display_options['arguments']['order_id']['summary']['format'] = 'default_summary';
    $handler->display->display_options['arguments']['order_id']['summary_options']['items_per_page'] = '25';
    $handler->display->display_options['arguments']['order_id']['break_phrase'] = 0;
    $handler->display->display_options['arguments']['order_id']['not'] = 0;

    $views['commerce_cart_summary'] = $view;
  }
  $export['commerce_cart_summary'] = $view;

  if (isset($views['commerce_line_item_table'])) {
    $view = new view;
    $view->name = 'commerce_line_item_table';
    $view->description = 'Display a set of line items in a table.';
    $view->tag = 'commerce';
    $view->base_table = 'commerce_line_item';
    $view->human_name = 'Line items';
    $view->core = 0;
    $view->api_version = '3.0';
    $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

    /* Display: Defaults */
    $handler = $view->new_display('default', 'Defaults', 'default');
    $handler->display->display_options['access']['type'] = 'none';
    $handler->display->display_options['cache']['type'] = 'none';
    $handler->display->display_options['query']['type'] = 'views_query';
    $handler->display->display_options['query']['options']['query_comment'] = FALSE;
    $handler->display->display_options['exposed_form']['type'] = 'basic';
    $handler->display->display_options['pager']['type'] = 'none';
    $handler->display->display_options['style_plugin'] = 'table';
    $handler->display->display_options['style_options']['columns'] = array(
      'line_item_id' => 'line_item_id',
      'type' => 'type',
      'product_attributes' => 'product_attributes',
      'field_class_lineitem_detail' => 'field_class_lineitem_detail',
      'field_lineitem_tkt_eventname' => 'field_class_lineitem_detail',
      'line_item_label' => 'line_item_label',
      'commerce_unit_price' => 'commerce_unit_price',
      'quantity' => 'quantity',
      'commerce_total' => 'commerce_total',
    );
    $handler->display->display_options['style_options']['default'] = '-1';
    $handler->display->display_options['style_options']['info'] = array(
      'line_item_id' => array(
        'sortable' => 0,
        'default_sort_order' => 'asc',
        'align' => '',
        'separator' => '',
        'empty_column' => 0,
      ),
      'type' => array(
        'sortable' => 0,
        'default_sort_order' => 'asc',
        'align' => '',
        'separator' => '',
        'empty_column' => 0,
      ),
      'product_attributes' => array(
        'align' => '',
        'separator' => '',
        'empty_column' => 0,
      ),
      'field_class_lineitem_detail' => array(
        'sortable' => 0,
        'default_sort_order' => 'asc',
        'align' => '',
        'separator' => '',
        'empty_column' => 0,
      ),
      'field_lineitem_tkt_eventname' => array(
        'sortable' => 0,
        'default_sort_order' => 'asc',
        'align' => '',
        'separator' => '',
        'empty_column' => 0,
      ),
      'line_item_label' => array(
        'sortable' => 0,
        'default_sort_order' => 'asc',
        'align' => '',
        'separator' => '',
        'empty_column' => 0,
      ),
      'commerce_unit_price' => array(
        'sortable' => 0,
        'default_sort_order' => 'asc',
        'align' => '',
        'separator' => '',
        'empty_column' => 0,
      ),
      'quantity' => array(
        'sortable' => 0,
        'default_sort_order' => 'asc',
        'align' => '',
        'separator' => '',
        'empty_column' => 0,
      ),
      'commerce_total' => array(
        'sortable' => 0,
        'default_sort_order' => 'asc',
        'align' => 'views-align-right',
        'separator' => '',
        'empty_column' => 0,
      ),
    );
    $handler->display->display_options['style_options']['override'] = 1;
    $handler->display->display_options['style_options']['sticky'] = 0;
    $handler->display->display_options['style_options']['empty_table'] = 0;
    /* No results behavior: Global: Text area */
    $handler->display->display_options['empty']['area']['id'] = 'area';
    $handler->display->display_options['empty']['area']['table'] = 'views';
    $handler->display->display_options['empty']['area']['field'] = 'area';
    $handler->display->display_options['empty']['area']['label'] = 'Empty line item text.';
    $handler->display->display_options['empty']['area']['empty'] = FALSE;
    $handler->display->display_options['empty']['area']['content'] = 'No line items found.';
    $handler->display->display_options['empty']['area']['format'] = 'plain_text';
    /* Field: Commerce Line Item: Line item ID */
    $handler->display->display_options['fields']['line_item_id']['id'] = 'line_item_id';
    $handler->display->display_options['fields']['line_item_id']['table'] = 'commerce_line_item';
    $handler->display->display_options['fields']['line_item_id']['field'] = 'line_item_id';
    $handler->display->display_options['fields']['line_item_id']['label'] = 'ID';
    $handler->display->display_options['fields']['line_item_id']['exclude'] = TRUE;
    $handler->display->display_options['fields']['line_item_id']['alter']['alter_text'] = 0;
    $handler->display->display_options['fields']['line_item_id']['alter']['make_link'] = 0;
    $handler->display->display_options['fields']['line_item_id']['alter']['absolute'] = 0;
    $handler->display->display_options['fields']['line_item_id']['alter']['external'] = 0;
    $handler->display->display_options['fields']['line_item_id']['alter']['nl2br'] = 0;
    $handler->display->display_options['fields']['line_item_id']['alter']['word_boundary'] = 1;
    $handler->display->display_options['fields']['line_item_id']['alter']['ellipsis'] = 1;
    $handler->display->display_options['fields']['line_item_id']['alter']['strip_tags'] = 0;
    $handler->display->display_options['fields']['line_item_id']['alter']['trim'] = 0;
    $handler->display->display_options['fields']['line_item_id']['alter']['html'] = 0;
    $handler->display->display_options['fields']['line_item_id']['element_label_colon'] = 1;
    $handler->display->display_options['fields']['line_item_id']['element_default_classes'] = 1;
    $handler->display->display_options['fields']['line_item_id']['hide_empty'] = 0;
    $handler->display->display_options['fields']['line_item_id']['empty_zero'] = 0;
    /* Field: Commerce Line Item: Type */
    $handler->display->display_options['fields']['type']['id'] = 'type';
    $handler->display->display_options['fields']['type']['table'] = 'commerce_line_item';
    $handler->display->display_options['fields']['type']['field'] = 'type';
    $handler->display->display_options['fields']['type']['exclude'] = TRUE;
    $handler->display->display_options['fields']['type']['alter']['alter_text'] = 0;
    $handler->display->display_options['fields']['type']['alter']['make_link'] = 0;
    $handler->display->display_options['fields']['type']['alter']['absolute'] = 0;
    $handler->display->display_options['fields']['type']['alter']['external'] = 0;
    $handler->display->display_options['fields']['type']['alter']['nl2br'] = 0;
    $handler->display->display_options['fields']['type']['alter']['word_boundary'] = 1;
    $handler->display->display_options['fields']['type']['alter']['ellipsis'] = 1;
    $handler->display->display_options['fields']['type']['alter']['strip_tags'] = 0;
    $handler->display->display_options['fields']['type']['alter']['trim'] = 0;
    $handler->display->display_options['fields']['type']['alter']['html'] = 0;
    $handler->display->display_options['fields']['type']['element_label_colon'] = 1;
    $handler->display->display_options['fields']['type']['element_default_classes'] = 1;
    $handler->display->display_options['fields']['type']['hide_empty'] = 0;
    $handler->display->display_options['fields']['type']['empty_zero'] = 0;
    /* Field: Commerce Line Item: Product Attributes */
    $handler->display->display_options['fields']['product_attributes']['id'] = 'product_attributes';
    $handler->display->display_options['fields']['product_attributes']['table'] = 'commerce_line_item';
    $handler->display->display_options['fields']['product_attributes']['field'] = 'product_attributes';
    $handler->display->display_options['fields']['product_attributes']['alter']['alter_text'] = 0;
    $handler->display->display_options['fields']['product_attributes']['alter']['make_link'] = 0;
    $handler->display->display_options['fields']['product_attributes']['alter']['absolute'] = 0;
    $handler->display->display_options['fields']['product_attributes']['alter']['external'] = 0;
    $handler->display->display_options['fields']['product_attributes']['alter']['replace_spaces'] = 0;
    $handler->display->display_options['fields']['product_attributes']['alter']['trim_whitespace'] = 0;
    $handler->display->display_options['fields']['product_attributes']['alter']['nl2br'] = 0;
    $handler->display->display_options['fields']['product_attributes']['alter']['word_boundary'] = 1;
    $handler->display->display_options['fields']['product_attributes']['alter']['ellipsis'] = 1;
    $handler->display->display_options['fields']['product_attributes']['alter']['strip_tags'] = 0;
    $handler->display->display_options['fields']['product_attributes']['alter']['trim'] = 0;
    $handler->display->display_options['fields']['product_attributes']['alter']['html'] = 0;
    $handler->display->display_options['fields']['product_attributes']['element_label_colon'] = 1;
    $handler->display->display_options['fields']['product_attributes']['element_default_classes'] = 1;
    $handler->display->display_options['fields']['product_attributes']['hide_empty'] = 0;
    $handler->display->display_options['fields']['product_attributes']['empty_zero'] = 0;
    $handler->display->display_options['fields']['product_attributes']['hide_alter_empty'] = 1;
    $handler->display->display_options['fields']['product_attributes']['show_link'] = 1;
    $handler->display->display_options['fields']['product_attributes']['link_with_line_item'] = 1;
    /* Field: Commerce Line item: Additional Details */
    $handler->display->display_options['fields']['field_class_lineitem_detail']['id'] = 'field_class_lineitem_detail';
    $handler->display->display_options['fields']['field_class_lineitem_detail']['table'] = 'field_data_field_class_lineitem_detail';
    $handler->display->display_options['fields']['field_class_lineitem_detail']['field'] = 'field_class_lineitem_detail';
    $handler->display->display_options['fields']['field_class_lineitem_detail']['alter']['alter_text'] = 0;
    $handler->display->display_options['fields']['field_class_lineitem_detail']['alter']['make_link'] = 0;
    $handler->display->display_options['fields']['field_class_lineitem_detail']['alter']['absolute'] = 0;
    $handler->display->display_options['fields']['field_class_lineitem_detail']['alter']['external'] = 0;
    $handler->display->display_options['fields']['field_class_lineitem_detail']['alter']['replace_spaces'] = 0;
    $handler->display->display_options['fields']['field_class_lineitem_detail']['alter']['trim_whitespace'] = 0;
    $handler->display->display_options['fields']['field_class_lineitem_detail']['alter']['nl2br'] = 0;
    $handler->display->display_options['fields']['field_class_lineitem_detail']['alter']['word_boundary'] = 1;
    $handler->display->display_options['fields']['field_class_lineitem_detail']['alter']['ellipsis'] = 1;
    $handler->display->display_options['fields']['field_class_lineitem_detail']['alter']['strip_tags'] = 0;
    $handler->display->display_options['fields']['field_class_lineitem_detail']['alter']['trim'] = 0;
    $handler->display->display_options['fields']['field_class_lineitem_detail']['alter']['html'] = 0;
    $handler->display->display_options['fields']['field_class_lineitem_detail']['element_label_colon'] = 1;
    $handler->display->display_options['fields']['field_class_lineitem_detail']['element_default_classes'] = 1;
    $handler->display->display_options['fields']['field_class_lineitem_detail']['hide_empty'] = 0;
    $handler->display->display_options['fields']['field_class_lineitem_detail']['empty_zero'] = 0;
    $handler->display->display_options['fields']['field_class_lineitem_detail']['hide_alter_empty'] = 1;
    $handler->display->display_options['fields']['field_class_lineitem_detail']['field_api_classes'] = 0;
    /* Field: Commerce Line item: Event Name */
    $handler->display->display_options['fields']['field_lineitem_tkt_eventname']['id'] = 'field_lineitem_tkt_eventname';
    $handler->display->display_options['fields']['field_lineitem_tkt_eventname']['table'] = 'field_data_field_lineitem_tkt_eventname';
    $handler->display->display_options['fields']['field_lineitem_tkt_eventname']['field'] = 'field_lineitem_tkt_eventname';
    $handler->display->display_options['fields']['field_lineitem_tkt_eventname']['alter']['alter_text'] = 0;
    $handler->display->display_options['fields']['field_lineitem_tkt_eventname']['alter']['make_link'] = 0;
    $handler->display->display_options['fields']['field_lineitem_tkt_eventname']['alter']['absolute'] = 0;
    $handler->display->display_options['fields']['field_lineitem_tkt_eventname']['alter']['external'] = 0;
    $handler->display->display_options['fields']['field_lineitem_tkt_eventname']['alter']['replace_spaces'] = 0;
    $handler->display->display_options['fields']['field_lineitem_tkt_eventname']['alter']['trim_whitespace'] = 0;
    $handler->display->display_options['fields']['field_lineitem_tkt_eventname']['alter']['nl2br'] = 0;
    $handler->display->display_options['fields']['field_lineitem_tkt_eventname']['alter']['word_boundary'] = 1;
    $handler->display->display_options['fields']['field_lineitem_tkt_eventname']['alter']['ellipsis'] = 1;
    $handler->display->display_options['fields']['field_lineitem_tkt_eventname']['alter']['strip_tags'] = 0;
    $handler->display->display_options['fields']['field_lineitem_tkt_eventname']['alter']['trim'] = 0;
    $handler->display->display_options['fields']['field_lineitem_tkt_eventname']['alter']['html'] = 0;
    $handler->display->display_options['fields']['field_lineitem_tkt_eventname']['element_label_colon'] = 1;
    $handler->display->display_options['fields']['field_lineitem_tkt_eventname']['element_default_classes'] = 1;
    $handler->display->display_options['fields']['field_lineitem_tkt_eventname']['hide_empty'] = 0;
    $handler->display->display_options['fields']['field_lineitem_tkt_eventname']['empty_zero'] = 0;
    $handler->display->display_options['fields']['field_lineitem_tkt_eventname']['hide_alter_empty'] = 1;
    $handler->display->display_options['fields']['field_lineitem_tkt_eventname']['field_api_classes'] = 0;
    /* Field: Commerce Line item: Unit price */
    $handler->display->display_options['fields']['commerce_unit_price']['id'] = 'commerce_unit_price';
    $handler->display->display_options['fields']['commerce_unit_price']['table'] = 'field_data_commerce_unit_price';
    $handler->display->display_options['fields']['commerce_unit_price']['field'] = 'commerce_unit_price';
    $handler->display->display_options['fields']['commerce_unit_price']['alter']['alter_text'] = 0;
    $handler->display->display_options['fields']['commerce_unit_price']['alter']['make_link'] = 0;
    $handler->display->display_options['fields']['commerce_unit_price']['alter']['absolute'] = 0;
    $handler->display->display_options['fields']['commerce_unit_price']['alter']['external'] = 0;
    $handler->display->display_options['fields']['commerce_unit_price']['alter']['nl2br'] = 0;
    $handler->display->display_options['fields']['commerce_unit_price']['alter']['word_boundary'] = 1;
    $handler->display->display_options['fields']['commerce_unit_price']['alter']['ellipsis'] = 1;
    $handler->display->display_options['fields']['commerce_unit_price']['alter']['strip_tags'] = 0;
    $handler->display->display_options['fields']['commerce_unit_price']['alter']['trim'] = 0;
    $handler->display->display_options['fields']['commerce_unit_price']['alter']['html'] = 0;
    $handler->display->display_options['fields']['commerce_unit_price']['element_label_colon'] = 1;
    $handler->display->display_options['fields']['commerce_unit_price']['element_default_classes'] = 1;
    $handler->display->display_options['fields']['commerce_unit_price']['hide_empty'] = 0;
    $handler->display->display_options['fields']['commerce_unit_price']['empty_zero'] = 0;
    $handler->display->display_options['fields']['commerce_unit_price']['click_sort_column'] = 'amount';
    $handler->display->display_options['fields']['commerce_unit_price']['type'] = 'commerce_price_formatted_amount';
    $handler->display->display_options['fields']['commerce_unit_price']['field_api_classes'] = 0;
    /* Field: Commerce Line Item: Quantity */
    $handler->display->display_options['fields']['quantity']['id'] = 'quantity';
    $handler->display->display_options['fields']['quantity']['table'] = 'commerce_line_item';
    $handler->display->display_options['fields']['quantity']['field'] = 'quantity';
    $handler->display->display_options['fields']['quantity']['alter']['alter_text'] = 0;
    $handler->display->display_options['fields']['quantity']['alter']['make_link'] = 0;
    $handler->display->display_options['fields']['quantity']['alter']['absolute'] = 0;
    $handler->display->display_options['fields']['quantity']['alter']['external'] = 0;
    $handler->display->display_options['fields']['quantity']['alter']['nl2br'] = 0;
    $handler->display->display_options['fields']['quantity']['alter']['word_boundary'] = 1;
    $handler->display->display_options['fields']['quantity']['alter']['ellipsis'] = 1;
    $handler->display->display_options['fields']['quantity']['alter']['strip_tags'] = 0;
    $handler->display->display_options['fields']['quantity']['alter']['trim'] = 0;
    $handler->display->display_options['fields']['quantity']['alter']['html'] = 0;
    $handler->display->display_options['fields']['quantity']['element_label_colon'] = 1;
    $handler->display->display_options['fields']['quantity']['element_default_classes'] = 1;
    $handler->display->display_options['fields']['quantity']['hide_empty'] = 0;
    $handler->display->display_options['fields']['quantity']['empty_zero'] = 0;
    $handler->display->display_options['fields']['quantity']['set_precision'] = 0;
    $handler->display->display_options['fields']['quantity']['precision'] = '0';
    $handler->display->display_options['fields']['quantity']['format_plural'] = 0;
    /* Field: Commerce Line item: Total */
    $handler->display->display_options['fields']['commerce_total']['id'] = 'commerce_total';
    $handler->display->display_options['fields']['commerce_total']['table'] = 'field_data_commerce_total';
    $handler->display->display_options['fields']['commerce_total']['field'] = 'commerce_total';
    $handler->display->display_options['fields']['commerce_total']['alter']['alter_text'] = 0;
    $handler->display->display_options['fields']['commerce_total']['alter']['make_link'] = 0;
    $handler->display->display_options['fields']['commerce_total']['alter']['absolute'] = 0;
    $handler->display->display_options['fields']['commerce_total']['alter']['external'] = 0;
    $handler->display->display_options['fields']['commerce_total']['alter']['nl2br'] = 0;
    $handler->display->display_options['fields']['commerce_total']['alter']['word_boundary'] = 1;
    $handler->display->display_options['fields']['commerce_total']['alter']['ellipsis'] = 1;
    $handler->display->display_options['fields']['commerce_total']['alter']['strip_tags'] = 0;
    $handler->display->display_options['fields']['commerce_total']['alter']['trim'] = 0;
    $handler->display->display_options['fields']['commerce_total']['alter']['html'] = 0;
    $handler->display->display_options['fields']['commerce_total']['element_label_colon'] = 1;
    $handler->display->display_options['fields']['commerce_total']['element_default_classes'] = 1;
    $handler->display->display_options['fields']['commerce_total']['hide_empty'] = 0;
    $handler->display->display_options['fields']['commerce_total']['empty_zero'] = 0;
    $handler->display->display_options['fields']['commerce_total']['click_sort_column'] = 'amount';
    $handler->display->display_options['fields']['commerce_total']['type'] = 'commerce_price_formatted_amount';
    $handler->display->display_options['fields']['commerce_total']['field_api_classes'] = 0;
    /* Sort criterion: Commerce Line Item: Line item ID */
    $handler->display->display_options['sorts']['line_item_id']['id'] = 'line_item_id';
    $handler->display->display_options['sorts']['line_item_id']['table'] = 'commerce_line_item';
    $handler->display->display_options['sorts']['line_item_id']['field'] = 'line_item_id';
    /* Contextual filter: Commerce Line Item: Line item ID */
    $handler->display->display_options['arguments']['line_item_id']['id'] = 'line_item_id';
    $handler->display->display_options['arguments']['line_item_id']['table'] = 'commerce_line_item';
    $handler->display->display_options['arguments']['line_item_id']['field'] = 'line_item_id';
    $handler->display->display_options['arguments']['line_item_id']['default_action'] = 'empty';
    $handler->display->display_options['arguments']['line_item_id']['default_argument_type'] = 'fixed';
    $handler->display->display_options['arguments']['line_item_id']['summary']['number_of_records'] = '0';
    $handler->display->display_options['arguments']['line_item_id']['summary']['format'] = 'default_summary';
    $handler->display->display_options['arguments']['line_item_id']['summary_options']['items_per_page'] = '25';
    $handler->display->display_options['arguments']['line_item_id']['break_phrase'] = 1;
    $handler->display->display_options['arguments']['line_item_id']['not'] = 0;

    $views['commerce_line_item_table'] = $view;
  }
  $export['commerce_line_item_table'] = $view;

  //return $export;
}