<?php global $user; ?>
<div class="iaa_notices_warning_questions _iaa_notices_warning_questions">
	<div class="iaa_notices_warning_questions_message">
		<?php echo $message; ?>
	</div>
	<div class="iaa_notices_warning_questions_intitule">
		<form class="_iaa_notices_warning_questions">
			<input type="hidden" class="_iaa_notices_warning_questions_uid" value="<?php echo $user->uid; ?>" />
			<input type="hidden" class="_iaa_notices_warning_questions_id" value="<?php echo $nid; ?>" />
			<?php foreach ($questions as $question) : ?>
				<input type="checkbox" class="_mandatory" /> <?php echo $question['value']; ?><br />
			<?php endforeach; ?>
			<input type="submit" value="<?php echo t("I understand"); ?>" />
		</form>
	</div>
</div>