// Q.6)Declare an interface called Function that has a method named evaluate that takes an int parameter and
// returns an int value.Create a class Half that implements Function. Make the implementation of the method
// evaluate() return the value obtained by dividing the int argument by 2.In a client, create a method that takes an
// arbitrary array of int values as parameter and returns an array that has the same length, but the value of an
// element in the new array is half that of the value in the corresponding element in the array passed as parameter.
// Let the implementation of this method create an instance of Half and use this instance to calculate the values in
// the array to be returned.


//interface is used to achieve abstraction and multiple inheritance in Java.
//it is a reference type in Java, similar to class, that can contain only constants, method signatures, default methods, static methods, and nested types.
//it cannot contain instance fields or constructors.
//it is used to specify a contract that implementing classes must follow.



import java.util.Scanner;


interface Function {
    int evaluate(int x);
}


class Half implements Function {
    public int evaluate(int x) {
        return x / 2;
    }
}


public class FunctionClient {

    // Method that processes array using Half
    static int[] processArray(int[] arr) {
        Function f = new Half();  // Create instance of Half
        int[] result = new int[arr.length];

        for (int i = 0; i < arr.length; i++) {
            result[i] = f.evaluate(arr[i]);
        }

        return result;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter number of elements: ");
        int n = sc.nextInt();

        int[] arr = new int[n];

        System.out.println("Enter elements:");
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }

        int[] newArr = processArray(arr);

        System.out.println("Array after applying Half function:");
        for (int val : newArr) {
            System.out.print(val + " ");
        }

        sc.close();
    }
}
