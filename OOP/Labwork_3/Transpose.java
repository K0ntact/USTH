import java.util.Random;

public class Transpose {
    public static void main(String[] args){
        //create n by n matrix
        int size = Integer.parseInt(args[0]);
        int[][] array = new int[size][size];
        for(int i = 0; i < size; i++){
            for(int j = 0; j < size; j++){
                int rand = new Random().nextInt(10);
                array[i][j] = rand;
            }
        }

        //print original matrix
        System.out.println("Original Matrix:");
        for(int i = 0; i < size; i++){
            for(int j = 0; j < size; j++){
                System.out.print(array[i][j] + " ");
            }
            System.out.println(" ");
        }

        //Transpose
        int temp;
        for(int i = 0; i < array.length; i++){
            for(int j = i+1; j < array[i].length; j++){
                temp = array[i][j];
                array[i][j] = array[j][i];
                array[j][i] = temp;
            }
        }

        //Print transpose
        System.out.println("Transpose Matrix:");
        for(int i = 0; i < size; i++){
            for(int j = 0; j < size; j++){
                System.out.print(array[i][j] + " ");
            }
            System.out.println(" ");
        }
    }
}
