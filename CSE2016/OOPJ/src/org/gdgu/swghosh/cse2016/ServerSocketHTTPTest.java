package org.gdgu.swghosh.cse2016;

import java.io.IOException;
import java.io.PrintWriter;
import java.net.ServerSocket;
import java.net.Socket;

public class ServerSocketHTTPTest {
    public static void main(String args[]) throws IOException {
        ServerSocket daemon = new ServerSocket(8961);
        Socket client = daemon.accept();
        PrintWriter pw = new PrintWriter(client.getOutputStream());
        pw.println("HTTP/1.1 200 OK" +
                "\r\n" +
                "Server: Simple/1.0" +
                "\r\n" +
                "Content-Type: text/plain" +
                "\r\n\r\n" +
                "Hello World!");
        pw.close();
        client.close();
    }
}
