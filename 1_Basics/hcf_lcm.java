
/********************
 * Program Name : HCF & LCM Calculator
 * 
 * Date : 27-08-2022
 * Author : Shashank J
 * 
*/

import java.util.*;

public class hcf_lcm{
    public static void main(String[] args) {
        Scanner scann = new Scanner(System.in);

        System.out.println("Enter 2 numbers to find out the HCF and LCM .");

        int num1 = scann.nextInt();
        int num2 = scann.nextInt();

        int HCF_ans = hcf(num1, num2);
        int LCM_ans = lcm(num1, num2, HCF_ans);

        System.out.println("HCF : " + HCF_ans + " || LCM : "+LCM_ans);
        scann.close();
    }

    private static int lcm(int num1, int num2, int hcf) {

        int lcmAns = (num1 * num2) / hcf;

        return lcmAns;
    }

    private static int hcf(int num1, int num2) {

        // Step 1 : Divide larger numb. by smaller numb.
        int dividend = Math.max(num1, num2);
        int divisor = Math.min(num1, num2);

        int rem = dividend % divisor;

        // Step 2 : Make the remainder of the above step as the divisor and the divisor of the above step as the dividend and perform the division again.
 
        // Step 3: Continue the division process till the remainder is not equal to 0.198
        while (rem != 0) {  
            dividend = divisor;
            divisor = rem;
            
            rem = dividend % divisor;
        }
        // Step 4: The last divisor will be the HCF of the given numbers.
        return divisor; 

    }
}