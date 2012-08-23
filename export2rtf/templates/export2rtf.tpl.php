<?php 
$messDl = t("Download as an RTF Document");
/*if (strpos($_SERVER['REQUEST_URI'],'/message-library/') !== false) {
	$messDl = t("Download as a Document");
}*/
?>
<div id="export2rtf_link" class="export2rtf_box"><a href="<?php echo export2rtf_getUrl(arg(0),arg(1)); ?>" class="export2rtf_link"><?php echo $messDl; ?></a></div>
