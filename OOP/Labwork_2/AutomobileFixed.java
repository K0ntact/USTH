public class AutomobileFixed {
    private double fuel;
    private double speed;
    private String license;

    public void init(double f, double s, String l) {
        this.fuel = f;
        this.speed = s;
        this.license = l;
    }
    public void accelerate(double v) {
        if(fuel>0){
            speed += v;
        }
    }
    public void decelerate(double v) {
        if(fuel<=0){
            speed -= v;
        }
    }
}

