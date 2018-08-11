<?php
// assuming that the number is read from GET
$userInputNumber1 = intval($_GET['number1']);
$userInputNumber2 = intval($_GET['number2']);

// create a function that performs swapping by value
function swapByValue($var1, $var2) {
    $var1 = $var2 + $var1;
    $var2 = $var1 - $var2;
    $var1 = $var1 - $var2;
}

// create a function that performs swapping by reference
function swapByReference(&$var1, &$var2) {
    $var1 = $var2 + $var1;
    $var2 = $var1 - $var2;
    $var1 = $var1 - $var2;
}

// call the requisite funtions
swapByValue($userInputNumber1, $userInputNumber2);
echo "Swapping by values: ".$userInputNumber1.",".$userInputNumber2."\n";

swapByReference($userInputNumber1, $userInputNumber2);
echo "Swapping by reference: ".$userInputNumber1.",".$userInputNumber2."\n";