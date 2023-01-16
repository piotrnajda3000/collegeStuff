import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class Lab1Zad1 extends JFrame {
    private JPanel app;
    private JTextField celsiusField;
    private JLabel wynik;
    private JButton konwertujButton;

    public static void main(String[] args) {
        Lab1Zad1 example = new Lab1Zad1();
        example.setVisible(true);
    }

    public Lab1Zad1()  {
        super("Moje GUI");
        this.setContentPane(this.app);
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        this.setSize(600, 600);
        konwertujButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                double fahrenheit = Double.parseDouble(celsiusField.getText()) * 1.8 + 32;
                wynik.setText(String.valueOf(fahrenheit));
            }
        });
    }
}
