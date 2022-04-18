public class Program {
    public static void main(String[] args) {
        int number = 479598;
        int i = number / 10;
        int sum = 0;

        while (number != 0)
        {
            sum += number % 10;
            number = number / 10;
        }
        System.out.println(sum);
    }
}