package org.gdgu.swghosh.cse2016;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;

class User implements Comparable<User> {
    String emailAddress, username;
    long phoneNumber;

    User(String username, String emailAddress, long phoneNumber) {
        this.username = username;
        this.emailAddress = emailAddress;
        this.phoneNumber = phoneNumber;
    }

    @Override
    public int compareTo(User another) {
        return this.username.compareTo(another.username);
    }
}

public class ComparableTests {
    public static void main(String args[]) {
        ArrayList<User> users = new ArrayList<>();
        users.add(new User("swarup.ghosh", "swarup.ghosh@example.com", 9830012345L));
        users.add(new User("sayanti.ghosh", "sayanti.ghosh@example.com", 9830012346L));
        users.add(new User("soma.ghosh", "soma.ghosh@example.com", 9830012347L));
        System.out.println("Sorting 3 users using Comparable interface and Collections.sort.");
        Collections.sort(users);
        for(User user : users) {
            System.out.printf("User: %s, %s, %d\n", user.username, user.emailAddress, user.phoneNumber);
        }
        System.out.println();
        System.out.println("Sorting 4 users using Comparator interface and ArrayList sort.");
        users.add(new User("sn.ghosh", "sn.ghosh@example.com", 9830012348L));
        users.sort(new Comparator<>() {
            @Override
            public int compare(User o1, User o2) {
                return o1.emailAddress.compareTo(o2.emailAddress);
            }
        });
        for(User user : users) {
            System.out.printf("User: %s, %s, %d\n", user.username, user.emailAddress, user.phoneNumber);
        }
    }
}
