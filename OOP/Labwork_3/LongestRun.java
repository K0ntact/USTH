public class LongestRun {
    public static void main(String[] args) {
        int[] a = {1, 2, 2, 1, 5, 1, 1, 7, 7, 7, 7,7,7,7, 1, 1};
        int longest = 0;
        int number = a[0];
        int count = 1;

        for(int i = 0; i < a.length-1; i++){
            if(a[i] == a[i+1]){
                count++;
                if(count > longest){
                    longest = count;
                    number = a[i];
                }
            }
            else{
                count = 1;
            }
        }
        
        System.out.println("Longest run: " + longest + " consecutives " + number + "s");
    }
}
