<?php
// assuming that the character is read from GET
// taking first character only from string
$userInputCharacter = substr($_GET['character'], 0, 1);
if(ctype_alpha($userInputCharacter)) {
    echo "Alphabet.";
}
else if(ctype_digit($userInputCharacter)) {
    echo "Digit.";
}
else {
    echo "Special Character";
}