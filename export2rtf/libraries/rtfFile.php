<?php

class RtfFile {
	
	var $content =  '';
	var $header = '{\rtf1\ansi\ansicpg1252\deff0\deflang1036\deflangfe1036{\fonttbl{\f0\fswiss\fprq2\fcharset0 Arial;}}';
	var $footer = '}';
	
	
	/**
	 * General functions
	 */
	public function getFileContent() {
		return $this->header."\n".$this->content."\n".$this->footer;
	}
	
	public function addEmptyLine($nb=1) {
		for ($i=0;$i<$nb;$i++) {
			$this->content .= '\par'."\n";
		}
	}
	
	/**
	 * Getter and setter
	 */
	public function addContent($content) {
		$this->content .= $content;
	}
	
	public function setContent($content) {
		$this->content = $content;
	}
	
	public function getContent() {
		return $this->content;
	}
	
}