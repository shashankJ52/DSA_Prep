// import java.util.*;

public class RowColMatrix{
    public static void main(String[] args) {

        int[][] arr = {
                {10, 20, 30, 40},
                {15, 25, 35, 45},
                {28, 29, 37, 49},
                {33, 34, 38, 50}
        };

        int[] ans = search(arr, 489);
        System.out.println("The Target is found at Row : " + ans[0] + " and Col : " + ans[1] + " !!");


    }

    public static int[] search(int[][] mat, int target) {
        int r = 0, c = mat.length - 1;

        while (r < mat.length && c >= 0) {

            // Case 1
            if (mat[r][c] == target) {
                // Answer Found
                return new int[] { r, c };
            }
            // Case 2
            else if (mat[r][c] < target) {
                // ignore that entire row and incr row.
                r++;
            }
            // case 3
            else if (mat[r][c] > target) {
                // ignore entire col and decr. col
                c--;
            }
        }
        return new int[] { -1, -1 };

    }
}