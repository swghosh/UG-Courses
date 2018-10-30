package org.gdgu.swghosh.cse2016;

/**
 * Simple program to print
 * information about current thread
 *
 * @author Swarup Ghosh
 * @version 1.0
 * @since 2018-10-26
 */
public class ThreadInfo {
    public static void main(String args[]) {
        Thread current = Thread.currentThread();
        System.out.println("Information about currently running thread.");
        System.out.println(" Property \t Value \n ------------------------------------------------------");
        System.out.printf(" Name \t\t %s \n State \t\t %s \n Priority \t %d \n Group \t\t %s \n",
                current.getName(), current.getState().toString(), current.getPriority(), current.getThreadGroup().toString());
    }
}
