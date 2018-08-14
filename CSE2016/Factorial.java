import java.util.Scanner;

/**
 * Simple program to find the factorial of
 * user input number using the recursion technique
 * 
 * @author Swarup Ghosh
 * @since 2018-08-14
 * @version 1.0
 * 
 */

class Factorial {

    /**
     * Method to find the factorial of an integer 
     * using recursion technique
     * @param number integer whose factorial is to be calculate
     * @return factorial of number
     */
    public static long factorial(int number) {
        if(number <= 1) {
            return 1;
        }
        else {
            return number * factorial(number - 1);
        }
    }
    
    /** 
     * Main method that is to be executed at runtime,
     * will take a single user input from stdin,
     * and print its factorial
     * @param args command line arguments (no arguments necessary)
     */
    public static void main(String args[]) {
        Scanner in = new Scanner(System.in);
        System.out.print("Number (integer expected) -> ");
        int userInputNumber = in.nextInt();
        System.out.println("The factorial of " + userInputNumber + " is " + factorial(userInputNumber));
        in.close();
    }
}