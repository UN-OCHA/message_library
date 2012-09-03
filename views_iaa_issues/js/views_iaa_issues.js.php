<?php
include '../views_iaa_issues.module';
$taxo = views_iaa_issues_get_taxo();

$parents = array();
$alpha = array();
$niveau = array();
$firstTaxo = 0;
$nextTaxo = 0;
foreach ($taxo as $t) {
  if ($t->depth == 0) {
    if (!$firstTaxo) $firstTaxo = $t->tid;
    $niveau[$t->tid]['name'] = t($t->name);
  }
  else if ($t->depth == 1) {
    foreach ($t->parents as $p) {
      $parents[$t->tid][] = $p;
      $niveau[$p]['child'][$t->tid] = array(
        'name' => t($t->name)
      );
    }
  }
  else if ($t->depth == 2) {
    foreach ($t->parents as $p) {
      if (sizeof($parents[$p])) {
        foreach ($parents[$p] as $p2) {
          $niveau[$p2]['child'][$p]['child'][$t->tid] = array(
            'name' => t($t->name)
          );
        }
      }
    }

    $alpha[$t->tid] = t($t->name);
  }
}
asort($alpha,SORT_STRING);

?>

<?php
$note = <<<EOT
// How is this function be invoked!
views_iaa_issues_change_apparence('.view-message-library .views-exposed-widgets #edit-issues','hierarchy');
views_iaa_issues_change_apparence('.view-message-library .views-exposed-widgets #edit-issues','alpha');

views_iaa_issues_change_apparence('#messagesearchissue #edit-issues','hierarchy');
views_iaa_issues_change_apparence('#messagesearchissue #edit-issues','alpha');

EOT;
?>

function views_iaa_issues_change_apparence(item,type) {
  <?php if (sizeof($alpha) > 0) : ?>
    var issueval = 'All';
    if ($(item).val() != null) issueval = $(item).val();
    var wrapper_content = '';
    var hierarchy_parent = '';
    var nextList = 'alpha';
    if (type == 'alpha') {
      wrapper_content += '<div class="_views_iaa_issues"><div id="_views_iaa_issues_alpha_link" class="views_iaa_alpha_link"><?php echo t("Alphabetically"); ?></div><select id="edit-issues" class="_views_iaa_issues_selectable" name="issues"><option value="All" selected="selected"><?php echo htmlentities((isset($_GET['page']) && $_GET['page'] == 'home')? t("Issues"):t("<All issues>")); ?></option>';
      <?php foreach($alpha as $val => $label) : ?>
        wrapper_content += '<option value="<?php echo $val; ?>"><?php echo t($label); ?></option>';
      <?php endforeach; ?>
      wrapper_content += '</select></div>';
      $(item+"-wrapper").html(wrapper_content);
    }
    else {
      <?php
      $prevNiveau = 0;
      foreach($niveau as $val1 => $niveau1) :
        ?>
        var wrapper_content_<?php echo $val1; ?> = '<div class="_views_iaa_issues"><div id="_views_iaa_issues_hierarchy_link" class="views_iaa_alpha_link"><?php echo t($niveau1['name']); ?></div>';
        wrapper_content_<?php echo $val1; ?> += '<select id="edit-issues" class="_views_iaa_issues_selectable" name="issues">';

        <?php
        $selectList[$val1] = '<option value="All">'.htmlentities((isset($_GET['page']) && $_GET['page'] == 'home')? t("Issues"):t("<All issues>")).'</option>';
        foreach ($niveau1['child'] as $val2 => $niveau2) {
        ?>
          if (issueval == '<?php echo $val2; ?>') {
            hierarchy_parent = '<?php echo $val1; ?>';
          }
        <?php
          $selectList[$val1] .= '<option value="'.$val2.'">'.htmlentities(t($niveau2['name'])).'</option>';
          if (sizeof($niveau2['child'])) {
            foreach ($niveau2['child'] as $val3 => $niveau3) {
              $selectList[$val1] .= '<option value="'.$val3.'"> - '.htmlentities(t($niveau3['name'])).'</option>';
          ?>
              if (issueval == '<?php echo $val3; ?>') {
                hierarchy_parent = '<?php echo $val1; ?>';
              }
          <?php }
          }
        }
        ?>
        wrapper_content_<?php echo $val1; ?> += '<?php echo $selectList[$val1] ?>';
        wrapper_content_<?php echo $val1; ?> += '</select></div>';
        if ((hierarchy_parent == '<?php echo $val1; ?>' && type == 'hierarchy' ) || type == '<?php echo $val1; ?>') {
          $(item+"-wrapper").html(wrapper_content_<?php echo $val1; ?>);
        }

        if ((hierarchy_parent == '<?php echo $prevNiveau; ?>' && type == 'hierarchy' ) || type == '<?php echo $prevNiveau; ?>') {
          nextList = '<?php echo $val1; ?>';
        }
        <?php $prevNiveau = $val1; ?>

      <?php endforeach; ?>
    }


    <?php
      $note = <<<EOT
        <select id="edit-issues" class="_views_iaa_issues_selectable" name="issues">
        </select>
EOT;
    ?>
    $('._views_iaa_issues_selectable').val(issueval);

    $("._views_iaa_issues_selectable").unbind('change').change(function(){
      <?php if (isset($_GET['page']) && $_GET['page'] == 'home') : ?>
        observeMLIssuesEvent($(this).val());
      <?php else : ?>
        $('#edit-title').val('All');
        $(this).parents("form").submit();
      return false;
      <?php endif; ?>
    });


    $('#_views_iaa_issues_hierarchy_link').unbind('click').click(function(){
      $('._views_iaa_issues_selectable').val("All");
      if (nextList == 'alpha') {
        $("body").removeClass("views_iaa_issues_hierarchy").addClass("views_iaa_issues_"+nextList);
      }
      views_iaa_issues_change_apparence(item,nextList);
      return false;
    });

    $('#_views_iaa_issues_alpha_link').unbind('click').click(function(){
      $('._views_iaa_issues_selectable').val("All");
      $("body").removeClass("views_iaa_issues_alpha").addClass("views_iaa_issues_hierarchy");
      views_iaa_issues_change_apparence(item,"<?php echo $firstTaxo; ?>");
      return false;
    });

    <?php if (isset($_GET['page']) && $_GET['page'] == 'home') : ?>
      observeMLIssuesEvent(issueval);
    <?php endif; ?>
  <?php endif; ?>

}
