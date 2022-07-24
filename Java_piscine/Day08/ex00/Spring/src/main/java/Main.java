public class Main {
    public static void main(String[] args) {
        PreProcessor preProcessor = new PreProcessorToUpperImpl();
        Renderer renderer = new RendererErrImpl(preProcessor);
        PrinterWithDateTimeImpl printer = new PrinterWithDateTimeImpl(renderer);
//        printer.setPrefix("HI");
        printer.print("Zhunya");
    }
}
