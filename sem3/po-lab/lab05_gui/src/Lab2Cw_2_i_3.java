import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
public class Lab2Cw_2_i_3 extends JFrame {
    private JRadioButton linuxRadioButton;
    private JRadioButton macintoshRadioButton;
    private JRadioButton windowsRadioButton;
    private JButton OKButton;
    private JCheckBox java3000PlnCheckBox;
    private JCheckBox c3000PlnCheckBox;
    private JCheckBox c4000PlnCheckBox;
    private JCheckBox python5000PlnCheckBox;
    private JButton OKButton1;
    private JPanel app;
    private JLabel icon;

    private ImageIcon iconLinux = new ImageIcon(getClass().getResource("Linux.png"));
    private ImageIcon iconWin = new ImageIcon(getClass().getResource("Windows.png"));
    private ImageIcon iconMac = new ImageIcon(getClass().getResource("Apple.png"));

    public static void main(String[] args) {
        Lab2Cw_2_i_3 example = new Lab2Cw_2_i_3();
        example.setVisible(true);
    }

    public Lab2Cw_2_i_3() {
        super("Moje GUI");
        this.setContentPane(this.app);
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        this.setSize(600, 600);
        final String[] selected = {""};
        linuxRadioButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                if (linuxRadioButton.isSelected()) {
                    icon.setIcon(resize(iconLinux, 200, 200));
                    selected[0] = "Linux";
                }
            }
        });
        windowsRadioButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                if (windowsRadioButton.isSelected()) {
                    icon.setIcon(resize(iconWin, 200, 200));
                    selected[0] = "Windows";
                }
            }
        });
        macintoshRadioButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                if (macintoshRadioButton.isSelected()) {
                    icon.setIcon(resize(iconMac, 200, 200));
                    selected[0] = "Mac";
                }
            }
        });
        OKButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                JOptionPane.showMessageDialog(null, "You selected: " + selected[0]);
            }
        });
        OKButton1.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                float cena = 0;
                String msg = "";
                if (java3000PlnCheckBox.isSelected()) {
                    cena += 3000;
                    msg += "Java \n";
                }
                if (c3000PlnCheckBox.isSelected()) {
                    cena += 3000;
                    msg += "C# \n";
                }
                if (c4000PlnCheckBox.isSelected()) {
                    cena += 4000;
                    msg += "C++ \n";
                }
                if (python5000PlnCheckBox.isSelected()) {
                    cena += 5000;
                    msg += "Python \n";
                }
                msg += "---------------------------\n";
                JOptionPane.showMessageDialog(null, msg + "Razem: " + cena);
            }
        });
    }

    public static ImageIcon resize(ImageIcon src, int destWidth, int destHeight) {
        return new ImageIcon(src.getImage().getScaledInstance(destWidth, destHeight, Image.SCALE_SMOOTH));
    }
}
