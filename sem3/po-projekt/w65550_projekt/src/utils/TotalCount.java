package utils;

import java.io.PrintWriter;

public class TotalCount {
    private final String fileName;
    private  int get() {
        var ref = new Object() {
            int totalId = 0;
        };
        FileUtils File = new FileUtils();


        File.loadFromFile(fileName, in -> {
            while (in.hasNextLine()) {
                ref.totalId = Integer.parseInt(in.nextLine());
            }
            return null;
        });

        return ref.totalId;
    }

    public int increment() {
        int oldTotal = get();
        int newTotal = oldTotal + 1;
        try {
            PrintWriter zapis = new PrintWriter("src/" + fileName);
            zapis.print(newTotal);
            zapis.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
        return newTotal;
    }

    public TotalCount(String fileName) {
        this.fileName = fileName;
    }
}
