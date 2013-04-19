; This Drush make file is for some modules that Message Library is dependent 
; upon but are not included in the [Humanitarian Response platform][http://features.humanitarianresponse.info/distribution/humanitarianresponse_platform/releases] 
; yet, or some patches, version update on the exsiting modules that requred to 
; get the Message Library working. 

core = 7.x
api  = 2

; [Inline Entity Form]
projects[inline_entity_form][type]      = module
projects[inline_entity_form][version]   = 1.1


