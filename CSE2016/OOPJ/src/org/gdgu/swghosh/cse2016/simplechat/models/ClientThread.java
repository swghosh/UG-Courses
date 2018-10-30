package org.gdgu.swghosh.cse2016.simplechat.models;

import java.io.PrintWriter;
import java.net.Socket;
import java.util.Scanner;

public class ClientThread implements Runnable {

    public Socket client;

    ClientThread(Socket client) {
        super();
        this.client = client;
    }

    public String receiveMessage() {

    }
    public void sendMessage() {

    }

    public void run() {
        Scanner fromClient = new Scanner(client.getInputStream());

        PrintWriter toClient = new PrintWriter(client.getOutputStream());
    }
}
