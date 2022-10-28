public class FivePerLine {
    public static void main(String[] args){
        for (int i = 1001; i<2001; i++){
            if(i%5 == 0) {
                System.out.println("\n");
                System.out.print(i + " ");
            }

            else{
                System.out.print(i + " ");
            }

        }
    }
}
