import utils.FileUtils;
import utils.TotalCount;
import utils.validation.ValidationException;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.*;

public class People {
    HashMap<Integer, Person> people = new HashMap<>();

    public HashMap<Integer, Person> getPeople() {
        return people;
    }

    public static String fileName;

    public TotalCount totalCount;

    public void loadFromFile() {
        FileUtils File = new FileUtils();

        File.loadFromFile(fileName, in -> {
            while (in.hasNextLine()) {
                String line = in.nextLine();
                ArrayList<String> csvColumns = new ArrayList<>(Arrays.asList(line.split("~")));
                int id = Integer.parseInt(csvColumns.get(0));
                String name = csvColumns.get(1);
                String surname = csvColumns.get(2);
                Person person  = null;
                try {
                    person = new Person(id, name, surname);
                } catch (ValidationException e) {
                    throw new RuntimeException(e);
                }
                people.put(person.getId(), person);
            }
            return null;
        });
    }

    public void saveToFile() throws FileNotFoundException {
        PrintWriter zapis = new PrintWriter("src/" + fileName);
        zapis.print("");
        people.forEach((i, project) -> {
            zapis.println(project.toCSV());
        });
        zapis.close();
    }

    public People(String fileName, String fileNameTotalCount) {
        People.fileName = fileName;
        totalCount = new TotalCount(fileNameTotalCount);
        try {
            loadFromFile();
        } catch(Exception e) {
            throw new RuntimeException(e.getMessage());
        }
    }

    public void DELETE(int id)  {
        people.remove(id);
        try {
            saveToFile();
        } catch (FileNotFoundException e) {
            throw new RuntimeException(e);
        }
    }

    public void PUT(Person person) {
        people.put(person.getId(), person);
        try {
            saveToFile();
        } catch (FileNotFoundException e) {
            throw new RuntimeException(e);
        }
    }
}
