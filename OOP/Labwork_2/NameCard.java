public class NameCard{
    private String name;
    private int phone;
    private String email;
    public void setName(String name){
        this.name = name;
    }
    public void setPhone(int phone){
        this.phone = phone;
    }
    public void setEmail(String email){
        this.email = email;
    }

    NameCard(String name, int phone, String email){
        this.setName(name);
        this.setPhone(phone);
        this.setEmail(email);
    }

    public String getName(){
        return name;
    }
    public int getPhone(){
        return phone;
    }
    public String getEmail(){
        return email;
    }
}