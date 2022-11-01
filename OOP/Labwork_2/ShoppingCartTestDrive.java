import java.util.Scanner;

public class ShoppingCartTestDrive {
    public static void main(String[] args){
        ShoppingCart cart = new ShoppingCart();

        Scanner sc = new Scanner(System.in);
        System.out.println("0-Exit   1-Add item   2-Remove item   3-Display cart");
        int choice = sc.nextInt();  // nextInt doesn't read new line character when press Enter
        sc.nextLine();              // so this nextLine is to absorb that new line,
                                    // prevent it from being received by String item

        while (choice != 0){
            if (choice == 1){
                System.out.println("Enter item name: ");
                String item = sc.nextLine();
                cart.addToCart(item);
            }
            else if (choice == 2) {
                System.out.println("Enter item name: ");
                String item = sc.nextLine();
                cart.removeFromCart(item);
            }
            else if (choice == 3){
                cart.checkOut();
            }
            else {
                System.out.println("Invalid choice");
            }

            System.out.println("0-Exit   1-Add item   2-Remove item   3-Display cart");
            choice = sc.nextInt();
            sc.nextLine();
        }
    }
}
