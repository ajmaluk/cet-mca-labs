import java.util.Scanner;

class ArraySearch {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int size,i;
        int array[];
        System.out.print("Enter the Size of Array : ");
        size = sc.nextInt();
        array = new int[size];
        System.out.println("Enter the Elements : ");
        System.out.println("-------------------------------------");
        for(i=0;i<size;i++){
            System.out.print("Enter the "+ (i+1) +"th Element : ");
            array[i] = sc.nextInt();
        }

        System.out.print("Enter the Item to Search");

        int item = sc.nextInt();

        System.out.println("\nArray Seaching is Started !!!!! : ");
        
        int flag = 0;

        for(i = 0 ;i< size ;i++){
            if(array[i] == item){
                flag = 1;
                break;
            }
        }
        if(flag == 1){
            System.out.println("\nItem Found at "+ i + "th Position");
        }else{
            System.out.println("\nNot Found in Array");
        }
    }
}