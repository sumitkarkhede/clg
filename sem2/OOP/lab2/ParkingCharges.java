/*Q7.)A parking garage charges a $2.00 minimum fee to park for up to three hours. The garage charges an
additional $0.50 per hours for each hours or part thereof in excess of three hours. The maximum charge for any
given 24-hours period is $10.00.Assume that no car parks for longer than 24 hours at a time. Write an application
that calculates and displays the parking charges for each customers who parked in the garage yesterday. You
should enter the hours parked for each customers . The program should display the charge for the current
customers and should calculate and display the running total os yesterday's receipts. It should use the method
calculate charges to determine the charge for each customer.*/

import java.util.Scanner;

public class ParkingCharges {

    // Method to calculate parking charges
    public static double calculateCharges(double hours) {

        double charge = 2.0; // minimum fee for up to 3 hours

        if (hours > 3) {
            charge += Math.ceil(hours - 3) * 0.5;
        }

        if (charge > 10.0) {
            charge = 10.0;
        }

        return charge;
    }

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        double hours;
        double totalReceipts = 0.0;

        System.out.print("Enter hours parked (-1 to quit): ");
        hours = sc.nextDouble();

        while (hours != -1) {

            double charge = calculateCharges(hours);
            totalReceipts += charge;

            System.out.printf("Charge for current customer: $%.2f%n", charge);
            System.out.printf("Running total of receipts: $%.2f%n%n", totalReceipts);

            System.out.print("Enter hours parked (-1 to quit): ");
            hours = sc.nextDouble();
        }

        sc.close();
        System.out.println("Program terminated.");
    }
}
