import java.util.Locale;

public class PreProcessorToUpperImpl implements PreProcessor {
    @Override
    public String strTo(String str) {
        return  str.toUpperCase();
    }
}
