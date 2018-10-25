package org.gdgu.swghosh.cse2016;

import java.io.File;

/**
 * Simple program to list the
 * contents in the current directory
 * @version 1.0
 * @author Swarup Ghosh
 * @since 2018-10-23
 */
public class DirectoryListing {
    public static void main(String args[]) {
        File currentDirectory = new File("./");
        System.out.println("Current directory is " + currentDirectory.getAbsolutePath());
        System.out.println("Listing contents in current directory...");
        for(File aFile : currentDirectory.listFiles()) {
            System.out.println("> " + aFile.getName());
        }
    }
}
