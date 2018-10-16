package org.gdgu.swghosh.cse2016;

import java.util.Scanner;

public class SubstringSearch {
    public static void main(String args[]) {
        Scanner in = new Scanner(System.in);
        in.useDelimiter("\n");
        System.out.print("Haystack (string to search in) -> ");
        String haystack = in.next();
        System.out.print("Needle (string to search for) -> ");
        String needle = in.next();
        System.out.println("Needle found at index " + haystack.indexOf(needle) + ".");
    }
}
