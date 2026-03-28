import java.util.ArrayList;

public class ArrayListDemo {
    public static void main(String[] args) {
        // Create an ArrayList of Integers
        ArrayList<Integer> intList = new ArrayList<>();
        intList.add(10);
        intList.add(20);
        intList.add(30);
        System.out.println("Integer ArrayList: " + intList);

        // Remove an element
        intList.remove(Integer.valueOf(20));
        System.out.println("After removing 20: " + intList);

        // Create an ArrayList of Strings
        ArrayList<String> strList = new ArrayList<>();
        strList.add("Apple");
        strList.add("Banana");
        strList.add("Cherry");
        System.out.println("String ArrayList: " + strList);

        // Access elements
        System.out.println("First element: " + strList.get(0));

        // Iterate using for-each
        System.out.print("All elements: ");
        for (String fruit : strList) {
            System.out.print(fruit + " ");
        }
        System.out.println();
    }
}
