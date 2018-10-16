package org.gdgu.swghosh.cse2016;

import java.util.Vector;

public class VectorTest {
    public static void main(String[] args) {
        int iterIndex = 0;
        Vector<Integer> myVector = new Vector<Integer>();
        for(iterIndex = 0; iterIndex < 10; iterIndex++) {
            Integer toAdd = new Integer(iterIndex);
            myVector.addElement(toAdd);
            System.out.println("Adding element " + toAdd.intValue());
        }
        System.out.println();
        for(Integer myNumber : myVector) {
            System.out.println("Element " + myNumber.intValue());
        }
        System.out.println();
        for(iterIndex = 0; iterIndex < 5; iterIndex++) {
            Integer forRemoval = myVector.get(iterIndex);
            System.out.println("Removing " + forRemoval.intValue());
            myVector.removeElement(forRemoval);
        }
        System.out.println();
        for(Integer myNumber : myVector) {
            System.out.println("Element " + myNumber.intValue());
        }
        System.out.println();
        for(iterIndex = 10; iterIndex < 20; iterIndex++) {
            Integer toAdd = new Integer(iterIndex);
            myVector.addElement(toAdd);
            System.out.println("Adding element " + toAdd.intValue());
        }
        System.out.println();
        for(iterIndex = 0; iterIndex < 2; iterIndex++) {
            myVector.removeElementAt(iterIndex);
        }
        System.out.println();
        for(Integer myNumber : myVector) {
            System.out.println("Element " + myNumber.intValue());
        }
    }
}
