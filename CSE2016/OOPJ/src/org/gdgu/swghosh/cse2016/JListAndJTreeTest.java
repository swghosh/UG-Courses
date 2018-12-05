package org.gdgu.swghosh.cse2016;

import javax.swing.*;
import javax.swing.tree.DefaultMutableTreeNode;

public class JListAndJTreeTest {
    private static int LIST_LIMIT = 20;
    public static void main(String[] args) {
        JFrame frame = new JFrame("My New Application");
        frame.setBounds(100, 100, 500, 400);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setLayout(null);

        String[] data = new String[LIST_LIMIT];
        for(int travIndex = 0; travIndex < LIST_LIMIT; travIndex++) {
            data[travIndex] = "Room # " + (travIndex + 1);
        }
        JList<String> list = new JList<>(data);
        JScrollPane pane = new JScrollPane(list);
        pane.setBounds(10, 10, 480, 200);
        frame.getContentPane().add(pane);

        DefaultMutableTreeNode n1 = new DefaultMutableTreeNode("Home");
        DefaultMutableTreeNode n2 = new DefaultMutableTreeNode("Bedroom 1");
        DefaultMutableTreeNode n3 = new DefaultMutableTreeNode("Bedroom 2");
        DefaultMutableTreeNode n4 = new DefaultMutableTreeNode("Furniture 1");
        DefaultMutableTreeNode n5 = new DefaultMutableTreeNode("Furniture 2");
        DefaultMutableTreeNode n6 = new DefaultMutableTreeNode("Furniture 3");
        DefaultMutableTreeNode n7 = new DefaultMutableTreeNode("Furniture 4");

        n1.add(n2); n1.add(n3);
        n2.add(n4); n2.add(n5);
        n3.add(n6); n3.add(n6);
        JTree tree = new JTree(n1);
        tree.setBounds(10, 220, 480, 150);
        frame.getContentPane().add(tree);

        frame.setVisible(true);
    }
}
