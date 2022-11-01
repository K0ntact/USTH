package Ex1;
public class NameCardTestDrive {
    public static void main(String[] args) {
        NameCard card = new NameCard();
        card.setName("John");
        card.setPhone(12345678);
        card.setEmail("John@gmail.com");

        System.out.println("Name: " + card.getName());
        System.out.println("Phone: " + card.getPhone());
        System.out.println("Email: " + card.getEmail());
    }
}
