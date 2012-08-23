<?php

function emailaspdf_generation() {
  if (isset($_GET['nid'])) {
    $nids = array_unique(explode(',', $_GET['nid']));
    $file = iaa_pdf_export_generate_report($nids);
    if ($file) {
      echo $file;
    }
    else {
      drupal_not_found();
      exit();
    }
  }
}

function downloadaspdf_generation() {
  if (isset($_GET['nid'])) {
    $nids = array_unique(explode(',', $_GET['nid']));
    $file = iaa_pdf_export_generate_report($nids);
    if ($file) {
      file_upload($file);
    }
    else {
      drupal_not_found();
      exit();
    }
  }
}
