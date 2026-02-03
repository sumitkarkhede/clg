// Q.1) Write a function to give demostrate the functionality of 3D matrix in 1D matirx. 
// Function prototye:
// void set (int value,int indexX,int indexY,int indexZ, int [] 1dArray);
// void get (int value,int indexX,int indexY,int indexZ, int [] 1dArray).


import java.util.Scanner;

public class Matrix3DTo1D {

    static int X, Y, Z; // Dimensions of 3D matrix

    // Convert 3D indices to 1D index
    static int getIndex(int indexX, int indexY, int indexZ) {
        return indexX * (Y * Z) + indexY * Z + indexZ;
    }

    // Set value in 1D array using 3D indices
    static void set(int value, int indexX, int indexY, int indexZ, int[] array) {
        int index = getIndex(indexX, indexY, indexZ);
        array[index] = value;
    }

    // Get value from 1D array using 3D indices
    static int get(int indexX, int indexY, int indexZ, int[] array) {
        int index = getIndex(indexX, indexY, indexZ);
        return array[index];
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter dimensions (X Y Z): ");
        X = sc.nextInt();
        Y = sc.nextInt();
        Z = sc.nextInt();

        int[] oneDArray = new int[X * Y * Z];

        System.out.print("How many values do you want to set? ");
        int n = sc.nextInt();

        System.out.println("Enter: value indexX indexY indexZ");
        for (int i = 0; i < n; i++) {
            int value = sc.nextInt();
            int x = sc.nextInt();
            int y = sc.nextInt();
            int z = sc.nextInt();
            set(value, x, y, z, oneDArray);
        }

        System.out.print("\nHow many values do you want to get? ");
        int m = sc.nextInt();

        System.out.println("Enter indices to retrieve (indexX indexY indexZ):");
        for (int i = 0; i < m; i++) {
            int x = sc.nextInt();
            int y = sc.nextInt();
            int z = sc.nextInt();
            int value = get(x, y, z, oneDArray);
            System.out.println("Value = " + value);
        }

        sc.close();
    }
}
