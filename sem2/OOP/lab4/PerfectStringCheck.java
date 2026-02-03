// Q.4) You have to enter a string and check whether it is a perfect string or not. A perfect string is a string which has
// occurance of every character only once.
// Eg. absdhkqwertyuioplmnvczx

import java.util.Scanner;

public class PerfectStringCheck {

    static boolean isPerfectString(String str) {
        int[] freq = new int[256]; // For ASCII characters

        for (int i = 0; i < str.length(); i++) {
            char ch = str.charAt(i);

            if (freq[ch] > 0) {
                return false; // Character repeated
            }
            freq[ch]++;
        }
        return true;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter a string: ");
        String input = sc.nextLine();

        if (isPerfectString(input))
            System.out.println("The string is a PERFECT string ");
        else
            System.out.println("The string is NOT a perfect string ");

        sc.close();
    }
}
