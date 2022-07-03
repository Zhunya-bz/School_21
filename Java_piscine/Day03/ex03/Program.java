import java.io.*;
import java.util.ArrayList;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

public class Program {
    private static int countThread;

    private static void error(String str) {
        System.out.println(str);
        System.exit(-1);
    }

    public static void main(String[] args) throws IOException {
        if (args.length != 1)
            error("Wrong arguments");
        if (args[0].startsWith("--threadsCount="))
            countThread = Integer.parseInt(args[0].substring(args[0].indexOf("=") + 1));
        else
            error("Wrong arguments");

        ExecutorService executor = Executors.newFixedThreadPool(countThread);

        FileReader reader = new FileReader("_urls.txt");
        BufferedReader br = new BufferedReader(reader);

        ArrayList<String> list = new ArrayList<>();
        String line;
        while ((line = br.readLine()) != null)
            list.add(line);

        for (int i = 0; i < list.size(); i++) { // даем столько задач сколько в файле
            executor.submit(new Download(list.get(i), i));
        }
        executor.shutdown();
    }
}