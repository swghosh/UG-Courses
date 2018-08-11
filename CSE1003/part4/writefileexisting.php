<?php
// php program to write to existing file
$filePath = 'sampletextfile_copy.txt';

// open the file
$theFile = fopen($filePath, 'w');

// write a string to the opened file
fwrite($theFile, 'some sample string');
fclose($theFile);
