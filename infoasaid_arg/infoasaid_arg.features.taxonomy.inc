<?php
/**
 * @file
 * infoasaid_arg.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function infoasaid_arg_taxonomy_default_vocabularies() {
  return array(
    'at_risk_groups' => array(
      'name' => 'At Risk Groups',
      'machine_name' => 'at_risk_groups',
      'description' => '',
      'hierarchy' => '0',
      'module' => 'taxonomy',
      'weight' => '0',
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
  );
}
