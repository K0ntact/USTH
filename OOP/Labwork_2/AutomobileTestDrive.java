public class AutomobileTestDrive {
    public static void main(String[] args) {
        AutomobileFixed test = new AutomobileFixed();
        test.init(4.5,34,"29JAD");
        test.accelerate(4);
        test.decelerate(5);
    }
}
