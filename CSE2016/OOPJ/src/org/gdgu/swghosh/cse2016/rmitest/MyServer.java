package org.gdgu.swghosh.cse2016.rmitest;

import java.rmi.Naming;
import java.rmi.RemoteException;

public class MyServer {

    public static final String rmiUrl = "rmi://localhost:9000/greet";

    public static void main(String args[]) {
        try {
            MyRemoteObject stub = new MyRemoteObject();
            Naming.rebind(rmiUrl, stub);
        }
        catch(Exception e) {
           System.err.println(e.getMessage());
        }
    }
}
