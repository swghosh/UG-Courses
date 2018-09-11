package org.gdgu.swghosh.cse2016;

import java.util.Scanner;

/**
 * Simple program to use a function to
 * swap two variables without using a
 * internal third variable
 *
 * @author Swarup Ghosh
 * @version 1.0
 * @since 2018-09-11
 *
 */

public class Swapper {
    /**
     * Swap the integers passed as arguments
     * @param n1 any integer
     * @param n2 any integer
     */
    static void swap(int n1, int n2) {
        System.out.println("Initially, numbers were: (" + n1 + ", " + n2 + ")");
        n1 = n1 + n2;
        n2 = n1 - n2;
        n1 = n1 - n2;
        System.out.println("After swapping, numbers are: (" + n1 + ", " + n2 + ")");
    }
}

class SwapperTest {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.print("Specify two numbers.. (space seperated integers expected) > ");
        int n1 = in.nextInt();
        int n2 = in.nextInt();
        Swapper.swap(n1, n2);
        in.close();
    }
}