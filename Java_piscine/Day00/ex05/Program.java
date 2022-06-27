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

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String [] names = new String[10];
        int i = 0;
        int countNames;
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
        countNames = i;
        i = 0;
        int [] times = new int[10];
        String [] dayWeek = new String[10];
        while (sc.hasNextLine()) {
            if (i == 10)
                error("More then 10 lessons!");
            times[i] = ft_atoi(sc.next());
            if (times[i] == -1) {
                break;
            }
//            System.out.println(times[i]);
            dayWeek[i] = sc.next();
            if (times[i] < 1 || times[i] > 6)
                error("Your lesson not in range");
            i++;
        }
        int countWeeks = i;
//        System.out.println("dayWeek " + Arrays.toString(dayWeek));

        String [] ar = {"TE", "WE", "TH", "FR", "SA", "SU", "MO"};
        String [] daysWeekSept = new String [30];
        for (int j = 0; j < 30; j++) {
            daysWeekSept[j] = ar[j % 7];
        }
        int count = countHowMuchDays(dayWeek, daysWeekSept, countWeeks);
//        System.out.println(count);
//        System.out.println(Arrays.toString(daysWeekSept));
        int [] day = new int[count]; // !!!!!!!!!
        int m = 0;
        for (int j = 0; j < 30; j++) {
            for (int k = 0; k < countWeeks; k++) {
                if (daysWeekSept[j].equals(dayWeek[k])) {
                    day[m++] = j + 1;
                }
            }
        }
        System.out.println(Arrays.toString(day));
//        System.out.println(Arrays.toString(names));
//        System.out.println(Arrays.toString(times));


        int [][] isVisit = new int[countNames][count];
        for (int j = 0; j < countNames; j++) {
            for (int k = 0; k < count; k++) {
                isVisit[j][k] = 0;
            }
        }
        int [] visitTimes = new int[countWeeks];
        int p = 0;
        while (sc.hasNextLine()) {
            String visitName = sc.next();
            if (visitName.equals("."))
                break;
//            int visitTime = ft_atoi(sc.next());
            visitTimes[p] = ft_atoi(sc.next());
            int visitDate = ft_atoi(sc.next());
            String status = sc.next();

            for (int j = 0; j < countNames; j++) {
                if (names[j].equals(visitName)) {
                    for (int k = 0; k < m; k++) {
                        for (int h = 0; h < countWeeks; h++) {
                            if (day[k] == visitDate && times[h] == visitTimes[p]) {
                                if (status.equals("HERE"))
                                    isVisit[j][k] = 1;
                                else
                                    isVisit[j][k] = -1;
                            }
                        }
                    }
                }
            }
            p++;
//            System.out.println(Arrays.deepToString(isVisit));
//            checks(visitName, names, visitTime, times);
        }


        for (int j = 0; j < countNames + 1; j++) {
            for (int k = 0; k < count + 1; k++) {
                if (j == 0) {
                    if (k == 0) {
                        System.out.printf("%10s", " ");
                        continue;
                    }

                    for (int r = 0; r < countWeeks; r++) {
                        for (int w = 0; w < p; w++) {
                            if (dayWeek[r].equals(ar[(day[k - 1] - 1) % 7]) && times[r] == visitTimes[w]) {
                                System.out.printf("%1d:00%3s%3d|", times[r], dayWeek[r], day[k - 1]);
                            }
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
}