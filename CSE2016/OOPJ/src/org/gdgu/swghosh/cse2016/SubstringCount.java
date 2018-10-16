package org.gdgu.swghosh.cse2016;

import java.util.Scanner;
import java.util.regex.Pattern;

public class SubstringCount {
    public static void main(String args[]) {
        Scanner in = new Scanner(System.in);
        System.out.print("Haystack (string to search in) -> ");
        String haystack = in.nextLine();
        System.out.print("Needle (string to search for) -> ");
        String needle = in.nextLine();
        int count = haystack.split(
                Pattern.quote(needle)
        ).length - 1;
        System.out.println("Needle found " + count + " number of times.");
    }
}
