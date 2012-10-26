<div class="message-library-sensitive-message">
  <?php if(!empty($sensitivity_message)): ?>
    <div class="sensitivity-message">
      <?php print $sensitivity_message; ?>
    </div>
  <?php endif;?>

  <?php if (!empty($question_form)): ?>
    <div class="sensitivity-questions">
      <?php print drupal_render($question_form); ?>
    </div>
  <?php endif; ?>
</div>
