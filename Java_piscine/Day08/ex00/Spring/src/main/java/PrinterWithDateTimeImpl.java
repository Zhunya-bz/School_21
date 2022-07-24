import java.time.LocalDateTime;

public class PrinterWithDateTimeImpl implements Printer{

    private LocalDateTime time;
    private Renderer renderer;

    public PrinterWithDateTimeImpl(Renderer renderer) {
        this.renderer = renderer;
        this.time = LocalDateTime.now();
    }

    @Override
    public void print(String str) {
        renderer.print(time + " " + str);
    }

    public LocalDateTime getTime() {
        return time;
    }

    public void setTime(LocalDateTime time) {
        this.time = time;
    }
}
