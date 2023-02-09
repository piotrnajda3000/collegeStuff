import components.EditableField;
import utils.validation.ValidationException;

import javax.swing.*;
import java.awt.*;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;
import java.util.stream.Collectors;


public class App extends JFrame {
    private JTabbedPane nav;
    private JPanel rootPanel;
    private JPanel PeopleView;
    private JPanel ProjectsView;

    Projects projects = new Projects("projekty.csv", "projekty-total.csv");
    People people = new People("ludzie.csv", "ludzie-total.csv");

    static final int preferredWidth = 585;

    public void renderPeopleView() {
        PeopleView.removeAll();
        people.getPeople().forEach((idx, person) -> {
            // Create components
            JPanel Item = new JPanel();
            JPanel Inner = new JPanel();
            JLabel Id = new JLabel("Person #" + person.getId());
            JLabel First = new JLabel("First name: " + person.getFirst());
            JLabel Last = new JLabel("Last name: " + person.getLast());
            JLabel ValidationMsg = new JLabel(person.validation.getMessage());
            JButton Delete = new JButton("Delete");
            JButton Edit = new JButton(person.getEditMode() ? "Confirm" : "Edit");
            EditableField FirstEditable = new EditableField("First name:", person.getFirst());
            EditableField LastEditable = new EditableField("Last name:", person.getLast());

            // Configure components
            Item.setPreferredSize(new Dimension(preferredWidth, 160));
            Item.setBorder(BorderFactory.createLineBorder(Color.GREEN));
            Item.setLayout(new GridLayout(5, 1, 1, 1));
            Inner.setLayout(new FlowLayout());

            // Add components to view
            Item.add(Id);
            if (!person.getEditMode()) {
                Item.add(First);
                Item.add(Last);
            } else {
                Item.add(FirstEditable.field);
                Item.add(LastEditable.field);
            }
            Item.add(Inner);
            Inner.add(Delete);
            Inner.add(Edit);
            Item.add(ValidationMsg);
            PeopleView.add(Item);

            Delete.addActionListener(e -> {
                people.DELETE(person.getId());
                PeopleView.remove(Item);
                components.Utils.refresh(PeopleView);
            });
            Edit.addActionListener(e -> {
                // "Please finish editing previous person" check.
                Map<Integer, Person> inEditMode = people.getPeople().entrySet().stream().filter(p -> p.getValue().getEditMode())
                        .collect(Collectors.toMap(Map.Entry::getKey, Map.Entry::getValue));
                for (Integer i : inEditMode.keySet()) {
                    if (i != person.getId()) {
                        ValidationMsg.setText("Please finish editing previous person.");
                        return;
                    }
                }
                // Edit the person data if Confirming an edit.
                if (person.getEditMode()) {
                    try {
                        person.PUT(FirstEditable.input.getText(), LastEditable.input.getText());
                        people.PUT(person);
                    } catch (ValidationException ex) {
                        ValidationMsg.setText(ex.getMessage());
                        return;
                    }
                }
                // Switch edit mode and rerender view.
                person.toggleEditMode();
                renderPeopleView();
            });
        });
        renderPeopleNewForm();
    }

    public void renderProjectsView() {
        ProjectsView.removeAll();
        projects.getProjects().forEach((idx, project) -> {
            // Create components
            JPanel Item = new JPanel();
            JPanel Inner = new JPanel();
            JLabel Id = new JLabel("Project #" + project.getId());
            JLabel Nazwa = new JLabel("Name: " + project.getNazwa());
            JLabel Opis = new JLabel("Description: " + project.getOpis());
            JLabel ValidationMsg = new JLabel(project.validation.getMessage());
            JButton Delete = new JButton("Delete");
            JButton Edit = new JButton(project.getEditMode() ? "Confirm" : "Edit");
            EditableField NazwaEditable = new EditableField("Name:", project.getNazwa());
            EditableField OpisEditable = new EditableField("Description:", project.getOpis());

            // Configure components
            Item.setPreferredSize(new Dimension(preferredWidth, 160));
            Item.setBorder(BorderFactory.createLineBorder(Color.BLUE));
            Item.setLayout(new GridLayout(5, 1, 1, 1));
            Inner.setLayout(new FlowLayout());

            // Add components to view
            Item.add(Id);
            if (!project.getEditMode()) {
                Item.add(Nazwa);
                Item.add(Opis);
            } else {
                Item.add(NazwaEditable.field);
                Item.add(OpisEditable.field);
            }
            Item.add(Inner);
            Inner.add(Delete);
            Inner.add(Edit);
            Item.add(ValidationMsg);
            ProjectsView.add(Item);

            Delete.addActionListener(e -> {
                projects.DELETE(project.getId());
                ProjectsView.remove(Item);
                components.Utils.refresh(ProjectsView);
            });
            Edit.addActionListener(e -> {
                // "Please finish editing previous project" check.
                Map<Integer, Project> inEditMode = projects.getProjects().entrySet().stream().filter(p -> p.getValue().getEditMode())
                        .collect(Collectors.toMap(Map.Entry::getKey, Map.Entry::getValue));
                for (Integer i : inEditMode.keySet()) {
                    if (i != project.getId()) {
                        ValidationMsg.setText("Please finish editing previous project.");
                        return;
                    }
                }
                // Edit the project data if Confirming an edit.
                if (project.getEditMode()) {
                    try {
                        project.PUT(NazwaEditable.input.getText(), OpisEditable.input.getText());
                        projects.PUT(project);
                    } catch (ValidationException ex) {
                        ValidationMsg.setText(ex.getMessage());
                        return;
                    }
                }
                // Switch edit mode and rerender view.
                project.toggleEditMode();
                renderProjectsView();
            });
        });
        renderProjectsNewForm();
    }

    public void renderPeopleNewForm() {
        // Create components
        JLabel ValidationMsg = new JLabel("");
        JPanel NewItem = new JPanel();
        JButton NewItemButton = new JButton("Dodaj");
        JLabel NewItemLabel = new JLabel("Stwórz nową osobę");
        JPanel FieldsWrapper = new JPanel();
        EditableField First = new EditableField("Imie:", "");
        EditableField Last = new EditableField("Nazwisko:", "");

        // Configure components
        FieldsWrapper.setLayout(new GridLayout(2, 1, 1, 1));
        NewItem.setLayout(new GridLayout(4, 1, 1, 1));
        NewItem.setPreferredSize(new Dimension(preferredWidth, 200));

        // Add components to view
        FieldsWrapper.add(First.field);
        FieldsWrapper.add(Last.field);
        NewItem.add(NewItemLabel);
        NewItem.add(FieldsWrapper);
        NewItem.add(NewItemButton);
        NewItem.add(ValidationMsg);
        PeopleView.add(NewItem);

        NewItemButton.addActionListener(e -> {
            // Try to create a new item, if failed, display validation message.
            try {
                Person newItem = new Person(people.totalCount.increment(), First.input.getText(), Last.input.getText());
                people.PUT(newItem);
                renderPeopleView();
            } catch (ValidationException ex) {
                ValidationMsg.setText(ex.getMessage());
                return;
            }
        });
    }

    public void renderProjectsNewForm() {
        // Create components
        JLabel ValidationMsg = new JLabel("");
        JPanel NewItem = new JPanel();
        JButton NewItemButton = new JButton("Dodaj");
        JLabel NewItemLabel = new JLabel("Stwórz nowy projekt");
        JPanel FieldsWrapper = new JPanel();
        EditableField OpisNew = new EditableField("Opis:", "");
        EditableField NazwaNew = new EditableField("Nazwa:", "");

        // Configure components
        FieldsWrapper.setLayout(new GridLayout(2, 1, 1, 1));
        NewItem.setLayout(new GridLayout(4, 1, 1, 1));
        NewItem.setPreferredSize(new Dimension(preferredWidth, 200));

        // Add components to view
        FieldsWrapper.add(OpisNew.field);
        FieldsWrapper.add(NazwaNew.field);
        NewItem.add(NewItemLabel);
        NewItem.add(FieldsWrapper);
        NewItem.add(NewItemButton);
        NewItem.add(ValidationMsg);
        ProjectsView.add(NewItem);

        // Try to create a new item, if failed, display validation message.
        NewItemButton.addActionListener(e -> {
            try {
                Project newItem = new Project(projects.totalCount.increment(), NazwaNew.input.getText(), OpisNew.input.getText());
                projects.PUT(newItem);
                renderProjectsView();
            } catch (ValidationException ex) {
                ValidationMsg.setText(ex.getMessage());
                return;
            }
        });
    }

    public static void main(String[] args) {
        App app = new App();
        app.setVisible(true);
    }

    App() {
        super("CRM");
        this.setMinimumSize(new Dimension(600, 700));
        this.setContentPane(this.rootPanel);
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        renderPeopleView();
        renderProjectsView();
        nav.addChangeListener(e -> {
            switch (nav.getSelectedIndex()) {
                case 0:
                    renderPeopleView();
                case 1:
                    renderProjectsView();
            }
        });
    }
}
