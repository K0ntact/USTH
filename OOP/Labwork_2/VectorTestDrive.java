public class VectorTestDrive {
    public static void main(String[] args){
        Vector a = new Vector(1,2);
        Vector b = new Vector(3,4);

        System.out.println("Vector addiction: \n");
        a.add(b);
        System.out.println("Vector subtraction: \n");
        a.subtract(b);
        System.out.println("Vector multiplication: \n");
        a.multiply(b);
    }
}
