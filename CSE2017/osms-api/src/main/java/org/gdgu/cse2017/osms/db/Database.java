package org.gdgu.cse2017.osms.db;

import java.sql.*;

public class Database {

    public static Connection conn;

    static {
        try {
            Class.forName("org.postgresql.Driver");
            conn = DriverManager.getConnection(
                    System.getenv("JDBC_DATABASE_URL"),
                    System.getenv("JDBC_DATABASE_USERNAME"),
                    System.getenv("JDBC_DATABASE_PASSWORD")
            );
        }
        catch(ClassNotFoundException ex) {
            System.err.println(ex.getMessage());
        }
        catch(SQLException ex) {
            System.err.println(ex.getMessage());
        }
    }
}
