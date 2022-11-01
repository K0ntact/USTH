public class Cow {
    private String name;
    private String breed;
    private int age;

    public void setName(String name){
        this.name = name;
    }

    public void setBreed(String breed){
        this.breed = breed;
    }
    
    public void setAge(int age){
        this.age = age;
    }

    Cow(String name, String breed, int age){
        this.name = name;
        this.breed = breed;
        this.age = age;
    }

    public String getName(){
        return this.name;
    }

    public String getBreed(){
        return this.breed;
    }
    
    public int getAge(){
        return this.age;
    }

    public void moo(){
        System.out.println("Moo...!");
    }
}
