import java.util.Random;

public class Deal {
    public static void main (String[] args){
        String[] suits = {"Clubs", "Diamonds", "Hearts", "Spades"};
        String[] ranks = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace"};

        for(int i = 0; i < Integer.parseInt(args[0]); i++){
            for(int j = 0; j < 5; j++){
                int rand_suits = new Random().nextInt(suits.length);
                int rand_ranks = new Random().nextInt(ranks.length);
                System.out.println(ranks[rand_ranks] + " " + suits[rand_suits]);
            }
            System.out.println(" ");
        }
    }
}
