<!DOCTYPE html>
<html lang="en">
    <head>
        <meta charset="UTF-8">
        <meta name="viewport" content="width=device-width, initial-scale=1.0">
        <title>Student Registration | GD Goenka University</title>
        <meta name="author" content="SwG Ghosh" />
        <link href="style.css" rel="stylesheet" type="text/css" />
    </head>
    <body>
        <h1>GD Goenka University</h1>
        <div>Re-registration Successful</div>
        <h2>Even Semester</h2>
        <p>
            <ol>
                <li>Name of the student: <?php echo "<u>".$_POST['name']."</u>"; ?></li>
                <li>
                    <ol type="a">
                        <li>Father's Name: <?php echo "<u>".$_POST['fathername']."</u>"; ?></li>
                        <li>Occupation of Father: <?php echo "<u>".$_POST['fatheroccupation']."</u>"; ?></li>
                        <li>Father's Mobile Number: <?php echo "<u>".$_POST['fathermobile']."</u>"; ?></li>
                        <li>Father's Email Address: <?php echo "<u>".$_POST['fatheremail']."</u>"; ?></li>
                    </ol>
                </li>
                <li>
                    <ol type="a">
                        <li>Mother's Name: <?php echo "<u>".$_POST['mothername']."</u>"; ?></li>
                        <li>Occupation of Mother: <?php echo "<u>".$_POST['motheroccupation']."</u>"; ?></li>
                        <li>Mother's Mobile Number: <?php echo "<u>".$_POST['mothermobile']."</u>"; ?></li>
                        <li>Mother's Email Address: <?php echo "<u>".$_POST['motheremail']."</u>"; ?></li>
                    </ol>
                <li>
                    Enrolment Number: <?php echo "<u>".$_POST['enrolmentnumber']."</u>"; ?>
                </li>
                <li>
                    School:
                    <?php
                    $schools = array("soe"=>"School of Engineering",
                    "som"=>"School of Management",
                    "soh"=>"School of Hospitality",
                    "sol"=>"School of Law",
                    "somas"=>"School of Medical and Allied Sciences",
                    "soc"=>"School of Communication",
                    "sohas"=>"School of Humanities and Applied Sciences",
                    "soap"=>"School of Architecture and Planning",
                    "soed"=>"School of Education",
                    "sofd"=>"School of Fashion and Design");
                    echo "<u>".$schools[$_POST['school']]."</u>";
                    ?>
                </li>
                <li>
                    Programme: <?php echo "<u>".$_POST['programme']."</u>"; ?>
                </li>
                <li>
                    Semester: <?php echo "<u>".$_POST['semester']."</u>"; ?>
                </li>
                <li>
                    Additional Information: <br><?php echo "<u>".$_POST['hostel']."</u>"; ?>, Domicile: <?php echo "<u>".$_POST['domicile']."</u>"; ?>
                </li>
                <li>
                    Course(s):
                    <table>
                        <tr> <th>Course Code</th> <th>Course Title</th> </tr>
                        <?php
                        for($i = 0; $i < count($_POST['coursecodes']); $i++) {
                            echo "<tr><td><u>".$_POST['coursecodes'][$i]."</u></td><td>".$_POST['coursenames'][$i]."</td></tr>";
                        }
                        ?>
                    </table>
                </li>
                <li>
                    Date: <?php echo "<u>".$_POST['date']."</u>"; ?>
                </li>
                <li>
                    Fee Receipts Enclosed: <?php echo "<u>".$_POST['feereceipts']."</u>"; ?>
                </li>
                <li>
                    Address: <?php echo "<u>".$_POST['address']."</u>"; ?>
                </li>
                <li>
                    Email Address: <?php echo "<u>".$_POST['emailaddress']."</u>"; ?>
                </li>
                <li>
                    Mobile Number: <?php echo "<u>".$_POST['mobile']."</u>"; ?>
                </li>
                <li>
                    Verified by Faculty: <?php echo "<u>".$_POST['facultyname']."</u>"; ?>
                </li>
            </ol>
            <input type="submit" value="Print" onclick="window.print();">
        </p>
    </body>
</html>
