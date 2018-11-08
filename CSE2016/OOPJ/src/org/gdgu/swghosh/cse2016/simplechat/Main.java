package org.gdgu.swghosh.cse2016.simplechat;

import org.gdgu.swghosh.cse2016.simplechat.views.App;

import java.util.Date;

public class Main {
    public static void main(String args[]) {
        System.out.println("Starting SimpleChat App at " + new Date().toString() + ".");
        App app = new App();
        app.messagify("Hello World");
        app.messagify("Hello World, yet again!");
    }
}
