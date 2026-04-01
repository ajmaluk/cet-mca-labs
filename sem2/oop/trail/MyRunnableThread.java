// Thread using Runnable interface
public class MyRunnableThread implements Runnable {
    private String name;
    public MyRunnableThread(String name) {
        this.name = name;
    }
    @Override
    public void run() {
        for (int i = 1; i <= 5; i++) {
            System.out.println(name + " (Runnable) - Count: " + i);
            try {
                Thread.sleep(500);
            } catch (InterruptedException e) {
                System.out.println(name + " interrupted.");
            }
        }
    }
    public static void main(String[] args) {
        Thread t1 = new Thread(new MyRunnableThread("Thread-1"));
        Thread t2 = new Thread(new MyRunnableThread("Thread-2"));
        t1.start();
        t2.start();
    }
}
