import java.util.Scanner;

public class NumberPyramid {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        System.out.print("Enter number of rows: ");
        int rows = input.nextInt();

        for (int i = 0; i < rows; i++) {

            // Print leading spaces for center alignment
            for (int space = 0; space < rows - i - 1; space++) {
                System.out.print("    "); // 4 spaces for proper formatting
            }

            // Left side (increasing powers of 2)
            int num = 1;
            for (int j = 0; j <= i; j++) {
                System.out.printf("%4d", num);
                num *= 2;
            }

            // Right side (decreasing powers of 2)
            num /= 4; // step back before halving
            for (int j = 0; j < i; j++) {
                System.out.printf("%4d", num);
                num /= 2;
            }

            System.out.println();
        }

        input.close();
    }
}
