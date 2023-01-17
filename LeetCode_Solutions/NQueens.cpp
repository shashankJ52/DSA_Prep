/*******************
 * Problem : 51. N-Queens [ LeetCode ]
 * 
 * Rules
 *      1. Every Row must have ONLY 1 Queen ('Q')
 *      2. Every Column must have ONLY 1 Queen ('Q')
 *      3. None of the 'Q' should attack each other
 * 
 * Approach : 
 *          -> Loop column wise (0 ---> N)
 *                  -> loop Row wise (0 ---> N) to fill the 'Q'
 *                  -> Use Hash Tables for leftRow || UpperDiag || LowerDiag 
*/

#include <bits/stdc++.h>
using namespace std;

void findPossibleQueens(int col, vector<string>& board,vector<vector<string>>& ans, vector<int>& leftRow, vector<int>& lowDiag, vector<int>& upDiag, int n ){

    // Base Case
    if(col == n){
        // 1. Add board to ans
        ans.push_back(board);
        return;
    }

    for(int row  = 0; row<n; row++){

        if(leftRow[row] == 0 && lowDiag[row + col] == 0 && upDiag[n-1 + col - row] == 0){
            // Step 1 : Mark Board
            board[row][col] = 'Q';

            // Step 2 : Mark Hash Tables
            leftRow[row] = 1;
            lowDiag[row + col] = 1;
            upDiag[n-1 + col - row] = 1;

            // Step 3 : Call Func. for next Cols
            findPossibleQueens(col+1, board, ans, leftRow, lowDiag, upDiag, n );

            // Step 4 : Un-Mark Board
            board[row][col] = '.';

            // Step 5 : Un-Mark Hash Tables
            leftRow[row] = 0;
            lowDiag[row + col] = 0;
            upDiag[n-1 + col - row] = 0;

        } 
    }
}

vector<vector<string>> solveNQueens(int n) {

    vector<vector<string>> ans;
    vector<string> board(n);
    string s(n, '.');

    for(int i = 0; i<n; i++){
        board[i] = s;
    }

    vector<int> leftRow(n,0), lowerDiag(2*n-1, 0), upperDiag(2*n-1, 0);

    findPossibleQueens(0, board, ans, leftRow, lowerDiag, upperDiag, n);
    return ans;
}

void printOutput(vector<vector<string>> arr, int N){

    cout << " ------------------------ " << endl;
    for(int row = 0; row<N; row++){

        for (int col = 0; col < N; col++){
            cout << arr[row][col] << endl;
        }
        cout << endl;
    }
    cout << " ------------------------ " << endl;
    
}

int main(){

    int N = 4;
    // To take input from User  : cin>>N;
    vector<vector<string>> result;

    result = solveNQueens(N);
    printOutput(result, N);

    return 0;
}