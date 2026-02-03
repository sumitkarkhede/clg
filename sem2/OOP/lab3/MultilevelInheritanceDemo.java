/*Q3.) Design a class named 'x' having two attributes i and j of the type int. Let it have a constructor 
that takes in two argument of type int and assign them to i and j.Let it also have a method name final 
sum that compute the sum of i and j that return it.Let a class 'y' extend class x,lets it have its own 
constructer and method name find product that compute and return i*j. lets a class Z extend a class Y.
Design a class name multilevel inheritance demo it must have the main method in which the object of
 class Z is constructed and all the methods(its own and the inherited one ) are invokeand the sum 
 difference and the product are display.*/

class X {
    int i, j;

    // Constructor
    X(int a, int b) {
        i = a;
        j = b;
    }

    // Final method to compute sum
    public final int sum() {
        return i + j;
    }
}

class Y extends X {

    // Constructor
    Y(int a, int b) {
        super(a, b); // Call parent constructor
    }

    // Method to find product
    public int findProduct() {
        return i * j;
    }
}

class Z extends Y {

    // Constructor
    Z(int a, int b) {
        super(a, b);
    }

    // Method to find difference
    public int findDifference() {
        return i - j;
    }
}

public class MultilevelInheritanceDemo {
    public static void main(String[] args) {

        Z obj = new Z(10, 5);

        int sum = obj.sum();                   // From class X
        int product = obj.findProduct();       // From class Y
        int difference = obj.findDifference(); // From class Z

        System.out.println("Sum = " + sum);
        System.out.println("Product = " + product);
        System.out.println("Difference = " + difference);
    }
}
