import java.lang.Thread;

public class Program {
    public static int count = 0;
    public static int flag = 0;

    public static class ProducerConsumer {
        private String str;
        public void produce() throws InterruptedException {
                synchronized (this) {
                    if (flag == 0)
                        wait();
                    System.out.println("Egg");
                    flag = 0;
                    notify();
                }
        }
        public void consume() throws InterruptedException {
                synchronized (this) {
                    if (flag == 1)
                        wait();
                    System.out.println("Hen");
                    flag = 1;
                    notify();
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

        ProducerConsumer pr = new ProducerConsumer();
        Thread myThread1 = new Thread(new Runnable() {
            @Override
            public void run() {
                try {
                    for (int i = 0; i < count; i++) {
                        pr.produce();
                    }
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
        });
        Thread myThread2 = new Thread(new Runnable() {
            @Override
            public void run() {
                try {
                    for (int i = 0; i < count; i++) {
                        pr.consume();
                    }
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
        });

        myThread1.start();
        myThread2.start();

        try {
            myThread1.join();
            myThread2.join();
        } catch (InterruptedException e) {
            System.out.println(e.getMessage());
        }


    }
}