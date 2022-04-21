import java.util.Scanner;
import java.io.IOException;

public class Program {
    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(System.in);
        String str;

        while (!((str = scanner.nextLine()).equals("42")))
        {
            Signature sig = new Signature();
            sig.readFile();
            sig.enterFile(str);
        }
    }
}