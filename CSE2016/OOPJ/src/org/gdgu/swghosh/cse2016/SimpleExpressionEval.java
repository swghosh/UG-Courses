package org.gdgu.swghosh.cse2016;

import java.util.Scanner;

/**
 * Program to evaluate simple mathematical
 * expression that contains two numerical
 * values and an arithmetic operator in between
 *
 * @author Swarup Ghosh
 * @version 1.0
 * @since 2018-09-18
 */

public class SimpleExpressionEval {
    /**
     * Main method that is to be executed at runtime
     * @param args command line arguments [no specific arguments required here]
     */
    public static void main(String args[]) {
        Scanner in = new Scanner(System.in);
        System.out.print("Specify a simple arithmetic expression... (number, [+|-|*|/], number space seperated expected) > ");
        String userExpression = in.nextLine();

        try {
            String required[] = userExpression.split(" ");
            char operator = required[1].charAt(0);

            double n1 = Double.parseDouble(required[0]), n2 = Double.parseDouble(required[2]);

            switch (operator) {
                case '+':
                    System.out.println("Ans: " + (n1 + n2));
                    break;
                case '-':
                    System.out.println("Ans: " + (n1 - n2));
                    break;
                case '/':
                    System.out.println("Ans: " + (n1 / n2));
                    break;
                case '*':
                    System.out.println("Ans: " + (n1 * n2));
                    break;
                default:
                    System.out.println("Invalid expression, operator not valid.");
            }
        }
        // error cases,
        // in case of invalid expression
        catch(NumberFormatException nfe) {
            System.out.println("Invalid expression, numeric values not found.");
        }
        catch(ArrayIndexOutOfBoundsException ae) {
            System.out.println("Invalid expression, required number of tokens not found.");
        }
    }
}
