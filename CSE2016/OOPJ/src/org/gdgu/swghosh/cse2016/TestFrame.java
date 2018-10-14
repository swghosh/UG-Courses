package org.gdgu.swghosh.cse2016;

import javax.swing.*;

public class TestFrame extends JFrame {
    JTextField jtf ;
    public TestFrame() {
        this.setTitle("Hello World!");
        this.setBounds(10, 10, 1366, 768);
        jtf = new JTextField();
        jtf.setText("Hello");
        jtf.setBounds(200, 200, 10, 10);
        this.getContentPane().add(jtf);
        this.setVisible(true);
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        this.getContentPane().setLayout(null);
    }
    public static void main(String args[]) {
        TestFrame t = new TestFrame();
    }
}
