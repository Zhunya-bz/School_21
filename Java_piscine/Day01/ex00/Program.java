public class Program {
    public static void main(String[] args) {
        User Zhun = new User("Zhunya", 500);
		User Val = new User("Valua", 300);
		User As = new User("Asul", 100);
		System.out.println(Zhun);

		Transaction one = new Transaction(Zhun, Val, 300); // Zhunya получила 300 от Valua
		Transaction two = new Transaction(As, Val, -100); // Valua получил 100 от Asul
		Transaction three = new Transaction(As, Val, -100); // Valua НЕ получил 100 от Asul так как у Asul нет денег

//		System.out.println(As);
//		System.out.println(Val);
		System.out.println(one);
		System.out.println(two);
		System.out.println(three);
    }
}