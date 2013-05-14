Note:

To prevent the timeout, add the following lines into 'settings.php'

ini_set('default_socket_timeout', 120);
$conf['http_request_timeout'] = 120;
