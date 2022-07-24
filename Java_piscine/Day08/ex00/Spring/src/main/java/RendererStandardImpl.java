public class RendererStandardImpl implements Renderer {

    private PreProcessor preProcessor;

    public RendererStandardImpl(PreProcessor preProcessor) {
        this.preProcessor = preProcessor;
    }

    @Override
    public void print(String str) {
        System.out.println(preProcessor.strTo(str));
    }
}
