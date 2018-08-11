<?php
// function to evaluate a single arithmetic expression containing string
// (may contain extra spaces in between)
// operators can be +, -, *, /
// both numbers are integers
function evaluateAritmeticExpression($expression) {
    // remove internal extra spaces
    $expression = implode('', explode(' ', $expression));

    $number1 = intval($expression);
    $operatorPostion = strlen(strval($number1));
    $operator = substr($expression, $operatorPostion, 1);
    $number2 = intval(substr($expression, $operatorPostion + 1));

    switch ($operator) {
        case '+':
            return $number1 + $number2;
        case '-':
            return $number1 - $number2;
        case '/':
            return $number1 / $number2;
        case '*':
            return $number1 * $number2;
    }
}

// test calls
echo evaluateAritmeticExpression('1+2')."\n";
echo evaluateAritmeticExpression('1 * 2')."\n";
echo evaluateAritmeticExpression('1 * 9')."\n";
echo evaluateAritmeticExpression('    119022 - 9292')."\n";
echo evaluateAritmeticExpression('19 /   2')."\n";
echo evaluateAritmeticExpression('28 y 1')."\n";
echo evaluateAritmeticExpression('19 1')."\n";