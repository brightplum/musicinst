<?php
/**
 * @file
 * Commerce Authorize.Net eCheck Payment Methods.
 */

/**
 * Payment method callback: settings form.
 */
function commerce_authnet_echeck_settings_form($settings = NULL) {
  $form = array();

  // Merge default settings into the stored settings array.
  $settings = (array) $settings + array(
    'login' => '',
    'tran_key' => '',
    'txn_mode' => AUTHNET_TXN_MODE_LIVE_TEST,
    'email_customer' => FALSE,
    'log' => array('request' => '0', 'response' => '0'),
  );

  $form['login'] = array(
    '#type' => 'textfield',
    '#title' => t('API Login ID'),
    '#description' => t('Where this can be found.'),
    '#default_value' => $settings['login'],
    '#required' => TRUE,
  );

  $form['tran_key'] = array(
    '#type' => 'textfield',
    '#title' => t('Transaction Key'),
    '#description' => t('Where this can be found.'),
    '#default_value' => $settings['tran_key'],
    '#required' => TRUE,
  );

  $form['txn_mode'] = array(
    '#type' => 'radios',
    '#title' => t('Transaction mode'),
    '#description' => t('Adjust to live transactions when you are ready to start processing real payments.') . '<br />' . t('Only specify a developer test account if you login to your account through https://test.authorize.net.'),
    '#options' => array(
      AUTHNET_TXN_MODE_LIVE => t('Live transactions in a live account'),
      AUTHNET_TXN_MODE_LIVE_TEST => t('Test transactions in a live account'),
      AUTHNET_TXN_MODE_DEVELOPER => t('Developer test account transactions'),
    ),
    '#default_value' => $settings['txn_mode'],
  );

  $form['email_customer'] = array(
    '#type' => 'checkbox',
    '#title' => t('Tell Authorize.net to e-mail the customer a receipt based on your account settings.'),
    '#default_value' => $settings['email_customer'],
  );

  $form['log'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Log the following messages for debugging'),
    '#options' => array(
      'request' => t('API request messages'),
      'response' => t('API response messages'),
    ),
    '#default_value' => $settings['log'],
  );

  return $form;
}

/**
 * Payment method callback: checkout form.
 */
function commerce_authnet_echeck_submit_form($payment_method, $pane_values, $checkout_pane, $order) {
  module_load_include('inc', 'commerce_payment', 'includes/commerce_payment.echeck');

  $fields = drupal_map_assoc(array('bank_name', 'acct_name'));
  $fields['type'] = drupal_map_assoc(array('checking', 'business_checking', 'savings'));

  $form = commerce_payment_echeck_form($fields);
  $form['echeck']['bank_name']['#maxlength'] = 50;
  $form['echeck']['acct_name']['#maxlength'] = 50;

  return $form;
}

/**
 * Payment method callback: checkout form validation.
 */
function commerce_authnet_echeck_submit_form_validate($payment_method, $pane_form, $pane_values, $order, $form_parents = array()) {
  module_load_include('inc', 'commerce_payment', 'includes/commerce_payment.echeck');

  // Validate the credit card fields.
  $settings = array(
    'form_parents' => array_merge($form_parents, array('echeck')),
  );

  if (!commerce_payment_echeck_validate($pane_values['echeck'], $settings)) {
    return FALSE;
  }
}

/**
 * Payment method callback: checkout form submission.
 */
function commerce_authnet_echeck_submit_form_submit($payment_method, $pane_form, $pane_values, $order, $charge) {
  // Build a name-value pair array for this transaction.
  $nvp = array(
    'x_method' => 'ECHECK',
    'x_bank_aba_code' => $pane_values['echeck']['aba_code'],
    'x_bank_acct_num' => $pane_values['echeck']['acct_num'],
    'x_bank_acct_type' => str_replace('', '_', strtoupper($pane_values['echeck']['type'])),
    'x_bank_name' => substr($pane_values['echeck']['bank_name'], 0, 50),
    'x_bank_acct_name' => substr($pane_values['echeck']['acct_name'], 0, 50),
    'x_echeck_type' => 'WEB',
    'x_recurring_billing' => 'FALSE',
    'x_amount' => commerce_currency_amount_to_decimal($charge['amount'], $charge['currency_code']),
  );

  // Add additional transaction invormation to the request array.
  $nvp += commerce_authnet_aim_request_order_details($order);

  // Submit the request to Authorize.Net.
  $response = commerce_authnet_aim_request($payment_method, $nvp);

  // Prepare a transaction object to log the API response.
  $transaction = commerce_payment_transaction_new($payment_method['method_id'], $order->order_id);
  $transaction->instance_id = $payment_method['instance_id'];
  $transaction->remote_id = $response[6];
  $transaction->amount = $charge['amount'];
  $transaction->currency_code = $charge['currency_code'];
  $transaction->payload[REQUEST_TIME] = $response;

  // Set transaction status from response code.
  if ($response[0] == '1') {
    $transaction->status = COMMERCE_PAYMENT_STATUS_SUCCESS;
    $reason_text = t('APPROVED');
  }
  elseif ($response[0] == '4') {
    $transaction->status = COMMERCE_PAYMENT_STATUS_PENDING;
    $reason_text = t('PENDING');
  }
  else {
    $transaction->status = COMMERCE_PAYMENT_STATUS_FAILURE;
    $reason_text = t('REJECTED');
  }

  // Store the type of transaction in the remote status.
  $transaction->remote_status = $response[11];

  // Build a meaningful response message.
  $message = array(
    '<b>ECHECK</b>',
    '<b>' . $reason_text . ':</b> ' . check_plain($response[3]),
  );

  // Add the CVV response if enabled.
  if (!empty($respnsee[6])) {
    $message[] = t('Transaction ID: @txn_id', array('@txn_id' => $response[6]));
  }

  $transaction->message = implode('<br />', $message);

  // Save the transaction information.
  commerce_payment_transaction_save($transaction);

  // If the payment failed, display an error and rebuild the form.
  if ($response[0] == '4') {
    drupal_set_message(t('We received the following notice processing your eCheck. Please contact support.'), 'warning');
    drupal_set_message(check_plain($response[3]), 'warning');
  }
  elseif ($response[0] != '1') {
    drupal_set_message(t('We received the following error processing your eCheck. Please enter your information again or try a different account.'), 'error');
    drupal_set_message(check_plain($response[3]), 'error');
    return FALSE;
  }
}
