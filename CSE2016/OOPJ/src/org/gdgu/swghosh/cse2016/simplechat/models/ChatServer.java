package org.gdgu.swghosh.cse2016.simplechat.models;

import java.io.IOException;
import java.io.PrintWriter;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.ArrayList;
import java.util.Date;
import java.util.Scanner;

public class ChatServer {

    private ServerSocket daemon;
    public static final int PORT = 9090;

    static ArrayList<String> messages = new ArrayList<>();

    public ChatServer() throws IOException {
        daemon = new ServerSocket(PORT);
    }

    public void serve() throws IOException {
        Socket client = daemon.accept();
        Scanner fromClient = new Scanner(client.getInputStream());
        PrintWriter toClient = new PrintWriter(client.getOutputStream(), true);
        for(String message: messages) {
            System.out.printf("[%s] Sending message to client: \"%s\".\n", new Date().toString(), message);
            toClient.println(message);
        }

        fromClient.useDelimiter("\n");
        while(fromClient.hasNext()) {
            String aMessage = fromClient.next();
            System.out.printf("[%s] Client message received: \"%s\".\n", new Date().toString(), aMessage);
            if(!aMessage.trim().isEmpty()) {
                messages.add(aMessage);
                toClient.println(aMessage);
            }
        }

        fromClient.close();
        toClient.close();
        client.close();
    }

    public void close() throws IOException {
        daemon.close();
    }
}
