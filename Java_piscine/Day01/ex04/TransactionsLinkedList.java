import java.util.UUID;

public class TransactionsLinkedList implements TransactionsList {
    private Node next;
    private Node prev;
    private Node head;
    private Node tail;
    private int size;

    public TransactionsLinkedList() {
        this.next = null;
        this.head = null;
        this.prev = null;
        size = 0;
    }

    public void addTransaction(Transaction transaction) {
        Node node = new Node(transaction);
        if (head == null) {
            head = node;
            tail = node;
        }
        else
        {
            node.next = head;
            head.prev = node;
            head = node;
        }
        size++;
    }

    public void removeTransactionId(UUID id) throws UserNotFoundException{
        Node tmp = head;
        while (tmp.next != null)
        {
            if (size == 1) {
                head = null;
                tail = null;
                size--;
                return;
            }
            if (tmp.getData().getIdentifier() == id)
            {
                tmp = tmp.next;
                tmp.prev = null;
                head = tmp;
                size--;
                return;
            }
            if (tmp.next.getData().getIdentifier() == id)
            {
                tmp.next = tmp.next.next;
                if (tmp.next == null) {
                    this.tail = tmp;
                    size--;
                    return;
                }
                tmp.next.prev = tmp;
                size--;
                return;
            }
            tmp = tmp.next;
        }
        throw new UserNotFoundException("User not found!");
    }

    public Transaction[] toArray() {
        Node tmp = tail;
        Transaction [] arr = new Transaction[size];
        int i = 0;
        while (tmp != null)
        {
            arr[i] = tmp.getData();
            i++;
            tmp = tmp.prev;
        }
        return (arr);
    }

    private class Node {
        private Node next;
        private Node prev;
        private Transaction data;

        public Node(Transaction data)
        {
            this.data = data;
            this.prev = null;
            this.next = null;
        }
        public Transaction getData() { return data;}
    }

    public void print() {
        Node tmp = head;
        while (tmp != null) {
            System.out.println(tmp.getData());
            tmp = tmp.next;
        }
    }

    @java.lang.Override
    public java.lang.String toString() {
        return "TransactionsLinkedList{" +
                "next=" + next +
                ", head=" + head.getData() +
                ", size=" + size +
                '}';
    }
}
