import java.util.Scanner;
public class Practical4 {
    public static int min(int arr[], int n) {
        if(n == 1){
            return arr[0];
        } else{
            return Math.min(arr[n-1], min(arr, n-1));
        }
    }
    public static int max(int arr[], int n) {
        if(n == 1){
            return arr[0];
        }else{
            return Math.max(arr[n-1], max(arr, n-1));
        }
    }
     public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the number");
        int n = sc.nextInt();
        int arr[] = new int[n];
        
        for(int i=0; i<n; i++){
            arr[i] = sc.nextInt();
        }
        System.out.println("The max is " + max(arr,n));   
        System.out.println("The min is " + min(arr,n));                    // [1, 2, 3, 4, 5]
    }
}

