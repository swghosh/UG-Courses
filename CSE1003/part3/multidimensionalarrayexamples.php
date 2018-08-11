<?php
// php program to show example usage of multidimensional arrays
// program to find multiplication of two matrices

// assuming that the array is received from GET input
// $matrixOneLines = $_GET['matrixone'];
// $matrixTwoLines = $_GET['matrixtwo'];

// sample array input
$matrixOne = array(
    array(1, 3, 5, 7),
    array(2, 4, 6, 8)
);

$matrixTwo = array(
    array(1, 8),
    array(2, 7),
    array(3, 6),
    array(4, 5)
);

// make all array elements integer
for($rIndex = 0; $rIndex < count($matrixOne); $rIndex++) {
    for($cIndex = 0; $cIndex < count($matrixOne[$rIndex]); $cIndex++) {
        $matrixOne[$rIndex][$cIndex] = intval($matrixOne[$rIndex][$cIndex]);
    }
}
for($rIndex = 0; $rIndex < count($matrixTwo); $rIndex++) {
    for($cIndex = 0; $cIndex < count($matrixTwo[$rIndex]); $cIndex++) {
        $matrixTwo[$rIndex][$cIndex] = intval($matrixTwo[$rIndex][$cIndex]);
    }
}

// initialise the array that'll contain the product
$matrixProduct = array();
for($rIndex = 0; $rIndex < count($matrixTwo[0]); $rIndex++) {
    $matrixProduct[$rIndex] = array();
    for($cIndex = 0; $cIndex < count($matrixOne); $cIndex++) {
        $matrixProduct[$rIndex][$cIndex] = 0;
    }
}

// perform matrix multiplications
for($rIndex = 0; $rIndex < count($matrixOne); $rIndex++) {
    for($cIndex = 0; $cIndex < count($matrixTwo[0]); $cIndex++) {
        $partSum = 0;
        for($extraIndex = 0; $extraIndex < count($matrixOne[0]); $extraIndex++) {
            $partSum = $partSum + ($matrixOne[$rIndex][$extraIndex] * $matrixTwo[$extraIndex][$cIndex]);
        }
        $matrixProduct[$rIndex][$cIndex] = $partSum;
    }
}

for($rIndex = 0; $rIndex < count($matrixProduct); $rIndex++) {
    for($cIndex = 0; $cIndex < count($matrixProduct[$rIndex]); $cIndex++) {
        echo $matrixProduct[$rIndex][$cIndex]." ";
    }
    echo "\n";
}