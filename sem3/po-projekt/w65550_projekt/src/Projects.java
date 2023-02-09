import utils.FileUtils;
import utils.TotalCount;
import utils.validation.ValidationException;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.*;

public class Projects {
    private final HashMap<Integer, Project> projects = new HashMap<>();

    public HashMap<Integer, Project> getProjects() {
        return projects;
    }

    public String fileName;

    public TotalCount totalCount;

    public void loadFromFile() {
        FileUtils File = new FileUtils();
        File.loadFromFile(fileName, in -> {
            while (in.hasNextLine()) {
                String line = in.nextLine();
                ArrayList<String> csvColumns = new ArrayList<>(Arrays.asList(line.split("~")));
                int id = Integer.parseInt(csvColumns.get(0));
                String nazwa = csvColumns.get(1);
                String opis = csvColumns.get(2);
                Project project  = null;
                try {
                    project = new Project(id, nazwa, opis);
                } catch (ValidationException e) {
                    throw new RuntimeException(e);
                }
                projects.put(project.getId(), project);
            }
            return null;
        });
    }

    public void saveToFile() throws FileNotFoundException {
        PrintWriter zapis = new PrintWriter("src/" + fileName);
        zapis.print("");
        projects.forEach((i, project) -> {
            zapis.println(project.toCSV());
        });
        zapis.close();
    }

    public Projects(String inputFilename, String fileNameTotalCount) {
        this.fileName = inputFilename;
        totalCount = new TotalCount(fileNameTotalCount);
        try {
            loadFromFile();
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
