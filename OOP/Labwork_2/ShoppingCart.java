import java.util.ArrayList;
import java.util.List;

public class ShoppingCart {
    private List<String> arrayOfItems = new ArrayList<>();

    public void addToCart(String item){
        arrayOfItems.add(item);
    }

    public void removeFromCart(String item){
        for(String s : arrayOfItems){
            arrayOfItems.removeIf(item::equals);
        }
    }

    public void checkOut(){
        System.out.println(arrayOfItems);
    }
}