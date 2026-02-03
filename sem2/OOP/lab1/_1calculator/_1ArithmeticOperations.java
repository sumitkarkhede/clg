package _1calculator;
//A package in Java is a group of related classes and interfaces that helps in organizing code,
//  avoiding name conflicts, and providing access protection.

import java.util.Scanner;

public class _1ArithmeticOperations {

    public static void main(String[] args) {

        int a, b;

        Scanner sc = new Scanner(System.in);

        // Input from user
        System.out.print("Enter first integer: ");
        a = sc.nextInt();

        System.out.print("Enter second integer: ");
        b = sc.nextInt();

        // Calculations
        int sum = a + b;
        int difference = a - b;
        int product = a * b;
        int quotient = a / b;   

        // Output
        System.out.println("\nSum = " + sum);
        System.out.println("Difference = " + difference);
        System.out.println("Product = " + product);
        System.out.println("Quotient = " + quotient);

        sc.close();
        //sc.close() is used to close the Scanner object and release the system resources associated with it.
        //  It prevents resource leaks and is considered good programming practice
    }
}
