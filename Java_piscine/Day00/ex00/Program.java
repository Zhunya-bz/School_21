public class Program {
    public static void main(String[] args) {
        int number = 479598;
        int sum = 0;

//        while (number != 0)
//        {
//            sum += number % 10;
//            number = number / 10;
//        }
        sum += number % 10 + (number / 10) % 10 + (number / 100) % 10 + (number / 1000) % 10 + (number / 10000) % 10 + (number / 100000) % 10;
        System.out.println(sum);
    }
}