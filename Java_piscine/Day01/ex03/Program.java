import java.util.Arrays;
import java.util.UUID;

public class Program {
    public static void main(String[] args) throws UserNotFoundException {
        User Zhun = new User("Zhunya", 500);
		User Val = new User("Valua", 900);
		User As = new User("Asul", 100);

        TransactionsLinkedList lst = new TransactionsLinkedList();

        Transaction one = new Transaction(Zhun, Val, 300); // Zhunya получила 300 от Valua
        lst.addTransaction(one);

        Transaction two = new Transaction(Zhun, Val, 400); // Zhunya получила 300 от Valua
        lst.addTransaction(two);

        Transaction three = new Transaction(Zhun, Val, 200); // Zhunya получила 300 от Valua
        lst.addTransaction(three);

        Transaction four = new Transaction(As, Val, -100); // Valua получил 100 от Asul
        lst.addTransaction(four);

        System.out.println("------------ALL TRANSACTIONS--------------");
        lst.print();
        System.out.println("------------ALL TRANSACTIONS--------------\n");

        lst.removeTransactionId(two.getIdentifier()); // remove!

        Transaction [] array = new Transaction[4];
        array = lst.toArray();
        System.out.println("----------------TO ARRAY------------------");
        System.out.println(Arrays.toString(array));
        System.out.println(array.length);
        System.out.println("----------------TO ARRAY------------------");


    }
}