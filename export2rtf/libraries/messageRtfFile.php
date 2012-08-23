<?php
require_once drupal_get_path('module', 'export2rtf') . '/libraries/rtfFile.php';

class MessageRtfFile extends RtfFile {

  /**
   * Threat
   */
  public function addThreatTitle($title = '') {
    $this->content .= '\viewkind4\uc1\pard\nowidctlpar\b\f0\fs28 ' . $title . '\par\b0\fs20\par' . "\n";
  }

  public function addThreatIssue($issues = array()) {
    $rtf = 'Issue: ';
    $i = 0;
    foreach ($issues as $issue) {
      $taxo = taxonomy_term_load($issue['tid']);
      $rtf .= $taxo->name;
      $i++;
      if ($i < count($issues)) {
        $rtf .= ', ';
      }
    }
    $rtf .= '\par\par\par' . "\n";
    $this->content .= $rtf;
  }

  public function addThreatSeparator() {
    $this->content .= '\par---------------------------------------------------------------------------------------------------------------------------\par\par' . "\n";
  }


  /**
   * Message
   */
  public function addMessageTitle($title = '') {
    $this->content .= '\b ' . $title . '\par\b0 ' . "\n";
  }

  public function addMessageDescription($content = '') {
    $this->content .= $content . '\par' . "\n";
  }

  public function addMessageSensitivityDescription($content = '') {
    $this->content .= strtoupper(strip_tags($content)) . '\par' . "\n";
  }

  public function addMessageSensitivityQuestions($questions = array()) {
    $this->content .= '\pard\tx220\tx720\pardeftab720\li720\fi-720' . "\n" . '\ls2\ilvl0\cf0';
    foreach ($questions as $question) {
      $this->content .= ' {\listtext	\uc0\u9642 	}' . $question['value'] . '\\' . "\n";
    }
    $this->content .= '\pard\pardeftab720' . "\n" . '\b0 \cf0' . "\n";
  }

  public function addMessageRiskGroup($groups = array()) {
    $rtf = '\ul At risk group\ulnone : ';
    $i = 0;
    foreach ($groups as $group) {
      $taxo = taxonomy_term_load($group['tid']);
      $rtf .= $taxo->name;
      $i++;
      if ($i < count($groups)) {
        $rtf .= ', ';
      }
    }
    $rtf .= '\par' . "\n";
    $this->content .= $rtf;
  }

  public function addMessageRiskGroupComment($content = '') {
    $this->content .= '\ul At risk group comment\ulnone : ' . $content . '\par' . "\n";
  }

  public function addMessageTargetAudience($targets = array()) {
    $rtf = '\ul Target audience\ulnone : ';
    $i = 0;
    foreach ($targets as $target) {
      $taxo = taxonomy_term_load($target['tid']);
      $rtf .= $taxo->name;
      $i++;
      if ($i < count($targets)) {
        $rtf .= ', ';
      }
    }
    $rtf .= '\par' . "\n";
    $this->content .= $rtf;
  }

  public function addMessageTargetAudienceComment($content = '') {
    $this->content .= '\ul Target audience comment\ulnone : ' . $content . '\par' . "\n";
  }

  public function addMessageInformationType($tid = '') {
    $taxo = taxonomy_term_load($tid);
    $this->content .= '\ul Information Type\ulnone : ' . $taxo->name . '\par' . "\n";
  }

  public function addMessageSensitivity($tid = '') {
    $taxo = taxonomy_term_load($tid);
    $this->content .= '\ul Sensitivity\ulnone : ' . $taxo->name . '\par' . "\n";
  }

  public function addMessageSensitivityCauses($content = '') {
    $this->content .= '\ul Sensitivity Causes\ulnone : ' . $content . '\par' . "\n";
  }

  public function addMessageSource($sources = array()) {
    $i = 1;
    $rtf = '';
    foreach ($sources as $source) {
      $rtf .= '\ul Source ' . $i . '\ulnone : ';
      if (!empty($source['title'])) {
        $rtf .= $source['title'];
      }
      if (!empty($source['title']) && !empty($source['url'])) {
        $rtf .= ', ';
      }
      if (!empty($source['url'])) {
        $rtf .= $source['url'];
      }
      $rtf .= '\par' . "\n";
      $i++;
    }
    $this->content .= $rtf;
  }

  public function addMessageWebsite($websites = array()) {
    $i = 1;
    $rtf = '';
    foreach ($websites as $website) {
      $rtf .= '\ul Website ' . $i . '\ulnone : ';
      if (!empty($website['title'])) {
        $rtf .= $website['title'];
      }
      if (!empty($website['title']) && !empty($website['url'])) {
        $rtf .= ', ';
      }
      if (!empty($website['url'])) {
        $rtf .= $website['url'];
      }
      $rtf .= '\par' . "\n";
      $i++;
    }
    $this->content .= $rtf;
  }
}
