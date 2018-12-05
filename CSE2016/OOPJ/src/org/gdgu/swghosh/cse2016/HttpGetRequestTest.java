package org.gdgu.swghosh.cse2016;

import javax.net.ssl.HttpsURLConnection;
import java.io.*;
import java.net.HttpURLConnection;
import java.net.MalformedURLException;
import java.net.URL;
import java.net.URLConnection;
import java.util.Scanner;

public class HttpGetRequestTest {
    public static void main(String[] args) throws IOException {
        Scanner in = new Scanner(System.in);
        System.out.print("Specify an URL (http[s] URL expected) -> ");
        URL userUrl = new URL(in.nextLine());
        // case of http
        if(userUrl.getProtocol().equals("http")) {
            HttpURLConnection connection = (HttpURLConnection) userUrl.openConnection();
            connection.setRequestMethod("GET");
            // request text from the url (mime type: text/plain)
            connection.setRequestProperty("Content-Type", "text/plain");
            BufferedReader out = new BufferedReader(
                    new InputStreamReader(
                            connection.getInputStream()
                    )
            );
            String line;
            while((line = out.readLine()) != null) {
                System.out.println(line);
            }
            out.close();
        }
        else {
            System.err.println("Invalid URL protocol.");
        }
        in.close();
    }
}
