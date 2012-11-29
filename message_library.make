core = 7.x
api = 2

; [Search Api] - Tue Nov 6 22:35:57 2012 +0100
projects[search_api][type] = module
projects[search_api][download][type] = git
projects[search_api][download][url] = http://git.drupal.org/project/search_api.git
projects[search_api][download][revision] = e03ce203b92fcd1fb3787efddfacf51755a0efe1

; [Search Api Solr] - Wed Nov 7 01:23:48 2012 +0100
projects[search_api_solr][type] = module
projects[search_api_solr][download][type] = git
projects[search_api_solr][download][url] = http://git.drupal.org/project/search_api_solr.git
projects[search_api_solr][download][revision] = a829b87cb752b6016528f712978e0b96b0500d0b

; [Search Api auto-complete] - Sun Oct 28 23:48:50 2012 +0100
projects[search_api_autocomplete][type] = module
projects[search_api_autocomplete][download][type] = git
projects[search_api_autocomplete][download][url] = http://git.drupal.org/project/search_api_autocomplete.git
projects[search_api_autocomplete][download][revision] = e320907cea62636fa84cd6029ddc6146c0d68cae
; Issue #1278042
projects[search_api_autocomplete][patch][] = http://drupal.org/files/search_api_autocomplete-auto_submit-1278042-26.patch
; Issue #1835108
projects[search_api_autocomplete][patch][] = http://drupal.org/files/search_api_autocomplete_access_argument_instance.patch

; [Nodequeue] - Tue May 15 23:27:27 2012 +0200
projects[nodequeue][type] = module
projects[nodequeue][download][type] = git
projects[nodequeue][download][url] = http://git.drupal.org/project/nodequeue.git
projects[nodequeue][download][revision] = 70c0602854643f3f488a20e8f9a88942b07d14fe
; Issue #997104
projects[nodequeue][patch][] = http://drupal.org/files/nodequeue_undefined_property_997104_7.patch

; [Text list formatter]
projects[textformatter][type] = module
projects[textformatter][version] = 1.3

; Note: These modules can be download via command:
; > cd DRUPAL_ROOT
; > drush make --no-core sites/all/modules/message_library/message_library.make
