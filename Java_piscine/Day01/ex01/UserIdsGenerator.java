// singleton
public class UserIdsGenerator {
    private static UserIdsGenerator instance;
    private static int Id = 0;

    private UserIdsGenerator() { } // чтобы нельязя было создать объект

    public static UserIdsGenerator getInstance() {
        if (instance == null) {        //если объект еще не создан
            instance = new UserIdsGenerator();    //создать новый объект один раз в начале
        }
        return instance;
    }

    public int generateId() {
        return (++Id);
    }
}