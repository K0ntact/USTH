public class ShapeTestDrive {
    public static void main(String[] args) {
        Object o = new Object();
        Shape[] sh = new Shape[3];
        sh[0] = new Point(1,2);
        sh[1] = new Circle(1,2,5);
        sh[2] = new Cylinder(1,2,5,6);

        for(int i = 0; i<sh.length; i++){
            System.out.println("Shape " + sh[i].getName() + ":");
            System.out.println("    Area: " + sh[i].calArea());
            System.out.println("    Volume: " + sh[i].calVolume());
        }
    }
}
