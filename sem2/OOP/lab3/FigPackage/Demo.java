/*Q4.) create a package named FigPackage. Define an abstract class called figure having the following attribute
r,a,v and pi of the datatype double.the attribute pi must have a value equal to 3.1428.must have the following

abstract method-
public abstract void calcArea(); 
public abstract void calcVolume();
public abstract void dispArea();
public abstract void dispVolume();
design three classes cone,sphere,cylinder. each of these class must extends the Figure class

class name      Attribute
Cone            r,h,s of type double
Sphere          r of type double
Cylinder        r,h of the type double

the formulae for the area and volume of the cone,cylinder and sphere are as follows:
Class        Formal
cone         area=(pi*r*s)+(pi*r*r)
             volume=(pi*r*r*h)/3
Sphere       area=(4*pi*r*r)
             volume=(4*pi*r*r*r)/3
Cylinder     area=(2*pi*r*r)+(2*pi*r*h)
             volume=pi*r*r*h

define the inherited abstract method in the subclass by using the given formulae and set values of inherited
attribute a and v for the rea and volume ,respectively define any constructor /method that may be necessary.
write a main method in a class called Demo and invoke the method of each subclass. all the created class must be
put in the fig Package compile and execute program at command prompt.*/

package FigPackage;

import java.util.Scanner;


public class Demo {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.println("Enter details of cone:");
        System.out.println("Enter radius:");
        double rCone = sc.nextDouble();
        System.out.println("Enter height:");
        double hCone = sc.nextDouble();
        System.out.println("Enter slant height:");
        double sCone = sc.nextDouble();
        


        Cone cone = new Cone(rCone, hCone, sCone);
        cone.calcArea();
        cone.calcVolume();
        cone.dispArea();
        cone.dispVolume();

        System.out.println();

        System.out.println("Enter details of sphere:");
        System.out.println("Enter radius:");
        double rSphere = sc.nextDouble();
        Sphere sphere = new Sphere(rSphere);
        sphere.calcArea();
        sphere.calcVolume();
        sphere.dispArea();
        sphere.dispVolume();

        System.out.println();

        System.out.println("Enter details of cylinder:");
        System.out.println("Enter radius:");
        double rCylinder = sc.nextDouble();
        System.out.println("Enter height:");
        double hCylinder = sc.nextDouble();
        
        Cylinder cylinder = new Cylinder(rCylinder, hCylinder);
        cylinder.calcArea();
        cylinder.calcVolume();
        cylinder.dispArea();
        cylinder.dispVolume();
        sc.close();
    }
}
