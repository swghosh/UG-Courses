package org.gdgu.swghosh.cse2016;

class MyThread implements Runnable {
    int trackingId;
    MyThread(int trackingId) {
        this.trackingId = trackingId;
    }
    public void run() {
        System.out.println("This line is executing inside the run() of MyThread with tracking id " + trackingId + ".");
    }
}

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

