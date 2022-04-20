public class Program {
    public static void main(String[] args) {
        User Zhun = new User("Zhunya", 500);
		User Val = new User("Valua", 900);
		User As = new User("Asul", 100);

        Transaction one = new Transaction(Zhun, Val, 300); // Zhunya получила 300 от Valua

        TransactionsLinkedList lst = new TransactionsLinkedList();
        lst.addTransaction(one);
//        System.out.println(one);
        Transaction one2 = new Transaction(Zhun, Val, 400); // Zhunya получила 300 от Valua
        lst.addTransaction(one2);
//        System.out.println(one2);
        Transaction one3 = new Transaction(Zhun, Val, 100); // Zhunya получила 300 от Valua
        lst.addTransaction(one3);
        Transaction two = new Transaction(As, Val, -100); // Valua получил 100 от Asul
        lst.addTransaction(two);

        System.out.println("----------------ALL TRANSACTIONS----------");
        lst.print();
        System.out.println("----------------ALL TRANSACTIONS----------");

//        lst.removeTransactionId(two.getIdentifier());
        Transaction [] array = new Transaction[4];
        array = lst.toArray();
        System.out.println("----------------TO ARRAY------------------");
        System.out.println(array[3]);
        System.out.println("----------------TO ARRAY------------------");

//        System.out.println(lst);
//        lst.print();
    }
}