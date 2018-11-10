package org.gdgu.swghosh.cse2016.simplechat.views;

import javax.swing.*;
import java.awt.*;
import java.util.Date;

public class App extends JFrame {

    private JLabel messagesHead, senderHead;
    private JTextArea messagesField;
    private JScrollPane messagesPane;
    private JTextArea senderField;
    private JButton sendButton, clearButton;

    static final int MARGIN_WIDTH = 25,
                     MARGIN_HEIGHT = 25,
                     WINDOW_WIDTH = 600,
                     WINDOW_HEIGHT = 600,
                     POSITION_OFFSET = 100;
    static final String WINDOW_TITLE = "Simple Chat App";

    public App() {
        super(WINDOW_TITLE);
        setBounds(POSITION_OFFSET, POSITION_OFFSET, WINDOW_WIDTH, WINDOW_HEIGHT);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        getContentPane().setLayout(null);

        populate();
        setVisible(true);
    }

    public void populate() {
        int fixedWidth = WINDOW_WIDTH - (2 * MARGIN_WIDTH);

        messagesHead = new JLabel("Available Messages");
        senderHead = new JLabel("New Message");
        messagesField = new JTextArea();
        senderField = new JTextArea();
        sendButton = new JButton("Send");
        clearButton = new JButton("Clear");

        messagesHead.setBounds(MARGIN_WIDTH, MARGIN_HEIGHT, fixedWidth, 20);
        messagesHead.setForeground(Color.DARK_GRAY);
        getContentPane().add(messagesHead);

        messagesField.setEditable(false);
        messagesField.setForeground(Color.DARK_GRAY);
        messagesPane = new JScrollPane(messagesField);
        messagesPane.setBorder(BorderFactory.createLineBorder(Color.DARK_GRAY));
        messagesPane.setBounds(MARGIN_WIDTH, (MARGIN_HEIGHT * 2) + 20, fixedWidth, (WINDOW_HEIGHT / 2) - (3 * MARGIN_HEIGHT + 20));
        getContentPane().add(messagesPane);

        senderHead.setBounds(MARGIN_WIDTH, WINDOW_HEIGHT / 2, fixedWidth, 20);
        senderHead.setForeground(Color.DARK_GRAY);
        getContentPane().add(senderHead);

        senderField.setBounds(MARGIN_WIDTH, (WINDOW_HEIGHT / 2) + MARGIN_HEIGHT + 20, fixedWidth, (WINDOW_HEIGHT / 2) - (5 * MARGIN_HEIGHT + 20));
        senderField.setBorder(BorderFactory.createLineBorder(Color.DARK_GRAY));
        getContentPane().add(senderField);

        sendButton.setBounds(MARGIN_WIDTH, WINDOW_HEIGHT - 2 * MARGIN_HEIGHT - 30, 100, 30);
        sendButton.addActionListener((event) -> {
            String userMessage = senderField.getText();
            System.out.printf("[%s] : %s\n", new Date().toString(), userMessage);
            message(userMessage);
            senderField.setText("");
        });
        getContentPane().add(sendButton);

        clearButton.setBounds((2 * MARGIN_WIDTH) + 100, WINDOW_HEIGHT - 2 * MARGIN_HEIGHT - 30, 100, 30);
        clearButton.addActionListener((event) -> {
            clearMessages();
        });
        getContentPane().add(clearButton);
    }

    public void message(String message) {
        messagesField.setText(
                String.format("%s\n[%s] : %s", messagesField.getText(), new Date().toString(), message)
        );
    }

    public void clearMessages() {
        messagesField.setText("");
    }
}
