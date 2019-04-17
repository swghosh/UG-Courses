package org.gdgu.cse2017.osms;

public class Product {
    public long id;
    public String name, category;
    public float price;
    public int qtyAvailable;
    public Product(long id, String name, float price, int qtyAvailable, String category) {
        this.id = id;
        this.name = name;
        this.price = price;
        this.qtyAvailable = qtyAvailable;
        this.category = category;
    }
}
