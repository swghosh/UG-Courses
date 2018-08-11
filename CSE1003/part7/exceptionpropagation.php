<?php
function getArrayValue($array, $key) {
	$keyTypeNumeric = true;
	// 	check if key is numeric or not
	if($key !== 0 && intval($key) === 0) $keyTypeNumeric = false;
	if(!isset($array[$key])) {
		// 		if no such key exists
		if($keyTypeNumeric) throw new OutOfRangeException('No such array key (out of bounds).');
		else throw new OutOfBoundsException('No such array index (out of range).');
	}
	return $array[$key];
}

$array1 = array(17, 28, 39, 40, 51);
$array2 = array('a'=>14, 'b'=>25);

try {
	echo getArrayValue($array1, 0)."\n";
	// 	will output 17
	echo getArrayValue($array1, 5)."\n";
	// 	will cause exception to occur
}
catch(OutOfRangeException $rex) {
	echo $rex->getMessage()."\n";
}
try {
	echo getArrayValue($array2, 'a')."\n";
	// 	will output 14
	echo getArrayValue($array1, 'z')."\n";
	// 	will cause exception to occur
}
catch(OutOfBoundsException $iex) {
	echo $iex->getMessage()."\n";
}
