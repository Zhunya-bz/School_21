import java.util.UUID;

public class TransactionsService {
    private UsersArrayList userList;
    private TransactionsLinkedList transactionsList;

    public TransactionsService() {
        userList = new UsersArrayList();
        transactionsList = new TransactionsLinkedList();
    }

    public void addUser(User user) {
        userList.addUser(user);
    }

    public int getBalance(Integer id) throws UserNotFoundException {
        return userList.getUserId(id).getBalance();
    }

    public void transferTransactions(Integer id1, Integer id2, Integer amount) throws UserNotFoundException, IllegalTransactionException{
        if (id1 == id2 || amount < 0)
            throw new IllegalTransactionException("Illegal transactions!");

        User sender = userList.getUserId(id2);
        User resipient = userList.getUserId(id1);
        Transaction one = new Transaction(sender, resipient, amount);
        Transaction two = new Transaction(one);
        transactionsList.addTransaction(one);
//        transactionsList.addTransaction(two);
        if (sender.getBalance() - amount < 0)
            throw new IllegalTransactionException("Balance low 0");
        sender.setBalance(sender.getBalance() - amount);
        resipient.setBalance(resipient.getBalance() + amount);

        sender.addTransaction(one); // add transaction to user
        resipient.addTransaction(two);
    }

    public Transaction [] transactionToArray(Integer id) throws UserNotFoundException {
        return userList.getUserId(id).transactionToArray();
    }

    public void removeTransactionById(Integer id, UUID uuid) throws UserNotFoundException {
        this.userList.getUserId(id).removeTransaction(uuid);
    }

    public Transaction [] unpairedTransactions() {
        return transactionsList.toArray();
    }



}