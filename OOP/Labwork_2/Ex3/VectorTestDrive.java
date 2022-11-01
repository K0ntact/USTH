package Ex3;

public class VectorTestDrive {
    public static void main(String[] args){
        Vector a = new Vector();
        Vector b = new Vector();

        a.setX(1);
        a.setY(2);
        b.setX(3);
        b.setY(4);
        
        System.out.println("Vector addiction: \n");
        a.add(b);
        System.out.println("Vector subtraction: \n");
        a.subtract(b);
        System.out.println("Vector multiplication: \n");
        a.multiply(b);
    }
}
