import java.util.Scanner;
import java.util.UUID;

public class Menu {
    private static TransactionsService service = new TransactionsService();
    public Menu(){}

    public void printInfo(boolean isProd) {
        System.out.println("1. Add a user");
        System.out.println("2. View user balances");
        System.out.println("3. Perform a transfer");
        System.out.println("4. View all transactions for a specific user");
        if (!isProd) {
            System.out.println("5. DEV - remove a transfer by ID");
            System.out.println("6. DEV - check transfer validity");
            System.out.println("7. Finish execution");
            System.out.print("-> ");
            return;
        }
        System.out.println("5. Finish execution");
        System.out.print("-> ");
    }

    public void launch(boolean isProd) throws UserNotFoundException, IllegalTransactionException {
        Scanner sc = new Scanner(System.in);
        while (true) {
            printInfo(isProd);
            int num = sc.nextInt();
            if (num == 1) {
                System.out.println("Enter a user name and a balance");
                String name = sc.next();
                int balance = sc.nextInt();
                User user = new User(name, balance);
                service.addUser(user);
                System.out.println("User with id = " + user.getIdentifier() + " is added");
            } else if (num == 3) {
                System.out.println("Enter a sender ID, a recipient ID, and a transfer amount");
                Integer id1 = sc.nextInt();
                Integer id2 = sc.nextInt();
                Integer amount = sc.nextInt();
                service.transferTransactions(id1, id2, amount);
                System.out.println("The transfer is completed");
            } else if (num == 2) {
                System.out.println("Enter a user ID");
                Integer id = sc.nextInt();
                System.out.println(service.getUserById(id).getName() + " - " + service.getBalance(id));
            }
            else if (num == 4) {
                System.out.println("Enter a user ID");
                Integer id = sc.nextInt();
                Transaction [] transactions = service.transactionToArray(id);
                int i = 0;
                while (i < transactions.length) {

                    System.out.println("To " + transactions[i].getResipient().getName() + "(id=" +
                            transactions[i].getResipient().getIdentifier() + ") " +
                            transactions[i].getTransferAmount() + " with id=" +
                            transactions[i].getIdentifier());
                    i++;
                }
            }
            else if (num == 5 && !isProd) {
                System.out.println("Enter a user ID and a transfer ID");
                Integer id = sc.nextInt();
                UUID uuid = UUID.fromString(sc.next());
                Transaction [] transactions = service.transactionToArray(id);
                int i = 0;
                while (i < transactions.length) {
                    if (transactions[i].getIdentifier().equals(uuid)) {
                        System.out.println("Transfer To " + transactions[i].getResipient().getName() + "(id=" +
                                transactions[i].getResipient().getIdentifier() + ") " +
                                transactions[i].getTransferAmount() + " removed");
                    }
                    i++;
                }
                service.removeTransactionById(id, uuid);
            }
            else if (num == 6 && !isProd) {
                System.out.println("Check results:");
                Transaction [] tr = service.unpairedTransactions();
                int i = 0;
                while (i < tr.length) {
                    System.out.printf("%s (id = %d) has an unacknowledged transfer id = %s from %s(id = %d) for %d\n",
                            tr[i].getResipient().getName(), tr[i].getResipient().getIdentifier(), tr[i].getIdentifier(), tr[i].getSender().getName(), tr[i].getSender().getIdentifier(), tr[i].getTransferAmount());
                    i++;
                }
            }
            else if (num == 7 || (num == 5 && isProd)) {
                System.out.println("Bye!");
                break;
            }
            System.out.println("------------------------------------------");
        }
    }
}
