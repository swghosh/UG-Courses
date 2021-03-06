package org.gdgu.swghosh.cse2016.simplechat.views;

import org.gdgu.swghosh.cse2016.simplechat.models.ChatClient;

import javax.swing.*;
import java.awt.*;
import java.io.IOException;
import java.util.Date;

/**
 * Used to initialise the GUI
 * application
 *
 * @version 1.0
 * @author Swarup Ghosh
 * @since 12-11-2018
 */
public class App extends JFrame {

    private JLabel messagesHead, senderHead;
    private JTextArea messagesField;
    private JScrollPane messagesPane;
    private JTextArea senderField;
    private JButton sendButton, clearButton;

    private static final int MARGIN_WIDTH = 25,
                     MARGIN_HEIGHT = 25,
                     WINDOW_WIDTH = 600,
                     WINDOW_HEIGHT = 600,
                     POSITION_OFFSET = 100;
    private static final String WINDOW_TITLE = "Simple Chat App";

    /**
     * Constructor of class App
     * to initialise GUI application
     */
    public App() {
        super(WINDOW_TITLE);
        setBounds(POSITION_OFFSET, POSITION_OFFSET, WINDOW_WIDTH, WINDOW_HEIGHT);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        getContentPane().setLayout(null);

        populate();
        setVisible(true);
    }

    /** Generate different UI components present
     * in the GUI
     */
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
            try {
                onSendMessage();
            }
            catch (IOException ie) {
                System.err.println("Failed. " + ie.getMessage());
            }
        });
        getContentPane().add(sendButton);

        clearButton.setBounds((2 * MARGIN_WIDTH) + 100, WINDOW_HEIGHT - 2 * MARGIN_HEIGHT - 30, 100, 30);
        clearButton.addActionListener((event) -> {
            clearMessages();
        });
        getContentPane().add(clearButton);
    }

    /**
     * Method that is executed
     * on each submit button press
     * @throws IOException
     */
    public void onSendMessage() throws IOException {
        String userMessage = senderField.getText();
        String fullMessage = String.format("[%s] : %s\n", new Date().toString(), userMessage);
        messagesField.setText(fullMessage);
        senderField.setText("");
        ChatClient.sendMessage(fullMessage);
        messagesField.setText(ChatClient.getMessages());
    }

    /**
     * Method that is executed
     * on each clear button press
     */
    public void clearMessages() {
        messagesField.setText("");
    }
}
