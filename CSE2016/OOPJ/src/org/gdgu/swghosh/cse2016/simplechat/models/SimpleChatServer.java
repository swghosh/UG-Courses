package org.gdgu.swghosh.cse2016.simplechat.models;

import java.io.IOException;
import java.io.PrintWriter;
import java.net.ServerSocket;
import java.net.Socket;

public class SimpleChatServer {
    public static final int PORT = 8961;

    private ServerSocket daemon;
    private PrintWriter toClient;

    public SimpleChatServer() throws IOException {
        daemon = new ServerSocket(PORT);
        runIndefinitely();
    }

    void runIndefinitely() throws IOException {
        while(true) {
            Socket client = daemon.accept();
            toClient = new PrintWriter(client.getOutputStream(), true);
        }
    }

    public void publishMessage(String message) {
        toClient.println(message);
    }
}
