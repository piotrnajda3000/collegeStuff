package components;
import javax.swing.*;

public class Utils {
    public static void refresh (JComponent component) {
        component.revalidate();
        component.repaint();
    }
}
