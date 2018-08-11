<?php
// assuming that the string is read from GET
$userInputString = $_GET['string'];

// reversing string without strrev string function
$reversedString = "";
for($index = strlen($userInputString) - 1; $index >= 0; $index--) {
    $reversedString = $reversedString.$userInputString[$index];
}

// display the results
echo "reversed string: $reversedString";