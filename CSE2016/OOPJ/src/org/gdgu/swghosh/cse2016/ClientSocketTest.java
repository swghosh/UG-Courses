package org.gdgu.swghosh.cse2016;

import java.io.IOException;
import java.io.PrintWriter;
import java.net.InetAddress;
import java.net.Socket;
import java.net.UnknownHostException;
import java.util.Scanner;

public class ClientSocketTest {
    static final int PORT = 9000;
    public static void main(String args[]) throws UnknownHostException, IOException {
        InetAddress localhost = InetAddress.getLocalHost();
        Socket socket = new Socket(localhost.getHostName(), PORT);

        PrintWriter toServer = new PrintWriter(socket.getOutputStream(), true);
        toServer.println("Request in progress");

        Scanner fromServer = new Scanner(socket.getInputStream());
        System.out.print(fromServer.nextLine());

        System.out.println();

        fromServer.close();
        toServer.close();
        socket.close();
    }
}
