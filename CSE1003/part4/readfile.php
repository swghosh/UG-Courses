<?php
// open the file and read conetents
$myFile = fopen('sampletextfile.txt', "r");
$myFileString = "";
while(!feof($myFile)) {
    $myFileChar = fread($myFile, 1);
    $myFileString = $myFileString.$myFileChar;
}
fclose($myFile);

// represent line endings in file with html line breaks
// print the file contents
echo implode("<br>", explode("\n", htmlspecialchars($myFileString)));
