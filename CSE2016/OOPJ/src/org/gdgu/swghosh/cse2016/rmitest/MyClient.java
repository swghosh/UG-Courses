package org.gdgu.swghosh.cse2016.rmitest;

import java.rmi.Naming;

public class MyClient {
    public static void main(String args[]) {
        try {
            MyRemote stub = (MyRemote) Naming.lookup(MyServer.rmiUrl);
            String message = stub.getMessage();
            System.out.println(message);
        }
        catch (Exception e) {
            System.err.println(e.getMessage());
        }
    }
}
