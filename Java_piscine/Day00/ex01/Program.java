import java.util.Scanner;

/*
 Наименьший делитель составного числа n не превосходит sqrt(n).
 */

public class Program {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int num = in.nextInt();

        int i = 2;
        for (i = 2; i * i <= num; i++)
        {
            if (num % i == 0)
                break;
        }
        if (num <= 1) {
            System.out.println("IllegalArgument");
            in.close();
            System.exit(-1);
        }
        if (i * i > num || num == 3)
            System.out.println("true " + --i);
        else
            System.out.println("false " + --i);

        in.close();
    }
}