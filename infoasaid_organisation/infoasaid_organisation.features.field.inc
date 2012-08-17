<?php
/**
 * @file
 * infoasaid_organisation.features.field.inc
 */

/**
 * Implements hook_field_default_fields().
 */
function infoasaid_organisation_field_default_fields() {
  $fields = array();

  // Exported field: 'node-media_telecom_organisation-body'
  $fields['node-media_telecom_organisation-body'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(
        0 => 'node',
      ),
      'field_name' => 'body',
      'foreign keys' => array(
        'format' => array(
          'columns' => array(
            'format' => 'format',
          ),
          'table' => 'filter_format',
        ),
      ),
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'module' => 'text',
      'settings' => array(
        'profile2_private' => FALSE,
      ),
      'translatable' => '1',
      'type' => 'text_with_summary',
    ),
    'field_instance' => array(
      'bundle' => 'media_telecom_organisation',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => 0,
        ),
        'teaser' => array(
          'label' => 'hidden',
          'module' => 'text',
          'settings' => array(
            'trim_length' => 600,
          ),
          'type' => 'text_summary_or_trimmed',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'body',
      'label' => 'Description',
      'required' => 0,
      'settings' => array(
        'display_summary' => 1,
        'text_processing' => '1',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'text',
        'settings' => array(
          'rows' => '20',
          'summary_rows' => 5,
        ),
        'type' => 'text_textarea_with_summary',
        'weight' => '3',
      ),
    ),
  );

  // Exported field: 'node-media_telecom_organisation-field_address'
  $fields['node-media_telecom_organisation-field_address'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_address',
      'foreign keys' => array(),
      'indexes' => array(),
      'module' => 'addressfield',
      'settings' => array(
        'profile2_private' => FALSE,
      ),
      'translatable' => '0',
      'type' => 'addressfield',
    ),
    'field_instance' => array(
      'bundle' => 'media_telecom_organisation',
      'default_value' => array(
        0 => array(
          'element_key' => 'node|media_telecom_organisation|field_address|und|0',
          'thoroughfare' => '',
          'premise' => '',
          'locality' => '',
          'administrative_area' => '',
          'postal_code' => '',
          'country' => 'US',
          'organisation_name' => '',
          'name_line' => '',
        ),
      ),
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'addressfield',
          'settings' => array(
            'format_handlers' => array(
              0 => 'address',
            ),
            'use_widget_handlers' => 1,
          ),
          'type' => 'addressfield_default',
          'weight' => 12,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_address',
      'label' => 'Organisation address',
      'required' => 0,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'addressfield',
        'settings' => array(
          'available_countries' => array(
            'AD' => 'AD',
            'AE' => 'AE',
            'AF' => 'AF',
            'AG' => 'AG',
            'AI' => 'AI',
            'AL' => 'AL',
            'AM' => 'AM',
            'AN' => 'AN',
            'AO' => 'AO',
            'AQ' => 'AQ',
            'AR' => 'AR',
            'AS' => 'AS',
            'AT' => 'AT',
            'AU' => 'AU',
            'AW' => 'AW',
            'AX' => 'AX',
            'AZ' => 'AZ',
            'BA' => 'BA',
            'BB' => 'BB',
            'BD' => 'BD',
            'BE' => 'BE',
            'BF' => 'BF',
            'BG' => 'BG',
            'BH' => 'BH',
            'BI' => 'BI',
            'BJ' => 'BJ',
            'BL' => 'BL',
            'BM' => 'BM',
            'BN' => 'BN',
            'BO' => 'BO',
            'BR' => 'BR',
            'BS' => 'BS',
            'BT' => 'BT',
            'BV' => 'BV',
            'BW' => 'BW',
            'BY' => 'BY',
            'BZ' => 'BZ',
            'CA' => 'CA',
            'CC' => 'CC',
            'CD' => 'CD',
            'CF' => 'CF',
            'CG' => 'CG',
            'CH' => 'CH',
            'CI' => 'CI',
            'CK' => 'CK',
            'CL' => 'CL',
            'CM' => 'CM',
            'CN' => 'CN',
            'CO' => 'CO',
            'CR' => 'CR',
            'CU' => 'CU',
            'CV' => 'CV',
            'CW' => 'CW',
            'CX' => 'CX',
            'CY' => 'CY',
            'CZ' => 'CZ',
            'DE' => 'DE',
            'DJ' => 'DJ',
            'DK' => 'DK',
            'DM' => 'DM',
            'DO' => 'DO',
            'DZ' => 'DZ',
            'EC' => 'EC',
            'EE' => 'EE',
            'EG' => 'EG',
            'EH' => 'EH',
            'ER' => 'ER',
            'ES' => 'ES',
            'ET' => 'ET',
            'FI' => 'FI',
            'FJ' => 'FJ',
            'FK' => 'FK',
            'FM' => 'FM',
            'FO' => 'FO',
            'FR' => 'FR',
            'GA' => 'GA',
            'GB' => 'GB',
            'GD' => 'GD',
            'GE' => 'GE',
            'GF' => 'GF',
            'GG' => 'GG',
            'GH' => 'GH',
            'GI' => 'GI',
            'GL' => 'GL',
            'GM' => 'GM',
            'GN' => 'GN',
            'GP' => 'GP',
            'GQ' => 'GQ',
            'GR' => 'GR',
            'GS' => 'GS',
            'GT' => 'GT',
            'GU' => 'GU',
            'GW' => 'GW',
            'GY' => 'GY',
            'HK' => 'HK',
            'HM' => 'HM',
            'HN' => 'HN',
            'HR' => 'HR',
            'HT' => 'HT',
            'HU' => 'HU',
            'ID' => 'ID',
            'IE' => 'IE',
            'IL' => 'IL',
            'IM' => 'IM',
            'IN' => 'IN',
            'IO' => 'IO',
            'IQ' => 'IQ',
            'IR' => 'IR',
            'IS' => 'IS',
            'IT' => 'IT',
            'JE' => 'JE',
            'JM' => 'JM',
            'JO' => 'JO',
            'JP' => 'JP',
            'KE' => 'KE',
            'KG' => 'KG',
            'KH' => 'KH',
            'KI' => 'KI',
            'KM' => 'KM',
            'KN' => 'KN',
            'KP' => 'KP',
            'KR' => 'KR',
            'KW' => 'KW',
            'KY' => 'KY',
            'KZ' => 'KZ',
            'LA' => 'LA',
            'LB' => 'LB',
            'LC' => 'LC',
            'LI' => 'LI',
            'LK' => 'LK',
            'LR' => 'LR',
            'LS' => 'LS',
            'LT' => 'LT',
            'LU' => 'LU',
            'LV' => 'LV',
            'LY' => 'LY',
            'MA' => 'MA',
            'MC' => 'MC',
            'MD' => 'MD',
            'ME' => 'ME',
            'MF' => 'MF',
            'MG' => 'MG',
            'MH' => 'MH',
            'MK' => 'MK',
            'ML' => 'ML',
            'MM' => 'MM',
            'MN' => 'MN',
            'MO' => 'MO',
            'MP' => 'MP',
            'MQ' => 'MQ',
            'MR' => 'MR',
            'MS' => 'MS',
            'MT' => 'MT',
            'MU' => 'MU',
            'MV' => 'MV',
            'MW' => 'MW',
            'MX' => 'MX',
            'MY' => 'MY',
            'MZ' => 'MZ',
            'NA' => 'NA',
            'NC' => 'NC',
            'NE' => 'NE',
            'NF' => 'NF',
            'NG' => 'NG',
            'NI' => 'NI',
            'NL' => 'NL',
            'NO' => 'NO',
            'NP' => 'NP',
            'NR' => 'NR',
            'NU' => 'NU',
            'NZ' => 'NZ',
            'OM' => 'OM',
            'PA' => 'PA',
            'PE' => 'PE',
            'PF' => 'PF',
            'PG' => 'PG',
            'PH' => 'PH',
            'PK' => 'PK',
            'PL' => 'PL',
            'PM' => 'PM',
            'PN' => 'PN',
            'PR' => 'PR',
            'PS' => 'PS',
            'PT' => 'PT',
            'PW' => 'PW',
            'PY' => 'PY',
            'QA' => 'QA',
            'RE' => 'RE',
            'RO' => 'RO',
            'RS' => 'RS',
            'RU' => 'RU',
            'RW' => 'RW',
            'SA' => 'SA',
            'SB' => 'SB',
            'SC' => 'SC',
            'SD' => 'SD',
            'SE' => 'SE',
            'SG' => 'SG',
            'SH' => 'SH',
            'SI' => 'SI',
            'SJ' => 'SJ',
            'SK' => 'SK',
            'SL' => 'SL',
            'SM' => 'SM',
            'SN' => 'SN',
            'SO' => 'SO',
            'SR' => 'SR',
            'ST' => 'ST',
            'SV' => 'SV',
            'SY' => 'SY',
            'SZ' => 'SZ',
            'TC' => 'TC',
            'TD' => 'TD',
            'TF' => 'TF',
            'TG' => 'TG',
            'TH' => 'TH',
            'TJ' => 'TJ',
            'TK' => 'TK',
            'TL' => 'TL',
            'TM' => 'TM',
            'TN' => 'TN',
            'TO' => 'TO',
            'TR' => 'TR',
            'TT' => 'TT',
            'TV' => 'TV',
            'TW' => 'TW',
            'TZ' => 'TZ',
            'UA' => 'UA',
            'UG' => 'UG',
            'UM' => 'UM',
            'US' => 'US',
            'UY' => 'UY',
            'UZ' => 'UZ',
            'VA' => 'VA',
            'VC' => 'VC',
            'VE' => 'VE',
            'VG' => 'VG',
            'VI' => 'VI',
            'VN' => 'VN',
            'VU' => 'VU',
            'WF' => 'WF',
            'WS' => 'WS',
            'YE' => 'YE',
            'YT' => 'YT',
            'ZA' => 'ZA',
            'ZM' => 'ZM',
            'ZW' => 'ZW',
          ),
          'format_handlers' => array(
            'address' => 'address',
            'address-hide-country' => 0,
            'name-full' => 0,
            'name-oneline' => 0,
            'organisation' => 0,
          ),
        ),
        'type' => 'addressfield_standard',
        'weight' => '4',
      ),
    ),
  );

  // Exported field: 'node-media_telecom_organisation-field_category_guide'
  $fields['node-media_telecom_organisation-field_category_guide'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_category_guide',
      'foreign keys' => array(
        'format' => array(
          'columns' => array(
            'format' => 'format',
          ),
          'table' => 'filter_format',
        ),
      ),
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'module' => 'text',
      'settings' => array(
        'max_length' => '255',
        'profile2_private' => FALSE,
      ),
      'translatable' => '0',
      'type' => 'text',
    ),
    'field_instance' => array(
      'bundle' => 'media_telecom_organisation',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => 2,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_category_guide',
      'label' => 'Category Guide',
      'required' => 0,
      'settings' => array(
        'text_processing' => '0',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'text',
        'settings' => array(
          'size' => '60',
        ),
        'type' => 'text_textfield',
        'weight' => '12',
      ),
    ),
  );

  // Exported field: 'node-media_telecom_organisation-field_circulation_area'
  $fields['node-media_telecom_organisation-field_circulation_area'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_circulation_area',
      'foreign keys' => array(
        'format' => array(
          'columns' => array(
            'format' => 'format',
          ),
          'table' => 'filter_format',
        ),
      ),
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'module' => 'text',
      'settings' => array(
        'max_length' => '255',
        'profile2_private' => FALSE,
      ),
      'translatable' => '0',
      'type' => 'text',
    ),
    'field_instance' => array(
      'bundle' => 'media_telecom_organisation',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => 3,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_circulation_area',
      'label' => 'Circulation Area',
      'required' => 0,
      'settings' => array(
        'text_processing' => '0',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'text',
        'settings' => array(
          'size' => '60',
        ),
        'type' => 'text_textfield',
        'weight' => '13',
      ),
    ),
  );

  // Exported field: 'node-media_telecom_organisation-field_email'
  $fields['node-media_telecom_organisation-field_email'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '-1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_email',
      'foreign keys' => array(
        'format' => array(
          'columns' => array(
            'format' => 'format',
          ),
          'table' => 'filter_format',
        ),
      ),
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'module' => 'text',
      'settings' => array(
        'max_length' => '255',
        'profile2_private' => FALSE,
      ),
      'translatable' => '0',
      'type' => 'text',
    ),
    'field_instance' => array(
      'bundle' => 'media_telecom_organisation',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => 5,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_email',
      'label' => 'Email',
      'required' => 0,
      'settings' => array(
        'text_processing' => '0',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'text',
        'settings' => array(
          'size' => '60',
        ),
        'type' => 'text_textfield',
        'weight' => '9',
      ),
    ),
  );

  // Exported field: 'node-media_telecom_organisation-field_hide_in_list'
  $fields['node-media_telecom_organisation-field_hide_in_list'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_hide_in_list',
      'foreign keys' => array(),
      'indexes' => array(
        'value' => array(
          0 => 'value',
        ),
      ),
      'module' => 'list',
      'settings' => array(
        'allowed_values' => array(
          0 => 'Display this organisation in Guides lists',
          1 => 'Hide this organisation in Guides lists',
        ),
        'allowed_values_function' => '',
        'profile2_private' => FALSE,
      ),
      'translatable' => '0',
      'type' => 'list_boolean',
    ),
    'field_instance' => array(
      'bundle' => 'media_telecom_organisation',
      'default_value' => array(
        0 => array(
          'value' => '0',
        ),
      ),
      'deleted' => '0',
      'description' => 'Display this organisation in Guides lists (all organisations are displayed in tables).',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'list',
          'settings' => array(),
          'type' => 'list_default',
          'weight' => 4,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_hide_in_list',
      'label' => 'Display this organisation in Guides lists',
      'required' => 1,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'options',
        'settings' => array(),
        'type' => 'options_buttons',
        'weight' => '2',
      ),
    ),
  );

  // Exported field: 'node-media_telecom_organisation-field_mobile'
  $fields['node-media_telecom_organisation-field_mobile'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_mobile',
      'foreign keys' => array(
        'format' => array(
          'columns' => array(
            'format' => 'format',
          ),
          'table' => 'filter_format',
        ),
      ),
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'module' => 'text',
      'settings' => array(
        'max_length' => '255',
        'profile2_private' => FALSE,
      ),
      'translatable' => '0',
      'type' => 'text',
    ),
    'field_instance' => array(
      'bundle' => 'media_telecom_organisation',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => 6,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_mobile',
      'label' => 'Mobile',
      'required' => 0,
      'settings' => array(
        'text_processing' => '0',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'text',
        'settings' => array(
          'size' => '60',
        ),
        'type' => 'text_textfield',
        'weight' => '6',
      ),
    ),
  );

  // Exported field: 'node-media_telecom_organisation-field_name_alias'
  $fields['node-media_telecom_organisation-field_name_alias'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_name_alias',
      'foreign keys' => array(
        'format' => array(
          'columns' => array(
            'format' => 'format',
          ),
          'table' => 'filter_format',
        ),
      ),
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'module' => 'text',
      'settings' => array(
        'max_length' => '255',
        'profile2_private' => FALSE,
      ),
      'translatable' => '0',
      'type' => 'text',
    ),
    'field_instance' => array(
      'bundle' => 'media_telecom_organisation',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => 1,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_name_alias',
      'label' => 'Alias (other names)',
      'required' => 0,
      'settings' => array(
        'text_processing' => '0',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'text',
        'settings' => array(
          'size' => '60',
        ),
        'type' => 'text_textfield',
        'weight' => '1',
      ),
    ),
  );

  // Exported field: 'node-media_telecom_organisation-field_note'
  $fields['node-media_telecom_organisation-field_note'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_note',
      'foreign keys' => array(
        'format' => array(
          'columns' => array(
            'format' => 'format',
          ),
          'table' => 'filter_format',
        ),
      ),
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'module' => 'text',
      'settings' => array(
        'profile2_private' => FALSE,
      ),
      'translatable' => '0',
      'type' => 'text_long',
    ),
    'field_instance' => array(
      'bundle' => 'media_telecom_organisation',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => 15,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_note',
      'label' => 'Notes',
      'required' => 0,
      'settings' => array(
        'text_processing' => '0',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'text',
        'settings' => array(
          'rows' => '5',
        ),
        'type' => 'text_textarea',
        'weight' => '16',
      ),
    ),
  );

  // Exported field: 'node-media_telecom_organisation-field_office'
  $fields['node-media_telecom_organisation-field_office'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '-1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_office',
      'foreign keys' => array(
        'format' => array(
          'columns' => array(
            'format' => 'format',
          ),
          'table' => 'filter_format',
        ),
      ),
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'module' => 'text',
      'settings' => array(
        'max_length' => '255',
        'profile2_private' => FALSE,
      ),
      'translatable' => '0',
      'type' => 'text',
    ),
    'field_instance' => array(
      'bundle' => 'media_telecom_organisation',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => 11,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_office',
      'label' => 'Office',
      'required' => 0,
      'settings' => array(
        'text_processing' => '0',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'text',
        'settings' => array(
          'size' => '60',
        ),
        'type' => 'text_textfield',
        'weight' => '7',
      ),
    ),
  );

  // Exported field: 'node-media_telecom_organisation-field_prarent_org'
  $fields['node-media_telecom_organisation-field_prarent_org'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '-1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_prarent_org',
      'foreign keys' => array(),
      'indexes' => array(
        'target_entity' => array(
          0 => 'target_type',
          1 => 'target_id',
        ),
      ),
      'module' => 'entityreference',
      'settings' => array(
        'handler' => 'base',
        'handler_settings' => array(
          'sort' => array(
            'direction' => 'ASC',
            'field' => 'body:value',
            'property' => 'title',
            'type' => 'property',
          ),
          'target_bundles' => array(
            'media_telecom_organisation' => 'media_telecom_organisation',
          ),
        ),
        'handler_submit' => 'Change handler',
        'profile2_private' => FALSE,
        'target_type' => 'node',
      ),
      'translatable' => '0',
      'type' => 'entityreference',
    ),
    'field_instance' => array(
      'bundle' => 'media_telecom_organisation',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'entityreference',
          'settings' => array(
            'link' => FALSE,
          ),
          'type' => 'entityreference_label',
          'weight' => 8,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_prarent_org',
      'label' => 'Parent organisation(s)',
      'required' => 0,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'entityreference',
        'settings' => array(
          'match_operator' => 'CONTAINS',
          'path' => '',
          'size' => '60',
        ),
        'type' => 'entityreference_autocomplete',
        'weight' => '10',
      ),
    ),
  );

  // Exported field: 'node-media_telecom_organisation-field_sales'
  $fields['node-media_telecom_organisation-field_sales'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_sales',
      'foreign keys' => array(
        'format' => array(
          'columns' => array(
            'format' => 'format',
          ),
          'table' => 'filter_format',
        ),
      ),
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'module' => 'text',
      'settings' => array(
        'max_length' => '255',
        'profile2_private' => FALSE,
      ),
      'translatable' => '0',
      'type' => 'text',
    ),
    'field_instance' => array(
      'bundle' => 'media_telecom_organisation',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => 'Number of copies sold per period',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => 13,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_sales',
      'label' => 'Sales',
      'required' => 0,
      'settings' => array(
        'text_processing' => '0',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'text',
        'settings' => array(
          'size' => '60',
        ),
        'type' => 'text_textfield',
        'weight' => '14',
      ),
    ),
  );

  // Exported field: 'node-media_telecom_organisation-field_sub_org'
  $fields['node-media_telecom_organisation-field_sub_org'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_sub_org',
      'foreign keys' => array(),
      'indexes' => array(
        'target_entity' => array(
          0 => 'target_type',
          1 => 'target_id',
        ),
      ),
      'module' => 'entityreference',
      'settings' => array(
        'handler' => 'base',
        'handler_settings' => array(
          'sort' => array(
            'direction' => 'ASC',
            'field' => 'body:value',
            'property' => 'title',
            'type' => 'property',
          ),
          'target_bundles' => array(
            'media_telecom_organisation' => 'media_telecom_organisation',
          ),
        ),
        'handler_submit' => 'Change handler',
        'profile2_private' => FALSE,
        'target_type' => 'node',
      ),
      'translatable' => '0',
      'type' => 'entityreference',
    ),
    'field_instance' => array(
      'bundle' => 'media_telecom_organisation',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'entityreference',
          'settings' => array(
            'link' => FALSE,
          ),
          'type' => 'entityreference_label',
          'weight' => 9,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_sub_org',
      'label' => 'Subsidiaries organisation(s)',
      'required' => 0,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'entityreference',
        'settings' => array(
          'match_operator' => 'CONTAINS',
          'path' => '',
          'size' => '60',
        ),
        'type' => 'entityreference_autocomplete',
        'weight' => '11',
      ),
    ),
  );

  // Exported field: 'node-media_telecom_organisation-field_switchboard'
  $fields['node-media_telecom_organisation-field_switchboard'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '-1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_switchboard',
      'foreign keys' => array(
        'format' => array(
          'columns' => array(
            'format' => 'format',
          ),
          'table' => 'filter_format',
        ),
      ),
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'module' => 'text',
      'settings' => array(
        'max_length' => '255',
        'profile2_private' => FALSE,
      ),
      'translatable' => '0',
      'type' => 'text',
    ),
    'field_instance' => array(
      'bundle' => 'media_telecom_organisation',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => 10,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_switchboard',
      'label' => 'Switchboard',
      'required' => 0,
      'settings' => array(
        'text_processing' => '0',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'text',
        'settings' => array(
          'size' => '60',
        ),
        'type' => 'text_textfield',
        'weight' => '8',
      ),
    ),
  );

  // Exported field: 'node-media_telecom_organisation-field_syndi_partner'
  $fields['node-media_telecom_organisation-field_syndi_partner'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_syndi_partner',
      'foreign keys' => array(),
      'indexes' => array(
        'target_entity' => array(
          0 => 'target_type',
          1 => 'target_id',
        ),
      ),
      'module' => 'entityreference',
      'settings' => array(
        'handler' => 'base',
        'handler_settings' => array(
          'sort' => array(
            'direction' => 'ASC',
            'field' => 'body:value',
            'property' => 'nid',
            'type' => 'property',
          ),
          'target_bundles' => array(
            'media_telecom_organisation' => 'media_telecom_organisation',
          ),
        ),
        'handler_submit' => 'Change handler',
        'profile2_private' => FALSE,
        'target_type' => 'node',
      ),
      'translatable' => '0',
      'type' => 'entityreference',
    ),
    'field_instance' => array(
      'bundle' => 'media_telecom_organisation',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'entityreference',
          'settings' => array(
            'link' => FALSE,
          ),
          'type' => 'entityreference_label',
          'weight' => 14,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_syndi_partner',
      'label' => 'Syndication partners',
      'required' => 0,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'entityreference',
        'settings' => array(
          'match_operator' => 'CONTAINS',
          'path' => '',
          'size' => '60',
        ),
        'type' => 'entityreference_autocomplete',
        'weight' => '15',
      ),
    ),
  );

  // Exported field: 'node-media_telecom_organisation-field_website'
  $fields['node-media_telecom_organisation-field_website'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '-1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_website',
      'foreign keys' => array(),
      'indexes' => array(),
      'module' => 'link',
      'settings' => array(
        'attributes' => array(
          'class' => '',
          'rel' => '',
          'target' => 'default',
        ),
        'display' => array(
          'url_cutoff' => 80,
        ),
        'enable_tokens' => 1,
        'profile2_private' => FALSE,
        'title' => 'optional',
        'title_maxlength' => 128,
        'title_value' => '',
        'url' => 0,
      ),
      'translatable' => '0',
      'type' => 'link_field',
    ),
    'field_instance' => array(
      'bundle' => 'media_telecom_organisation',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'link',
          'settings' => array(),
          'type' => 'link_default',
          'weight' => 7,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_website',
      'label' => 'Organisation Website',
      'required' => 0,
      'settings' => array(
        'attributes' => array(
          'class' => '',
          'configurable_title' => 0,
          'rel' => '',
          'target' => 'default',
          'title' => '',
        ),
        'display' => array(
          'url_cutoff' => '80',
        ),
        'enable_tokens' => 1,
        'title' => 'none',
        'title_maxlength' => '128',
        'title_value' => '',
        'url' => 0,
        'user_register_form' => FALSE,
        'validate_url' => 1,
      ),
      'widget' => array(
        'active' => 0,
        'module' => 'link',
        'settings' => array(),
        'type' => 'link_field',
        'weight' => '5',
      ),
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Alias (other names)');
  t('Category Guide');
  t('Circulation Area');
  t('Description');
  t('Display this organisation in Guides lists');
  t('Display this organisation in Guides lists (all organisations are displayed in tables).');
  t('Email');
  t('Mobile');
  t('Notes');
  t('Number of copies sold per period');
  t('Office');
  t('Organisation Website');
  t('Organisation address');
  t('Parent organisation(s)');
  t('Sales');
  t('Subsidiaries organisation(s)');
  t('Switchboard');
  t('Syndication partners');

  return $fields;
}
