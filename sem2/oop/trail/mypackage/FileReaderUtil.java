package mypackage;

import java.io.File;
import java.util.Scanner;

public class FileReaderUtil {
    public static void readFile(String filename) {
        try {
            File file = new File(filename);
            Scanner sc = new Scanner(file);
            while (sc.hasNextLine()) {
                System.out.println(sc.nextLine());
            }
            sc.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
