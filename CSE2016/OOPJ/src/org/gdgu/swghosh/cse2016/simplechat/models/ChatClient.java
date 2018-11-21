package org.gdgu.swghosh.cse2016.simplechat.models;

import java.io.IOException;
import java.io.PrintWriter;
import java.net.InetAddress;
import java.net.Socket;
import java.util.Scanner;

public class ChatClient {
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
