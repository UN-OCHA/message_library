<div class="iaa_notices_warning_questions _iaa_notices_warning_questions">
  <?php if(!empty($sensitivity_message)): ?>
    <div class="message-library-sensitivity-message">
      <?php print $sensitivity_message; ?>
    </div>
  <?php endif;?>

  <?php if (!empty($question_form)): ?>
    <div class="message-library-sensitivity-questions">
      <?php print drupal_render($question_form); ?>
    </div>
  <?php endif; ?>
</div>
