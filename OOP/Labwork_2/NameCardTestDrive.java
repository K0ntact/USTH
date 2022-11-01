public class NameCardTestDrive {
    public static void main(String[] args) {
        NameCard card = new NameCard("John", 12345678, "John@gmail.com");

        System.out.println("Name: " + card.getName());
        System.out.println("Phone: " + card.getPhone());
        System.out.println("Email: " + card.getEmail());
    }
}
