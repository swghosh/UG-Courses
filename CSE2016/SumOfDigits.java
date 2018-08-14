import java.util.Scanner;

/**
 * Simple program to find the sum of digits of
 * user input number
 * 
 * @author Swarup Ghosh
 * @since 2018-08-14
 * @version 1.0
 * 
 */

public class SumOfDigits {

    /**
     * Method to find the sum of digits of an integer
     * @param number integer whose sum of digits is to be found
     * @return sum of digits
     */
    public static long sumOfDigits(int number) {
        long sum = 0;
        for(; number > 0; number = number / 10) {
            sum += number % 10;
        }
        return sum;
    }

    /** 
     * Main method that is to be executed at runtime,
     * will take a single user input from stdin,
     * and print its sum of digits
     * @param args command line arguments (no arguments necessary)
     */
    public static void main(String args[]) {
        Scanner in = new Scanner(System.in);
        System.out.print("Number (integer expected) -> ");
        int userInputNumber = in.nextInt();
        System.out.println("The sum of the digits of " + userInputNumber + " is " + sumOfDigits(userInputNumber));
        in.close();
    }
}