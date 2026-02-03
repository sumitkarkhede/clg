// 4. (Health application: computing BMI) Body Mass Index (BMI) is a measure of health on
// weight. It can be calculated by taking your weight in kilograms and dividing by the square of

// your height in meters. Write a program that prompts the user to enter a weight in pounds and
// height in inches and displays the BMI. Note that one pound is 0.45359237 kilograms and one
// inch is 0.0254 meters.

import java.util.Scanner;

public class BMICalculator {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        // Constants for conversion
        //final is used to declare constants , meaning their values cannot be changed once assigned.
        final double POUND_TO_KG = 0.45359237;
        final double INCH_TO_METER = 0.0254;

        // User input
        System.out.print("Enter weight in pounds: ");
        double weightPounds = input.nextDouble();

        System.out.print("Enter height in inches: ");
        double heightInches = input.nextDouble();

        // Convert to metric units
        double weightKg = weightPounds * POUND_TO_KG;
        double heightMeters = heightInches * INCH_TO_METER;

        // Calculate BMI
        double bmi = weightKg / (heightMeters * heightMeters);

        // Display result
        System.out.println("Your BMI is " + bmi);

        input.close();
    }
}
