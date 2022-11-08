import java.util.ArrayList;
import java.util.Scanner;

public class MaxMin {
    public static void main(String[] args){
        int max = 0, min = 0;

        //dynamic array to store user input
        ArrayList<Integer> numbers = new ArrayList<Integer>();

        try (Scanner input = new Scanner(System.in)) {
            System.out.println("Enter a series of numbers, enter 0 to stop");
            int number = input.nextInt();
            while(number != 0){
                numbers.add(number);
                number = input.nextInt();
                if(number > max){
                    max = number;
                }
                if(number < min){
                    min = number;
                }
            }
        }
        System.out.println("Max: "+max+"\n"+"Min: "+min);
    }
}
