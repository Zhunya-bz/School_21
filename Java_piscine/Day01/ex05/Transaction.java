import java.util.UUID;

enum Category {
    DEBIT,
    CREDIT;
}

public class Transaction {
    private UUID Identifier;
    private User Resipient; // получатель
    private User Sender; // отправитель
    private Category TransferCategory; //debit - поступление, credit - списание
    private Integer TransferAmount;
    private boolean success;

    public Transaction(User Resipient, User Sender, Integer TransferAmount) // amount - может быть как > 0 так и < 0,
    {                                                                       // потом далее переводим только в положительные
        Identifier = UUID.randomUUID();
        this.Resipient = Resipient;
        this.Sender = Sender;
        this.TransferCategory = Category.CREDIT;
        if (TransferAmount > 0)
            this.TransferCategory = Category.DEBIT;
        this.TransferAmount = TransferAmount;
        if (TransferAmount < 0)
            this.TransferAmount = -TransferAmount;
        this.success = true;
        if ((Resipient.getBalance() - this.TransferAmount < 0) && (this.TransferCategory == Category.CREDIT))
            success = false;
        if (Sender.getBalance() - this.TransferAmount < 0 && this.TransferCategory == Category.DEBIT)
            success = false;
    }

    public Transaction(Transaction transaction) {
        this.Identifier = transaction.getIdentifier();
        this.Resipient = transaction.getResipient();
        this.Sender = transaction.getSender();
        if (transaction.getTransferCategory() == Category.CREDIT)
            this.TransferCategory = Category.DEBIT;
        else
            this.TransferCategory = Category.CREDIT;
        this.TransferAmount = transaction.getTransferAmount() * (-1);
        this.success = true;
    }

    public void setResipient(User Resipient) {
        this.Resipient = Resipient;
    }
    public void setSender(User Sender) {
        this.Sender = Sender;
    }
    public void setTransferCategory(Category TransferCategory) {
        this.TransferCategory = TransferCategory;
    }
    public void setTransferAmount(Integer TransferAmount) {
        this.TransferAmount = TransferAmount;
    }
    public UUID getIdentifier() {
        return (this.Identifier);
    }
    public User getResipient() {
        return (this.Resipient);
    }
    public User getSender() {
        return (this.Sender);
    }
    public Category getTransferCategory() {
        return (this.TransferCategory);
    }
    public Integer getTransferAmount() {
        return (this.TransferAmount);
    }

    @java.lang.Override
    public java.lang.String toString() {
        return "Transaction{" +
                "Identifier=" + this.Identifier +
                ", Resipient=" + this.Resipient +
                ", Sender=" + this.Sender +
                ", TransferCategory=" + this.TransferCategory +
                ", TransferAmount=" + this.TransferAmount +
                ", success=" + this.success +
                '}';
    }
}