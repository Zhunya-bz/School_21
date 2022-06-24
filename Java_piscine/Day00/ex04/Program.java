import java.util.Scanner;

public class Program {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String str = sc.nextLine();
        sc.close();

        char [] countStrOccur = new char[65536];
        char [] charInitStr = str.toCharArray();

        for (int i = 0; i < charInitStr.length; i++) {
            if (countStrOccur[i] < 999) // количество появлений символа должно быть меньше 999
                countStrOccur[charInitStr[i]]++; // добавляем единицу к числовому представлению символа (A=65)
            else {
                System.out.println("The number of character occurrences more then 999");
                System.exit(-1);
            }
        }

        char [] maxOccur = new char[10];


    }
}