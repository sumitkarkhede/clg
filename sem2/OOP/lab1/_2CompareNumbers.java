// Q2) Write an application that asks user to enter two integer, obtain them from the user and display the larger
// number followed by the word "is larger". if the numbers are equal, print the" the number are equal". Path and
// Classpath Concept use in this Application.
import java.util.Scanner;

public class _2CompareNumbers {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        System.out.print("Enter first integer: ");
        int num1 = sc.nextInt();

        System.out.print("Enter second integer: ");
        int num2 = sc.nextInt();

        if (num1 > num2) {
            System.out.println(num1 + " is larger");
        } else if (num2 > num1) {
            System.out.println(num2 + " is larger");
        } else {
            System.out.println("The numbers are equal");
        }

        sc.close();
    }
}
