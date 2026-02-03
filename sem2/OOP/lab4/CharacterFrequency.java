// Q.3) A string is entered like aabcdeaabcjlkjerwlaaabbsadfdsf...
// And you have to print those characters which exceed a given no. n entered by user.

import java.util.Scanner;

public class CharacterFrequency {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter a string: ");
        String input = sc.nextLine();

        System.out.print("Enter threshold n: ");
        int n = sc.nextInt();

        int[] freq = new int[256]; 

        // Count frequency
        for (int i = 0; i < input.length(); i++) {
            char ch = input.charAt(i);
            freq[ch]++;
        }

        System.out.println("\nCharacters with frequency greater than " + n + ":");

        boolean found = false;
        for (int i = 0; i < 256; i++) {
            if (freq[i] > n) {
                System.out.println((char)i + " appears " + freq[i] + " times");
                found = true;
            }
        }

        if (!found) {
            System.out.println("No character exceeds the given limit.");
        }

        sc.close();
    }
}
