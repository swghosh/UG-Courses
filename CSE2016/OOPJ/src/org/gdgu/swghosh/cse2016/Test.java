package org.gdgu.swghosh.cse2016;

import java.util.Scanner;

/**
 * Class Test that inherits
 * Student class
 * @since 2018-10-16
 * @author Swarup Ghosh
 * @version 1.0
 */

public class Test extends Student {
    int subject1Marks, subject2Marks;
    void inputMarks() {
        Scanner in = new Scanner(System.in);
        System.out.print("Specify marks of two subjects... (two integers expected) -> ");
        subject1Marks = in.nextInt();
        subject2Marks = in.nextInt();
    }
    void displayMarks() {
        System.out.println("Subject 1 Marks = " + subject1Marks + "; Subject 2 Marks = " + subject2Marks + ".");
    }
}
