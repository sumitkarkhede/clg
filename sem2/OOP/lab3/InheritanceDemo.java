/*Q1.)Design a class called figure . It must have three attributes r, a ,and v of the data type douoble.
It must have the following methods:
public void dispArea(); public void dispVolume();
The method dispArea must have a statement to print the volume of a. The method dispVolume();
must have a statement to print the value of v.Design a class cone . It must extends class figure
class .It must also have the following attributes h,s of type double.It must have following methods:
public void calcArea();public void calcVolume();
The formulae for the area and volume of the cone are as follows:
Area of a cone(p*r*s)+(p*r*s)
volume of a con=(p*r*s)/3
Write a main method in a class called inheritance demo to demonstrate inheritance.*/

//Inheritance is a concept where one class acquires the properties and behavior of another class
//It helps in code reuse and creating a parent–child relationship between classes.
//Inheritance allows a class to use variables and methods of another class using the keyword: extends.

import java.util.Scanner;

class Figure {
    double r;
    double a;
    double v;

    public void dispArea() {
        System.out.println("Area = " + a);
    }

    public void dispVolume() {
        System.out.println("Volume = " + v);
    }
}

class Cone extends Figure {
    double h; 
    double s; 

    public void calcArea() {
        a = Math.PI * r * (r + s); 
    }

    public void calcVolume() {
        v = (Math.PI * r * r * h) / 3; 
    }
}

public class InheritanceDemo {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        Cone c = new Cone();

        System.out.print("Enter radius: ");
        c.r = sc.nextDouble();

        System.out.print("Enter height: ");
        c.h = sc.nextDouble();

        System.out.print("Enter slant height: ");
        c.s = sc.nextDouble();

        c.calcArea(); // method of Cone
        c.calcVolume(); // method of Cone

        c.dispArea(); // inherited from Figure
        c.dispVolume(); // inherited from Figure

        sc.close();
    }
}
