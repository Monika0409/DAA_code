import java.util.Scanner;

public class odd_even {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int a[] = new int[n];
        int e[] = new int[n];
        int o[] = new int[n];
        for(int i=0; i<n; i++){
            a[i] = sc.nextInt();
        }
        System.out.println("The Even number is:");
        for(int i=0; i<n; i++){
            if(a[i]%2 == 0){
                e[i] = a[i];
                System.out.println(e[i]);
            }
        }

        System.out.println("The Odd number is:");
        for(int i=0; i<n; i++){
            if(a[i]%2 != 0){
                o[i] = a[i];
                System.out.println(o[i]);
            }
        }
    }
}
