package org.gdgu.cse2017.osms;

import org.gdgu.cse2017.osms.db.Database;

import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;

public class Administrator extends User {
    public String name;
    public long phone;
    public Administrator(String username, String password, String email, String name, long phone) {
        super(username, password, email);
        this.name = name;
        this.phone = phone;
    }
    public static boolean login(String username, String password) throws SQLException, ClassNotFoundException {
        Database.connect();
        PreparedStatement st = Database.conn.prepareStatement("SELECT username, password FROM administrator WHERE username = ? AND password = ?");
        st.setString(1, username);
        st.setString(2, password);
        ResultSet rs = st.executeQuery();
        int count = 0;
        while(rs.next()) count++;
        return count == 1;
    }
}
