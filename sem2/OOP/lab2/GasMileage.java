/*Q5.)(Gas mileage ) Drivers are concerned with the mileage theit automobiles get. One driver has kept track of
several trips by recording the miles driven and gallons used for each tankful.Develop a java application that will
input the miles driven and gallons used(both as in) for each trip.The program should calculate and display the
miles per gallon obtained for each trip and print the combined miles per gallon obtained for all trips up to this
point. All averaging calculate should produce floating point results. Use class scanner and sentinel-controlled
repetition to obtain the data from the user.*/

import java.util.Scanner;

public class GasMileage {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        int miles, gallons;
        int totalMiles = 0, totalGallons = 0;

        System.out.println("Enter miles driven (-1 to quit): ");
        miles = sc.nextInt();

        while (miles != -1) {

            System.out.print("Enter gallons used: ");
            gallons = sc.nextInt();

            // Calculate miles per gallon for this trip
            double mpg = (double) miles / gallons;
            System.out.printf("Miles per gallon for this trip: %.2f%n", mpg);

            // Update totals
            totalMiles += miles;
            totalGallons += gallons;

            // Calculate combined MPG
            double combinedMPG = (double) totalMiles / totalGallons;
            System.out.printf("Combined miles per gallon: %.2f%n%n", combinedMPG);

            // Take next input
            System.out.print("Enter miles driven (-1 to quit): ");
            miles = sc.nextInt();
        }

        sc.close();
        System.out.println("Program terminated.");
    }
}
