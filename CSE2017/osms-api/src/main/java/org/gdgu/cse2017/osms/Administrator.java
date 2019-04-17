package org.gdgu.cse2017.osms;

public class Administrator extends User {
    public String name;
    public long phone;
    public Administrator(String username, String password, String email, String name, long phone) {
        super(username, password, email);
        this.name = name;
        this.phone = phone;
    }
}
