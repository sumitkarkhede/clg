/*Q6.) (Credit limit calculator) Develop a java application that determines whether any of several department -
store customer has exceeded the credit limit on a charge account. For each customer following facts are available:
 account number.
 balance at the begining of the month.
 total of all items charged by the customer this month.
 total of all credits applied to the*/

import java.util.Scanner;

public class CreditLimitCalculator {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        int accountNumber;
        double beginningBalance, charges, credits, creditLimit;

        System.out.print("Enter account number (-1 to quit): ");
        accountNumber = sc.nextInt();

        while (accountNumber != -1) {

            System.out.print("Enter beginning balance: ");
            beginningBalance = sc.nextDouble();

            System.out.print("Enter total charges: ");
            charges = sc.nextDouble();

            System.out.print("Enter total credits: ");
            credits = sc.nextDouble();

            System.out.print("Enter credit limit: ");
            creditLimit = sc.nextDouble();

            // Calculate new balance
            double newBalance = beginningBalance + charges - credits;

            System.out.println("New balance is: " + newBalance);

            // Check credit limit
            if (newBalance > creditLimit) {
                System.out.println("Credit limit exceeded!");
            }
        
            System.out.println();
            System.out.print("Enter account number (-1 to quit): ");
            accountNumber = sc.nextInt();
        }

        sc.close();
        System.out.println("Program terminated.");
    }
}
