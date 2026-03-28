
import mypackage.FileReaderUtil;
import mypackage.PackageDemo;

public class file {
    public static void main(String[] args) {
        // Show package demo
        PackageDemo.show();

        // File handling demonstration
        String filename = "file.txt";
        System.out.println("Reading from file: " + filename);
        FileReaderUtil.readFile(filename);
    }
    }
}
