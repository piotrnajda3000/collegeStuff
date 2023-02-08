import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.*;

public class People {
    HashMap<Integer, Person> people = new HashMap<>();

    public HashMap<Integer, Person> getPeople() {
        return people;
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
                String name = csvColumns.get(0);
                String surname = csvColumns.get(1);
                Person person  = new Person(name, surname);
                people.put(person.getId(), person);
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    public void saveToFile() throws FileNotFoundException {
        PrintWriter zapis = new PrintWriter("src/" + fileName);
        zapis.print("");
        people.forEach((i, project) -> {
            zapis.println(project.toCSV());
        });
        zapis.close();
    }

    public People(String inputFilename) {
        this.fileName = inputFilename;
        try {
            loadFromFile(inputFilename);
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
