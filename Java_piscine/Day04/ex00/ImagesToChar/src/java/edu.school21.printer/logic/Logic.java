package edu.school21.printer.logic;

import java.awt.*;
import java.awt.image.BufferedImage;
import javax.imageio.ImageIO;
import java.io.File;
import java.io.IOException;

public class Logic {

    public Logic(){};

    public char[][] readBMP(char white, char black, String path) throws IOException {
        File file = new File(path);
        BufferedImage image = ImageIO.read(file);
        char[][] array = new char[image.getWidth()][image.getHeight()];

        for (int i = 0; i < image.getWidth(); i++)
        {
            for (int j = 0; j < image.getHeight(); j++)
            {
                int color = image.getRGB(i, j);
                if (color == Color.BLACK.getRGB())
                    array[i][j] = black;
                else if (color == Color.WHITE.getRGB())
                    array[i][j] = white;
            }
        }
        return (array);
    }

}