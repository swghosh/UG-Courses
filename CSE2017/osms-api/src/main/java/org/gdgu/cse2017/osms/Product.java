package org.gdgu.cse2017.osms;

public class Product {
    public long id;
    public String name;
    public float price;
    public int qtyAvailable;
    public Product(long id, String name, float price, int qtyAvailable) {
        this.id = id;
        this.name = name;
        this.price = price;
        this.qtyAvailable = qtyAvailable;
    }
}
