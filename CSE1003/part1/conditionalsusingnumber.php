<?php
// assuming that the number is read from GET
$userInputNumber = intval($_GET['number']);

// check number is even or odd
if($userInputNumber % 2 == 0) {
    echo "Even number";
}
else {
    echo "Odd Number";
}