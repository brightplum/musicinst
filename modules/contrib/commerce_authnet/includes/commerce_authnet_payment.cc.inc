<?php
/**
 * @file
 * Commerce Authorize.Net Credit Card Payment Methods.
 */

/**
 * Payment method callback: settings form.
 */
function commerce_authnet_aim_settings_form($settings = NULL) {
  module_load_include('inc', 'commerce_payment', 'includes/commerce_payment.credit_card');

  // Merge default settings into the stored settings array.
  $settings = (array) $settings + commerce_authnet_aim_default_settings();

  $form = array();

  $form['login'] = array(
    '#type' => 'textfield',
    '#title' => t('API Login ID'),
    '#description' => t('Your API Login ID is different from the username you use to login to your Authorize.Net account. Once you login, browse to your Account tab and click the <em>API Login ID and Transaction Key</em> link to find your API Login ID. If you are using a new Authorize.Net account, you may still need to generate an ID.'),
    '#default_value' => $settings['login'],
    '#required' => TRUE,
  );
  $form['tran_key'] = array(
    '#type' => 'textfield',
    '#title' => t('Transaction Key'),
    '#description' => t('Your Transaction Key can be found on the same screen as your API Login ID. However, it will not be readily displayed. You must answer your security question and submit a form to see your Transaction Key.'),
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
  $form['txn_type'] = array(
    '#type' => 'radios',
    '#title' => t('Default credit card transaction type'),
    '#description' => t('The default will be used to process transactions during checkout.'),
    '#options' => array(
      COMMERCE_CREDIT_AUTH_CAPTURE => t('Authorization and capture'),
      COMMERCE_CREDIT_AUTH_ONLY => t('Authorization only (requires manual or automated capture after checkout)'),
    ),
    '#default_value' => $settings['txn_type'],
  );

  $form['card_types'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Limit accepted credit cards to the following types'),
    '#description' => t('If you want to limit acceptable card types, you should only select those supported by your merchant account.') . '<br />' . t('If none are checked, any credit card type will be accepted.'),
    '#options' => commerce_payment_credit_card_types(),
    '#default_value' => $settings['card_types'],
  );

  // CIM support in conjunction with AIM requires the Card on File module.
  if (module_exists('commerce_cardonfile')) {
    $form['cim_cardonfile'] = array(
      '#type' => 'checkbox',
      '#title' => t('Enable Card on File functionality with this payment method using Authorize.Net CIM.'),
      '#description' => t('This requires an Authorize.Net account upgraded to include support for CIM (Customer Information Manager).'),
      '#default_value' => $settings['cim_cardonfile'],
    );
  }

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
function commerce_authnet_aim_submit_form($payment_method, $pane_values, $checkout_pane, $order) {
  module_load_include('inc', 'commerce_payment', 'includes/commerce_payment.credit_card');

  // Prepare the fields to include on the credit card form.
  $fields = array(
    'code' => '',
  );

  // Add the credit card types array if necessary.
  $card_types = array_diff(array_values($payment_method['settings']['card_types']), array(0));

  if (!empty($card_types)) {
    $fields['type'] = $card_types;
  }

  return commerce_payment_credit_card_form($fields);
}

/**
 * Payment method callback: checkout form validation.
 */
function commerce_authnet_aim_submit_form_validate($payment_method, $pane_form, $pane_values, $order, $form_parents = array()) {
  // If the customer specified a card on file, skip the normal validation.
  if (module_exists('commerce_cardonfile') && !empty($payment_method['settings']['cim_cardonfile']) &&
    !empty($pane_values['cardonfile']) && $pane_values['cardonfile'] !== 'new') {
    return;
  }

  module_load_include('inc', 'commerce_payment', 'includes/commerce_payment.credit_card');

  // Validate the credit card fields.
  $settings = array(
    'form_parents' => array_merge($form_parents, array('credit_card')),
  );

  if (!commerce_payment_credit_card_validate($pane_values['credit_card'], $settings)) {
    return FALSE;
  }
}

/**
 * Payment method callback: checkout form submission.
 */
function commerce_authnet_aim_submit_form_submit($payment_method, $pane_form, $pane_values, $order, $charge) {
  // If the customer specified payment using a card on file, attempt that now
  // and simply return the result.
  if (module_exists('commerce_cardonfile') && $payment_method['settings']['cim_cardonfile'] &&
    !empty($pane_values['cardonfile']) && $pane_values['cardonfile'] !== 'new') {
    return commerce_authnet_cim_submit_form_submit($payment_method, $pane_form, $pane_values, $order, $charge);
  }

  // Determine the credit card type if possible for use in later code.
  if (!empty($pane_values['credit_card']['number'])) {
    module_load_include('inc', 'commerce_payment', 'includes/commerce_payment.credit_card');
    $card_type = commerce_payment_validate_credit_card_type($pane_values['credit_card']['number'], array_keys(commerce_payment_credit_card_types()));
  }

  // If the charge amount is 0...
  if ($charge['amount'] == 0) {
    // Prevent the transaction except under limited circumstances.
    $prevent_transaction = TRUE;

    // Allow 0 amount authorizations on Visa cards.
    if ($payment_method['settings']['txn_type'] == COMMERCE_CREDIT_AUTH_ONLY && $card_type == 'visa') {
      $prevent_transaction = FALSE;
    }

    // If the transaction should still be prevented...
    if ($prevent_transaction) {
      // Create a transaction to log the skipped transaction and display a
      // helpful message to the customer.
      $transaction = commerce_payment_transaction_new('authnet_aim', $order->order_id);
      $transaction->amount = $charge['amount'];
      $transaction->currency_code = $charge['currency_code'];
      $transaction->status = COMMERCE_PAYMENT_STATUS_FAILURE;
      $transaction->message = t('Invalid @amount transaction not attempted.', array('@amount' => commerce_currency_format($charge['amount'], $charge['currency_code'])));
      commerce_payment_transaction_save($transaction);

      drupal_set_message('We encountered an error processing your transaction. Please contact us to resolve the issue.', 'error');
      return FALSE;
    }
  }

  // Get the default transaction type from the payment method settings.
  $txn_type = $payment_method['settings']['txn_type'];

  // If txn_type has been specified in the pane values array, such as through
  // the special select element we alter onto the payment terminal form, use
  // that instead.
  if (!empty($pane_values['txn_type'])) {
    $txn_type = $pane_values['txn_type'];
  }

  // Build a name-value pair array for this transaction.
  $nvp = array(
    'x_type' => commerce_authnet_txn_type($txn_type),
    'x_method' => 'CC',
    'x_amount' => commerce_currency_amount_to_decimal($charge['amount'], $charge['currency_code']),
    'x_card_num' => $pane_values['credit_card']['number'],
    'x_exp_date' => $pane_values['credit_card']['exp_month'] . $pane_values['credit_card']['exp_year'],
  );

  if (isset($pane_values['credit_card']['code'])) {
    $nvp['x_card_code'] = $pane_values['credit_card']['code'];
  }

  // Add additional transaction invormation to the request array.
  $nvp += commerce_authnet_aim_request_order_details($order);

  // Submit the request to Authorize.Net.
  $response = commerce_authnet_aim_request($payment_method, $nvp);

  // Prepare a transaction object to log the API response.
  $transaction = commerce_payment_transaction_new('authnet_aim', $order->order_id);
  $transaction->instance_id = $payment_method['instance_id'];
  $transaction->remote_id = $response[6];
  $transaction->amount = $charge['amount'];
  $transaction->currency_code = $charge['currency_code'];
  $transaction->payload[REQUEST_TIME] = $response;

  // If we didn't get an approval response code...
  if ($response[0] != '1') {
    // Create a failed transaction with the error message.
    $transaction->status = COMMERCE_PAYMENT_STATUS_FAILURE;
  }
  else {
    // Set the transaction status based on the type of transaction this was.
    switch ($txn_type) {
      case COMMERCE_CREDIT_AUTH_ONLY:
        $transaction->status = COMMERCE_PAYMENT_STATUS_PENDING;
        break;

      case COMMERCE_CREDIT_AUTH_CAPTURE:
        $transaction->status = COMMERCE_PAYMENT_STATUS_SUCCESS;
        break;

      case COMMERCE_CREDIT_CAPTURE_ONLY:
        $transaction->status = COMMERCE_PAYMENT_STATUS_SUCCESS;
        break;
    }
  }

  // Store the type of transaction in the remote status.
  $transaction->remote_status = $response[11];

  // Build a meaningful response message.
  $message = array(
    '<b>' . commerce_authnet_reverse_txn_type($response[11]) . '</b>',
    '<b>' . ($response[0] != '1' ? t('REJECTED') : t('ACCEPTED')) . ':</b> ' . check_plain($response[3]),
    t('AVS response: @avs', array('@avs' => commerce_authnet_avs_response($response[5]))),
  );

  // Add the CVV response if enabled.
  if (isset($nvp['x_card_code'])) {
    $message[] = t('CVV match: @cvv', array('@cvv' => commerce_authnet_cvv_response($response[38])));
  }

  $transaction->message = implode('<br />', $message);

  // Save the transaction information.
  commerce_payment_transaction_save($transaction);

  // If the payment failed, display an error and rebuild the form.
  if ($response[0] != '1') {
    drupal_set_message(t('We received the following error processing your card. Please enter your information again or try a different card.'), 'error');
    drupal_set_message(check_plain($response[3]), 'error');
    return FALSE;
  }

  // If Card on File storage is enabled via CIM and the form says to store
  // data...
  if (module_exists('commerce_cardonfile') && !empty($payment_method['settings']['cim_cardonfile']) &&
    !empty($pane_values['credit_card']['cardonfile_store']) && $pane_values['credit_card']['cardonfile_store']) {
    // Build a payment details array for the credit card.
    $payment_details = array(
      'cardNumber' => $pane_values['credit_card']['number'],
      'expirationDate' => $pane_values['credit_card']['exp_year'] . '-' . $pane_values['credit_card']['exp_month'],
    );

    if (isset($pane_values['credit_card']['code'])) {
      $payment_details['cardCode'] = $pane_values['credit_card']['code'];
    }

    // First look to see if we already have cards on file for the user.
    $stored_cards = commerce_cardonfile_data_load_multiple($order->uid, $payment_method['instance_id']);
    $add_to_profile = NULL;

    // If we didn't find any, attempt to make a new Customer Profile now.
    if (empty($stored_cards)) {
      // Submit a CIM request to create the Customer Profile.
      if ($response = commerce_authnet_cim_create_customer_profile_request($payment_method, $order, $payment_details)) {
        // If the Customer Profile creation was a success, store the new card on
        // file data locally.
        if ((string) $response->messages->resultCode == 'Ok') {
          // Build a remote ID that includes the Customer Profile ID and the
          // Payment Profile ID.
          $remote_id = (string) $response->customerProfileId . '|' . (string) $response->customerPaymentProfileIdList->numericString;

          $card_data = array(
            'uid' => $order->uid,
            'payment_method' => $payment_method['method_id'],
            'instance_id' => $payment_method['instance_id'],
            'remote_id' => $remote_id,
            'card_type' => !empty($card_type) ? $card_type : 'card',
            'card_name' => !empty($billing_address['name_line']) ? $billing_address['name_line'] : '',
            'card_number' => substr($pane_values['credit_card']['number'], -4),
            'card_exp_month' => $pane_values['credit_card']['exp_month'],
            'card_exp_year' => $pane_values['credit_card']['exp_year'],
            'status' => 1,
          );

          // Save and log the creation of the new card on file.
          commerce_cardonfile_data_save($card_data);
          watchdog('commerce_authnet', 'CIM Customer Profile @profile_id created and saved to user @uid.', array('@profile_id' => (string) $response->customerProfileId, '@uid' => $order->uid));
        }
        elseif ((string) $response->messages->message->code == 'E00039') {
          // But if a Customer Profile already existed for this user, attempt
          // instead to add this card as a new Payment Profile to it.
          $result = array_filter(explode(' ', (string) $response->messages->message->text), 'is_numeric');
          $add_to_profile = reset($result);
        }
      }
    }
    else {
      // Extract the user's Customer Profile ID from the first card's remote ID.
      $card_data = reset($stored_cards);
      list($cim_customer_profile_id, $cim_payment_profile_id) = explode('|', $card_data['remote_id']);

      // Attempt to add the card as a new payment profile to this Customer
      // Profile.
      $add_to_profile = $cim_customer_profile_id;
    }

    // Attempt to add the card to an existing Customer Profile if specified.
    if (!empty($add_to_profile)) {
      $response = commerce_authnet_cim_create_customer_payment_profile_request($payment_method, $add_to_profile, $order, $payment_details);

      // If the Payment Profile creation was a success, store the new card on
      // file data locally.
      if ((string) $response->messages->resultCode == 'Ok') {
        // Build a remote ID that includes the Customer Profile ID and the new
        // Payment Profile ID.
        $remote_id = $add_to_profile . '|' . (string) $response->customerPaymentProfileId;

        $card_data = array(
          'uid' => $order->uid,
          'payment_method' => $payment_method['method_id'],
          'instance_id' => $payment_method['instance_id'],
          'remote_id' => $remote_id,
          'card_type' => !empty($card_type) ? $card_type : 'card',
          'card_name' => !empty($billing_address['name_line']) ? $billing_address['name_line'] : '',
          'card_number' => substr($pane_values['credit_card']['number'], -4),
          'card_exp_month' => $pane_values['credit_card']['exp_month'],
          'card_exp_year' => $pane_values['credit_card']['exp_year'],
          'status' => 1,
        );

        // Save and log the creation of the new card on file.
        commerce_cardonfile_data_save($card_data);
        watchdog('commerce_authnet', 'CIM Payment Profile added to Customer Profile @profile_id for user @uid.', array('@profile_id' => $add_to_profile, '@uid' => $order->uid));
      }
      elseif (!empty($card_data) && (string) $response->messages->message->code == 'E00040') {
        // But if we could not find a customer profile, assume the existing
        // customer profile ID we had is no longer valid and deactivate the card
        // data that resulted in the error.
        $card_data['status'] = 0;
        commerce_cardonfile_data_save($card_data);

        // Submit a CIM request to create the Customer Profile.
        if ($response = commerce_authnet_cim_create_customer_profile_request($payment_method, $order, $payment_details)) {
          // If the Customer Profile creation was a success, store the new card
          // on file data locally.
          if ((string) $response->messages->resultCode == 'Ok') {
            // Build a remote ID that includes the Customer Profile ID and the
            // Payment Profile ID.
            $remote_id = (string) $response->customerProfileId . '|' . (string) $response->customerPaymentProfileIdList->numericString;

            $card_data = array(
              'uid' => $order->uid,
              'payment_method' => $payment_method['method_id'],
              'instance_id' => $payment_method['instance_id'],
              'remote_id' => $remote_id,
              'card_type' => !empty($card_type) ? $card_type : 'card',
              'card_name' => !empty($billing_address['name_line']) ? $billing_address['name_line'] : '',
              'card_number' => substr($pane_values['credit_card']['number'], -4),
              'card_exp_month' => $pane_values['credit_card']['exp_month'],
              'card_exp_year' => $pane_values['credit_card']['exp_year'],
              'status' => 1,
            );

            // Save and log the creation of the new card on file.
            commerce_cardonfile_data_save($card_data);
            watchdog('commerce_authnet', 'CIM Customer Profile @profile_id created and saved to user @uid.', array('@profile_id' => (string) $response->customerProfileId, '@uid' => $order->uid));
          }
        }
      }
    }
  }
}

/**
 * Returns the message text for a CVV match.
 */
function commerce_authnet_cvv_response($code) {
  switch ($code) {
    case 'M':
      return t('Match');
    case 'N':
      return t('No Match');
    case 'P':
      return t('Not Processed');
    case 'S':
      return t('Should have been present');
    case 'U':
      return t('Issuer unable to process request');
  }

  return '-';
}
