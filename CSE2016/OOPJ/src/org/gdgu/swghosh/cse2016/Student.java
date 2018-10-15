package org.gdgu.swghosh.cse2016;

import java.util.Scanner;

/**
 * Class Student
 * to store roll number
 *
 * @since 2018-10-16
 * @author Swarup Ghosh
 * @version 1.0
 */

public class Student {
    long rollNo;
    long getRollNo() {
        return rollNo;
    }
    void putRollNo() {
        Scanner in = new Scanner(System.in);
        System.out.print("Specify roll number... (long integer expected) -> ");
        rollNo = in.nextLong();
    }
}
