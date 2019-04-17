package org.gdgu.cse2017.osms.api;

import javax.servlet.annotation.*;
import javax.servlet.http.*;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

import com.google.gson.*;
import org.gdgu.cse2017.osms.Product;

@WebServlet("/api/hello")
public class HelloWorldServlet extends HttpServlet {
    @Override
    public void doGet(HttpServletRequest request, HttpServletResponse response)
    throws IOException {
        Gson gson = new Gson();
        String jsonRepr = gson.toJson(true);
        response.setContentType("application/json");
        PrintWriter out = response.getWriter();
        out.println(jsonRepr);
        out.close();
    }

    @Override
    public void doPost(HttpServletRequest request, HttpServletResponse response)
    throws IOException {
        Scanner sc = new Scanner(request.getReader());
        String in = "";
        while(sc.hasNext()) {
            in += " " + sc.next();
        }
        sc.close();
        response.setContentType("application/json");
        PrintWriter out = response.getWriter();
        out.println(in);
        out.close();
    }
}
