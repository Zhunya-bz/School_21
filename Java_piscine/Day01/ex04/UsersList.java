public interface UsersList {
    public void addUser(User user);
    public User getUserId(Integer id) throws UserNotFoundException;
    public User getUserIndex(Integer index) throws UserNotFoundException;
    public Integer getUserCount();
}