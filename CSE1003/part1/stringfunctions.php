<?php
// assuming that the string is read from GET
$userInputString = $_GET['string'];

// using string functions
$uppercaseString = strtoupper($userInputString);
$lowercaseString = strtolower($userInputString);
$titlecaseString = ucwords($userInputString);
$sentencecaseString = ucfirst($userInputString);

// display the results
echo "upper case: $uppercaseString
lower case: $lowercaseString
title case: $titlecaseString
sentence case: $sentencecaseString";