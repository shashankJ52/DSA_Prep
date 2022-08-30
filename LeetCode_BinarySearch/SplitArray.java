package LeetCode_BinarySearch;
// Problem Link : https://leetcode.com/problems/split-array-largest-sum/
public class SplitArray {
    public static void main(String[] args) {
        int[] arr = { 7, 2, 5, 10, 8 };
        int m = 2;

        int ans = splitArray(arr, m);
        System.out.println("Min-Max(largest SubArray Sum ) is : "+ans);

    }

    public static int splitArray(int[] nums, int m) {

        // 1. Find Range( Low, Hi);
        int minVal = 0, maxVal = 0;
        for (int i = 0; i < nums.length; i++) {
            maxVal += nums[i];
            minVal = Math.max(minVal, nums[i]);
        }

        // Apply Binary Search
        int result = specialBS(nums, minVal, maxVal, m);
        return result;
    }
    
    // Binary Search
    public static int specialBS(int[] nums, int low, int high, int m) {
        int n = nums.length;
        while (low < high) {
            int midVal = low + (high - low) / 2;

            int totalPieces = 1, sum = 0;
            for (int i = 0; i < n; i++) {
                int curr = nums[i];
                if (sum + curr <= midVal) {
                    sum += curr;
                } else {
                   
                    sum = curr;
                    totalPieces++;
                }
            }

            // 2. Compare totalPieces and M
            if (totalPieces <= m) {
                high = midVal;
            } else {
                low = midVal + 1;
            }
        }
        return high;
    }

}
