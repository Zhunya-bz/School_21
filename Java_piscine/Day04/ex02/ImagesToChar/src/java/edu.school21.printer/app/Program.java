package edu.school21.printer.app;

import com.beust.jcommander.JCommander;
import com.beust.jcommander.Parameter;
import com.beust.jcommander.Parameters;
import edu.school21.printer.logic.Logic;
import java.io.IOException;

import static edu.school21.printer.app.SeparatorEqual.black;
import static edu.school21.printer.app.SeparatorEqual.white;

@Parameters(separators = "=")
class SeparatorEqual {
    @Parameter(names={"--white"})
    public static String white;
    @Parameter(names={"--black"})
    public static String black;
}

public class Program {

    public static void main(String ... args)  throws IOException {

        SeparatorEqual se = new SeparatorEqual();
        JCommander.newBuilder()
                .addObject(se)
                .build()
                .parse(args);

        Logic logic = new Logic();
        logic.readBMP(white, black);
    }
}


