<?php
/**
 * @file
 * message_library.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function message_library_taxonomy_default_vocabularies() {
  return array(
      'at_risk_groups' => array('name' => 'At Risk Groups',
          'machine_name' => 'at_risk_groups', 'description' => '',
          'hierarchy' => '0', 'module' => 'taxonomy', 'weight' => '0',
          'rdf_mapping' => array(
              'rdftype' => array(0 => 'skos:ConceptScheme',),
              'name' => array(
                  'predicates' => array(0 => 'dc:title',),),
              'description' => array(
                  'predicates' => array(0 => 'rdfs:comment',),),),),
      'hazard' => array('name' => 'Hazard', 'machine_name' => 'hazard',
          'description' => '', 'hierarchy' => '0', 'module' => 'taxonomy',
          'weight' => '0',
          'rdf_mapping' => array(
              'rdftype' => array(0 => 'skos:ConceptScheme',),
              'name' => array(
                  'predicates' => array(0 => 'dc:title',),),
              'description' => array(
                  'predicates' => array(0 => 'rdfs:comment',),),),),
      'information_type' => array('name' => 'Information Type',
          'machine_name' => 'information_type', 'description' => '',
          'hierarchy' => '0', 'module' => 'taxonomy', 'weight' => '0',
          'rdf_mapping' => array(
              'rdftype' => array(0 => 'skos:ConceptScheme',),
              'name' => array(
                  'predicates' => array(0 => 'dc:title',),),
              'description' => array(
                  'predicates' => array(0 => 'rdfs:comment',),),),),
      'issues' => array('name' => 'Issues', 'machine_name' => 'issues',
          'description' => '', 'hierarchy' => '0', 'module' => 'taxonomy',
          'weight' => '0',
          'rdf_mapping' => array(
              'rdftype' => array(0 => 'skos:ConceptScheme',),
              'name' => array(
                  'predicates' => array(0 => 'dc:title',),),
              'description' => array(
                  'predicates' => array(0 => 'rdfs:comment',),),),),
      'sector' => array('name' => 'Sector', 'machine_name' => 'sector',
          'description' => '', 'hierarchy' => '0', 'module' => 'taxonomy',
          'weight' => '0',
          'rdf_mapping' => array(
              'rdftype' => array(0 => 'skos:ConceptScheme',),
              'name' => array(
                  'predicates' => array(0 => 'dc:title',),),
              'description' => array(
                  'predicates' => array(0 => 'rdfs:comment',),),),),);
}
