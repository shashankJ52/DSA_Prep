/********************
 * Program Name : Fibonacci Series Generator
 * 
 * Date : 27-08-2022
 * Author : Shashank J
 * 
*/
import java.util.*;
public class Fibo {
    public static void main(String[] args) {
        Scanner scann = new Scanner(System.in);

        int testCases = scann.nextInt();
        while (testCases-- > 0) {
            int num = scann.nextInt();
            printFibo(num);

        }
        scann.close();
    }

    private static void printFibo(int num) {

        // base Case 
        int num1 = 0 ,num2 = 1, i = 3;
        System.out.print("Fibonacci Series : "+num1+" , "+num2+" , ");

        while (i <= num) {
            int num3 = num1 + num2;
            if (i == num)
                System.out.print(num3);
            else System.out.print(num3 + " , ");

            // swap
            num1 = num2;
            num2 = num3;

            i++; // Increment cntr
        }
        System.out.println();
        

    }
}
