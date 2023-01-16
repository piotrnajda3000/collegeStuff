import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class Lab2Cw_1_i_zad_1 extends JFrame {
    private JTextField usernameInput;
    private JPasswordField passwordInput;
    private JButton loginButton;
    private JLabel passwordValue;
    private JLabel usernameValue;
    private JPanel app;
    private JPasswordField passwordConfirm;

    String username, password;

    public static void main(String[] args) {
        Lab2Cw_1_i_zad_1 example = new Lab2Cw_1_i_zad_1();
        example.setVisible(true);
    }

    public Lab2Cw_1_i_zad_1()  {
        super("Moje GUI");
        this.setContentPane(this.app);
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        this.setSize(600, 600);

    loginButton.addActionListener(new ActionListener() {
        @Override
        public void actionPerformed(ActionEvent e) {
            if (!passwordConfirm.getText().equals(passwordInput.getText())) {
                JOptionPane.showMessageDialog(null, "passwords do not match");
            } else if (!passwordConfirm.getText().equals("codejava"))  {
                JOptionPane.showMessageDialog(null, "wrong password");
            } else {
                JOptionPane.showMessageDialog(null, "correct password!");
            }
            passwordValue.setText(passwordInput.getText());
            usernameValue.setText(usernameInput.getText());
        }
    });
}
}
