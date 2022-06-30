public class Program {
    public static void main(String[] args) {
        User Zhun = new User("Zhunya", 500);
		User Val = new User("Valua", 300);
		User As = new User("Asul", 100);

//		System.out.println(Zhun);
//        System.out.println(Val);
//        System.out.println(As);

        UsersArrayList Data = new UsersArrayList();
        Data.addUser(Zhun);
        Data.addUser(Zhun);
        Data.addUser(Zhun);
        Data.addUser(Zhun);
        Data.addUser(Zhun);
        Data.addUser(Val);
        Data.addUser(Val);
        Data.addUser(Val);
        Data.addUser(Val);
        Data.addUser(As);

//        Data.addUser(Zhun); // 11

        try {
            // System.out.println(Data.getUserId(2));
//             System.out.println(Data.getUserId(12));
            // System.out.println(Data.getUserIndex(9));
            System.out.println(Data.getUserIndex(11));
            System.out.println();
            System.out.println(Data);
        }
        catch (UserNotFoundException ex) {
            ex.printStackTrace();
//            ex.getMessage();
        }

    }
}