<!DOCTYPE html>
<html>
	<head>
		<meta charset="utf8" />
        <title>Making a simple calulator.</title>
        <style>
            body {
                margin: 5%;
                font-family: monospace;
            }
            input[type=number], select {
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
        <?php
            $number1 = intval($_GET['number1']);
            $number2 = intval($_GET['number2']);
            $operation = $_GET['operation'];
            
            $result = 0;
            switch($operation) {
                case '+':
                $result = $number1 + $number2;
                break;
                case '-':
                $result = $number1 - $number2;
                break;
                case '*':
                $result = $number1 * $number2;
                break;
                case '/':
                $result = $number1 / $number2;
                break;
            }
        ?>
		<h1>Calculator</h1>
		Result: <?php echo $result; ?>
	</body>
</html>