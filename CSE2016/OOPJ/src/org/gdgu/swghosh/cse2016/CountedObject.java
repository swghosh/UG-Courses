package org.gdgu.swghosh.cse2016;

/**
 * Class that will keep a count of
 * the number of objects that has been
 * instantiated from it.
 * Also, will print the number of objects
 * so far whenever object is created.
 *
 * @author Swarup Ghosh
 * @since 2018-10-09
 * @version 1.0
 */

public class CountedObject {
    // will keep track on number of objects
    static int objectCount = 0;

    // constructor will print number of objects so far
    CountedObject() {
        System.out.println(++objectCount + " object(s) of this class have been instantiated so far.");
    }

    public static void main(String args[]) {
        CountedObject cos[] = new CountedObject[10];
        for(int iterIndex = 0; iterIndex < 10; iterIndex++) {
            cos[iterIndex] = new CountedObject();
        }
    }
}
