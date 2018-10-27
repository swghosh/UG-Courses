package org.gdgu.swghosh.cse2016;

public class ThreadInfo {
    public static void main(String args[]) {
        Thread current = Thread.currentThread();
        System.out.println("Information about currently running thread.");
        System.out.println(" Property \t Value \n ------------------------------------------------------");
        System.out.printf(" Name \t\t %s \n State \t\t %s \n Priority \t %d \n Group \t\t %s \n",
                current.getName(), current.getState().toString(), current.getPriority(), current.getThreadGroup().toString());
    }
}
