api  = 2
core = 7.x

; Migrate
projects[migrate][type]    = module
projects[migrate][version] = 2.x-dev

; Migrate Extras
projects[migrate_extras][type]    = module
projects[migrate_extras][version] = 2.x-dev

; 'Drupal-to-Drupal data migration' is still a sandbox project yet
projects[migrate_d2d][type] = module
projects[migrate_d2d][directory_name]   = drupal_to_drupal_data_migration
projects[migrate_d2d][download][type]   = git
projects[migrate_d2d][download][url]    = http://git.drupal.org/sandbox/mikeryan/1234554.git
