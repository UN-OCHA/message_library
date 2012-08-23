<?php

/**
 * @todo Please document this function.
 * @see http://drupal.org/node/1354
 */
function export2rtf_node($nidString) {
  $nids = explode(',', $nidString);
  $nodes = node_load_multiple($nids);
  $rtfFile = new MessageRtfFile();
  $i = 0;
  foreach ($nodes as $node) {
    $rtfFile->addThreatTitle($node->title);
    $rtfFile->addThreatIssue($node->field_threat_category['und']);
    foreach ($node->field_threat_message['und'] as $mid) {
      $message = node_load($mid['target_id']);
      $rtfFile->addMessageTitle($message->title);
      if (!empty($message->field_message_sensitivity['und'][0]['value'])) {
        if ($message->field_message_sensitivity['und'][0]['value'] == 1 && !empty($message->field_message_sensitivity_messag['und'][0])) {
          $rtfFile->addEmptyLine(1);
          $rtfFile->addMessageSensitivityDescription($message->field_message_sensitivity_messag['und'][0]['value']);
          $rtfFile->addEmptyLine(1);
        }
        if ($message->field_message_sensitivity['und'][0]['value'] == 2 && !empty($message->field_message_sensitivity_messag['und'][0])) {
          $rtfFile->addEmptyLine(1);
          $rtfFile->addMessageSensitivityDescription($message->field_message_sensitivity_messag['und'][0]['value']);
          $rtfFile->addEmptyLine(1);
          $rtfFile->addMessageSensitivityQuestions($message->field_message_sensitivity_questi['und']);
          $rtfFile->addEmptyLine(1);
        }
      }
      $rtfFile->addMessageDescription(export2rtf_formatTextarea($message->field_message_group_mess['und'][0]['value']));
      $rtfFile->addMessageRiskGroup($message->field_message_group_risk['und']);
      if (!empty($message->field_message_group_risk_comment['und'][0]['value'])) {
        $rtfFile->addMessageRiskGroupComment($message->field_message_group_risk_comment['und'][0]['value']);
      }
      $rtfFile->addMessageTargetAudience($message->field_message_audience['und']);
      if (!empty($message->field_message_target_comment['und'][0]['value'])) {
        $rtfFile->addMessageTargetAudienceComment($message->field_message_target_comment['und'][0]['value']);
      }
      $rtfFile->addMessageInformationType($message->field_message_info_type['und'][0]['tid']);
      $rtfFile->addMessageSensitivity($message->field_message_sensitivity['und'][0]['value']);
      if (!empty($message->field_message_sensitivity_causes['und'][0]['value'])) {
        $rtfFile->addMessageSensitivityCauses($message->field_message_sensitivity_causes['und'][0]['value']);
      }
      if (!empty($message->field_message_source['und'][0]['url'])) {
        $rtfFile->addMessageSource($message->field_message_source['und']);
      }
      if (!empty($message->field_message_url['und'][0]['url'])) {
        $rtfFile->addMessageWebsite($message->field_message_url['und']);
      }
      $rtfFile->addEmptyLine(2);
    }
    $i++;
    if ($i < count($nodes)) {
      $rtfFile->addThreatSeparator();
    }
  }
  header("Content-type: text/rtf");
  header("Content-Disposition: attachment; filename=message.rtf");
  echo $rtfFile->getFileContent();
}

/**
 * @todo Please document this function.
 * @see http://drupal.org/node/1354
 */
function export2rtf_formatTextarea($content) {
  return export2rtf_br2par(strip_tags($content, "<br>"));
}

/**
 * @todo Please document this function.
 * @see http://drupal.org/node/1354
 */
function export2rtf_br2par($string) {
  $return = eregi_replace('<br[[:space:]]*/?' .
    	'[[:space:]]*>', '\par' . "\n", $string);
  return $return;
}

/**
 * @todo Please document this function.
 * @see http://drupal.org/node/1354
 */
function export2rtf_br2nl($string) {
  $return = eregi_replace('<br[[:space:]]*/?' .
    	'[[:space:]]*>', chr(13) . chr(10), $string);
  return $return;
}
