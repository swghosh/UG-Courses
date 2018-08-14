import javax.swing.JOptionPane;
/**
 * Simple program using the Swing JOptionPane class
 * to take user input of two numbers
 * from showInputDialog and print their sum
 * using showMessageDialog
 * 
 * @since 2018-08-14
 * @author Swarup Ghosh
 * @version 1.0
 * 
 * @see javax.swing.JOptionPane
 */
public class SimpleSumGUI {
    /** 
     * Main method that is to be executed at runtime, 
     * will take input from dialog
     * will show output message in dialog
     * @param args command line arguments (no arguments necessary) 
     */
    public static void main(String args[]) {
        int firstNumber, secondNumber;
        // take two user input integers
        firstNumber = Integer.parseInt(
            JOptionPane.showInputDialog(null, "First Number -> ")
        );
        secondNumber = Integer.parseInt(
            JOptionPane.showInputDialog(null, "Second Number -> ")
        );
        // show the message containing sum of the input numbers
        JOptionPane.showMessageDialog(null, "Addition of " + firstNumber + " and " + secondNumber + " is " + (firstNumber + secondNumber) + ".");
    }
}