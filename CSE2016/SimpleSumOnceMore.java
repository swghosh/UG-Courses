import java.util.Scanner;
/**
 * Simple program to print the addition of two numbers
 * accepted from stdin with an internal usage of a
 * static function
 * 
 * @since 2018-08-16
 * @version 1.0
 * @author Swarup Ghosh
 */

public class SimpleSumOnceMore {
    public static long sum(int firstNumber, int secondNumber) {
        return (long)firstNumber + (long)secondNumber;
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        System.out.print("First Number (integer expected) -> ");
        int firstNumber = in.nextInt();
        System.out.print("Second Number (integer expected) -> ");
        int secondNumber = in.nextInt();
        in.close();

        System.out.println("The sum of " + firstNumber + " and " + secondNumber + " is " + sum(firstNumber, secondNumber));
    }
}