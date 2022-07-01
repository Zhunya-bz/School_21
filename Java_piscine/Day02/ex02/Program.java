import java.io.*;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.Scanner;

import static java.nio.file.StandardCopyOption.REPLACE_EXISTING;

public class Program {
    private static String curPath;

    public static void ls() {
        File file = new File(curPath);
        for (File item : file.listFiles()) {
            System.out.println(item.getName() + " " + Math.round((double) item.length() / 1024) + " KB");
        }
    }
    public static void cd(String [] in) {
        String cdPath = in[1];
        curPath += "/";
        if (cdPath.isEmpty())
            curPath = "/";
        if (Paths.get(cdPath).isAbsolute() && Files.isDirectory(Paths.get(cdPath)))
            curPath = cdPath;
        else if (Files.exists(Paths.get(curPath + cdPath)) &&
                Files.isDirectory(Paths.get(curPath + cdPath))) {
            curPath += cdPath;
        }
        else
            System.out.println("Dosn't go");
        System.out.println(Paths.get(curPath).normalize());
    }

    public static void mv(String [] in) throws IOException {
        String fileFrom;
        String fileTo;
        String name = "";
        int x = in[1].lastIndexOf("/");
        if (x >= 0)
            name = in[1].substring(x);
        else
            name = in[1];
        if (Paths.get(in[1]).isAbsolute())
            fileFrom = in[1];
        else
            fileFrom = curPath + "/" + name;
        if (Paths.get(in[2]).isAbsolute())
            fileTo = in[2] + "/" + name;
        else
            fileTo = curPath + "/" + in[2];

        if (Files.exists(Paths.get(fileFrom)) &&
                !Files.isDirectory(Paths.get(fileFrom))) {
            if (Files.isDirectory(Paths.get(fileTo))) {
                fileTo = fileTo + "/" + name;
            }
            Files.move(Paths.get(fileFrom).normalize(), Paths.get(fileTo).normalize(), REPLACE_EXISTING);
        }
    }

    public static void main(String[] args) throws IOException {
        if (args.length == 1 && args[0].startsWith("--current-folder=")) {
            Scanner sc = new Scanner(System.in);
            curPath = args[0].substring(args[0].indexOf("=") + 1);
            Path path = Paths.get(curPath);
            if (!path.isAbsolute() || Files.notExists(path) || !Files.isDirectory(path)) {
                System.err.println("Wrong current folder");
                return;
            }
            System.out.println(curPath);
            while (true) {
                System.out.print("-> ");
                String input = sc.nextLine();
                String [] in = input.split(" ");
                if (input.equals("ls")) {
                    ls();
                } else if (in[0].equals("cd")) {
                    if (in.length != 2) {
                        System.out.println("Wrong argument");
                        continue;
                    }
                    cd(in);
                }
                else if (in[0].equals("mv")) {
                    if (in.length != 3) {
                        System.out.println("Wrong argument");
                        continue;
                    }
                    mv(in);
                }
                else if (in[0].equals("exit"))
                    break;
                else
                    System.out.println("Command not found");
            }
        }
        else
            System.out.println("Wrong arguments!");
    }
}
