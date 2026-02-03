// Q5)Write an application that inputs one number consisting of five digits from the user, separate the number into
// its individual digits and print the digit separates from one another for three spaces each. for example if the user
// type the number 42335 the program should print ( 4 2 3 3 5).

import java.util.Scanner;

public class _5SeparateDigits 
{

    public static void main(String[] args)
    {

        Scanner sc = new Scanner(System.in);

        System.out.print("Enter a five-digit number: ");
        int number = sc.nextInt();

        int d1 = number / 10000;
        int d2 = (number / 1000) % 10;
        int d3 = (number / 100) % 10;
        int d4 = (number / 10) % 10;
        int d5 = number % 10;

        System.out.println("The digits are:\n " + d1 + "   " + d2 + "   " + d3 + "   " + d4 + "   " + d5);

        sc.close();
    }
}
