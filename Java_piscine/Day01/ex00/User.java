public class User {
    private static Integer IdValue = 0;
    private Integer Identifier;
    private String Name;
    private Integer Balance;

    public User(String name, Integer balance) {
        Name = name;
        Balance = balance;
        Identifier = ++IdValue;
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
//    public void printUser() {
//        System.out.println(this.Identifier + " " + this.Name + " " + this.Balance);
//    }

    @java.lang.Override
    public java.lang.String toString() {
        return "User{" +
                "Identifier=" + Identifier +
                ", Name='" + Name + '\'' +
                ", Balance=" + Balance +
                '}';
    }

}