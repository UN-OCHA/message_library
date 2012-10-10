Setting up for development
--------------------------

Preparation work:
=================

- Download a latest stable release from [Humanitarianresponse Platform](http://features.humanitarianresponse.info/distribution/humanitarianresponse_platform/releases)

Example code:

```
shell>
```
-　



1. Enable relevant modules


2. Prepare the taxonomies
=========================

```
drush prepopulate-ml-terms
```

3. Prepare some content for testing
===================================


4.Make sure solr is configured and working propertly
====================================================

- Make essential configuration at: `admin/config/search/search_api`

  * Solr host: localhost
  * Solr port: 8983
  *
