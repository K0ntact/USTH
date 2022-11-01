package Ex3;

public class Vector {
    private int x;
    private int y;

    public void setX(int x){
        this.x = x;
    }
    public void setY(int y){
        this.y = y;
    }

    public int getX(){
        return this.x;
    }
    public int getY(){
        return this.y;
    }

    //vector addiction
    public void add(Vector a){
        System.out.println("X: "+ (this.getX() + a.getX()) +"\n");
        System.out.println("Y: "+ (this.getY() + a.getY()) +"\n");
    }

    //vector subtraction
    public void subtract(Vector a){
        System.out.println("X: "+ (this.getX() - a.getX()) +"\n");
        System.out.println("Y: "+ (this.getY() - a.getY()) +"\n");
    }

    //Vector multiplication
    public void multiply(Vector a){
        System.out.println("X: "+ (this.getX()*a.getX() + this.getX()*a.getY()) +"\n");
        System.out.println("Y: "+ (this.getY()*a.getX() + this.getY()*a.getY()) +"\n");
    }
}
