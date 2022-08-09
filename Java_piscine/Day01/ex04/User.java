import java.util.UUID;

public class User {
    private Integer Identifier;
    private String Name;
    private Integer Balance;
    private TransactionsList transactions;

    public User(String name, Integer balance) {
        Name = name;
        Balance = balance;
        Identifier = UserIdsGenerator.getInstance().generateId();
        transactions = new TransactionsLinkedList();
    }
    public void setName(String name) {
        this.Name = name;
    }
    public void setIdentifier(Integer Identifier) {
        this.Identifier = Identifier;
    }
    public void setBalance(Integer Balance) {
        if (Balance < 0)
            this.Balance = 0;
        else    
            this.Balance = Balance;
    }
    public Integer getIdentifier() {
        return (this.Identifier);
    }
    public String getName() {
        return (this.Name);
    }
    public Integer getBalance() {
        return (this.Balance);
    }

    public void removeTransaction(UUID id) throws UserNotFoundException {
        this.transactions.removeTransactionId(id);
    }

    public void addTransaction(Transaction transaction) {
        this.transactions.addTransaction(transaction);
    }
    public Transaction [] transactionToArray() {
         return this.transactions.toArray();
    }

    public boolean isTransactionInList(UUID uuid) {
        Transaction[] array = transactions.toArray();
        for (Transaction t : array) {
            if (t.getIdentifier().equals(uuid))
                return true;
        }
        return false;
    }

    @java.lang.Override
    public java.lang.String toString() {
        return "User{" +
                "Identifier=" + Identifier +
                ", Name='" + Name + '\'' +
                ", Balance=" + Balance +
                '}';
    }

}