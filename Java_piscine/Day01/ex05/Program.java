import java.util.Arrays;
import java.util.Scanner;
import java.util.UUID;

public class Program {
    public static void main(String[] args) throws UserNotFoundException, IllegalTransactionException {
        if (args.length != 1)
            System.exit(-1);

        Scanner sc = new Scanner(System.in);
        Menu menu = new Menu();
        if (args[0].equals("--profile=dev")) {
            menu.launch(false);
        }
        else if (args[0].equals("--profile=production")) {
            menu.launch(true);
        }
    }
}