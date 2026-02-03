/*Q.2) We need to write the function to check the password entered is correct or not based on the following
conditions.
a) It must have atleast one lower case character and one digit.
b) It must not have any Upper case characters and any special characters
c) length should be b/w 5-12.
d) It should not have any same immediate patterns like
abcanan1 : not acceptable coz of an an pattern
abc11se: not acceptable, coz of pattern 11
123sd123 : acceptable, as not immediate pattern
adfasdsdf : not acceptable, as no digits
Aasdfasd12: not acceptable, as have uppercase character*/

import java.util.Scanner;

public class PasswordValidator {

    // Function to check immediate repeated patterns
    static boolean hasImmediatePattern(String s) {
        int len = s.length();

        for (int size = 1; size <= len / 2; size++) {
            for (int i = 0; i <= len - 2 * size; i++) {
                String part1 = s.substring(i, i + size);
                String part2 = s.substring(i + size, i + 2 * size);
                if (part1.equals(part2)) {
                    return true; // Immediate repetition found
                }
            }
        }
        return false;
    }

    // Password validation function
    static boolean isValidPassword(String password) {

        // Rule c: Length check
        if (password.length() < 5 || password.length() > 12)
            return false;

        boolean hasLower = false;
        boolean hasDigit = false;

        for (char ch : password.toCharArray()) {

            // Rule b: No uppercase or special characters
            if (Character.isUpperCase(ch) || !Character.isLetterOrDigit(ch))
                return false;

            if (Character.isLowerCase(ch))
                hasLower = true;

            if (Character.isDigit(ch))
                hasDigit = true;
        }

        // Rule a
        if (!hasLower || !hasDigit)
            return false;

        // Rule d: Immediate pattern
        if (hasImmediatePattern(password))
            return false;

        return true;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter password: ");
        String password = sc.nextLine();

        if (isValidPassword(password))
            System.out.println("Password is VALID ");
        else
            System.out.println("Password is INVALID ");

        sc.close();
    }
}
