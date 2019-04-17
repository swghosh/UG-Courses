package org.gdgu.cse2017.osms;

public class Customer extends User {
    public String name, address;
    public long phone;
    public Customer(String username, String password, String email, String name, long phone, String address) {
        super(username, password, email);
        this.name = name;
        this.phone = phone;
        this.address = address;
    }
}
