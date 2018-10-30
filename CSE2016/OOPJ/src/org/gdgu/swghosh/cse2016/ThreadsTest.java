package org.gdgu.swghosh.cse2016;

/**
 * Simple program to implement
 * test threads by implementing
 * the Runnable interface
 *
 * @author Swarup Ghosh
 * @since 2018-10-24
 * @version 1.0
 */

class MyThread implements Runnable {
    private int trackingId;
    MyThread(int trackingId) {
        this.trackingId = trackingId;
    }

    /**
     * Overriden method run
     * Test code segment to be
     * executed by this thread
     */
    public void run() {
        System.out.println("This line is executing inside the run() of MyThread with tracking id " + trackingId + ".");
    }
}

/**
 * Class will run the implemented thread
 */

public class ThreadsTest {
    public static void main(String args[]) {
        int index = 1;
        MyThread myThread = new MyThread(index++);
        MyThread myThread2 = new MyThread(index++);
        Thread test = new Thread(myThread);
        Thread test2 = new Thread(myThread2);
        test.start();
        test2.start();
    }
}

