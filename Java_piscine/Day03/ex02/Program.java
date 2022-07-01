import java.lang.Thread;
import java.util.Random;

public class Program {
    public static int size = 0;
    public static int thredCount = 0;
    public static int countNumber = 0;
    public static int sumThread = 0;
    public static int i = 0;

    public static class MyThread extends Thread {
        private int count;
        private Integer [] array;
        private int summa;
        private int iStart;
        private int countNum;

        public MyThread(int countNum, int count, Integer [] array) {
            this.countNum = countNum;
            this.count = count;
            this.array = array;
            this.summa = 0;
            this.iStart = i;
        }
        @Override
        public void run() {
            synchronized (this) {
                for (; i < countNum; i++) {
                    summa += array[i];
                    sumThread += summa;
                }
                System.out.println("Thread " + count + ": from " + iStart + " to " + (i - 1) + " sum is " + summa);
            }
        }
    }

    private static void error() {
        System.out.println("Invalid arguments");
        System.exit(-1);
    }

    public static void main(String[] args) throws InterruptedException {

        if (args.length != 2)
            error();

        if (args[0].startsWith("--arraySize="))
            size = Integer.parseInt(args[0].substring(args[0].indexOf('=') + 1));
        else
            error();
        if (args[1].startsWith("--threadsCount="))
            thredCount = Integer.parseInt(args[1].substring(args[1].indexOf('=') + 1));
        else
            error();

        if (size > 2000000 || thredCount > 2000000 || size < 0 || thredCount < 0) {
            System.out.println("Wrong thread size or thread count");
            System.exit(-1);
        }

        Integer [] array = new Integer[size];
        Random rand = new Random();

        countNumber = size / thredCount;
        int sum = 0;

        for (int i = 0; i < size; i++) {
            array[i] = rand.nextInt(10);
            sum += array[i];
        }
        System.out.println("Sum: " + sum);
        for (int i = 0; i < thredCount - 1; i++) {
            MyThread myThread = new MyThread(countNumber * (i + 1), i + 1, array);
            myThread.start();
            myThread.join();
        }
        MyThread myThread2 = new MyThread(size, thredCount, array);
        myThread2.start();
        myThread2.join();

        System.out.println("Sum by threads: " + sum);
    }
}