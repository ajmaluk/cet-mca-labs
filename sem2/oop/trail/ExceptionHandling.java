import java.io.*;
import java.util.*;

class ExceptionHandling{
    public static void main(String[] args){
        try{
            Scanner s = new Scanner(System.in);
            int a = s.nextInt();
            int b = s.nextInt();
            int c = a/b;
            System.out.println(c);
        }catch(Exception e){
            System.out.println(e);
        }finally{
            System.out.println("From Finnaly");
        }
    }
}