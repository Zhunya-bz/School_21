import java.lang.Thread;

public class Program {
    public static int count = 0;

    public static class MyThread extends Thread {
        private String str;
        public MyThread(String str) {
            this.str = str;
        }
        @Override
        public void run() {
            for (int i = 0; i < count; i++) {
                System.out.println(str);
            }
        }
    }

    public static void main(String[] args) {

        if (args.length == 0) {
            System.out.println("Invalid arguments");
            System.exit(0);
        }

        if (args[0].startsWith("--count="))
            count = Integer.parseInt(args[0].substring(args[0].indexOf('=') + 1));

        MyThread myThread = new MyThread("Egg");
        MyThread myThread2 = new MyThread("Hen");
        myThread.start();
        myThread2.start();

        try {
            myThread.join();
            myThread2.join();
        } catch (InterruptedException e) {
            System.out.println(e.getMessage());
        }

        for (int i = 0; i < count; i++)
            System.out.println("Human");

    }
}