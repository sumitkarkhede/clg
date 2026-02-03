
// 3. (Physics: finding runway length) Given an airplane’s acceleration a and take-off speed v, you
// can compute the minimum runway length needed for an airplane to take off using the
// following formula:
// length =v/2a
// Write a program that prompts the user to enter v in meters/second (m/s) and the acceleration a
// in meters/second squared (m/s2), length and displays the minimum runway.

import java.util.Scanner;

public class RunwayLength {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        // User input
        System.out.print("Enter take-off speed (v) in m/s: ");
        double v = input.nextDouble();

        System.out.print("Enter acceleration (a) in m/s^2: ");
        double a = input.nextDouble();

        // Calculate runway length
        double length = (v * v) / (2 * a);

        // Display result
        System.out.println("The minimum runway length needed is " + length + " meters.");

        input.close();
    }
}