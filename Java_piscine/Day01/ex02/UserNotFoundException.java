public class UserNotFoundException extends Exception {
    public UserNotFoundException(){};
    public void message() {
        System.out.println("User not found!");
    }
}