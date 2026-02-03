// 1. (Physics: acceleration) Average acceleration is defined as the change of velocity divided by the
// time taken to make the change, as shown in the following formula:
// a =
// v0−v1
// t
// Write a program that prompts the user to enter the starting velocity meters/second, the ending
// velocity v1 v0 in in meters/second, and the time span t in seconds, and displays the average
// acceleration.


import java.util.Scanner;

public class AverageAcceleration {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        // Prompt user for input
        System.out.print("Enter starting velocity (v0) in m/s: ");
        double v0 = input.nextDouble();

        System.out.print("Enter ending velocity (v1) in m/s: ");
        double v1 = input.nextDouble();

        System.out.print("Enter time taken (t) in seconds: ");
        double t = input.nextDouble();

        // Calculate average acceleration
        double a = (v1 - v0) / t;

        // Display result
        System.out.println("The average acceleration is " + a + " m/s²");

        input.close();
    }
}
