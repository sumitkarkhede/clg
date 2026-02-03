/*Q4.) Create a class called date that include three instance variable
 a) month(type int) b)day (type int) and c) year(type int) .
 provide a constructer that initialize a three instance variable and assume the value provided are
correct. Provide a set and a get method for each instance variable.Provide a method DisplayDate that display the
month year and day separated by forward slashand write a test application named DateTest that demonstrate
date capabilities.*/

class Date {

    // Instance variables (default access)
    
    int month;
    int day;
    int year;

    // Constructor
    Date(int month, int day, int year) {
        this.month = month;
        this.day = day;
        this.year = year;
    }

    // Set methods
    void setMonth(int month) {
        this.month = month;
    }

    void setDay(int day) {
        this.day = day;
    }

    void setYear(int year) {
        this.year = year;
    }

    // Get methods
    int getMonth() {
        return month;
    }

    int getDay() {
        return day;
    }

    int getYear() {
        return year;
    }

    // Display date in mm/dd/yyyy format
    void displayDate() {
        System.out.println(month + "/" + day + "/" + year);
    }
}

public class DateTest {

    public static void main(String[] args) {

        // Create Date object
        Date d = new Date(04, 30, 2025);

        // Display date
        System.out.print("Date: ");
        d.displayDate();

        // Change date using setters
        d.setMonth(04);
        d.setDay(30);
        d.setYear(2026);

        System.out.print("Updated Date: ");
        d.displayDate();
    }
}
