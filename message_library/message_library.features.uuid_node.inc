<?php
/**
 * @file
 * message_library.features.uuid_node.inc
 */

/**
 * Implements hook_uuid_features_default_content().
 */
function message_library_uuid_features_default_content() {
  $nodes = array();

  $nodes[] = array(
  'uid' => 1,
  'title' => 'Frequently Asked Questions - Users FAQ',
  'log' => '',
  'status' => 1,
  'comment' => 1,
  'promote' => 1,
  'sticky' => 0,
  'vuuid' => '0c82ddad-25fc-4aca-bf1d-a9c19fe622a3',
  'title_original' => 'Frequently Asked Questions - Users FAQ',
  'type' => 'page',
  'language' => 'und',
  'created' => 1377607256,
  'tnid' => 0,
  'translate' => 0,
  'uuid' => '295bdf1f-6776-45e8-a888-7328188050cb',
  'reliefweb' => 0,
  'revision_uid' => 1,
  'base_reliefweb' => 0,
  'body' => array(
    'und' => array(
      0 => array(
        'value' => '<ul>
  <li><a href="#ml-aim">What is the aim of the message library?</a></li>
  <li><a href="#ml-inteted-use">What are its intended uses?</a></li>
  <li><a href="#ml-how-access">How can people access the library?</a></li>
  <li><a href="#ml-who-will-use">Who will use the message library?</a></li>
  <li><a href="#ml-for">Who are the messages for?</a></li>
  <li><a href="#ml-limitations">What are the limitations of the message library?</a></li>
</ul>

<h3 id="ml-aim">What is the aim of the message library?</h3>
<div>
  <p>The aim of the message library is to have a set of generic, multi-sectoral messages targeted at crisis-affected populations. The message library includes alerts, advice on how to mitigate risk, what to do in the absence of any assistance and prompts for messages on programmatic interventions/services available.</p>
  <p>The library is not designed to be a ‘rip and read’ resource – instead it should be used as a reference for those working in emergency situations about what can be shared with affected communities during and after disasters be they natural or man-made. It is not an exhaustive list. As this is a dynamic tool, messages can be added, edited, and revised at any point, should the need arise.</p>
  <p>The message library is designed for sudden onset emergencies, but it can also be a useful tool in protracted crises.</p>
</div>

<h3 id="ml-inteted-use">What are its intended uses?</h3>
<p>The library has several intended uses:</p>
<ul>
  <li>a) To act as a reference for what can and should be communicated to affected populations during the first few days and weeks of an emergency</li>
  <li>b) To help improve collaboration and coordination specifically around messaging to affected populations.</li>
</ul>

<h3 id="ml-how-access">How can people access the library?</h3>
<p>The library will sit on-line but users will also be able to download and/or print an off-line version and store it on their laptops. As the content is likely to be added to regularly by cluster leads, it is advisable to access and download the on-line version every time an emergency hits, in order to get the most up to date content</p>

<h3 id="ml-who-will-use">Who will use the message library?</h3>
<p>Users will depend on the organisation involved and the roles and responsibilities of individual staff. It is expected they will be a mixture of programme managers, sector specialists, ‘beneficiary communication’ specialists, accountability officers and public health officers.</p>
<p>The content of the message library will be owned and maintained by the Global Cluster leads. It’s hoped that all actors involved in humanitarian response, including national governments, NGOs, international aid agencies, media development organisations, local media channels and the communities themselves can work in partnership wherever possible to contextualise, adapt and disseminate potentially life-saving information to populations.</p>

<h3 id="ml-for">Who are the messages for?</h3>
<p>The messages are for crisis-affected populations. Each message has a target audience and depending on the “at risk” group, these can include some of the following groups: affected population, community leaders, parents and teachers. Many of the messages are targeted at mothers, fathers and other primary caregivers. This is because babies and children under 5 are often the most vulnerable in emergencies and so many of the messages are aimed at saving their lives. However, even though there are ‘at risk’ groups, many of the messages will be useful for everyone affected by the crisis.</p>

<h3 id="ml-limitations">What are the limitations of the message library?</h3>
<p>The message library has several limitations. While it may act as a tool to help improve the timing and coordination of information dissemination, it can only accommodate messages in their generic form. This means that users would still need to spend time adapting, translating and pilot testing each message according to the context on the ground (see section 2 on contextualisation for guidance). For example, messages on how to treat water using a particular method could only be disseminated if that method was feasible and acceptable. Understanding the context therefore is crucial to make the message library work and, more importantly, to make messaging to populations effective.</p>
<p>Another limitation is the fact that it is a tool that is essentially designed for ‘one way’ communication, i.e. organisations telling the affected population what the threats are, how to mitigate risk, what to do in the absence of assistance. Two-way communication - where the affected populations engage with humanitarian responders, giving their views and opinions around specific ‘threats’  and needs -  is likely to produce far better results.</p>
<p>Finally, if behaviour change is your objective (e.g. trying to get people to defecate in a latrine rather than the open air to avoid diarrhoea), it is important to recognise that messaging alone will not necessarily lead to behaviour change in practice. There are many other factors that act as barriers to change – social norms, structural constraints, historical/political context etc. Therefore, messaging is just one small part of a much wider process to facilitate actual behaviour change</p>
',
        'summary' => '',
        'format' => 'full_html',
      ),
    ),
  ),
  'title_field' => array(
    'und' => array(
      0 => array(
        'value' => 'Frequently Asked Questions - Users FAQ',
        'format' => NULL,
        'safe_value' => 'Frequently Asked Questions - Users FAQ',
      ),
    ),
  ),
  'rdf_mapping' => array(
    'rdftype' => array(
      0 => 'sioc:Item',
      1 => 'foaf:Document',
    ),
    'title' => array(
      'predicates' => array(
        0 => 'dc:title',
      ),
    ),
    'created' => array(
      'predicates' => array(
        0 => 'dc:date',
        1 => 'dc:created',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
    'changed' => array(
      'predicates' => array(
        0 => 'dc:modified',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
    'body' => array(
      'predicates' => array(
        0 => 'content:encoded',
      ),
    ),
    'uid' => array(
      'predicates' => array(
        0 => 'sioc:has_creator',
      ),
      'type' => 'rel',
    ),
    'name' => array(
      'predicates' => array(
        0 => 'foaf:name',
      ),
    ),
    'comment_count' => array(
      'predicates' => array(
        0 => 'sioc:num_replies',
      ),
      'datatype' => 'xsd:integer',
    ),
    'last_activity' => array(
      'predicates' => array(
        0 => 'sioc:last_activity_date',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
  ),
  'translations' => array(
    'original' => NULL,
    'data' => array(),
  ),
  'cid' => 0,
  'last_comment_name' => NULL,
  'last_comment_uid' => 1,
  'comment_count' => 0,
  'name' => 'guillaumev',
  'picture' => 0,
  'data' => 'b:0;',
  'date' => '2013-08-27 14:40:56 +0200',
);
  $nodes[] = array(
  'uid' => 1,
  'title' => 'Message Library: Quick Reference User Manual',
  'log' => '',
  'status' => 1,
  'comment' => 1,
  'promote' => 1,
  'sticky' => 0,
  'vuuid' => '2b88182e-424c-43cb-838d-3778a71a9d88',
  'title_original' => 'Message Library: Quick Reference User Manual',
  'type' => 'page',
  'language' => 'und',
  'created' => 1377607256,
  'tnid' => 0,
  'translate' => 0,
  'uuid' => '2f65a574-0bf6-4ba6-9be2-4116404fe663',
  'reliefweb' => 0,
  'revision_uid' => 1,
  'base_reliefweb' => 0,
  'body' => array(
    'und' => array(
      0 => array(
        'value' => '<p>There are a number of different ways to access the message library.</p><p>A <strong><em>quick search</em></strong> allows you to type in a key word and the tool will list all messages related to that particular word or phrase categorised under the following table headings: Issue, Threat, At Risk Group, Target Audience, Information Requirement and Examples. For example, typing in ‘diarrhoea’ will show all messages related to diarrhoea under Health, Nutrition and Water, Sanitation and Hygiene.</p><p>The <strong><em>advanced search</em></strong> allows the user to select their search criteria from a set of drop down menus. The user has a choice of viewing the list of issues in two different ways - through an alphabetical list or via \'sectors\' or clusters.</p><p>It is important to note that in the advanced search option, individual ‘threats’ are linked to “issues” so you would need to first identify the “issue” in order to get the corresponding “threats”.</p><p>The other main drop down menus - ‘Threat’, ‘At-Risk Group’ and ‘Target Audience’ act as filters. The user simply selects an item from the list from each drop down menu and then clicks search. For example, if the user is looking for hygiene messages to prevent cholera in children, they can do the following:</p><p>&nbsp;</p><ul><li>a) Under ‘issue’ - choose <strong><em>Communicable diseases</em></strong></li><li>b) Under ‘threat’ - choose <strong><em>Cholera</em></strong></li><li>c) Under ‘at-risk group’- choose <strong><em>Children</em></strong></li><li>d) Under ‘target audience’-&nbsp; choose <strong><em>mothers/fathers/other primary caregivers</em></strong></li></ul><p>A list of messages will appear from simple alerts, to awareness, self-care and, where applicable, service.</p><p>There are four different types of messages and they tend to reflect the different emergency phases.</p><ul><li><p><strong>Alerts</strong> are disseminated very soon after an emergency has struck to alert a population to an emerging threat. This could be a tsunami warning following an earthquake, information about an outbreak of disease or threat of aftershocks or on a contaminated water supply.</p></li><li><p><strong>Awareness</strong> messages are similar to public education. This could be information on recognising symptoms of a condition such as malnutrition, or how to protect assets to ward off food insecurity or how to identify warning signs of unexploded ordnance.</p></li><li><p><strong>Self-care</strong> messages are designed to give advice to populations in the absence of any assistance. This could be because of security or logistical reasons or simply time related. Examples include how to make homemade ORS, how to treat children who are suffering from influenza or what to do if you have diarrhoea.</p></li><li><p><strong>Service</strong> messages are basically prompts related to programme interventions and contain practical information such as where to go for assistance, what supplies are being distributed, opening hours, the procedure involved etc.</p></li></ul><p>Once you have finished your search, click on any of the messages in the list and you will access the content of the message itself. In each message there is additional information on \'at-risk\' group, target audience, type of message, source (where applicable) and a short text on issues to consider before dissemination.</p><p><strong>Message bundles</strong> (NB These are stil in draft form)</p><p>If you want to quickly refer to a list of the main threats affecting populations in a particular type of emergency,&nbsp; click on one of the <em>‘Hazard specific message bundles’</em>. These are the most important messages to get out to populations in the first 72 hours of an emergency. The hazards listed are Earthquake, Flood, Cyclone and Tsunami. Each bundle includes messages from different sector areas according to key threats facing populations. They can be quickly downloaded, translated, adapted to suit the local context, pilot tested and then disseminated.</p><p>For more detailed information on the Message Library, guidance on contextualisation and other important components of communication with crisis-affected populations, please download the guide <a href="http://infoasaid.org/sites/infoasaid.org/files/documentation/Message_library_guide_March_2012.pdf">here</a>.&nbsp;</p>',
        'summary' => '',
        'format' => 'full_html',
      ),
    ),
  ),
  'title_field' => array(
    'und' => array(
      0 => array(
        'value' => 'Message Library: Quick Reference User Manual',
        'format' => NULL,
        'safe_value' => 'Message Library: Quick Reference User Manual',
      ),
    ),
  ),
  'rdf_mapping' => array(
    'rdftype' => array(
      0 => 'sioc:Item',
      1 => 'foaf:Document',
    ),
    'title' => array(
      'predicates' => array(
        0 => 'dc:title',
      ),
    ),
    'created' => array(
      'predicates' => array(
        0 => 'dc:date',
        1 => 'dc:created',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
    'changed' => array(
      'predicates' => array(
        0 => 'dc:modified',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
    'body' => array(
      'predicates' => array(
        0 => 'content:encoded',
      ),
    ),
    'uid' => array(
      'predicates' => array(
        0 => 'sioc:has_creator',
      ),
      'type' => 'rel',
    ),
    'name' => array(
      'predicates' => array(
        0 => 'foaf:name',
      ),
    ),
    'comment_count' => array(
      'predicates' => array(
        0 => 'sioc:num_replies',
      ),
      'datatype' => 'xsd:integer',
    ),
    'last_activity' => array(
      'predicates' => array(
        0 => 'sioc:last_activity_date',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
  ),
  'translations' => array(
    'original' => NULL,
    'data' => array(),
  ),
  'cid' => 0,
  'last_comment_name' => NULL,
  'last_comment_uid' => 1,
  'comment_count' => 0,
  'name' => 'guillaumev',
  'picture' => 0,
  'data' => 'b:0;',
  'date' => '2013-08-27 14:40:56 +0200',
);
  return $nodes;
}
