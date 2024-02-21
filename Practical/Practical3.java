

import java.util.Scanner;

class Practical3{
    public static int array(int arr[],int n){
        if(n<=0){
            return 0;
        }
        else{
            return ((arr[n-1]) + array(arr, n-1) );  
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
        System.out.println(array(arr,n));                               // [1,2,3,4,5]
    }
}



