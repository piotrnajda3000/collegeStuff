import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Scanner;

public class Projects {
    HashMap<Integer, Project> projects = new HashMap<>();

    public String fileName;

    public void loadProjects(String inputFilename) {
        try {
            ClassLoader classLoader = getClass().getClassLoader();
            File file = new File(classLoader.getResource(inputFilename).getFile());
            Scanner in = new Scanner(file);
            while (in.hasNextLine()) {
                String projectLine = in.nextLine();
                ArrayList<String> projectInput = new ArrayList<>(
                        Arrays.asList(projectLine.split(",")));
                String nazwa = projectInput.get(0);
                String opis = projectInput.get(1);
                Project project  = new Project(nazwa, opis);
                projects.put(project.getId(), project);
                }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    public void saveProjects() throws FileNotFoundException {
        PrintWriter zapis = new PrintWriter("src/" + fileName);
        zapis.print("");
        projects.forEach((i, project) -> {
            zapis.println(project.toCSV());
        });
        zapis.close();
    }

    public Projects(String inputFilename) {
        this.fileName = inputFilename;
        try {
            loadProjects(inputFilename);
        } catch(Exception e) {
            return;
        }
    }

    public void delete(int id)  {
        projects.remove(id);
        try {
            saveProjects();
        } catch (FileNotFoundException e) {
            throw new RuntimeException(e);
        }
    }

    public void update(Project p) {
        projects.put(p.getId(), p);
        try {
            saveProjects();
        } catch (FileNotFoundException e) {
            throw new RuntimeException(e);
        }
    }
}
