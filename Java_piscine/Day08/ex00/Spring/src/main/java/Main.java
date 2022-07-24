import org.springframework.context.ApplicationContext;
import org.springframework.context.support.ClassPathXmlApplicationContext;

public class Main {
    public static void main(String[] args) {
//        PreProcessor preProcessor = new PreProcessorToUpperImpl();
//        Renderer renderer = new RendererErrImpl(preProcessor);
//        PrinterWithDateTimeImpl printer = new PrinterWithDateTimeImpl(renderer);
////        printer.setPrefix("HI");
//        printer.print("Zhunya");

        ApplicationContext context = new ClassPathXmlApplicationContext("context.xml");
        Printer printer = context.getBean("prefixErrUpper", Printer.class);
        printer.print("Hello");

    }
}
