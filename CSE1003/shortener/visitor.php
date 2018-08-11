<?php

include_once("db.php");

$sql = "INSERT INTO `visitor` (`script`, `useragent`) VALUES ('" . $_SERVER['SCRIPT_NAME'] . "', '". $_SERVER['HTTP_USER_AGENT'] ."');";
mysqli_query($db, $sql);

$sql = "SELECT * FROM `visitor` WHERE `script`='".$_SERVER['SCRIPT_NAME'] . "';";
$res = mysqli_query($db, $sql);

// get the current number of visitors for this script name
global $visitor;
$visitor = mysqli_num_rows($res);