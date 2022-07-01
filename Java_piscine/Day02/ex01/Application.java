import java.io.*;
import java.util.*;

public class Application {
    private  List<String> list1;
    private  List<String> list2;
    private List<Integer> vectorA;
    private List<Integer> vectorB;
    private TreeSet<String> treeSet;
    private  int size;


    public Application() {
        list1 = new ArrayList<>();
        list2 = new ArrayList<>();
        vectorA = new ArrayList<>();
        vectorB = new ArrayList<>();
        size = 0;
    }
    private int countOccur(List<String> list, String str) {
        int count = 0;
        for (int j = 0; j < list.size(); j++) {
            if (list.get(j).equals(str)) {
                count++;
            }
        }
        return count;
    }

    private void fillArray(BufferedReader br, List<String> list) throws IOException {
        String line;
        String [] ar;
        while((line = br.readLine()) != null) {
            ar = line.split(" ");
            list.addAll(Arrays.asList(ar));
        }
        br.close();
    }

    public double similarity() {
        int numerator = 0;
        for (int i = 0; i < size; i++) {
            numerator += vectorA.get(i) * vectorB.get(i);
        }
        int sum = 0;
        int sum2 = 0;
        for (int i = 0; i < size; i++) {
            sum += Math.pow(vectorA.get(i), 2);
            sum2 += Math.pow(vectorB.get(i), 2);
        }
        double res = numerator / (Math.sqrt(sum) * Math.sqrt(sum2));
        return Math.round((int)(res * 100)) / 100.0;
    }

    public void createDict() throws IOException {
        FileWriter fw = new FileWriter("dictionary.txt", false);
        for (String str: treeSet) {
            fw.write(str + " ");
        }
        fw.close();
    }

    public void readFromFiles(String [] args) throws IOException {
        FileReader reader1 = new FileReader(args[0]);
        FileReader reader2 = new FileReader(args[1]);
        BufferedReader br1 = new BufferedReader(reader1);
        BufferedReader br2 = new BufferedReader(reader2);
        fillArray(br1, list1);
        fillArray(br2, list2);
        reader1.close();
        reader2.close();

        treeSet = new TreeSet<>(list1);
        treeSet.addAll(list2);
        size = treeSet.size();

        for (String str : treeSet) {
            vectorA.add(countOccur(list1, str));
            vectorB.add(countOccur(list2, str));
        }
    }
}
