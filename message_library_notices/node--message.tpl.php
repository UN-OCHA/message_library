<?php
/**
 * @file
 * Custom theme implementation to display a node of type - 'Message'
 *
 * The origial template has:
 * - An anchor with the message node nid, so it can't quickly located under a
 *   threat.
 * - A class 'message_highlight' on the outter div, so that any hightlighting
 *   css style can be easily applied
 * - Provide a edit link if the user has access for it, this seems not necessary
 *   in D7
 * - Sensitivity warning block
 * - Search highlight links
 */
?>
<a name="<?php print $node->nid ?>"></a>
<div id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>
  <?php if (!$page): ?>
    <?php print render($title_prefix); ?>
    <h2<?php print $title_attributes; ?>><?php print $title; ?></h2>
    <?php print render($title_suffix); ?>

    <div class="clearfix">
      <?php print $user_picture; ?>

      <?php if (!empty($ml_sensitivity_questions)): ?>
        <?php print $ml_sensitivity_questions; ?>
      <?php endif; ?>


      <div class="content"<?php print $content_attributes; ?>>
        <?php
          hide($content['links']);
          print render($content);
        ?>
      </div>
			<?php print render($prev_next_links); ?>
    </div>
  <?php endif; ?>
</div>
