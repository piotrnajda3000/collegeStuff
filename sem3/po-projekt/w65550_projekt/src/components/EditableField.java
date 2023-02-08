package components;

import javax.swing.*;
import java.awt.*;

public class EditableField {
    public JPanel field = new JPanel();
    public JLabel label;
    public JTextField input;

    public <V> EditableField(String label, V value) {
        this.label = new JLabel(label);
        this.input = new JTextField((String) value, 20);
        field.add(this.label);
        field.add(this.input);
    }
}