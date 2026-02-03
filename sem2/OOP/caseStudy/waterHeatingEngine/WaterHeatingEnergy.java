// 2. (Science: calculating energy) Write a program that calculates the energy eeded to heat water
// from an initial temperature to a final temperature. Your program should prompt the user to enter
// the amount of water in kilograms and the initial and final temperatures of the water. The formula
// to compute the energy is
// Q = M * (finalTemperature – initialTemperature) * 4184
// where M is the weight of water in kilograms, temperatures are in degrees Celsius, and energy
// Q is measured in joules.


import java.util.Scanner;

public class WaterHeatingEnergy {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        // User input
        System.out.print("Enter the amount of water in kilograms: ");
        double mass = input.nextDouble();

        System.out.print("Enter the initial temperature (°C): ");
        double initialTemp = input.nextDouble();

        System.out.print("Enter the final temperature (°C): ");
        double finalTemp = input.nextDouble();

        // Calculate energy
        double energy = mass * (finalTemp - initialTemp) * 4184;

        // Output result
        System.out.println("The energy needed is " + energy + " joules.");

        input.close();
    }
}
