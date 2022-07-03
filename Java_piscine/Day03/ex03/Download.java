import java.io.IOException;
import java.io.InputStream;
import java.net.URL;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.nio.file.StandardCopyOption;

public class Download implements Runnable {
    private String downloadString;
    private int countTask;

    public Download(String str, int countTask) {
        this.downloadString = str;
        this.countTask = countTask;
    }
    @Override
    public void run() {
        String id = Thread.currentThread().getName()
                .substring(Thread.currentThread().getName().lastIndexOf("-") + 1);
        System.out.println("Thread-" + id + " start download file number " + (countTask + 1));
        String extension = downloadString.substring(downloadString.lastIndexOf('.') + 1);
        try {
            URL url = new URL(downloadString);
            InputStream in = url.openStream();
            Files.copy(in, Paths.get((countTask + 1) + "." + extension), StandardCopyOption.REPLACE_EXISTING);
            in.close();
            System.out.println("Thread-" + id + " finish download file number " + (countTask + 1));
        }
        catch (IOException ex) {
            ex.printStackTrace();
        }
    }
}