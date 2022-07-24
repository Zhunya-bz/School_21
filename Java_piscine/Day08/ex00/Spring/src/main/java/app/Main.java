package app;

import org.springframework.context.ApplicationContext;
import org.springframework.context.support.ClassPathXmlApplicationContext;
import printer.Printer;

public class Main {
    public static void main(String[] args) {
//        processor.PreProcessor preProcessor = new processor.PreProcessorToUpperImpl();
//        render.Renderer renderer = new render.RendererErrImpl(preProcessor);
//        printer.PrinterWithDateTimeImpl printer = new printer.PrinterWithDateTimeImpl(renderer);
////        printer.setPrefix("HI");
//        printer.print("Zhunya");

        ApplicationContext context = new ClassPathXmlApplicationContext("context.xml");
        Printer printer = context.getBean("prefixErrUpper", Printer.class);
        printer.print("Hello");

    }
}
