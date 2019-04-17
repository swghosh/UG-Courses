package org.gdgu.cse2017.osms.api;

import com.google.gson.Gson;
import org.gdgu.cse2017.osms.Administrator;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.io.PrintWriter;
import java.sql.SQLException;

@WebServlet("/api/users/administrators/login")
public class AdministratorLoginServlet extends HttpServlet {
    class Credentials {
        String username, password;
    }

    @Override
    public void doPost(HttpServletRequest request, HttpServletResponse response)
            throws IOException {
        Gson gson = new Gson();
        Credentials creds = gson.fromJson(request.getReader(), Credentials.class);
        response.setContentType("application/json");
        PrintWriter out = response.getWriter();
        boolean isLoggedIn = false;
        try {
            isLoggedIn = Administrator.login(creds.username, creds.password);
        }
        catch (SQLException ex) {
            System.err.println(ex.getMessage());
        }
        finally {
            out.println(gson.toJson(isLoggedIn));
        }
        out.close();
    }

}
