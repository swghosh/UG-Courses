package org.gdgu.cse2017.osms;

import org.gdgu.cse2017.osms.db.Database;

import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.ArrayList;

public class Catalogue {
    public static ArrayList<Product> products = new ArrayList<>();
    static {
        try {
            Statement st = Database.conn.createStatement();
            ResultSet rs = st.executeQuery("SELECT id, name, price, qty, category FROM product");
            while(rs.next()) {
                Product product = new Product(
                    rs.getLong("id"),
                    rs.getString("name"),
                    rs.getFloat("price"),
                    rs.getInt("qty"),
                    rs.getString("category")
                );
                products.add(product);
            }
        }
        catch (SQLException ex) {
            System.err.println(ex.getMessage());
        }
    }
}
