
import java.util.Scanner;

public class Program {
    public static void checkGrade(int grade) {
        if (grade < 1 || grade > 9)
        {
            System.err.println("IllegalArgument");
            System.exit(-1);
        }
    }
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String week = "";
        long data = 0;
        int dataOrder = 0;

        while (!(week = in.nextLine()).equals("42") && ++dataOrder <= 18)
        {
            if (!week.equals("Week " + dataOrder))
            {
                System.err.println("IllegalArgument");
                System.exit(-1);
            }
            int grade1 = in.nextInt();
            checkGrade(grade1);
            for (int i = 0; i < 4; i++) // find minimum
            {
                int grade2 = in.nextInt();
                checkGrade(grade2);
                if (grade2 < grade1)
                    grade1 = grade2;
            }
            long pow = 1;
            for (int i = 0; i < dataOrder - 1; i++)
                pow = pow * 10;
            data = grade1 * pow + data;    // 71 -> 17 // 713 -> 317
            in.nextLine();
        }
        long count = 0;
        for (int i = 1; i <= dataOrder; i++)
        {
            System.out.printf("Week " + i + "\t");
            count = data % 10;
            data = data / 10;
            for (int j = 0; j < count; j++)
                System.out.print("=");
            System.out.println(">");
        }
        in.close();
    }
}
