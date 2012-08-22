<?php

function export2rtf_node($nidString) {
	$nids = explode(',',$nidString);
	$nodes = node_load_multiple($nids);
	$rtfFile = new MessageRtfFile();
	$i = 0;
	foreach ($nodes as $node) {
		$rtfFile->addThreatTitle($node->title);
		$rtfFile->addThreatIssue($node->field_threat_category);
		foreach ($node->field_threat_message as $mid) {
			$message = node_load($mid['nid']);
			$rtfFile->addMessageTitle($message->title);
			
			if ($message->field_message_sensitivity[0]['value']  == 57) { // sensitive
				$rtfFile->addEmptyLine(1);
				$rtfFile->addMessageSensitivityDescription($message->field_message_sensitivity_messag[0]['value']);
				$rtfFile->addEmptyLine(1);
			}
			if ($message->field_message_sensitivity[0]['value'] == 58) { // very sensitive
				$rtfFile->addEmptyLine(1);
				$rtfFile->addMessageSensitivityDescription($message->field_message_sensitivity_messag[0]['value']);
				$rtfFile->addEmptyLine(1);
				$rtfFile->addMessageSensitivityQuestions($message->field_message_sensitivity_questi);
				$rtfFile->addEmptyLine(1);
			}
			$rtfFile->addMessageDescription(export2rtf_formatTextarea($message->field_message_group_mess[0]['value']));
			$rtfFile->addMessageRiskGroup($message->field_message_group_risk);
			if ($message->field_message_group_risk_comment[0]['value'] != '') {
				$rtfFile->addMessageRiskGroupComment($message->field_message_group_risk_comment[0]['value']);
			}
			$rtfFile->addMessageTargetAudience($message->field_message_audience);
			if ($message->field_message_target_comment[0]['value'] != '') {
				$rtfFile->addMessageTargetAudienceComment($message->field_message_target_comment[0]['value']);
			}
			$rtfFile->addMessageInformationType($message->field_message_info_type[0]['value']);
			$rtfFile->addMessageSensitivity($message->field_message_sensitivity[0]['value']);
			if ($message->field_message_sensitivity_causes[0]['value'] != '') {
				$rtfFile->addMessageSensitivityCauses($message->field_message_sensitivity_causes[0]['value']);
			}
			if ($message->field_message_source[0]['url'] != '') {
				$rtfFile->addMessageSource($message->field_message_source);
			}
			if ($message->field_message_url[0]['url'] != '') {
				$rtfFile->addMessageWebsite($message->field_message_url);
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

function export2rtf_formatTextarea($content) {
	return export2rtf_br2par(strip_tags($content,"<br>"));
}

function export2rtf_br2par($string){
	$return=eregi_replace('<br[[:space:]]*/?'.
    	'[[:space:]]*>','\par'."\n",$string);
	return $return;
} 

function export2rtf_br2nl($string){
	$return=eregi_replace('<br[[:space:]]*/?'.
    	'[[:space:]]*>',chr(13).chr(10),$string);
	return $return;
} 