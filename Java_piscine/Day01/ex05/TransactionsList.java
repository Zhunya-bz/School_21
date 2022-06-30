import java.util.UUID;

public interface TransactionsList {
    public void addTransaction(Transaction transaction);
    public void removeTransactionId(UUID Id) throws UserNotFoundException;
    public Transaction[] toArray();
}