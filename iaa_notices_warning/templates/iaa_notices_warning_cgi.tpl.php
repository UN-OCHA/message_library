<form id="iaa_notices_warning_cgi" action="<?php echo url("cgi-message-library/accepted"); ?>">
	<input type="hidden" id="iaa_notices_warning_cgi_destination" value="<?php echo $_GET['destination']; ?>" name="destination" />
	
	<div class="iaa_notices_warning_cgi_text">
		<?php echo $node->body; ?>
	</div>
	
	<div class="iaa_notices_warning_cgi_button">
		<input type="checkbox" name="understand" id="iaa_notices_warning_cgi_understand" value="1" /> <?php echo t("I accept"); ?><br />
		<?php if (!user_is_logged_in()) : ?>
			<input type="checkbox" name="login" id="iaa_notices_warning_cgi_login" value="1" /> <?php echo t("I want to register"); ?><br />
		<?php endif; ?>
	</div>
	
	<input type="submit" value="<?php echo t("GO"); ?>" id="iaa_notices_warning_cgi_submit" />
</form>