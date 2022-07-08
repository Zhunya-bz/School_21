package edu.school21.printer.logic;

import com.diogonunes.jcdp.color.ColoredPrinter;
import com.diogonunes.jcdp.color.api.Ansi;

import java.awt.*;
import java.awt.image.BufferedImage;
import javax.imageio.ImageIO;
import java.io.IOException;

public class Logic {

    public Logic(){};

    public void readBMP(String white, String black) throws IOException {
        BufferedImage image = ImageIO.read(Logic.class.getResource("/resources/image.bmp"));
        int array[][] = new int[image.getWidth()][image.getHeight()];

        ColoredPrinter cpWhite = new ColoredPrinter.Builder(1, false)
                .background(Ansi.BColor.valueOf(white))
                .build();

        ColoredPrinter cpBlack = new ColoredPrinter.Builder(1, false)
                .background(Ansi.BColor.valueOf(black))
                .build();

        for (int xPixel = 0; xPixel < image.getWidth(); xPixel++)
        {
            for (int yPixel = 0; yPixel < image.getHeight(); yPixel++)
            {
                int color = image.getRGB(yPixel, xPixel);
                if (color == Color.BLACK.getRGB()) {
                    cpBlack.print(" ");
                } else {
                    cpWhite.print(" ");
                }
            }
//            cpBlack.setBackgroundColor(Ansi.BColor.NONE);
//            cpWhite.setBackgroundColor(Ansi.BColor.NONE);
            cpWhite.clear();
            cpWhite.print("\n");
//            cpWhite.setBackgroundColor(Ansi.BColor.valueOf(white));
            cpWhite.setBackgroundColor(Ansi.BColor.valueOf(white));
//            System.out.println();
//            cpWhite.clear();
        }
    }

}