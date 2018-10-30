package org.gdgu.swghosh.cse2016;

import java.io.IOException;
import java.io.PrintWriter;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.Date;
import java.util.Scanner;

public class ServerSocketTest {
    static final int PORT = 9000;
    public static void main(String args[]) throws IOException {
        ServerSocket daemon = new ServerSocket(PORT);
        Socket client = daemon.accept();

        Scanner fromClient = new Scanner(client.getInputStream());
        System.out.println(fromClient.nextLine());

        PrintWriter toClient = new PrintWriter(client.getOutputStream(), true);
        String message = String.format("[%s] Hello World!\n", new Date().toString());
        toClient.println(message);

        fromClient.close();
        toClient.close();
        daemon.close();
    }
}
