package org.gdgu.cse2017.osms;

import com.google.gson.Gson;
import org.gdgu.cse2017.osms.db.Database;

import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;

public class Customer extends User {
    public String name, address;
    public long phone;
    public Customer(String username, String password, String email, String name, long phone, String address) {
        super(username, password, email);
        this.name = name;
        this.phone = phone;
        this.address = address;
    }
    public static boolean login(String username, String password) throws SQLException, ClassNotFoundException {
        PreparedStatement st = Database.conn.prepareStatement("SELECT username, password FROM customer WHERE username = ? AND password = ?");
        st.setString(1, username);
        st.setString(2, password);
        ResultSet rs = st.executeQuery();
        int count = 0;
        while(rs.next()) count++;
        return count == 1;
    }
    public static Customer signup(String username, String password, String email, String name, long phone, String address) throws SQLException, ClassNotFoundException {
        Database.connect();
        PreparedStatement st = Database.conn.prepareStatement("INSERT INTO customer (username, password, email, name, phone, address) VALUES (?, ?, ?, ?, ?, ?)");
        st.setString(1, username);
        st.setString(2, password);
        st.setString(3, email);
        st.setString(4, name);
        st.setLong(5, phone);
        st.setString(6, address);
        int count = st.executeUpdate();
        return ((count == 1) ? new Customer(username, password, email, name, phone, address) : null);
    }
}
