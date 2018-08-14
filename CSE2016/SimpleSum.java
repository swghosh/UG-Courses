/**
 * Simple program to print the addition of two numbers
 * accepted from command line input
 * 
 * @since 2018-08-07
 * @version 1.0
 * @author Swarup Ghosh
 */

public class SimpleSum {
    /** 
     * Main method that is to be executed at runtime
     * @param args command line arguments (must contain two integers) 
     */
    public static void main(String[] args) {
        // convert two arguments to integers
        int number1 = Integer.parseInt(args[0]);
        int number2 = Integer.parseInt(args[1]);
        // add the integers and print it
        System.out.println("Sum = " + (number1 + number2));
    }
}