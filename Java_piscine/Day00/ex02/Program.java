import java.util.Scanner;

/*
 Наименьший делитель составного числа n не превосходит sqrt(n).
 */

public class Program {
    public static int sumNum(int number) {
        int sum = 0;
        while (number != 0)
        {
            sum += number % 10;
            number = number / 10;
        }
        return (sum);
    }

    public static int isPrime(int num) {
        int i = 2;
        for (i = 2; i * i <= num ; i++)
        {
            if (num % i == 0)
                break;
        }
        if (num <= 1) {
            System.err.println("IllegalArgument");
            System.exit(-1);
        }
        if (i * i > num || num == 3)
            return (1);
        else
            return (0);
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int coffee = 0;
        int num = in.nextInt();

        while (num != 42)
        {
            int rezSum = sumNum(num);
            if (isPrime(rezSum) == 1) {
                coffee++;
            }
            num = in.nextInt();
        }
        System.out.println("Count of coffee - request - " + coffee);
        in.close();
    }
}