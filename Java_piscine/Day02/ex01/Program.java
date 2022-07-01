import java.io.FileNotFoundException;
import java.io.IOException;

public class Program {
    public static void main(String[] args) throws IOException {
        if (args.length == 2) {
            Application app = new Application();
            app.readFromFiles(args);
            System.out.format("%.2f", app.similarity());
            app.createDict();
        }
        else
            System.out.println("Wrong arguments!");
    }
}
