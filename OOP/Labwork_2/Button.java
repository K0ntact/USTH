public class Button {
    private String label;
    private String color;

    private void setColor(String color) {
        this.color = color;
    }
    private void setLabel(String label){
        this.label = label;
    }

    Button (String label, String color){
        this.color = color;
        this.label = label;
    }

    public void dePress(){
        System.out.println(color + " button: " + label);
    }
    public  void unDepress(){
        System.out.println("Unpress " + color + "button");
    }
}
