package org.gdgu.swghosh.cse2016.simplechat;

import org.gdgu.swghosh.cse2016.simplechat.models.ChatServer;
import org.gdgu.swghosh.cse2016.simplechat.views.App;

import java.io.IOException;
import java.util.Date;

/**
 * SimpleChatApp,
 * Main is used to initialise and start
 * all components of the application.
 * Sample application to show use of
 * TCP IP Server Client Communication
 * over a Java Swing based GUI interface.
 *
 * @version 1.0
 * @author Swarup Ghosh
 * @since 12-11-2018
 */

public class Main {
    /** Main method that is to be executed at runtime
     * @param args command line arguments (no specific requirements for running)
     */
    public static void main(String args[]) {
        System.out.println("Starting SimpleChat App at " + new Date().toString() + ".");
        App app = new App();

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
    }
}
