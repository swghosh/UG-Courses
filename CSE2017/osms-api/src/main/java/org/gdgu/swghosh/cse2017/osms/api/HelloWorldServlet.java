package org.gdgu.swghosh.cse2017.osms.api;

import javax.servlet.annotation.*;
import javax.servlet.http.*;
import java.io.IOException;
import java.io.PrintWriter;
import com.google.gson.*;

@WebServlet("/api/*")
public class HelloWorldServlet extends HttpServlet {
    @Override
    public void doGet(HttpServletRequest request, HttpServletResponse response)
    throws IOException {
        Gson gson = new Gson();
        String jsonRepr = gson.toJson(new Test());
        response.setContentType("application/json");
        PrintWriter out = response.getWriter();
        out.println(jsonRepr);
        out.close();
    }
}
