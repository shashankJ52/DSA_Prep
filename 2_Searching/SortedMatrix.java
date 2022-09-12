public class SortedMatrix {
    public static void main(String[] args) {
        int[][] arr = {
            {1,2,3,4},
            {5,6,7,8},
            {9,10,11,12},
            {13,14,15,16}
        };
        int target = 6;

        int[] ans = search(arr, target);
        System.out.println("Target Element ("+target+") Found at row : " + ans[0] + " && col : " + ans[1] + " !!");

    }

    private static int[] search(int[][] arr, int target) {

        int rows = arr.length;
        int cols = arr[0].length;

        if (rows == 1) {
            binarySearch(arr, 0, 0, cols - 1, target);
        }
        // Step 1 : Take middle col and perform BSearch
        int rStart = 0, rEnd = rows-1;
        int cMid = cols/2;
        // Continue loop : Until only 2 rows remaining
        while(rStart < (rEnd -1) ){
            int mid = rStart + (rEnd-rStart)/2;

            if(arr[mid][cMid] == target){
                // Element found
                return new int[] {mid, cMid};
            }else if(arr[mid][cMid] < target){
                rStart = mid; // ignore all rows above it !!
            }else{
                rEnd = mid; // Ignore all rows below it !!
            }
        }
        // Now only 2 Rows are remaining.
        // i) if target is in the col of 2 rows

        if(arr[rStart][cMid] == target){ // First Row
            return new int[] {rStart, cMid};
        }else if(arr[rStart+1][cMid] == target){ // Second Row
            return new int[] {rStart+1,cMid};
        }

        // Search in 1st Half
        if( target <= arr[rStart][cMid-1]){
            return binarySearch(arr, rStart, 0, cMid-1, target);
        }
        // Search in 2st Half
        if( target >= arr[rStart][cMid+1] && target <= arr[rStart][cols-1] ){
            return binarySearch(arr, rStart, cMid+1, cols-1, target);
        }
        // Search in 3st Half
        if( target <= arr[rStart+1][cMid-1]){
            return binarySearch(arr, rStart+1, 0, cMid-1, target);
        }
        // Search in 4st Half
        else{
            return binarySearch(arr, rStart+1, cMid+1, cols-1, target);
        }
    }
    
    // Binary Search in the row Provided.
    public static int[] binarySearch(int[][] arr, int row, int cStart, int cEnd, int target) {
        
        while (cStart <= cEnd) {
            int mid = cStart + (cEnd - cStart) / 2;

            if (arr[row][mid] == target) {
                return new int[] { row, mid };
            } else if (arr[row][mid] < target) {
                cStart = mid + 1;
            } else {
                cEnd = mid - 1;
            }
        }
        return new int[] { -1, -1 };
    }
    

}
