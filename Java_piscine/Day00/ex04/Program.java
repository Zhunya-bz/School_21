import java.util.Arrays;
import java.util.Scanner;

public class Program {
    public static int [] fillCharArrays(String str, int [] countStrOccur) {
        char [] charInitStr = str.toCharArray();

        for (int i = 0; i < charInitStr.length; i++) {
            if (countStrOccur[i] < 999) // количество появлений символа должно быть меньше 999
                countStrOccur[charInitStr[i]] += 1; // добавляем единицу к числовому представлению символа (A=65)
            else {
                System.err.println("The number of character occurrences more then 999");
                System.exit(-1);
            }
        }
//        System.out.println(Arrays.toString(countStrOccur));
        return countStrOccur;
    }

    public static void findMaxOccur(char [] maxOccurChar, int [] maxOccurCount, int [] countStrOccur) {
        int max, maxId;

        for (int j = 0; j < 10; j++) {
            max = 0;
            maxId = 0;
            for (int i = 0; i < countStrOccur.length; i++) {
                if (countStrOccur[i] > max) {
                    max = countStrOccur[i];
                    maxId = i;
                }
            }
            countStrOccur[maxId] = 0;
            maxOccurChar[j] = (char)maxId;
            maxOccurCount[j] = max;
        }

//        System.out.println(Arrays.toString(maxOccurChar));
//        System.out.println(Arrays.toString(maxOccurCount));
    }

    public static void printDiagram(int [] maxOccurCount, char [] maxOccurChar) {
        int lenJ = 0; // нахождение длины массива maxOccurCount, если он меньше 10 (ширина диаграммы)
        for (int j = maxOccurCount.length - 1; j >= 0; j--) {
            if (maxOccurCount[j] != 0) {
                lenJ = j + 1;
                break;
            }
        }
        int lenI; // высота диаграммы в зависимости от количества вхождений
        if (maxOccurCount[0] > 11)
            lenI = 12;
        else
            lenI = maxOccurCount[0] + 2;

        String space; // нужно для вывода
        int x; // для подсчета соотношения
        for (int i = 0; i < lenI; i++) {
            for (int j = 0; j < lenJ; j++) {
                if (maxOccurCount[j] > 9)
                    space = "";
                else
                    space = " ";
                if (i == 0 && maxOccurCount[0] == maxOccurCount[j]) {
                    System.out.print(space + maxOccurCount[j] + " ");
                }
                else if (i == lenI - 1) { // последняя строка сиволов
                    System.out.print(" " + maxOccurChar[j] + " ");
                }
                else
                {
                    if (maxOccurCount[0] > 11)
                        x = maxOccurCount[j] * 100 / maxOccurCount[0] / 10; // считаем какая часть от 100% и / 10 - получаем количество #
                    else
                        x = maxOccurCount[j];
                    if (lenI - i - 2 == x) // выводим число вхождениий
                        System.out.print(space + maxOccurCount[j] + " ");
                    else if (lenI - i - 2 < x)
                        System.out.print(" # ");
                    else
                        System.out.print("  ");
                }
            }
            System.out.println();
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String str = sc.nextLine();
        sc.close();

        int [] countStrOccur = new int[65536];
        countStrOccur = fillCharArrays(str, countStrOccur);

        char [] maxOccurChar = new char[10];
        int [] maxOccurCount = new int[10];
        findMaxOccur(maxOccurChar, maxOccurCount, countStrOccur);
        printDiagram(maxOccurCount, maxOccurChar);
    }
}

// AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAASSSSSSSSSSSSSSSSSSSSSSSSDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDWEWWKFKKDKKDSKAKLSLDKSKALLLLLLLLLLRTRTETWTWWWWWWWWWWOOOOOOO42