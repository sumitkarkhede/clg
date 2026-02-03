/*Q1)Create an application that calculate your daily driving cost , so that you can estimate how much money could
be saved by car pooling which also has other advantages such as reducing carbon emission and traffic congestion
. The application should input the following informationand display the user's cost per day of driving to work.

 a)total miles driven per day
 b)cost per gallon of gasoline
 c)average fees per day
 d)tolls per day*/

import java.util.Scanner;
public class DrivingCostCalculator {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        
        System.out.print("Enter total miles driven per day: ");
        double milesDriven = scanner.nextDouble();

        
        System.out.print("Enter cost per gallon of gasoline: ");
        double costPerGallon = scanner.nextDouble();

        
        System.out.print("Enter average miles per gallon: ");
        double milesPerGallon = scanner.nextDouble();

        
        System.out.print("Enter average fees per day: ");
        double averageFees = scanner.nextDouble();

        
        System.out.print("Enter tolls per day: ");
        double tolls = scanner.nextDouble();

        
        double gallonsUsed = milesDriven / milesPerGallon;
        double fuelCost = gallonsUsed * costPerGallon;
        double totalDailyCost = fuelCost + averageFees + tolls;

        
        System.out.printf("Your daily driving cost is: $%.2f%n", totalDailyCost);

        scanner.close();
    }
}