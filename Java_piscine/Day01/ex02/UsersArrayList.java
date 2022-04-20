public class UsersArrayList implements UsersList {
    private Integer size;
    private User[] Data;
    private Integer curSize;

    public UsersArrayList() {
        size = 10;
        curSize = 0;
        Data = new User[size];
    }

    public void addUser(User user) {
        if (curSize < size) {
            Data[curSize] = user;
            curSize++;
        }
        else
        {
            size += (int)(size * 0.5);
            User[] newData = new User[size];
            for (int i = 0; i < curSize; i++)
                newData[i] = Data[i];
            Data = newData;
            Data[curSize] = user;
            curSize++;
        }

    }
    public User getUserId(Integer id) throws UserNotFoundException {
        for (int i = 0; i < curSize; i++)
        {
            if (Data[i].getIdentifier() == id)
                return (Data[i]);
        }
        throw new UserNotFoundException();
    };

    public User getUserIndex(Integer index) throws UserNotFoundException {
        if (index >= curSize)
            throw new UserNotFoundException();
        return (Data[index]);
    };

    public Integer getUserCount(){
        return (this.curSize);
    };

    @java.lang.Override
    public java.lang.String toString() {
        return "UsersArrayList{" +
                "size=" + size +
                ", Data=" + java.util.Arrays.toString(Data) +
                ", curSize=" + curSize +
                '}';
    }
}