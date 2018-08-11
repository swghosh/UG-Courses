<?php
class Table {
    private $dataArray;
    function __construct($dataArray) {
        $this->dataArray = $dataArray;
    }
    function getTableHtmlString() {
        $html = "<table>";
        for($rIndex = 0; $rIndex < count($this->dataArray); $rIndex++) {
            $html = $html."<tr>";
            for($cIndex = 0; $cIndex < count($this->dataArray[$rIndex]); $cIndex++) {
                $html = $html."<td>".$this->dataArray[$rIndex][$cIndex]."</td>";
            }
            $html = $html."</tr>";
        }
        $html = $html."</table>";
        return $html;
    }
}

$myData = array(
    array("Name", "Number"),
    array("Swarup", "+918961517827")
);
$myTable = new Table($myData);

echo $myTable->getTableHtmlString();