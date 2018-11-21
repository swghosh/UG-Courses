package org.gdgu.swghosh.cse2016.simplechat.models;

import java.io.IOException;
import java.io.PrintWriter;
import java.net.InetAddress;
import java.net.Socket;
import java.util.Scanner;

/**
 * Used to perform client end
 * functionality on a known
 * local TCP IP server
 * to allow send and receiving of messages
 *
 * @version 1.0
 * @author Swarup Ghosh
 * @since 12-11-2018
 */
public class ChatClient {
    /**
     * Fetches all available messages
     * from a local TCP/IP Server
     * @return a full string containing line space seperated messages
     * @throws IOException
     */
    public static String getMessages() throws IOException {
        StringBuffer messages = new StringBuffer();
        InetAddress localhost = InetAddress.getLocalHost();
        Socket socket = new Socket(localhost, ChatServer.PORT);

        Scanner fromServer = new Scanner(socket.getInputStream());

        socket.shutdownOutput();
        while(fromServer.hasNextLine()) {
            String message = fromServer.nextLine();
            messages.append("\n").append(message);
        }

        fromServer.close();
        socket.close();

        return messages.toString().trim();
    }

    /**
     * Send a message
     * to a local TCP/IP Server
     * @param message the message that is to be sent
     * @throws IOException
     */
    public static void sendMessage(String message) throws IOException {
        InetAddress localhost = InetAddress.getLocalHost();
        Socket socket = new Socket(localhost, ChatServer.PORT);

        PrintWriter toServer = new PrintWriter(socket.getOutputStream(), true);

        socket.shutdownInput();
        toServer.println(message);

        toServer.close();
        socket.close();
    }
}
