<?php
// php program to copy contents of a file to another
$sourceFilePath = 'sampletextfile.txt';
$targetFilePath = 'sampletextfile_copy.txt';

// open the files
$sourceFile = fopen($sourceFilePath, 'r');
$targetFile = fopen($targetFilePath, 'w');

// get contents of source file as a string and close the file
$sourceFileContents = fread($sourceFile, filesize($sourceFilePath));
fclose($sourceFile);

// write the contents to the target file and close the file
fwrite($targetFile, $sourceFileContents);
fclose($targetFile);