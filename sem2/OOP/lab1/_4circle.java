// Write an application that input from the user that the radius of the circle is an integer and the print the circle
// diameter , circumfrence and area using the floating point value 3.14159 for math.Pi(You can also use the
// predefined constant math.pi for the value of pi.)
import java.util.Scanner;
public class _4circle
{

    public static void main(String[] args)
    {

        Scanner sc = new Scanner(System.in);

        System.out.print("Enter the radius of the circle (integer): ");
        int radius = sc.nextInt();

        double diameter = 2 * radius;
        double circumference = 2 * Math.PI * radius;
        double area = Math.PI * radius * radius;

        System.out.printf("Diameter: %.2f%n", diameter);
        System.out.printf("Circumference: %.2f%n", circumference);
        System.out.printf("Area: %.2f%n", area);

        sc.close();
    }
}