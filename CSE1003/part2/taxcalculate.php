<?php
$income = intval($_GET['income']);
$tax = 0;
$cess = 0;
if($income > 250000 && $income < 500000) {
    $tax = 0.05 * $income;
}
else if($income > 500000 && $income < 1000000) {
    $tax = 12500 + 0.2 * ($income - 500000);
}
else {
    $tax = 110000 + 0.3 * ($income - 1000000);    
}
$cess = 0.04 * $tax;
?>
<!DOCTYPE html>
<html>
	<head>
		<meta charset="utf8" />
        <title>Making a simple tax calculator!</title>
        <style>
            body {
                margin: 5%;
                font-family: monospace;
            }
            input[type=number], input[type=text], select {
                background-color: #fff;
                color: #000;
                font-size: 1.2em;
                outline: none;
                border: none;
                border-bottom: 1px dotted white;
                font-family: monospace;
                margin: 2%;
            }
        </style>
	</head>
	<body>
		<h1>Tax Calculator</h1>
		<b>
            Income: ₹<?php echo $income; ?><br>
            Tax: ₹<?php echo $tax; ?><br>
            Cess: ₹<?php echo $cess; ?><br>
        </b>
	</body>
</html>