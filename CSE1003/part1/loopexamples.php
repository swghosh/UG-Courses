<?php
// assuming that the number is read from GET
$userInputNumber = intval($_GET['number']);

// loop to count number of prime factors of a number
$factorCounter = 0;
for($index = 1; $index <= $userInputNumber; $index++) {
    if($userInputNumber % $index == 0) {
        $factorCounter++;
    }
}

// prime when number of factors is 2
if($factorCounter == 2) {
    echo "Prime number";
}
// composite otherwise
else {
    echo "Composite Number";
}