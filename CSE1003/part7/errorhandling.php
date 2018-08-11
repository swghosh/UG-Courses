<?php
// require a particular file
echo "Hello world!\n\n";

// try to open a file
fopen('somefile.txt', 'r') or die("\n\nThe file somephpscript.php does not exist hence cannot be required.\n");

// if require is successful only then this will be executed
echo "The file somephpscript.php was successfully included.";