import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.HashMap;
import java.util.Map;

// poczytac sb musze: https://www.tutorialspoint.com/java/java_innerclasses.htm

public class PrzykladZWykladu extends JFrame {
    private javax.swing.JPanel app;
    private JButton suma;
    private JButton roznica;
    private JButton exit;
    private JTextField a;
    private JTextField b;
    private JLabel wynikText;

    double liczbaA, liczbaB, wynik;

    public static void main(String[] args) {
        PrzykladZWykladu example = new PrzykladZWykladu();
        example.setVisible(true);
    }

    final Map<String, Double> Inputs = new HashMap<>();
    void processInputs() {
        Inputs.put("a", Double.parseDouble(a.getText()));
        Inputs.put("b", Double.parseDouble(b.getText()));
    }

    public PrzykladZWykladu() {
        super("Moje GUI");
        this.setContentPane(this.app);
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        this.setSize(300, 400);
        this.pack();
        suma.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                processInputs();
                wynik = Inputs.get("a") + Inputs.get("b");
                wynikText.setText(String.valueOf(wynik));
            }
        });
        roznica.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                processInputs();
                wynik = Inputs.get("a") - Inputs.get("b");
                wynikText.setText(String.valueOf(wynik));
            }
        });
        exit.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                dispose();
            }
        });
    }
}
