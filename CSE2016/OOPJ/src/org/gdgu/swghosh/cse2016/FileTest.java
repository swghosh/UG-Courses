package org.gdgu.swghosh.cse2016;

import java.io.File;
import java.io.IOException;

public class FileTest {
    public static void main(String[] args) {
        // will cause NullPointerException for child as null in constructor arg
        // File f = new File("/Users", null);
        // System.out.println(f.exists());
        File file = new File("/abc.txt");
        System.out.println(file.getPath());
        System.out.println(file.getPath());
        try {
           System.out.println(file.getCanonicalPath());
        }
        catch (IOException e) {
            e.printStackTrace();
        }
    }
}
