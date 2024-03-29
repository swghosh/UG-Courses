import java.util.Scanner;
/**
 * Simple program to print the addition of two numbers
 * accepted from stdin with an internal usage of a
 * non-static function
 * 
 * @since 2018-08-16
 * @version 1.0
 * @author Swarup Ghosh
 */

public class SimpleSumAgain {
    private long sum = 0l;
    /**
     * Simple non static function that
     * computes sum of two integers
     * @param firstNumber first integer
     * @param secondNumber second integer
     * @return sum of firstNumber and secondNumber
     */
    public long getSum(int firstNumber, int secondNumber) {
        sum = (long)firstNumber + (long)secondNumber;
        return sum;
    }

    /**
     * Main method that is to be executed
     * at runtime
     * @param args Command line arguments (not necessary)
     */
    public static void main(String[] args) {
        SimpleSumAgain sumHelper = new SimpleSumAgain();
        Scanner in = new Scanner(System.in);

        System.out.print("First Number (integer expected) -> ");
        int firstNumber = in.nextInt();
        System.out.print("Second Number (integer expected) -> ");
        int secondNumber = in.nextInt();
        in.close();

        long sum = sumHelper.getSum(firstNumber, secondNumber);
        System.out.println("The sum of " + firstNumber + " and " + secondNumber + " is " + sum);
    }
}