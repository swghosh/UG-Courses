package org.gdgu.cse2017.osms.api;

import com.google.gson.Gson;
import org.gdgu.cse2017.osms.Customer;

import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.io.PrintWriter;
import java.sql.SQLException;
import java.util.Scanner;

@WebServlet("/api/users/customers/signup")
public class CustomerSignupServlet extends HttpServlet {
    @Override
    public void doPost(HttpServletRequest request, HttpServletResponse response)
            throws IOException {
        Gson gson = new Gson();
        Scanner in = new Scanner(request.getReader());
        in.useDelimiter("\n");
        String body = "";
        while(in.hasNext()) {
            body += in.next();
        }
        Customer provCust = gson.fromJson(body, Customer.class);
        response.setContentType("application/json");
        PrintWriter out = response.getWriter();
        try {
            String jsonRepr = gson.toJson(provCust.signup());
            out.println(jsonRepr);
        }
        catch (SQLException ex) {
            System.err.println(ex.getMessage());
            out.println(gson.toJson(null));
        }
        out.close();
    }
}
