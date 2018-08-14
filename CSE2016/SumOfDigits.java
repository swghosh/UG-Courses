import java.util.Scanner;

class SumOfDigits {

    public static long sumOfDigits(int number) {
        long sum = 0;
        for(; number > 0; number = number / 10) {
            sum += number % 10;
        }
        return sum;
    }

    public static void main(String args[]) {
        Scanner in = new Scanner(System.in);
        System.out.print("Number (integer expected) -> ");
        int userInputNumber = in.nextInt();
        System.out.println("The sum of the digits of " + userInputNumber + " is " + sumOfDigits(userInputNumber));
        in.close();
    }
}