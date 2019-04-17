package org.gdgu.cse2017.osms.db;

import java.sql.*;

public class Database {
    public static void main(String[] args) throws ClassNotFoundException, SQLException {
        Class.forName("org.postgresql.Driver");
        Connection conn = DriverManager.getConnection(
            System.getenv("JDBC_DATABASE_URL"),
            System.getenv("JDBC_DATABASE_USERNAME"),
            System.getenv("JDBC_DATABASE_PASSWORD")
        );
        Statement st = conn.createStatement();
        ResultSet rs = st.executeQuery("SELECT name FROM customer");
        while(rs.next()) {
            System.out.println(rs.getString("name"));
        }
        conn.close();
    }
}
