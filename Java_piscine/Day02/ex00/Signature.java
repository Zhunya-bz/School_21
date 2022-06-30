import java.io.File;
import java.io.BufferedReader;
import java.io.IOException;
import java.util.HashMap;
import java.util.Map;
import java.io.FileInputStream;
import java.io.FileOutputStream;

public class Signature {

    private HashMap<String, String> map;
    private int count;
    public Signature(){
        map = new HashMap<>();
        count = 0;
    };

    public void readFile() throws IOException{
        FileInputStream file = new FileInputStream("./signatures.txt");
        byte[] buffer = new byte[file.available()]; //  массив байтов
        file.read(buffer, 0, file.available()); // читаем в буффер
        String result = "";

        for (int i = 0; i < buffer.length; i++)
        {
            if (buffer[i] != 32)
                result += (char)buffer[i];
        }
        String [] arrStr = result.split("\n");

        for (String line : arrStr)
        {
            String byt = line.substring(line.indexOf(',') + 1);
            int c = byt.length();
            if (c > count)
                count = c;
            map.put(line.substring(0, line.indexOf(',')), byt);
        }
    }
    public void enterFile(String str) throws IOException {
        File files = new File(str);
        if (!files.exists())
        {
            System.out.println("file not found!");
            return;
        }
        FileInputStream file = new FileInputStream(str);
        int i;
        int c = 0;
        int flag = 0;
        String result = "";

        while ((i = file.read()) != -1) // читаем в буффер
        {
            if (c >= count / 2)
                break;
            result += Integer.toHexString(i);
            c++;
        }
//        System.out.println(result);
        for (Map.Entry<String, String> entry : map.entrySet()) {
            if (result.toLowerCase().startsWith(entry.getValue().toLowerCase()))
            {
                System.out.println("PROCESSED");
                FileOutputStream fos = new FileOutputStream("result.txt", true);
                byte[] buffer = entry.getKey().getBytes();

                fos.write(buffer);
                fos.write(10); // \n
                flag = 1;
                break;
            }
        }
        if (flag == 0)
            System.out.println("UNDEFINED");
    }
}