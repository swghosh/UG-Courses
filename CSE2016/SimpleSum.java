class SimpleSum {
    // will add two numbers from user input
    // user input passed over command line arguments
    public static void main(String[] args) {
        int number1 = Integer.parseInt(args[0]);
        int number2 = Integer.parseInt(args[1]);
        System.out.println("Sum = " + (number1 + number2));
    }
}