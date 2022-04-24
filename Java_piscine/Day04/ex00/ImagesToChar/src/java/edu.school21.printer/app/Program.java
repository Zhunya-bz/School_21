package edu.school21.printer.app;

import edu.school21.printer.logic.Logic;

import java.io.IOException;

public class Program {

    public static void main(String[] args)  throws IOException {

        if (args.length != 3) {
            System.out.println("Invalid arguments");
            System.exit(0);
        }

        char white = args[0].charAt(0);
        char black = args[1].charAt(0);
        String path = args[2];
        Logic logic = new Logic();

        char [][] arrayToChar = logic.readBMP(white, black, path);

        for (int i = 0; i < arrayToChar.length; i++) {
            for (int j = 0; j < arrayToChar[i].length; j++) {
                System.out.print(arrayToChar[j][i]);
            }
            System.out.println();
        }

    }
}


