import java.util.Arrays;

public class Program {
    public static void main(String[] args) throws UserNotFoundException, IllegalTransactionException {
        User zhunya = new User("Zhunya", 500);
        User valya = new User("Valya", 800);

        TransactionsService service = new TransactionsService();

        service.addUser(zhunya);
        service.addUser(valya);

//        System.out.println(service.getBalance(zhunya.getIdentifier()));
        service.transferTransactions(zhunya.getIdentifier(), valya.getIdentifier(), 400);
//        System.out.println("balance = " + service.getBalance(zhunya.getIdentifier()));
        service.transferTransactions(zhunya.getIdentifier(), valya.getIdentifier(), 100);
        System.out.println("------transaction to array user--------");
        Transaction [] tr = service.transactionToArray(zhunya.getIdentifier());
        System.out.println(Arrays.toString(tr));

        System.out.println("------unpaired transactions-------");
        System.out.println(Arrays.toString(service.unpairedTransactions()));
        System.out.println();
        service.removeTransactionById(zhunya.getIdentifier(), tr[0].getIdentifier());
        System.out.println(Arrays.toString(service.transactionToArray(zhunya.getIdentifier())));
        service.transferTransactions(zhunya.getIdentifier(), valya.getIdentifier(), 1000);
    }
}