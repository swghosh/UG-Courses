<!DOCTYPE html>
<html>
	<head>
		<meta charset="utf8" />
        <title>Grading.</title>
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
		<h1>Grade</h1>
		<b>
            <?php
                $subject = $_GET['subject'];
                $marks = $_GET['marks'];

                echo $subject.": ";
                if($marks >= 90 && $marks <= 100) {
                    echo "A+";
                }
                else if($marks >=80 && $marks < 90) {
                    echo "A";
                }
                else if($marks >=70 && $marks < 80) {
                    echo "B+";
                }
                else if($marks >=60 && $marks < 70) {
                    echo "B";
                }
                else if($marks >=50 && $marks < 60) {
                    echo "C+";
                }
                else if($marks >=40 && $marks < 50) {
                    echo "C";
                }
                else {
                    echo "F";
                }
            ?>
        </b>
	</body>
</html>