core = 7.x
api = 2

; [Search Api auto-complete] - Fri Jan 4 00:14:44 2013 +0100
projects[search_api_autocomplete][type] = module
projects[search_api_autocomplete][download][type] = git
projects[search_api_autocomplete][download][url] = http://git.drupal.org/project/search_api_autocomplete.git
projects[search_api_autocomplete][download][revision] = ef8775f
; Add auto-submit for the autocompletion(http://drupal.org/node/1278042)
projects[search_api_autocomplete][patch][] = https://gist.github.com/kurtzhong/72bb3b9bf39772e63bed/raw/e3b0757539ffdbae2de252e6a28e7e692896534b/search_api_autocomplete-auto_submit-1278042-33.patch

; [Feeds] - Thu Jan 24 12:52:27 2013 -0800
projects[feeds][type] = module
projects[feeds][version] = 2.0-alpha7
; Drush integration(http://drupal.org/node/608408)
projects[feeds][patch][] = http://drupal.org/files/608408-feeds_drush_vd7-71.patch

; [Nodequeue] - Tue May 15 23:27:27 2012 +0200
projects[nodequeue][type] = module
projects[nodequeue][download][type] = git
projects[nodequeue][download][url] = http://git.drupal.org/project/nodequeue.git
projects[nodequeue][download][revision] = 70c0602
; Issue #997104
projects[nodequeue][patch][] = http://drupal.org/files/nodequeue_undefined_property_997104_7.patch

; [Text list formatter]
projects[textformatter][type] = module
projects[textformatter][version] = 1.3

; [Field reference delete] - Wed Sep 5 18:42:10 2012 -0400
; http://drupal.org/node/1281114
projects[field_reference_delete][type] = module
projects[field_reference_delete][download][type] = git
projects[field_reference_delete][download][url] = http://git.drupal.org/sandbox/drothstein/1775816.git
projects[field_reference_delete][download][revision] = adb0a3c

; [Link]
projects[link][type] = module
projects[link][version] = 1.1
; http://drupal.org/node/1914286
projects[link][patch][] = http://drupal.org/files/Fixed_title_value_in_link_field_update_instance_undefined-1914286-3.patch

; [Views] - Tue Feb 19 22:56:39 2013 +0100
; This dev version contains an important fix for this issue:
projects[views][type] = module
projects[views][download][type] = git
projects[views][download][url] = http://git.drupal.org/project/views.git
projects[views][download][revision] = 2aed68c

; Note: These modules can be download via command:
; > cd DRUPAL_ROOT
; > drush make --no-core sites/all/modules/message_library/message_library.make -y
