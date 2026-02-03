// Q6)Write an application that calculate the square and cubes of number from 0to10 and print the resulting value
// in table format.

public class _6SquareCubeTable {

    public static void main(String[] args) 
    {

        System.out.println("Number\tSquare\tCube");

        for (int i = 0; i <= 10; i++) 
        {
            System.out.println(i + "\t" + (i * i) + "\t" + (i * i * i));
        }
    }
}
