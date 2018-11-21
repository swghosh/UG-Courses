package org.gdgu.swghosh.cse2016.simplechat.models;

import java.io.IOException;
import java.io.PrintWriter;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.ArrayList;
import java.util.Date;
import java.util.Scanner;

/**
 * Used to perform server end
 * functionality on a
 * specified port
 * to allow send and receiving of messages
 * from clients.
 * Clients may directly send messages
 * over socket input streams, and
 * may receive all persisted messages
 * on respective output streams.
 *
 * @version 1.0
 * @author Swarup Ghosh
 * @since 12-11-2018
 */

public class ChatServer {

    private ServerSocket daemon;
    /**
     * Port 9090 used for Socket Server
     */
    public static final int PORT = 9090;

    static ArrayList<String> messages = new ArrayList<>();

    /**
     * Initialise a server socket
     * @throws IOException
     */
    public ChatServer() throws IOException {
        daemon = new ServerSocket(PORT);
    }

    /**
     * Serve a single client
     * using the server socket.
     * Waits until a client connects
     * @throws IOException
     */
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

    /**
     * Close the server socket
     * @throws IOException
     */
    public void close() throws IOException {
        daemon.close();
    }
}
