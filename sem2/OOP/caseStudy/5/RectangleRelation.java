import java.util.Scanner;

public class RectangleRelation {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        // Rectangle 1 input
        System.out.println("Enter Rectangle 1 (x y width height):");
        double x1 = input.nextDouble();
        double y1 = input.nextDouble();
        double w1 = input.nextDouble();
        double h1 = input.nextDouble();

        // Rectangle 2 input
        System.out.println("Enter Rectangle 2 (x y width height):");
        double x2 = input.nextDouble();
        double y2 = input.nextDouble();
        double w2 = input.nextDouble();
        double h2 = input.nextDouble();

        // Rectangle 1 boundaries
        double left1 = x1 - w1 / 2;
        double right1 = x1 + w1 / 2;
        double top1 = y1 + h1 / 2;
        double bottom1 = y1 - h1 / 2;

        // Rectangle 2 boundaries
        double left2 = x2 - w2 / 2;
        double right2 = x2 + w2 / 2;
        double top2 = y2 + h2 / 2;
        double bottom2 = y2 - h2 / 2;

        // Check if inside
        if (left2 >= left1 && right2 <= right1 &&
            bottom2 >= bottom1 && top2 <= top1) {
            System.out.println("Rectangle 2 is inside Rectangle 1.");
        }
        // Check overlap
        else if (right2 > left1 && left2 < right1 &&
                 top2 > bottom1 && bottom2 < top1) {
            System.out.println("Rectangle 2 overlaps Rectangle 1.");
        }
        // No overlap
        else {
            System.out.println("Rectangle 2 does not overlap Rectangle 1.");
        }

        input.close();
    }
}
