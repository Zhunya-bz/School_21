import java.util.Arrays;
import java.util.Scanner;

public class Program {
    public static int ft_atoi(String str) {
        char [] array = new char[str.length()];
        array = str.toCharArray();
        int i = 0, num = 0;
        int sign = 1;
        while (((array[i] > 8) && (array[i] < 14)) || (array[i] == 32))
            i++;
        if ((array[i] == '-') || (array[i] == '+'))
        {
            if (array[i] == '-')
                sign = -1;
            i++;
        }
        while (i < str.length() && array[i] >= '0' && array[i] <= '9') {
            num = num * 10 + array[i] - '0';
            i++;
        }
        if (num == 0)
            return (-1);
        return (sign * num);
    }

    public static void checks(String visitName, String [] names, int visitTime, int [] times) {
        boolean fl = false;
        for (int i = 0; i < names.length; i++) {
            if (visitName.equals(names[i]))
                fl = true;
        }
        if (!fl)
            error("Name not correct!");
        fl = false;
        for (int i = 0; i < times.length; i++) {
            if (visitTime == times[i])
                fl = true;
        }
        if (!fl)
            error("Time not correct!");

    }

    public static void error(String str) {
        System.err.println(str);
        System.exit(-1);
    }

    public static int countHowMuchDays(String [] dayWeek, String [] daysWeekSept, int countWeeks) {
        int count = 0;
        for (int j = 0; j < daysWeekSept.length; j++) {
            for (int k = 0; k < countWeeks; k++) {
                if (daysWeekSept[j].equals(dayWeek[k]))
                    count++;
            }
        }
        return (count);
    }

    public static int readNames(Scanner sc, String [] names) {
        int i = 0;
        // читаем имена до точки
        while (sc.hasNextLine()) {
            if (i == 10)
                error("More then 10 students!");
            names[i] = sc.nextLine();
            if (names[i].equals(".")) {
                names[i] = null;
                break;
            }
            if (names[i].length() > 10)
                error("More then 10 characters of name!");
            i++;
        }
        return i;
    }

    public static int readTimeAndDayOfTheWeek(Scanner sc, int [] times, String [] dayWeek) {
        int i = 0;
        // читаем время и день недели до точки
        while (sc.hasNextLine()) {
            if (i == 10)
                error("More then 10 lessons!");
            times[i] = ft_atoi(sc.next());
            if (times[i] == -1)
                break;
            dayWeek[i] = sc.next();
            if (times[i] < 1 || times[i] > 6)
                error("Your lesson not in range");
            i++;
        }
        return i;
    }

    public static void readVisitedLesson(Scanner sc, int [] visitTimes, int countNames, int [] day, int countDay, int [][] isVisit, String [] names, int [] dayTime) {
        int p = 0;
        // считываем посещения учеников до точки
        while (sc.hasNextLine()) {
            String visitName = sc.next();
            if (visitName.equals("."))
                break;
            visitTimes[p] = ft_atoi(sc.next());
            int visitDate = ft_atoi(sc.next());
            String status = sc.next();

            //  проверяем совпала ли дата посещения и время посещения
            for (int j = 0; j < countNames; j++) {
                if (names[j].equals(visitName)) {
                    for (int k = 0; k < countDay; k++) {
                        if (day[k] == visitDate && dayTime[k] == visitTimes[p]) {
                            if (status.equals("HERE"))
                                isVisit[j][k] = 1;
                            else
                                isVisit[j][k] = -1;
                            break;
                        }
                    }
                }
            }
            p++;
//            checks(visitName, names, visitTime, times);
        }
    }

    public static void printTable(int countNames, int countWeeks, int count, String [] names, String [] dayWeek, int [] day, int [] times, int [][] isVisit, String [] ar) {
        // логика вывода таблички
        for (int j = 0; j < countNames + 1; j++) {
            String [] dayWeekCopy = new String[countWeeks]; // создаем копию массива
            for (int k = 0; k < count + 1; k++) {
                int q = 0;
                for (; q < countWeeks; q++) {
                    if (dayWeekCopy[q] != null) {
                        break;
                    }
                }
                if  (q == countWeeks) { // если весь массив равен null то создаем копию
                    for (int s = 0; s < countWeeks; s++) {
                        dayWeekCopy[s] = dayWeek[s];
                    }
                }
                if (j == 0) {
                    if (k == 0) {
                        System.out.printf("%10s", " ");
                        continue;
                    }
                    // здесь выкидываем элементы, которые уже нашли и идем дальше по циклу K
                    for (int r = 0; r < countWeeks; r++) {
                        if (dayWeekCopy[r] != null && dayWeekCopy[r].equals(ar[(day[k - 1] - 1) % 7])) {
                            System.out.printf("%1d:00%3s%3d|", times[r], dayWeek[r], day[k - 1]);
                            dayWeekCopy[r] = null;
                            break;
                        }
                    }
                }
                else {
                    if (k == 0)
                        System.out.printf("%10s", names[j - 1]);
                    else if (isVisit[j - 1][k - 1] != 0)
                        System.out.printf("%10d|", isVisit[j - 1][k - 1]);
                    else
                        System.out.printf("%10s|", " ");
                }
            }
            System.out.println();
        }
    }

    public static int fillArrays(int countWeeks, int [] day, int [] dayTime, int [] times, String [] dayWeek, String [] daysWeekSept) {
        int countDay = 0;
        for (int j = 0; j < 30; j++) {
            for (int k = 0; k < countWeeks; k++) {
                if (daysWeekSept[j].equals(dayWeek[k])) {
                    day[countDay] = j + 1;
                    dayTime[countDay++] = times[k];
                }
            }
        }
        return countDay;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String [] names = new String[10];

        int countNames = readNames(sc, names);

        int [] times = new int[10];
        String [] dayWeek = new String[10];

        int countWeeks = readTimeAndDayOfTheWeek(sc, times, dayWeek);

        // создаем массив дней недели 2020 года Сентябрь
        String [] ar = {"TE", "WE", "TH", "FR", "SA", "SU", "MO"};
        String [] daysWeekSept = new String [30];
        for (int j = 0; j < 30; j++) {
            daysWeekSept[j] = ar[j % 7];
        }
        // считаем количество дней, подходящих под наши введенные (с клавиатуры) дни недели (нужно для массива)
        int count = countHowMuchDays(dayWeek, daysWeekSept, countWeeks);

        int [] dayTime = new int[count]; // создаем массив для последовательного заполнения времени по дню недели
        int [] day = new int[count]; // создаем массив чисел дней недели

        int countDay = fillArrays(countWeeks, day, dayTime, times, dayWeek, daysWeekSept);

        int [][] isVisit = new int[countNames][count]; // создаем двумерный массив для посещения учеников
        for (int j = 0; j < countNames; j++) {
            for (int k = 0; k < count; k++) {
                isVisit[j][k] = 0;
            }
        }
        int [] visitTimes = new int[count];

        readVisitedLesson(sc, visitTimes, countNames, day, countDay, isVisit, names, dayTime);

        printTable(countNames, countWeeks, count, names, dayWeek, day, times, isVisit, ar);

    }
}