package org.gdgu.cse2017.osms;

public class User {
    protected String username;
    protected String password;
    protected String email;
    public User(String username, String password, String email) {
        this.username = username;
        this.password = password;
        this.email = email;
    }
}
