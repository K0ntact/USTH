public class SumOfSines {
    public static void main(String[] args){
        double a = Math.sin(Double.parseDouble(args[0]));
        double b = Math.sin(Double.parseDouble(args[1]));
        System.out.println("Sum of sin(2a) + sin(3b): "+ (2*a + 3*b));
    }
}
