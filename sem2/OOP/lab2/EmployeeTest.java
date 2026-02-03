/*Q3.)Create a class called employee that include three instance variable 
a)name(type string) b) last name (typestring) and c) monthly salary(double). 
Provide a constructor that initialize the three instance variable. Provide a
set and a get method of instance variable. if the monthly salary is not positive 
do not set its value. Write a test aplication named employeetest that demonstrate 
class employee capabilities.create two employee object and
display each object yearly salary. Then give each employee a 10% hike and 
display each employee yearly salary again.*/
class Employee {

    // Instance variables
    String name;
    String lastName;
    double monthlySalary;

    // Constructor
    Employee(String name, String lastName, double monthlySalary) {
        this.name = name;
        this.lastName = lastName;

        if (monthlySalary > 0)
            this.monthlySalary = monthlySalary;
        else
            this.monthlySalary = 0.0;
    }

    // Set methods
    void setName(String name) {
        this.name = name;
    }

    void setLastName(String lastName) {
        this.lastName = lastName;
    }

    void setMonthlySalary(double monthlySalary) {
        if (monthlySalary > 0)
            this.monthlySalary = monthlySalary;
    }

    // Get methods
    String getName() {
        return name;
    }

    String getLastName() {
        return lastName;
    }

    double getMonthlySalary() {
        return monthlySalary;
    }

    // Yearly salary
    double getYearlySalary() {
        return monthlySalary * 12;
    }

    // 10% hike
    void applyHike() {
        monthlySalary = monthlySalary + (monthlySalary * 0.10);
    }
}

public class EmployeeTest {

    public static void main(String[] args) {

        // Create two Employee objects
        Employee emp1 = new Employee("Rahul", "Sharma", 30000);
        Employee emp2 = new Employee("Anita", "Verma", 45000);

        // Display yearly salary before hike
        System.out.println("Before Hike:");
        System.out.println(emp1.getName() + " " + emp1.getLastName() + " Yearly Salary: " + emp1.getYearlySalary());
        System.out.println(emp2.getName() + " " + emp2.getLastName() + " Yearly Salary: " + emp2.getYearlySalary());

        // Apply 10% hike
        emp1.applyHike();
        emp2.applyHike();

        // Display yearly salary after hike
        System.out.println("\nAfter 10% Hike:");
        System.out.println(emp1.getName() + " " + emp1.getLastName() + " Yearly Salary: " + emp1.getYearlySalary());
        System.out.println(emp2.getName() + " " + emp2.getLastName() + " Yearly Salary: " + emp2.getYearlySalary());
        
    }
}
