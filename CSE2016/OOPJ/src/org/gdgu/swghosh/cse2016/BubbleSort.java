package org.gdgu.swghosh.cse2016;

import java.util.Scanner;

/**
 * Simple program to implement bubble sort
 * and perform sorting on a numeric array
 *
 * @author Swarup Ghosh
 * @since 2018-09-04
 * @version 1.0
 */

public class BubbleSort {

    /**
     * Performs bubble sort on the given array
     *
     * @param array the unsorted array
     * @return the sorted array
     */
    static int[] sort(int[] array) {
        for(int indexA = 0; indexA < array.length - 1; indexA++) {
            for(int indexB = 0; indexB < array.length - indexA - 1; indexB++) {
                if(array[indexB] > array[indexB + 1]) {
                    int temp = array[indexB];
                    array[indexB] = array[indexB + 1];
                    array[indexB + 1] = temp;
                }
            }
        }
        return array;
    }

    /**
     * Main method that is to be executed at runtime
     * @param args command line arguments (not necessary)
     */
    public static void main(String args[]) {
        /**
         * Take user input
         */
        Scanner in = new Scanner(System.in);
        System.out.print("Specify how many elements? (integer expected) > ");
        int userLength = in.nextInt();

        int numbers[] = new int[userLength];
        System.out.print("Specify " + userLength + " number of elements... (" + userLength + " integers expected) > ");
        int iterIndex;
        for(iterIndex = 0; iterIndex < userLength; iterIndex++) {
            numbers[iterIndex] = in.nextInt();
        }
        in.close();

        /**
         * Sort the array and print it
         */
        numbers = BubbleSort.sort(numbers);
        System.out.println("After sorting: ");
        for(iterIndex = 0; iterIndex < userLength; iterIndex++) {
            System.out.print(numbers[iterIndex] + " | ");
        }
    }
}
