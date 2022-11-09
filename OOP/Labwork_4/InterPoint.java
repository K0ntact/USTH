public class InterPoint implements InterfaceShape{
    int x, y;

    InterPoint(int a, int b){
        this.x = a;
        this.y = b;
    }
    InterPoint(){}   //default constructor in order for child constructor to work

    @Override
    public float calArea(){return 0;}

    @Override
    public float calVolume(){return 0;}

    @Override
    public String getName() {return "Point";}
}

class InterCircle extends InterPoint{
    int radius;

    InterCircle(int a, int b, int r){
        this.x = a;
        this.y = b;
        this.radius = r;
    }
    InterCircle(){}

    @Override
    public float calArea(){
        return (float) (radius*radius*2*3.14);
    }
    
    @Override
    public String getName() {
        return "Circle";
    }
}

class InterCylinder extends InterCircle{
    int height;

    InterCylinder(int a, int b, int r, int h){
        this.x = a;
        this.y = b;
        this.radius = r;
        this.height = h;
    }

    @Override
    public float calArea(){
        return (float) (2*3.14*radius*height + 2*3.14*radius*radius);
    }

    @Override
    public float calVolume(){
        return (float) (3.14 * radius * radius * height);
    }

    @Override
    public String getName() {
        return "Cylinder";
    }
}
