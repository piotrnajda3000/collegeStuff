package utils;

import java.io.File;
import java.util.Scanner;
import java.util.function.Function;

public class FileUtils {
    public void loadFromFile(String fileName, Function<Scanner, Void> cb) {
        try {
            File file = new File("src/" + fileName);
            Scanner in = new Scanner(file);
            cb.apply(in);
            in.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
