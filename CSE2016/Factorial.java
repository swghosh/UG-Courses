import java.util.Scanner;

class Factorial {

    public static long factorial(int number) {
        if(number <= 1) {
            return 1;
        }
        else {
            return number * factorial(number - 1);
        }
    }

    public static void main(String args[]) {
        Scanner in = new Scanner(System.in);
        System.out.print("Number (integer expected) -> ");
        int userInputNumber = in.nextInt();
        System.out.println("The factorial of " + userInputNumber + " is " + factorial(userInputNumber));
        in.close();
    }
}