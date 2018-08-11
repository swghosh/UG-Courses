<?php
// (mocking) pre-parser to take user input from stdin and pass it as GET

echo "input -> ";
$stdin = fopen("php://stdin", "r");
$userInput = "";
while(!feof($stdin)) {
    $character = fgetc($stdin);
    $userInput = $userInput.$character;
}
$lines = explode("\n", $userInput);

// assuming that other php file will use $_GET['string']/$_GET['number']/$_GET['character'] for input
$_GET = array(
    'string'=>$lines[0],
    'number1'=>$lines[0],
    'number2'=>$lines[1],
    'character'=>$lines[0]
);
fclose($stdin);

echo "--------------\n";

// require('./part1/conditionalsusingcharacter.php');
// require('./part1/conditionalsusingnumber.php');
// require('./part1/loopexamples.php');
// require('./part1/stringfunctions.php');
// require('./part1/stringmanipulation.php');
require('./part2/reversestring.php');
// require('./part2/callbyvalueandref.php');

echo "\n\n";