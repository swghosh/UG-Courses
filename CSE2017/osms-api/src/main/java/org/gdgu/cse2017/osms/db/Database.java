package org.gdgu.cse2017.osms.db;

import java.sql.*;

public class Database {

    public static Connection conn;

    public static void connect() throws ClassNotFoundException, SQLException {
        Class.forName("org.postgresql.Driver");
        conn = DriverManager.getConnection(
            System.getenv("JDBC_DATABASE_URL"),
            System.getenv("JDBC_DATABASE_USERNAME"),
            System.getenv("JDBC_DATABASE_PASSWORD")
        );
    }

    public static void close() throws SQLException {
        conn.close();
    }
}
