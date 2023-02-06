import components.EditableField;
import utils.validation.ValidationException;

import javax.swing.*;
import java.awt.*;
import java.sql.SQLOutput;


public class App extends JFrame {
    private JTabbedPane nav;
    private JPanel rootPanel;
    private JPanel peopleView;
    private JPanel projectsView;

    Projects projects = new Projects("projekty.csv");

    public void loadProjects() {
        projectsView.removeAll();
        projects.projects.forEach((i, p) -> {
            JPanel projekt = new JPanel();
            JPanel inner = new JPanel();
            JLabel id = new JLabel("Projekt #" +p.getId());
            JLabel nazwa = new JLabel("Nazwa: " + p.getNazwa());
            JLabel opis = new JLabel("Opis: " + p.getOpis());
            JLabel validationMsg = new JLabel(p.validation.getMessage());
            JButton delete = new JButton("X");
            JButton edit = new JButton("Edit");

            projekt.setPreferredSize(new Dimension(585, 160));
            projekt.setBorder(BorderFactory.createLineBorder(Color.BLUE));
            projekt.setLayout(new GridLayout(5, 1, 1, 1));
            inner.setLayout(new FlowLayout());

            EditableField nazwaEditable = new EditableField("Nazwa:", p.getNazwa());
            EditableField opisEditable = new EditableField("Opis:", p.getOpis());

            projekt.add(id);

            if (!p.getEditMode()) {
                projekt.add(nazwa);
                projekt.add(opis);
            } else {
                projekt.add(nazwaEditable.field);
                projekt.add(opisEditable.field);
            }

            projekt.add(inner);
            inner.add(delete);
            inner.add(edit);
            projekt.add(validationMsg);
            projectsView.add(projekt);

            delete.addActionListener(e -> {
                projects.delete(p.getId());
                projectsView.remove(projekt);
                components.Utils.refresh(projectsView);
            });
            edit.addActionListener(e -> {
                System.out.println(nazwaEditable.input.getText());
                if (p.getEditMode()) {
                    try {
                        p.update(nazwaEditable.input.getText(), opisEditable.input.getText());
                        projects.update(p);
                    } catch (ValidationException ex) {
                        validationMsg.setText(ex.getMessage());
                        return;
                    }
                }
                p.toggleEditMode();
                loadProjects();
                components.Utils.refresh(projekt);
            });
            components.Utils.refresh(projectsView);
        });
    }

    public static void main(String[] args) {
        App app = new App();
        app.setVisible(true);
    }

    App() {
        super("CRM");
        this.setSize(600, 600);
        this.setContentPane(this.rootPanel);
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        nav.addChangeListener(e -> {
            if (nav.getSelectedIndex() == 1) {
                loadProjects();
            }
        });
    }
}
