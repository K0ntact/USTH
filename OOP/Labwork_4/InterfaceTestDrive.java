public class InterfaceTestDrive {
    public static void main(String[] args) {
        InterPoint[] p = new InterPoint[3];
        p[0] = new InterPoint(1,2);
        p[1] = new InterCircle(1, 2, 5);
        p[2] = new InterCylinder(1, 2, 5, 6);
        
        for(int i = 0; i<p.length; i++){
            System.out.println("Shape " + p[i].getName() + ":");
            System.out.println("    Area: " + p[i].calArea());
            System.out.println("    Volume: " + p[i].calVolume());
        }
    }
}
