// Q3) write an application that input three integer from the user and obtain the sum, average,product,largest and
// smallest of the numbers using interface and abstract class concept.

import java.util.Scanner;

//abstract class in Java is a special type of class that serves as a blueprint for other classes
// and cannot be instantiated on its own. It is a core component for achieving abstraction in 
// Object-Oriented Programming, allowing developers to hide implementation details and focus on functionality
abstract class _3Calculator {
    abstract int sum(int a, int b, int c);
    // abstract int is a method that is declared without an implementation

    abstract double average(int a, int b, int c);

    abstract int product(int a, int b, int c);

    abstract int largest(int a, int b, int c);

    abstract int smallest(int a, int b, int c);
}
//extends keyword is used to inherit the properties and methods of an abstract class into a subclass
class _3SimpleCalculator extends _3Calculator {
    int sum(int a, int b, int c) {
        return a + b + c;
    }

    double average(int a, int b, int c) {
        return sum(a, b, c) / 3.0;
    }

    int product(int a, int b, int c) {
        return a * b * c;
    }

    int largest(int a, int b, int c) {
        return Math.max(a, Math.max(b, c));
    }

    int smallest(int a, int b, int c) {
        return Math.min(a, Math.min(b, c));
    }
}

public class _3opereationsOnThreeNumbers {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter three integers: ");
        int a = sc.nextInt();
        int b = sc.nextInt();
        int c = sc.nextInt();

        _3SimpleCalculator calculator = new _3SimpleCalculator();

        System.out.println("Sum: " + calculator.sum(a, b, c));
        System.out.println("Average: " + calculator.average(a, b, c));
        System.out.println("Product: " + calculator.product(a, b, c));
        System.out.println("Largest: " + calculator.largest(a, b, c));
        System.out.println("Smallest: " + calculator.smallest(a, b, c));

        sc.close();
    }
}