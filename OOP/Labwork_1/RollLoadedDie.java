public class RollLoadedDie {
    public static void main(String[] args){
        int a = Integer.parseInt(args[0]);

        if (a == 1 || a == 2 || a == 3 || a == 4 || a == 5){
            System.out.println("1/8");
        }

        else{
            System.out.println("3/8");
        }
    }
}
