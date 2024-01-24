import java.util.Scanner;

public class duplicate {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int a[] = new int[n];

        System.out.println("Enter the duplicate array");
        for(int i=0; i<n; i++){
            a[i] = sc.nextInt();
        }

        int count = 0;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(a[i] == a[j]){
                    count++;
                }
            }
        }
        System.out.println("The duplicate array count is:");
        System.out.println(count);

        
        for(int i=0; i<n; i++){
            int count1 = 1;
            for(int j=i+1; j<n; j++){
                if(a[i] == a[j]){
                    count1++;
                }
            }
            if (count1 > 1) {
                System.out.println("Element: " + a[i] + ", Count: " + count1);
            }
        }       
    }
}
