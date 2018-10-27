package org.gdgu.swghosh.cse2016;

import java.net.InetAddress;
import java.net.UnknownHostException;

public class InetTest {
    public static void main(String args[]) throws UnknownHostException {
        InetAddress ip = InetAddress.getByName("localhost");
        System.out.print(ip.getHostAddress());
    }
}
