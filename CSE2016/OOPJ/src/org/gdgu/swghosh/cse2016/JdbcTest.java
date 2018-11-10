package org.gdgu.swghosh.cse2016;

import java.sql.*;

public class JdbcTest {

    static final String DATABASE_URL = "jdbc:mysql://localhost:3306/campaigntreasurercompanion";
    static final String DATABASE_USERNAME = "root";
    static final String DATABASE_PASSWORD = "this is not the password you are looking for";

    public static void main(String[] args) throws ClassNotFoundException, SQLException {
        Class.forName("com.mysql.cj.jdbc.Driver");
        Connection conn = DriverManager.getConnection(DATABASE_URL, DATABASE_USERNAME, DATABASE_PASSWORD);
        Statement st = conn.createStatement();
        ResultSet rs = st.executeQuery("SELECT name, current, difference, percentage FROM stocks");
        System.out.printf("%30s\t | %10s\t | %10s\t | %10s\t \n\n", "NAME", "CURRENT", "DIFFERENCE", "PERCENTAGE");
        while(rs.next()) {
            int cIndex = 1;
            System.out.printf("%30.30s\t | %10.2f\t | %10.2f\t | %10.2f\t \n", rs.getString(cIndex++), rs.getFloat(cIndex++), rs.getFloat(cIndex++), rs.getFloat(cIndex++));
        }
        conn.close();
    }
}
