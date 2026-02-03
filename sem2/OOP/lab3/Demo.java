/*Q2.) Define an abstract class called Figure having following attribute pi of the data type double. 
The attribute pi have a value equal to 3.1420.It must have the following abstract methods .
public abstract void calcArea();
public abstract void calcVol();
public abstract void DispArea();
public abstract void Dispvol();
Design three classes cone , sphere and cylinder. Each of these classes must extend the Figure class
|class name  | Attribute            |
|Cone        | r,h,s of type double   |
|Sphere      | r                    |
|Cylinder    | r,h of type double     |
Define the inherited abstract methods in the subclass by using the given formulae and set the value of
 the inherited attribute a and v for area and volume, rspe. Define any constructor /method that may be 
necessary.Write a main method in a class called Demo and invoke the methods of each subclass.*/


//An abstract class is a class that cannot be instantiated (you cannot create its object) 
// and is used as a base class for other classes.
//t provides a common structure for related classes and forces subclasses to implement certain methods.

import java.util.Scanner;

abstract class Figure {
    double pi = 3.1420;
    double a;
    double v;

    public abstract void calcArea();

    public abstract void calcVol();

    public abstract void DispArea();

    public abstract void Dispvol();
}

class Cone extends Figure {
    double r, h, s;

    Cone(double r, double h, double s) {
        this.r = r;
        this.h = h;
        this.s = s;
    }
    
    public void calcArea() {
        a = pi * r * (r + s);
    }

    public void calcVol() {
        v = (pi * r * r * h) / 3;
    }

    public void DispArea() {
        System.out.println("Cone Area = " + a);
    }

    public void Dispvol() {
        System.out.println("Cone Volume = " + v);
    }
}

class Sphere extends Figure {
    double r;

    Sphere(double r) {
        this.r = r;
    }

    public void calcArea() {
        a = 4 * pi * r * r;
    }

    public void calcVol() {
        v = (4 * pi * r * r * r) / 3;
    }

    public void DispArea() {
        System.out.println("Sphere Area = " + a);
    }

    public void Dispvol() {
        System.out.println("Sphere Volume = " + v);
    }
}

class Cylinder extends Figure {
    double r, h;

    Cylinder(double r, double h) {
        this.r = r;
        this.h = h;
    }

    public void calcArea() {
        a = 2 * pi * r * (r + h);
    }

    public void calcVol() {
        v = pi * r * r * h;
    }

    public void DispArea() {
        System.out.println("Cylinder Area = " + a);
    }

    public void Dispvol() {
        System.out.println("Cylinder Volume = " + v);
    }
}

public class Demo {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Cone
        System.out.print("Enter cone radius, height, slant height: ");
        Cone cone = new Cone(sc.nextDouble(), sc.nextDouble(), sc.nextDouble());
        cone.calcArea();
        cone.calcVol();
        cone.DispArea();
        cone.Dispvol();

        // Sphere
        System.out.print("\nEnter sphere radius: ");
        Sphere sphere = new Sphere(sc.nextDouble());
        sphere.calcArea();
        sphere.calcVol();
        sphere.DispArea();
        sphere.Dispvol();

        // Cylinder
        System.out.print("\nEnter cylinder radius and height: ");
        Cylinder cylinder = new Cylinder(sc.nextDouble(), sc.nextDouble());
        cylinder.calcArea();
        cylinder.calcVol();
        cylinder.DispArea();
        cylinder.Dispvol();

        sc.close();
    }
}
