# Message Library

## 1. Relevant Content types

### 1.1 Message (message)


No |Field Name | Field type | Note
---|----------------|-------------|-----
1|Information Requirement(title)   | |
2|Message 								| Long text | It's like **body**
3|At risk group						| Term reference | Referencing Vocabulary - *At Risk Groups*
4|At risk group comment | text |
5|Target audience | Term reference | Referencing Vocabulary - *Target Audience*
6|Target audience comment | text |
7|Information type | Term reference | Referencing Vocabulary - *Information Type*
8|Sensitivity  | Term reference | Referencing Vocabulary - *Sensitivity*
9|Sensitivity Causes| Long text | Only used when the sensitivity is marked as *Sensitive* or *Very sensitive*
10|Threat | Term reference | Referencing node of content type - *Threat*
11|Examples of Communication around this issue | File | Support formats: *jpg, pdf, png, gif, doc, docx, mp3, mp4, avi, flv* cardinality - unlimited
12|Websites| Link | cardinality - unlimited
13|Alert questions|text| Only used when the sensitivity is marked as *Very sensitive*
14|Source|Link|cardinality - unlimited
15|Warning/Alert message|Long text| Only used when the sensitivity is marked as *Sensitive* or *Very sensitive*


### 1.2 Threat (threat)

No |Field Name | Field type | Note
-----------------------|----------------|-------------|-----
1|Hazard  | Term reference | Referencing Vocabulary - *Hazard* ; cardinality - unlimited
2|Issue   | Term reference | Referencing Vocabulary - *Issues* ; cardinality - unlimited
3|Message | Node reference | Referencing node of content type - *Message*
4|Notification message | Text |
5|Sector | Term reference | Referencing Vocabulary - *Sector* ; cardinality - unlimited


## 2. Relevant vocabularies

### 2.1 Hazard ( *original vid-11* )

~~~
+------+------------+
| tid  | name       |
+------+------------+
| 2313 | Cyclone    |
| 1420 | Earthquake |
| 2303 | Flood      |
| 1421 | Tsunami    |
+------+------------+
~~~

### 2.2 Issues ( *original vid-12* )

This is used as a exposed filter, to refine the .

~~~
+------+-----------------------------------------------+
| tid  | name                                          |
+------+-----------------------------------------------+
| 1408 | Sexual and Reproductive Health                |
| 1418 | Injury                                        |
| 1423 | Child Protection                              |
| 1425 | Protection                                    |
| 1429 | Mine Risk Education (MRE)                     |
| 1430 | Gender based violence                         |
| 1432 | Food Security                                 |
| 1438 | Educ - Access & Learning Environment          |
| 1444 | Educ - Teachers & Other Educational Personnel |
| 1445 | Educ - Teaching & Learning Environment        |
| 1381 | Management of malnutrition                    |
| 1396 | Infant and young child feeding                |
| 1397 | Nutrition - HIV transmission                  |
| 1398 | Prevention of diarrhoea                       |
| 1399 | Water                                         |
| 1401 | Sanitation                                    |
| 1402 | Hygiene                                       |
| 1403 | Communicable Diseases                         |
| 1404 | Child Health                                  |
| 1741 | Mental health and psychosocial support        |
| 1793 | Sectors                                       |
| 1795 | Health                                        |
| 1796 | WASH                                          |
| 1797 | Protection                                    |
| 1864 | Education                                     |
| 1868 | Food Security                                 |
| 1867 | Nutrition                                     |
| 2337 | Camp Coordination Camp Management             |
| 2338 | CCCM - Natural disaster                       |
+------+-----------------------------------------------+
~~~

### 2.3 Sector ( *original vid-3* )

~~~
+------+---------------+
| tid  | name          |
+------+---------------+
| 1439 | Education     |
| 1433 | Food Security |
| 1405 | Health        |
| 1382 | Nutrition     |
| 1424 | Protection    |
| 1400 | WASH          |
+------+---------------+
~~~

### 2.4 At risk group ( *original vid-2* )

~~~
+------+------------------------------------------+
| tid  | name                                     |
+------+------------------------------------------+
| 1436 | Adolescents                              |
| 1383 | Affected population                      |
| 1387 | Babies                                   |
| 2341 | Camp population                          |
| 1377 | Children                                 |
| 2062 | Children                                 |
| 2022 | Children Under 5                         |
| 1426 | Disabled children                        |
| 1395 | Families who have lost primary caregiver |
| 1390 | HIV+ people                              |
| 1416 | HIV+ pregnant women                      |
| 1379 | Lactating women                          |
| 1414 | Men                                      |
| 1417 | Mothers                                  |
| 1385 | Older people                             |
| 1434 | Pastoralists                             |
| 2340 | People with disabilities                 |
| 1392 | Post partum women (up to 6 weeks)        |
| 1394 | Pregnant women                           |
| 1406 | Sexually active groups                   |
| 1437 | Teachers                                 |
| 1431 | Vulnerable groups                        |
| 1411 | Women                                    |
+------+------------------------------------------+
~~~

### 2.5 Target audience ( *original vid-1* )

~~~
+------+-----------------------------------------------------------------------+--------+
| tid  | name                                                                  | weight |
+------+-----------------------------------------------------------------------+--------+
| 1384 | Mothers/fathers/other primary caregivers                              |      0 |
| 1386 | Primary caregivers                                                    |      0 |
| 1388 | Lactating women                                                       |      0 |
| 1389 | Husbands                                                              |      0 |
| 1391 | Lactating women/husbands/other primary caregivers of breastfed babies |      0 |
| 1393 | Pregnant women                                                        |      0 |
| 1407 | Affected adult population                                             |      0 |
| 1409 | Sexually active males                                                 |      0 |
| 1410 | Women                                                                 |      0 |
| 1415 | HIV+ people                                                           |      0 |
| 1419 | Children                                                              |      0 |
| 1435 | Pastoralists                                                          |      0 |
| 1440 | Teachers                                                              |      0 |
| 1441 | Community leaders                                                     |      0 |
| 1442 | Educational authorities                                               |      0 |
| 2018 | All target audiences                                                  |      0 |
| 2339 | Camp population                                                       |      0 |
+------+-----------------------------------------------------------------------+--------+
~~~

### 2.6 Information Type ( *original vid-14* )

~~~
+-----+-----------+
| tid | name      |
+-----+-----------+
|  37 | Service   |
|  38 | Alert     |
|  39 | Awareness |
| 668 | Self-care |
+-----+-----------+
~~~

### 2.7 Sensitivity ( *original vid-17* )

~~~
+-----+----------------+
| tid | name           |
+-----+----------------+
|  56 | Not sensitive  |
|  57 | Sensitive      |
|  58 | Very sensitive |
+-----+----------------+
~~~

## 3. Relevant views

### 3.1 message_library

#### 3.1.1 Display - Search Page

This is a content view, for content type *Message*. Page path is : `/message-library`

**(1) Example output of a table row from the result:**

~~~
<tr class="odd views-row-first">
    <!-- #Column 1 - Issue -->
    <td class="views-field views-field-field-threat-category-value">
        <div class="field-item field-item-0"><span class="search_highlight">Child Protection</span></div>
        <div class="field-item field-item-1">Educ - Access &amp; Learning Environment</div>
    </td>
    <!-- #Column 2 - Threat -->
    <td class="views-field views-field-field-message-threat-nid">
        <a href="/message-library/children-stop-going-school" class="views-processed">Children stop going to school</a>
    </td>
    <!-- #Column 3 - Information requirement -->
    <td class="views-field views-field-title-1">
        <a href="http://infoasaidorg6_dev.local/message-library/children-stop-going-school#3802" class="views-processed">When children do not attend school</a>
    </td>
    <!-- #Column 4 - Message -->
    <td class="views-field views-field-field-message-group-mess-value">
        All children can benefit from safe, relevant and quality education. Please support children in attending school.
        However, if a child is not attending school it is important that you make sure that they are safe and accounted for. [...]
    </td>
    <!-- #Column 5 - Resources -->
    <td class="views-field views-field-phpcode">
    </td>
</tr>
~~~

**(2) Several links here:**

- Clicking on the result in column threat will to the path like
  > `/message-library/children-stop-going-school`
- Clicking on a item in the column **Information requirment** will redirect to a absoluteoslute path like
  > `http://infoasaidorg6_dev.local/message-library/children-stop-going-school#3802`


**(3) Exposed filters on this display:**

- Search field
- Hazard （*Threat* field）
- Issues (*Threat* field)
- Threat（*Threat* field）
- At risk group (*Message* field)
- Target audience (*Message* field)


#### 3.1.2 Display - Edit Page
This is also a content view, for content type *Message*. Page path is : `/edit-message-library`
Seems like this display provides a place to edit the title of *Message* nodes. The fields *At risk group* and *Target audience* also should be editable, but it's not working on my local. The exposed filters seems to be the same as the previous display.

#### 3.1.3 Display - Bundle Page
This is almost the same as the first display. The page path is `/message-library-bundle`

#### 3.1.4 Display - Feed
This is a content view, for content type *Threat*. Page path is : `/message-library/export`

This view take a nodequeue's name as an argument.

~~~
SELECT
    DISTINCT(node.nid) AS nid,
    node.type AS node_type,
    node.vid AS node_vid,
    node.title AS node_title,
    node_data_field_message_group_mess.field_message_group_mess_value AS node_data_field_message_group_mess_field_message_group_mess_value,
    node_data_field_message_group_mess.field_message_sensitivity_value AS node_data_field_message_group_mess_field_message_sensitivity_value,
    node_data_field_message_group_mess.field_message_sensitivity_causes_value AS node_data_field_message_group_mess_field_message_sensitivity_causes_value,
    node_data_field_message_group_mess.field_message_sensitivity_causes_format AS node_data_field_message_group_mess_field_message_sensitivity_causes_format,
    node.nid AS node_nid
FROM node node
LEFT JOIN content_field_message_threat node_data_field_message_threat
    ON node.vid = node_data_field_message_threat.vid
INNER JOIN node node_node_data_field_message_threat
    ON node_data_field_message_threat.field_message_threat_nid = node_node_data_field_message_threat.nid
LEFT JOIN nodequeue_nodes nodequeue_nodes_node
    ON node.nid = nodequeue_nodes_node.nid
LEFT JOIN ( content_field_threat_message node_data_field_threat_message INNER JOIN node node_node_data_field_threat_message ON node_data_field_threat_message.vid = node_node_data_field_threat_message.vid )
    ON node.nid = node_data_field_threat_message.field_threat_message_nid
LEFT JOIN nodequeue_queue nodequeue_nodes_node__nodequeue_queue
    ON nodequeue_nodes_node.qid = nodequeue_nodes_node__nodequeue_queue.qid
LEFT JOIN content_type_message node_data_field_message_group_mess
    ON node.vid = node_data_field_message_group_mess.vid
WHERE
    (node.type in ('threat'))  AND
    (node.status = 1) AND
    (nodequeue_nodes_node__nodequeue_queue.name = 'flood')
GROUP BY nid
ORDER BY node_nid ASC
~~~

I fail to get results from this display using the nodequeue's names: 'test_bundle', 'flood', 'cyclone', and 'tsunami'. Don't know where is going wrong.

## 4. Relevant modules

### 4.1 Search Hightlight(search_hightlight)

This module is responsible for:

- Highlight the search keyword.
- Allow backward/forward navigation between the highlight messages


### 4.2 Message Library Subscription (message_library_subscription)
Provides a block 'My Saved Searches', allow the user to save the current search, and allow quick visiting, subscription, removing  on each  saved item.

### 4.3 IAA Notices Warning (iaa_notices_warning)
This module add two tables 'iaa_notices_warning' to the database.

A screenshot of the `iaa_notices_warning`:
~~~
+----+-----+-----------+
| id | uid | messageid |
+----+-----+-----------+
|  1 |   1 |      3513 |
|  2 |  44 |      3584 |
+----+-----+-----------+
~~~

A screenshot of the table `iaa_notices_warning_cgi`:

~~~
+----+-----+----------+
| id | uid | accepted |
+----+-----+----------+
|  1 |   1 |        1 |
|  2 |  44 |        1 |
|  3 |  49 |        1 |
|  4 |  53 |        1 |
|  5 |  55 |        1 |
|  6 |  57 |        1 |
|  7 |  62 |        1 |
|  8 |  56 |        1 |
|  9 |  64 |        1 |
| 10 |  68 |        1 |
| 11 |  71 |        1 |
| 12 |  78 |        1 |
| 13 |  95 |        1 |
+----+-----+----------+
~~~

This module is responsible for:

- decide whether to redirect to the page `cgi-message-library` by checking table `iaa_notices_warning_cgi` or the session.
- When come to page `iaa_notices_warning_cgi`, it will display a form. This is the template used:

~~~
<form id="iaa_notices_warning_cgi" action="<?php echo url("cgi-message-library/accepted"); ?>">
  <input type="hidden" id="iaa_notices_warning_cgi_destination" value="<?php echo $_GET['destination']; ?>" name="destination" />
  <div class="iaa_notices_warning_cgi_text">
      <!--This node is a page node, nid is 6709 -->
    <?php echo $node->body; ?>
  </div>
  <div class="iaa_notices_warning_cgi_button">
    <input type="checkbox" name="understand" id="iaa_notices_warning_cgi_understand" value="1" /> <?php echo t("I accept"); ?><br />
    <?php if (!user_is_logged_in()) : ?>
      <input type="checkbox" name="login" id="iaa_notices_warning_cgi_login" value="1" /> <?php echo t("I want to register"); ?><br />
    <?php endif; ?>
  </div>
  <input type="submit" value="<?php echo t("GO"); ?>" id="iaa_notices_warning_cgi_submit" />
</form>
~~~

Then some AHAH actions are bind on the form, on the checkboxes, and the submit button. When the user just accept the terms and don't want to register, then (handled by router `cgi-message-library/accepted`) a session *iaa_notices_warning_cgi* is added for guest or a new record is added to the table `iaa_notices_warning_cgi` for logged in users.
If the user choose *I want to register*, then a popup form is displayed. This is the template:

~~~
<div id="iaa_notices_warning_form_login">
  <div class="">
    <?php
      echo drupal_get_form('iaa_notices_warning_login_block');
    ?>
  </div>
  <div class="">
    <button class="_iaa_notices_warning_form_login_no_account"><?php echo t("I haven't an account"); ?></button>
  </div>
</div>
~~~

This form has a `user_login_block` form embeded.

-　It provides some blocks on message sensitivity, which is embed in to by the node
  template.

  * For `sensitive` message, it's using this template

  ~~~
  <div class="iaa_notices_warning_sensitive">
    <?php echo $message; ?>
  </div>
  ~~~

  An example for this can be found at [here](http://www.infoasaid.org/message-library/explosive-remnants-war)

  * For `very sensitive` message, it's using this template:
  ~~~
  <?php global $user; ?>
  <div class="iaa_notices_warning_questions _iaa_notices_warning_questions">
    <div class="iaa_notices_warning_questions_message">
      <?php echo $message; ?>
    </div>
    <div class="iaa_notices_warning_questions_intitule">
      <form class="_iaa_notices_warning_questions">
        <input type="hidden" class="_iaa_notices_warning_questions_uid" value="<?php echo $user->uid; ?>" />
        <input type="hidden" class="_iaa_notices_warning_questions_id" value="<?php echo $nid; ?>" />
        <?php foreach ($questions as $question) : ?>
          <input type="checkbox" class="_mandatory" /> <?php echo $question['value']; ?><br />
        <?php endforeach; ?>
        <input type="submit" value="<?php echo t("I understand"); ?>" />
      </form>
    </div>
  </div>
  ~~~

  An example for this can be found at [here](http://www.infoasaid.org/message-library/gbv)


### 4.4 Export to RTF(export2rtf)

This is responsible for the link *Download as an RTF Document* below the Message Library.

- How is the link generated and added?

First in the views *message_library*,  the following code is used to generate the footer

~~~
    // intentionally using a silly var name to avoid scoping issues
    $my_view = views_get_current_view();
    //echo "<pre>";print_r($my_view);echo "</pre>";
    // again, avoiding scoping issues
    $my_total = $my_view->total_rows;
    // too lazy to do proper t('') with placeholder
    print '<p><strong>' . $my_total . '</strong> records matched criteria.</p>';

    $arrayThreat  = array();
    $arrayMessage = array();
    $listResult = db_query($my_view->build_info['query'], $my_view->build_info['query_args']);

    while($res = db_fetch_object($listResult)) {
      $arrayThreat[]  = $res->node_node_data_field_message_threat_nid;
      $arrayMessage[] = $res->nid;;
    }

    $arrayThreat  = array_unique($arrayThreat);
    $arrayMessage = array_unique($arrayMessage);

    $listThreat = "";
    foreach ($arrayThreat as $threat) {
      $listThreat .= $threat.',';
    }
    echo '<input type="hidden" id="search_list_threat" value="'.substr($listThreat,0,-1).'" />';

    $listMessage = "";
    foreach ($arrayMessage as $mess) {
      $listMessage .= $mess.',';
    }
    echo '<input type="hidden" id="search_list_mess" value="'.substr($listMessage,0,-1).'" />';
?>
~~~

As a result, the generated markup is like this:

~~~
<div class="view-footer">
    <p><strong>364</strong> records matched criteria.</p>
    <input type="hidden" id="search_list_threat" value="3514,9710,3803,3775,3483,3782,3575,3530,3722,3726,3728,3724,11070,3683,3445,3786,3630,6228,3744,3615,3800,3583,3790,3535,9645,3442,3586,3424,3415,3680,3738,3475,3667,3805,3792,3798,3740,3757,3521,3389,3491,3541,3419,3691,3784,3769,3468,3608,10941,10943,3671,3766,9713,3642,6214,3407,3559,3571,3796,3794,3599,3427,3435,3567,3779,3772,3455,3409,3550">
    <input type="hidden" id="search_list_mess" value="3513,3515,3516,3517,3518,3519,9709,10871,9711,3802,3774,3776,3777,3482,3484,3485,3706,3486,3487,3488,3489,3781,3574,3576,3577,3578,3579,3580,3581,3529,3531,3532,3533,3721,3725,3727,3723,11067,11068,11069,11071,11072,11073,11074,11075,11076,11077,11078,11079,11080,11081,11082,3682,3684,3685,3686,3687,3444,3446,3447,3448,3449,3450,3451,3452,3453,3505,3506,3507,3508,3509,3510,3785,3787,3788,3629,3632,3633,3634,3635,3636,3638,3639,6230,3692,3695,6232,6231,3696,3743,3745,3746,3747,3748,3749,3750,3751,3752,3753,3754,3755,3614,3616,6204,3617,3618,3619,3637,6205,3620,3621,3622,3623,3624,3625,3678,3626,3627,3628,3799,3582,3584,3705,3707,3709,3710,3711,3712,3713,3715,3716,3717,3718,3801,3806,3789,3534,3536,3537,3538,3539,9644,3441,3443,3585,3587,3588,3589,3590,3591,3592,3593,3594,3595,3596,3597,3423,3425,3414,3416,3417,3679,3681,3737,3474,3476,3477,3478,3479,6211,3480,3481,3666,3668,3669,3804,3791,3797,3739,3756,3758,3759,3760,3761,3762,3763,3764,3520,3522,3523,3524,3525,3526,3527,3528,3673,3388,3390,3391,3392,3393,3394,3395,3396,3397,3398,3399,3400,3401,3402,3403,3404,3405,3421,3422,3490,3492,3493,3494,3495,3496,3497,3498,3499,3500,3501,3502,3503,3504,3540,3542,3543,3544,3545,3546,3547,3548,3418,3420,3693,3694,3697,3690,3698,3699,3700,3701,3702,3703,3704,3783,3768,3770,3467,3469,3470,3471,3472,3473,3607,10940,3672,3609,3611,10942,6206,3674,3765,3767,9712,9714,3641,6213,3647,6215,3648,6216,3649,6217,6218,3650,6219,3651,3652,6227,3653,6222,3654,6223,3655,3656,3657,3658,3659,3660,3663,6220,6221,3406,3439,3440,3558,3560,3561,3562,3563,3564,3565,3570,3572,3573,3795,3793,3598,3600,3601,3602,3603,3604,3605,3606,3426,3428,3429,3430,3431,3432,3433,3434,3436,3437,3438,3566,3568,3569,3778,3780,3771,3773,3454,3456,3457,3458,3459,3460,3461,3462,3463,3464,3465,3466,3408,3410,3411,3412,3413,3549,3551,3552,3553,3554,3555,3556,3557">
</div>
~~~

Then the link is controlled by the code:
~~~
// Make sure thre is the message library
if ($('.view-message-library .views-exposed-widgets').size()>0){
    // Make sure there are nodes
    if ($('.view-message-library #search_list_threat').size() > 0) {
        // SHow the 'Download as an RTF Document' link
        $('.block-export2rtf').show();
        // Generate the right link
        $('.export2rtf_link').attr("href",'/export2rtf/'+$("#search_list_threat").val());
    }
    else {
        $('.block-export2rtf').hide();
    }
}
~~~



### 4.5 Download/Email Links(download_email)

The links *Download as a PDF* and *Email as an RTF* below the search result of Message Library are provide by this module.
The template is like the following:

~~~~
<div id="download_email_download_link" class="download_email_download_box">
    <a href="<?php echo download_email_getDownloadUrl(arg(0),arg(1)); ?>" class="download_email_download_link">
        <?php echo t("Download as a PDF"); ?>
    </a>
</div>
<div id="download_email_email_rtf_link" class="download_email_email_rtf_box">
    <a href="<?php echo download_email_getRTFEmailUrl(arg(0),arg(1)); ?>" class="download_email_email_rtf_link">
        <?php echo t("Email as an RTF"); ?>
    </a>
</div>
~~~~

The generated href part is like the following:

- For the Link 'Download as a PDF'

~~~
"/downloadaspdf?nid=3514,9710,3803,3775,3483,3782,3575,3530,3722,3726,3728,3724,11070,3683,3445,3786,3630,6228,3744,3615,3800,3583,3790,3535,9645,3442,3586,3424,3415,3680,3738,3475,3667,3805,3792,3798,3740,3757,3521,3389,3491,3541,3419,3691,3784,3769,3468,3608,10941,10943,3671,3766,9713,3642,6214,3407,3559,3571,3796,3794,3599,3427,3435,3567,3779,3772,3455,3409,3550"
~~~

- For the anchor 'Email as an RTF'

~~~
"mailto:?body=Download the RTF from the server at the URL : http://infoasaidorg6_dev.local/export2rtf/3514,9710,3803,3775,3483,3782,3575,3530,3722,3726,3728,3724,11070,3683,3445,3786,3630,6228,3744,3615,3800,3583,3790,3535,9645,3442,3586,3424,3415,3680,3738,3475,3667,3805,3792,3798,3740,3757,3521,3389,3491,3541,3419,3691,3784,3769,3468,3608,10941,10943,3671,3766,9713,3642,6214,3407,3559,3571,3796,3794,3599,3427,3435,3567,3779,3772,3455,3409,3550"
~~~

The value of element `#search_list_threat` is used to generate the hrefs of the links, which is the footer content of the view - `message_library`.

This module depends on the *artools*. It's not a contribute module hosted on drupal.org. It would be better if this module's comment is written in English, not in French.


### 4.6 PDF export(iaa_pdf_export)

This seems involves lot of modules and lots of work.But essentially, the PDF was generated using a utility named [*wkhtmltopdf*](http://code.google.com/p/wkhtmltopdf/).

This module relies on the 'artools_pdf' module.

### 4.7 IAA Inline Help (iaa_inline_help)
This allows the admin to edit the help message in the message library.

### 4.8 VIEWS IAA Issues (views_iaa_issues)


### 4.9 Prev/Next IAA (prev_next_iaa)
Table `prev_next_iaa_node` was installed by this module.


### 4.10 Prev/Next IAA for Views (prev_next_iaa_views)


## 5. Notes

Qutoted from [this discussion](http://atrium.wiredcraft.com/internews/node/4681#comment-6286) in atrium:

> We are dropping the Message Bundle features for now. This means that we won't
use the Hazard taxonomy anymore (I'll hide it in the message forms and body
via CSS on the live site) and that they will disappear from the Message Library
home page as well (again via CSS).

> The field name 'hazard' needs to be removed in section 1.2. (as per our discussion today) and in section 2.1 [JM: I will hide the field myself on the live site as its not in the scope of Wiredcraft's mission. WiredCraft please implement the field but hide it via CSS on the slave instance]
> In section 2.2 Issues, please remove 2338 - CCCM Natural disaster [JM: This should be done by you on the live site as it is Content related, I can show you how to do it in Loic's absence]
> In section 2.3 Sector, CCCM needs to be added [JM: Same as this is content]
> IN section 3.1.1 (3) 'hazard' needs to be removed [JM: I'm taking care of this on the live site. WiredCraft, same thing, please implement it but hide it]
> IN section 3.1.3 - 'Bundle page' needs to be removed [JM: Again, I'll deal with the live site and WireCraft can implement but hide]
> In section 4.1 Search highlight - the cluster person for Mine risk education told me that when he does a search for Mine risk education messages, several WASH messages are listed because the word 'risk' is in the message. Can anything be done about this? [JM: Miranda, this is a question for Loic].
> Here are my comments. In general the main components of the Message Library have been captured but there are a number of customization that didn't make it into the list which I'll try to list here:

> Please note that the Disclaimer feature (and its editable text) are also part of the Message Library : http://www.infoasaid.org/cgi-message-library?destination=%2Fmessage-library
> Please note that there are PDF generation and RTF generation features (Download and email) that allow to export the whole library, current searches or individual messages.
> Please note there is a feature allowing administrators to change inline the text of the Help that is displayed when clicking on the blue I icons.
> Please note that in the Advanced search, there is a toggle link "Sectors/Alphabetically" that allows to display different taxonomies.
> Please note that in search results there is a feature that not only highlights results for the current search but also allow to browse through next and previous results inside the same Threat or across different Threats (you can test by searching for "Injury" clicking on the first result, then click on the link "Next highlight message" repeatedly which will then take you to another Threat once all the Messages that contain the search term on the same page have been viewed - with an anchor.
> Please note that some messages have a sensitivity field which triggers a custom behavior that you can see here (http://www.infoasaid.org/message-library/explosive-remnants-war on "Advice on prevention for young children" for a message marked as Sensitive, or here http://www.infoasaid.org/message-library/gbv on "Where to go for advice / treatment for rape" for very sensitive messages).
> Given the absence of documentation it could be that there are other aspects that I'm missing but to make sure everything is covered thoroughly I recommend going through:

> the custom modules that are in sites/infoasaid.org/modules/infoasaid/ to check what is related to the Message Library.
> the original request for quotation which described the featured that were developed during Lot 1 of our Phase II beta development phase.





