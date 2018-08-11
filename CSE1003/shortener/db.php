<?php
//Set database settings
$host = "sql104.epizy.com";
$username = "epiz_21990511";
$password = "tomcat2k16";
$database = "epiz_21990511_shortener";
//-----------------------------
$db = mysqli_connect($host, $username, $password, $database) or die('Database connection failed');
