import java.util.Scanner;

class Practical1 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int decimalNumber = sc.nextInt();
        String binaryRepresentation = decimalToBinary(decimalNumber);
        System.out.println("Binary representation of " + decimalNumber + " is: " + binaryRepresentation);
    }

    public static String decimalToBinary(int decimal) {
        if (decimal == 0) {
            return "";
        } else {
            int remainder = decimal % 2;
            int quotient = decimal / 2;
            return decimalToBinary(quotient) + remainder;
        }
    }
}
