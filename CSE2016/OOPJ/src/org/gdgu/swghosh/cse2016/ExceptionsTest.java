package org.gdgu.swghosh.cse2016;

/**
 * Simple program to test
 * the exceptions that are
 * raised from a specific
 * block of given code
 *
 * Catches ArithmeticException
 *
 * @author Swarup Ghosh
 * @version 1.0
 * @since 2018-09-18
 */

public class ExceptionsTest {
    public static void main(String args[]) {
        try {
            // given expressions in question
            int arr[] = {3, 0};
            int i = arr[0] / arr[1];

            System.out.println(i);
        }
        catch(ArithmeticException ae) {
            System.out.println("Invalid arithmetic. " + ae.getMessage());
        }

        try {
            // given expressions in question
            int arr[] = {};
            int i = arr[0] / arr[1];

            System.out.println(i);
        }
        catch(ArrayIndexOutOfBoundsException ae) {
            System.out.println("Array out of bounds. " + ae.getMessage());
        }
    }
}
