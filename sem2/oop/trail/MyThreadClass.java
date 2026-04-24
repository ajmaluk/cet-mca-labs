// Thread using Thread class
public class MyThreadClass extends Thread {
    private String name;
    public MyThreadClass(String name) {
        this.name = name;
    }
    @Override
    public void run() {
        for (int i = 0; i <5; i++) {
            System.out.println(name + " (Thread) - Count: " + i);
            try {
                Thread.sleep(500);
            } catch (InterruptedException e) {
                System.out.println(name + " interrupted");
            }
        }
    }
    public static void main(String[] args) {
        MyThreadClass t1 = new MyThreadClass("Thread-A");
        MyThreadClass t2 = new MyThreadClass("Thread-B");
        t1.start();
        t2.start();
    }
}
