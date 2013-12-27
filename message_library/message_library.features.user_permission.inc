<?php
/**
 * @file
 * message_library.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function message_library_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'access contextual links'.
  $permissions['access contextual links'] = array(
    'name' => 'access contextual links',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'manager' => 'manager',
    ),
    'module' => 'contextual',
  );

  // Exported permission: 'administer at_risk_groups vocabulary terms'.
  $permissions['administer at_risk_groups vocabulary terms'] = array(
    'name' => 'administer at_risk_groups vocabulary terms',
    'roles' => array(
      'manager' => 'manager',
    ),
    'module' => 'vppr',
  );

  // Exported permission: 'administer hazard vocabulary terms'.
  $permissions['administer hazard vocabulary terms'] = array(
    'name' => 'administer hazard vocabulary terms',
    'roles' => array(
      'manager' => 'manager',
    ),
    'module' => 'vppr',
  );

  // Exported permission: 'administer information_type vocabulary terms'.
  $permissions['administer information_type vocabulary terms'] = array(
    'name' => 'administer information_type vocabulary terms',
    'roles' => array(
      'manager' => 'manager',
    ),
    'module' => 'vppr',
  );

  // Exported permission: 'administer issues vocabulary terms'.
  $permissions['administer issues vocabulary terms'] = array(
    'name' => 'administer issues vocabulary terms',
    'roles' => array(
      'manager' => 'manager',
    ),
    'module' => 'vppr',
  );

  // Exported permission: 'administer message library notices'.
  $permissions['administer message library notices'] = array(
    'name' => 'administer message library notices',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'message_library_notices',
  );

  // Exported permission: 'administer notices warning'.
  $permissions['administer notices warning'] = array(
    'name' => 'administer notices warning',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'message_library_tou',
  );

  // Exported permission: 'administer population_types vocabulary terms'.
  $permissions['administer population_types vocabulary terms'] = array(
    'name' => 'administer population_types vocabulary terms',
    'roles' => array(
      'manager' => 'manager',
    ),
    'module' => 'vppr',
  );

  // Exported permission: 'administer sector vocabulary terms'.
  $permissions['administer sector vocabulary terms'] = array(
    'name' => 'administer sector vocabulary terms',
    'roles' => array(),
    'module' => 'vppr',
  );

  // Exported permission: 'administer target_audience vocabulary terms'.
  $permissions['administer target_audience vocabulary terms'] = array(
    'name' => 'administer target_audience vocabulary terms',
    'roles' => array(
      'manager' => 'manager',
    ),
    'module' => 'vppr',
  );

  // Exported permission: 'administer threat vocabulary terms'.
  $permissions['administer threat vocabulary terms'] = array(
    'name' => 'administer threat vocabulary terms',
    'roles' => array(
      'manager' => 'manager',
    ),
    'module' => 'vppr',
  );

  // Exported permission: 'clear csv_population_types feeds'.
  $permissions['clear csv_population_types feeds'] = array(
    'name' => 'clear csv_population_types feeds',
    'roles' => array(),
    'module' => 'feeds',
  );

  // Exported permission: 'clear message_library_node_message feeds'.
  $permissions['clear message_library_node_message feeds'] = array(
    'name' => 'clear message_library_node_message feeds',
    'roles' => array(),
    'module' => 'feeds',
  );

  // Exported permission: 'clear message_library_term_at_risk_group feeds'.
  $permissions['clear message_library_term_at_risk_group feeds'] = array(
    'name' => 'clear message_library_term_at_risk_group feeds',
    'roles' => array(),
    'module' => 'feeds',
  );

  // Exported permission: 'clear message_library_term_hazard feeds'.
  $permissions['clear message_library_term_hazard feeds'] = array(
    'name' => 'clear message_library_term_hazard feeds',
    'roles' => array(),
    'module' => 'feeds',
  );

  // Exported permission: 'clear message_library_term_information_type feeds'.
  $permissions['clear message_library_term_information_type feeds'] = array(
    'name' => 'clear message_library_term_information_type feeds',
    'roles' => array(),
    'module' => 'feeds',
  );

  // Exported permission: 'clear message_library_term_issues feeds'.
  $permissions['clear message_library_term_issues feeds'] = array(
    'name' => 'clear message_library_term_issues feeds',
    'roles' => array(),
    'module' => 'feeds',
  );

  // Exported permission: 'clear message_library_term_sector feeds'.
  $permissions['clear message_library_term_sector feeds'] = array(
    'name' => 'clear message_library_term_sector feeds',
    'roles' => array(),
    'module' => 'feeds',
  );

  // Exported permission: 'clear message_library_term_target_audience feeds'.
  $permissions['clear message_library_term_target_audience feeds'] = array(
    'name' => 'clear message_library_term_target_audience feeds',
    'roles' => array(),
    'module' => 'feeds',
  );

  // Exported permission: 'clear message_library_term_threat feeds'.
  $permissions['clear message_library_term_threat feeds'] = array(
    'name' => 'clear message_library_term_threat feeds',
    'roles' => array(),
    'module' => 'feeds',
  );

  // Exported permission: 'create message content'.
  $permissions['create message content'] = array(
    'name' => 'create message content',
    'roles' => array(
      'editor' => 'editor',
      'manager' => 'manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any message content'.
  $permissions['delete any message content'] = array(
    'name' => 'delete any message content',
    'roles' => array(
      'manager' => 'manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own message content'.
  $permissions['delete own message content'] = array(
    'name' => 'delete own message content',
    'roles' => array(
      'editor' => 'editor',
      'manager' => 'manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete terms in at_risk_groups'.
  $permissions['delete terms in at_risk_groups'] = array(
    'name' => 'delete terms in at_risk_groups',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in hazard'.
  $permissions['delete terms in hazard'] = array(
    'name' => 'delete terms in hazard',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in information_type'.
  $permissions['delete terms in information_type'] = array(
    'name' => 'delete terms in information_type',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in issues'.
  $permissions['delete terms in issues'] = array(
    'name' => 'delete terms in issues',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in population_types'.
  $permissions['delete terms in population_types'] = array(
    'name' => 'delete terms in population_types',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in sector'.
  $permissions['delete terms in sector'] = array(
    'name' => 'delete terms in sector',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in target_audience'.
  $permissions['delete terms in target_audience'] = array(
    'name' => 'delete terms in target_audience',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in threat'.
  $permissions['delete terms in threat'] = array(
    'name' => 'delete terms in threat',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit any message content'.
  $permissions['edit any message content'] = array(
    'name' => 'edit any message content',
    'roles' => array(
      'manager' => 'manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own message content'.
  $permissions['edit own message content'] = array(
    'name' => 'edit own message content',
    'roles' => array(
      'editor' => 'editor',
      'manager' => 'manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit terms in at_risk_groups'.
  $permissions['edit terms in at_risk_groups'] = array(
    'name' => 'edit terms in at_risk_groups',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in hazard'.
  $permissions['edit terms in hazard'] = array(
    'name' => 'edit terms in hazard',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in information_type'.
  $permissions['edit terms in information_type'] = array(
    'name' => 'edit terms in information_type',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in issues'.
  $permissions['edit terms in issues'] = array(
    'name' => 'edit terms in issues',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in population_types'.
  $permissions['edit terms in population_types'] = array(
    'name' => 'edit terms in population_types',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in sector'.
  $permissions['edit terms in sector'] = array(
    'name' => 'edit terms in sector',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in target_audience'.
  $permissions['edit terms in target_audience'] = array(
    'name' => 'edit terms in target_audience',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in threat'.
  $permissions['edit terms in threat'] = array(
    'name' => 'edit terms in threat',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'import csv_population_types feeds'.
  $permissions['import csv_population_types feeds'] = array(
    'name' => 'import csv_population_types feeds',
    'roles' => array(),
    'module' => 'feeds',
  );

  // Exported permission: 'import message_library_node_message feeds'.
  $permissions['import message_library_node_message feeds'] = array(
    'name' => 'import message_library_node_message feeds',
    'roles' => array(),
    'module' => 'feeds',
  );

  // Exported permission: 'import message_library_term_at_risk_group feeds'.
  $permissions['import message_library_term_at_risk_group feeds'] = array(
    'name' => 'import message_library_term_at_risk_group feeds',
    'roles' => array(),
    'module' => 'feeds',
  );

  // Exported permission: 'import message_library_term_hazard feeds'.
  $permissions['import message_library_term_hazard feeds'] = array(
    'name' => 'import message_library_term_hazard feeds',
    'roles' => array(),
    'module' => 'feeds',
  );

  // Exported permission: 'import message_library_term_information_type feeds'.
  $permissions['import message_library_term_information_type feeds'] = array(
    'name' => 'import message_library_term_information_type feeds',
    'roles' => array(),
    'module' => 'feeds',
  );

  // Exported permission: 'import message_library_term_issues feeds'.
  $permissions['import message_library_term_issues feeds'] = array(
    'name' => 'import message_library_term_issues feeds',
    'roles' => array(),
    'module' => 'feeds',
  );

  // Exported permission: 'import message_library_term_sector feeds'.
  $permissions['import message_library_term_sector feeds'] = array(
    'name' => 'import message_library_term_sector feeds',
    'roles' => array(),
    'module' => 'feeds',
  );

  // Exported permission: 'import message_library_term_target_audience feeds'.
  $permissions['import message_library_term_target_audience feeds'] = array(
    'name' => 'import message_library_term_target_audience feeds',
    'roles' => array(),
    'module' => 'feeds',
  );

  // Exported permission: 'import message_library_term_threat feeds'.
  $permissions['import message_library_term_threat feeds'] = array(
    'name' => 'import message_library_term_threat feeds',
    'roles' => array(),
    'module' => 'feeds',
  );

  // Exported permission: 'tamper csv_population_types'.
  $permissions['tamper csv_population_types'] = array(
    'name' => 'tamper csv_population_types',
    'roles' => array(),
    'module' => 'feeds_tamper',
  );

  // Exported permission: 'tamper message_library_term_hazard'.
  $permissions['tamper message_library_term_hazard'] = array(
    'name' => 'tamper message_library_term_hazard',
    'roles' => array(),
    'module' => 'feeds_tamper',
  );

  // Exported permission: 'tamper message_library_term_information_type'.
  $permissions['tamper message_library_term_information_type'] = array(
    'name' => 'tamper message_library_term_information_type',
    'roles' => array(),
    'module' => 'feeds_tamper',
  );

  // Exported permission: 'tamper message_library_term_issues'.
  $permissions['tamper message_library_term_issues'] = array(
    'name' => 'tamper message_library_term_issues',
    'roles' => array(),
    'module' => 'feeds_tamper',
  );

  // Exported permission: 'tamper message_library_term_sector'.
  $permissions['tamper message_library_term_sector'] = array(
    'name' => 'tamper message_library_term_sector',
    'roles' => array(),
    'module' => 'feeds_tamper',
  );

  // Exported permission: 'tamper message_library_term_target_audience'.
  $permissions['tamper message_library_term_target_audience'] = array(
    'name' => 'tamper message_library_term_target_audience',
    'roles' => array(),
    'module' => 'feeds_tamper',
  );

  // Exported permission: 'tamper message_library_term_threat'.
  $permissions['tamper message_library_term_threat'] = array(
    'name' => 'tamper message_library_term_threat',
    'roles' => array(),
    'module' => 'feeds_tamper',
  );

  // Exported permission: 'unlock csv_population_types feeds'.
  $permissions['unlock csv_population_types feeds'] = array(
    'name' => 'unlock csv_population_types feeds',
    'roles' => array(),
    'module' => 'feeds',
  );

  // Exported permission: 'unlock message_library_node_message feeds'.
  $permissions['unlock message_library_node_message feeds'] = array(
    'name' => 'unlock message_library_node_message feeds',
    'roles' => array(),
    'module' => 'feeds',
  );

  // Exported permission: 'unlock message_library_term_at_risk_group feeds'.
  $permissions['unlock message_library_term_at_risk_group feeds'] = array(
    'name' => 'unlock message_library_term_at_risk_group feeds',
    'roles' => array(),
    'module' => 'feeds',
  );

  // Exported permission: 'unlock message_library_term_hazard feeds'.
  $permissions['unlock message_library_term_hazard feeds'] = array(
    'name' => 'unlock message_library_term_hazard feeds',
    'roles' => array(),
    'module' => 'feeds',
  );

  // Exported permission: 'unlock message_library_term_information_type feeds'.
  $permissions['unlock message_library_term_information_type feeds'] = array(
    'name' => 'unlock message_library_term_information_type feeds',
    'roles' => array(),
    'module' => 'feeds',
  );

  // Exported permission: 'unlock message_library_term_issues feeds'.
  $permissions['unlock message_library_term_issues feeds'] = array(
    'name' => 'unlock message_library_term_issues feeds',
    'roles' => array(),
    'module' => 'feeds',
  );

  // Exported permission: 'unlock message_library_term_sector feeds'.
  $permissions['unlock message_library_term_sector feeds'] = array(
    'name' => 'unlock message_library_term_sector feeds',
    'roles' => array(),
    'module' => 'feeds',
  );

  // Exported permission: 'unlock message_library_term_target_audience feeds'.
  $permissions['unlock message_library_term_target_audience feeds'] = array(
    'name' => 'unlock message_library_term_target_audience feeds',
    'roles' => array(),
    'module' => 'feeds',
  );

  // Exported permission: 'unlock message_library_term_threat feeds'.
  $permissions['unlock message_library_term_threat feeds'] = array(
    'name' => 'unlock message_library_term_threat feeds',
    'roles' => array(),
    'module' => 'feeds',
  );

  // Exported permission: 'use search_api_autocomplete for search_api_views_message_library'.
  $permissions['use search_api_autocomplete for search_api_views_message_library'] = array(
    'name' => 'use search_api_autocomplete for search_api_views_message_library',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'search_api_autocomplete',
  );

  return $permissions;
}
