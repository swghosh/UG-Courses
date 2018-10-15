package org.gdgu.swghosh.cse2016;

import java.util.Scanner;

/** Class SportsAndTest will
 * inherit Test class and implement
 * Sports interface
 *
 * @since 2018-10-16
 * @author Swarup Ghosh
 * @version 1.0
 */

public class SportsAndTest extends Test implements Sports {
    // implementation of Sports
    int sportsMarks;
    public void displaySportsMarks() {
        System.out.println("Sports Marks: " + sportsMarks);
    }
    public void inputSportsMarks() {
        Scanner in = new Scanner(System.in);
        System.out.print("Specify sports marks... (integer expected) -> ");
        sportsMarks = in.nextInt();
    }

    /**
     * Main method that is to be executed at runtime
     * for sample implementations
     * @param args no command-line arguments required explicitly
     */
    public static void main(String args[]) {
        SportsAndTest st = new SportsAndTest();
        st.putRollNo();
        st.inputMarks();
        st.inputSportsMarks();

        long roll = st.getRollNo();
        System.out.println("Student # " + roll);
        st.displayMarks();
        st.displaySportsMarks();
    }
}
