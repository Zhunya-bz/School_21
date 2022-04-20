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
//            node.prev = head;
        }
        size++;

    }

    public void removeTransactionId(UUID id) {
        Node tmp = head;
        while (tmp.next != null)
        {
            if (size == 1) {
                head = null;
                tail = null;
                return;
            }
            if (tmp.getData().getIdentifier() == id)
            {
                tmp = tmp.next;
                tmp.prev = null;
                head = tmp;
                return;
            }
            if (tmp.next.getData().getIdentifier() == id)
            {
                tmp.next = tmp.next.next;
                tmp.prev = tmp.prev.prev;
                return;
            }
            tmp = tmp.next;
        }
    }

    public Transaction[] toArray() {
        Node tmp = tail;
        Transaction [] arr = new Transaction[size];
        int i = 0;
        while (tail != null)
        {
            arr[i] = tail.getData();
            i++;
            tail = tail.prev;
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
