package TCS_NQT;
import java.util.*;
public class problem_1 {
    public static void main(String[] args) {
        Scanner scann = new Scanner(System.in);

        
            System.out.println("Enter N : ");
            int N = scann.nextInt(); // Size of Array

            int[] arr = new int[N];
            // Read Array input;
            for (int i = 0; i < N; i++) {
                arr[i] = scann.nextInt();
            }

            int ans = countPairs(arr, N);
            System.out.println("Ans is : " + ans);
        

        scann.close();
        
    }

    public static int countPairs(int[] arr, int n) {
        
        int cntr = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j)
                    continue;
                // Check condition
                if ((arr[i] + arr[j]) >= (arr[i] * arr[j])) {
                    cntr++;
                }
            }
        }
        cntr = cntr / 2;
        return cntr;

    }
}
