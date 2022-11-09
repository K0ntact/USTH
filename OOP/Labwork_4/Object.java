public class Object{
}

abstract class Shape extends Object{
    public float calArea(){
        return 0;
    }
    public float calVolume(){
        return 0;
    }
    public abstract String getName();
}

class Point extends Shape{
    int x, y;

    Point(int a, int b){
        this.x = a;
        this.y = b;
    }
    Point(){}   //default constructor in order for child constructor to work

    @Override
    public String getName() {
        return "Point";
    }
}

class Circle extends Point{
    int radius;

    Circle(int a, int b, int r){
        this.x = a;
        this.y = b;
        this.radius = r;
    }
    Circle(){}

    @Override
    public float calArea(){
        return (float) (radius*radius*2*3.14);
    }
    
    @Override

    public String getName() {
        return "Circle";
    }
}

class Cylinder extends Circle{
    int height;

    Cylinder(int a, int b, int r, int h){
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
