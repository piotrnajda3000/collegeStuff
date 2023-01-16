import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class Lab1_Zad1_i_Lab2_Zad2 extends JFrame {
    private JPanel app;
    private JRadioButton takRadioButton;
    private JRadioButton nieRadioButton;
    private JLabel result;
    private JLabel icon;

    private ImageIcon sun = new ImageIcon(getClass().getResource("sun.jpg"));
    private ImageIcon eclipse = new ImageIcon(getClass().getResource("eclipse.jpg"));

    ButtonGroup group = new ButtonGroup();




    public static void main(String[] args) {
        Lab1_Zad1_i_Lab2_Zad2 example = new Lab1_Zad1_i_Lab2_Zad2();
        example.setVisible(true);
    }

    public Lab1_Zad1_i_Lab2_Zad2()  {
        super("Moje GUI");
        this.setContentPane(this.app);
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        this.setSize(700, 600);

        group.add(takRadioButton);
        group.add(nieRadioButton);
        takRadioButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                System.out.println(group.getSelection());
                icon.setIcon(resize(eclipse, 200, 200));
                result.setText("W takim wypadku, jesteś skazany na wieczny mrok.");
            }
        });
        nieRadioButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                icon.setIcon(resize(sun, 300, 200));
                result.setText("W takim wypadku, zasmakujesz światła.");
            }
        });
    }

    public static ImageIcon resize(ImageIcon src, int destWidth, int destHeight) {
        return new ImageIcon(src.getImage().getScaledInstance(destWidth, destHeight, Image.SCALE_SMOOTH));
    }
}
