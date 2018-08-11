<?php
// user input array from GET
// $someArray = $_GET["array"];

function quickSort(&$data, $lIndex, $hIndex) {
    if($lIndex >= $hIndex) return;

    print("partitioning between $lIndex, $hIndex<br>\n");
	$pivot = partition($data, $lIndex, $hIndex);

	// sort before pivot
	print("quick sorting between, $lIndex, ".($pivot - 1)."<br>\n");
	quickSort($data, $lIndex, $pivot - 1);

    // sort after pivot
	print("quick sorting between, ".($pivot + 1).", $hIndex<br>\n");	
	quickSort($data, $pivot + 1, $hIndex);
}

function partition(&$data, $lIndex, $hIndex) {
    $aIndex = $lIndex;
	$bIndex = $hIndex - 1;
	$pivot = $data[$hIndex];

	print("original: [".implode(", ", $data)."]<br>\n");

	while($aIndex < $bIndex) {
		if($data[$aIndex] > $pivot) {
			swap($data[$aIndex], $data[$bIndex]);
			print("swap: [".implode(", ", $data)."]<br>\n");
			$bIndex--;
		}
		else {
			$aIndex++;
		}
	}

	if($data[$aIndex] > $pivot) {
		swap($data[$aIndex], $data[$hIndex]);
		print("last swap: [".implode(", ", $data)."]<br>\n");
		return $aIndex;
	}
	else {
		swap($data[$aIndex + 1], $data[$hIndex]);
		print("last swap: [".implode(", ", $data)."]<br>\n");
		return $aIndex + 1;
	}
}

function swap(&$firstVar, &$secondVar) {
    $extraVar = $firstVar;
    $firstVar = $secondVar;
    $secondVar = $extraVar;
}

$data = array(65, 27, 42, 59, 18, 94, 63, 71, 0, 99, 15, 76, 37, 16, 81);

quickSort($data, 0, count($data) - 1);

print("<br>\n<h1>SORTED ARRAY [".implode(", ", $data)."]</h1><br>\n");
