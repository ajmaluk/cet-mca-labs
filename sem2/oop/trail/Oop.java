import java.util.Scanner;

class Shape{

    void area(int a){
        System.out.println("Area of Sqaure is : " + (a*a));
    }
    void area(int a,int b){
        System.out.println("Area of Rectangle is : " + (a*b));
    }
}


class Main{
    public static void main(String[] args){
        Shape rect = new Shape();
        Shape sq = new Shape();
        rect.area(10,20);
        sq.area(10);
    }
}