package org.gdgu.swghosh.cse2016.rmitest;

import java.rmi.Remote;
import java.rmi.RemoteException;

public interface MyRemote extends Remote {
    String getMessage() throws RemoteException;
}
