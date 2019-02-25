package org.gdgu.swghosh.cse2017.osms.api;

import javax.servlet.annotation.*;
import javax.servlet.http.*;
import java.io.IOException;
import java.io.PrintWriter;

@WebServlet("/api")
public class HelloWorldServlet extends HttpServlet {
    @Override
    public void doGet(HttpServletRequest request, HttpServletResponse response)
    throws IOException {
        response.setContentType("application/json");
        PrintWriter out = response.getWriter();
        out.println("{\"message\": \"Hello World!\"}");
        out.close();
    }
}
