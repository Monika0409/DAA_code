

import java.util.Scanner;

public class Practical2 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String original = sc.next();
        String reversed = reverseString(original);
        System.out.println("Original string: " + original);
        System.out.println("Reversed string: " + reversed);
    }

    public static String reverseString(String str) {
        if (str.isEmpty() || str.length() == 1) {
            return str;
        }
        return reverseString(str.substring(1)) + str.charAt(0);
    }  
    
}


