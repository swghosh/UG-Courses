package org.gdgu.swghosh.cse2016.simplechat;

import org.gdgu.swghosh.cse2016.simplechat.models.SimpleChatServer;
import org.gdgu.swghosh.cse2016.simplechat.views.App;

import java.io.IOException;
import java.util.Date;

public class Main {
    public static void main(String args[]) {
        Thread forServer = new Thread(() -> {
            System.out.println("Starting SimpleChat Server at " + new Date().toString() + ".");
            try {
                SimpleChatServer server = new SimpleChatServer();
                server.publishMessage("Hello");
            }
            catch (IOException ie) {
                System.out.println(ie.getMessage());
            }
        });
        forServer.start();
        System.out.println("Starting SimpleChat App at " + new Date().toString() + ".");
        App app = new App();
        app.message("Hello World");
    }
}
