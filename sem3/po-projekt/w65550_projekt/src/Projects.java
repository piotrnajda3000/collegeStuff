import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.*;

public class Projects {
    private final HashMap<Integer, Project> projects = new HashMap<>();

    public HashMap<Integer, Project> getProjects() {
        return projects;
    }

    public String fileName;

    public void loadFromFile(String inputFilename) {
        try {
            ClassLoader classLoader = getClass().getClassLoader();
            File file = new File(Objects.requireNonNull(classLoader.getResource(inputFilename)).getFile());
            Scanner in = new Scanner(file);
            while (in.hasNextLine()) {
                String line = in.nextLine();
                ArrayList<String> csvColumns = new ArrayList<>(Arrays.asList(line.split("~")));
                String nazwa = csvColumns.get(0);
                String opis = csvColumns.get(1);
                Project project  = new Project(nazwa, opis);
                projects.put(project.getId(), project);
                }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    public void saveToFile() throws FileNotFoundException {
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
            loadFromFile(inputFilename);
        } catch(Exception e) {
            throw new RuntimeException(e.getMessage());
        }
    }

    public void DELETE(int id)  {
        projects.remove(id);
        try {
            saveToFile();
        } catch (FileNotFoundException e) {
            throw new RuntimeException(e);
        }
    }

    public void PUT(Project p) {
        projects.put(p.getId(), p);
        try {
            saveToFile();
        } catch (FileNotFoundException e) {
            throw new RuntimeException(e);
        }
    }
}
