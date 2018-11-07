package org.gdgu.swghosh.cse2016.rmitest;

import java.rmi.RemoteException;
import java.rmi.server.UnicastRemoteObject;

public class MyRemoteObject extends UnicastRemoteObject implements MyRemote {
    MyRemoteObject() throws RemoteException {
        super();
    }
    public String getMessage() throws RemoteException {
        return "Hello world!";
    }
}
