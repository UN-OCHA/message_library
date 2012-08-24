<?php
/**
'help' => array('id'=>'','message'=>''),
'status' => 'show', // "show" or "hide" message
'icon' => 'both', // "controller", "message" or "both" icon button
*/
?>
<div class="iaa_inline_help">
  <?php if ($icon == 'both' || $icon == 'controller') : ?>
    <?php if ($status == 'show'): ?>
     	<div class="_iaa_inline_help_button_wrapper iaa_inline_help_button_wrapper_hide" id="<?php echo $help['id']; ?>">
             <a href="#<?php echo $help['id']; ?>-message" class="_iaa_inline_help_button_hide">
                 <span class="_iaa_inline_help_button_message"><?php echo t("hide"); ?></span>
             </a>
         </div>
     <?php else : ?>
     	<div class="_iaa_inline_help_button_wrapper iaa_inline_help_button_wrapper_show" id="<?php echo $help['id']; ?>">
             <a href="#<?php echo $help['id']; ?>-message" class="_iaa_inline_help_button_show">
                 <span class="_iaa_inline_help_button_message"><?php echo t("show"); ?></span>
             </a>
    	</div>
     <?php endif; ?>
  <?php endif; ?>

  <?php if ($icon == 'both' || $icon == 'message') : ?>
     <div class="_iaa_inline_help_wrapper" id="<?php echo $help['id']; ?>-message">
         <div class="<?php if (user_access('administer inline help')) echo '_iaa_inline_help_wrapper_message'; ?>"><?php echo t($help['message']); ?></div>
         <?php if (user_access('administer inline help')) : ?>
         <div style="display: none;" class="_iaa_inline_help_wrapper_form">
             <form method="POST" action="<?php echo url('admin/config/iaa_inline_help/edit'); ?>" class="_iaa_inline_help_form">
                 <input type="hidden" value="<?php echo $help['id']; ?>" name="id" class="_iaa_inline_help_form_id" />
                 <textarea name="message" id="iaa_inline_help_message_<?php echo $help['id']; ?>" rows="5" cols="70" class="_iaa_inline_help_form_message"><?php echo $help['message']; ?></textarea>
                 <button class="_iaa_inline_help_form_cancel"><?php echo t("Cancel"); ?></button>
                 <input type="submit" value="<?php echo t("Save"); ?>" />
             </form>
         </div>
         <?php endif; ?>
     </div>
  <?php endif; ?>
</div>