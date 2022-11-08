import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class Company{

    private void addEmployee(){
        Employee e = new Employee();

        File file = new File("employees.txt");  

        //try catch to handle the exception when creating file
        try {
            if(file.createNewFile()){   
                System.out.println("File created: " + file.getName());
            }
        } catch (IOException err0) {
            System.out.println("File creating exception occured.");
            err0.printStackTrace();
        }

        //try catch to handle the exception when writing to file
        try {

            //try-with-resources: close file scanner at the end of execution
            try (FileWriter writer = new FileWriter("employees.txt", true)) {
                
                System.out.println("Enter the employee name: ");
                Scanner sc = new Scanner(System.in); 
                String name = sc.nextLine();
                e.setName(name);
                writer.write(name + ":\n");
                
                System.out.println("Enter the employee id: ");
                int id = sc.nextInt();
                e.setId(id);
                writer.write("  ID: " + id + "\n");
                sc.nextLine();  // Read the leftover new line character

                System.out.println("Enter the employee department: ");
                String department = sc.nextLine();
                e.setDepartment(department);
                writer.write("  Department: " + department + "\n");

                System.out.println("Enter the employee basic salary: ");
                int b_salary = sc.nextInt();
                e.setB_salary(b_salary);
                writer.write("  Basic salary: " + b_salary + "\n");

                System.out.println("Enter the employee extra salary: ");
                int e_salary = sc.nextInt();
                e.setE_salary(e_salary);
                writer.write("  Extra salary: " + e_salary + "\n");

                writer.write(" Total income: " + (b_salary + e_salary)*2.5 + "\n");
            }

        } catch (IOException err1) {
            System.out.println("File writing exception occured.");
            err1.printStackTrace();
        }
    }


    private void showCompany(){
        try(Scanner sc = new Scanner(new File("employees.txt"))){
            while(sc.hasNextLine()){
                System.out.println(sc.nextLine());
            }
        } catch (IOException err2) {
            System.out.println("File reading exception occured.");
            err2.printStackTrace();
        }
    }

    public static void main(String[] args) {
        Company c = new Company();
        System.out.println("0-Exit \n1-Add \n2-Show \n 3-Delete company");

        Scanner scanner = new Scanner(System.in);
        int choice = scanner.nextInt();
        scanner.nextLine(); // Read the leftover new line

        while(choice != 0){
            switch(choice){
                case 1:
                    c.addEmployee();
                    break;
                case 2:
                    c.showCompany();
                    break;
                default:
                    System.out.println("Invalid choice.");
            }
            System.out.println("0-Exit \n1-Add \n2-Show");
            choice = scanner.nextInt();
        }
        scanner.close();

    }
}
