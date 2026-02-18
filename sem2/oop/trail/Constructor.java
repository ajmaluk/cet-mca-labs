class Constructor{
    int a,b;
    Constructor(int a,int b){
        this.a = a;
        this.b = b;
    }
    Constructor(int a){
        this.a = a;
        this.b = 20;
    }
    void Display(){
        System.out.println("Values are : " + a + "and" + b);
    }

    public static void main(String[] args){
        Constructor c1 = new Constructor(10);
        Constructor c2 = new Constructor(20,40);
        c1.Display();
        c2.Display();
    }
}