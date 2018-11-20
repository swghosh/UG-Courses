package org.gdgu.swghosh.cse2016.simplechat;

import org.gdgu.swghosh.cse2016.simplechat.models.ChatServer;
import org.gdgu.swghosh.cse2016.simplechat.views.App;

import java.io.IOException;
import java.util.Date;

public class Main {
    public static void main(String args[]) {
        // Thread to handle Chat Server
        Thread serverThread = new Thread(new Runnable() {
            @Override
            public void run() {
                System.out.println("Starting SimpleChat Server at " + new Date().toString() + ".");
                try {
                    ChatServer server = new ChatServer();
                    while (true) {
                        server.serve();
                    }
                }
                catch (IOException ie) {
                    System.err.println("IO Exception Occured, " + ie.getMessage());
                }
            }
        });
        serverThread.start();

        // Thread to handle Chat Client

        System.out.println("Starting SimpleChat App at " + new Date().toString() + ".");
        App app = new App();
        app.message("Hello World");
    }
}
