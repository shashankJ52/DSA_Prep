/*******************
 * Problem : 37. Sudoko Solver [ LeetCode ]
 *
 * Link : https://leetcode.com/problems/sudoku-solver/
 *
 * Approach :
 *          -> Loop Row wise (0 ---> 9)
 *                  -> loop Column wise (0 ---> 9) to find Empty Space
 *                      -> if(board[i][j] == '.')
 *                      -> Check for 1 to 9 if a VALID BOARD is Possible
 *
 *          VALID BOARD CONDITION
 *          -> false Conditions
 *                  if(board[i][col] == val);
 *                  if(board[row][i] == val);
 *                  if(board[3*(row/3)+i/3][3*(col/3)+i%3] == val);
 *
 */


#include <bits/stdc++.h>
using namespace std;

bool isValid(vector<vector<int>>& board, int row, int col, int val){
    for (int i = 0; i < 9; i++){
        if(board[i][col] == val)
            return false;
        if(board[row][i] == val)
            return false;
        if(board[3*(row/3)+i/3][3*(col/3)+i%3] == val)
            return false;
    }
    return true;

}

bool SolveSudoko(vector<vector<int>>& board){

    // Step 1 : Traverse the board and find empty space to fill
    for(int i = 0; i<board.size(); i++){
        for(int j = 0; j<board[0].size(); j++){
            // Empty Space 
            if(board[i][j] == 0){
                
                // Step 2 : check if board is vaild after filling 1-->9
                for(int c = 1; c<=9; c++){
                    // check row-wise || col-wise || 3x3 Matrix
                    if(isValid(board, i, j, c)){
                        
                        board[i][j] = c; // Mark Board
                        // Step 3 : <-- RECURSION CALL --> 
                        if(SolveSudoko(board) == true)
                            return true;
                        else
                            board[i][j] = 0; // Un-Mark Board
                    }
                    
                }
                return false;
            }
        }
    }
    return true;
}

void printGrid(vector<vector<int>>& board){
    
    // cout << "--------------------------------" << endl;
    for (int i = 0; i < 9; i++){
        for (int j = 0; j < 9; j++){

            cout << board[i][j] << " ";
            if(j == 2 || j == 5)
                cout << " | ";
        }
        cout << endl;
        if(i == 2 || i == 5 )
            cout << "---------------------------" << endl;
        
    }
    cout << endl;
    // cout << "--------------------------------" << endl;
}


int main(){
    vector<vector<int>> board {
             {0, 0, 0, 2, 0, 4, 9, 0, 0},
             {9, 0, 1, 8, 0, 5, 6, 0, 0},
             {0, 0, 0, 0, 0, 0, 0, 1, 0},

             {0, 0, 9, 0, 4, 0, 0, 6, 0},
             {3, 6, 0, 0, 0, 0, 0, 9, 7},
             {0, 5, 0, 0, 6, 0, 2, 0, 0},

             {0, 7, 0, 0, 0, 0, 0, 0, 0},
             {0, 0, 6, 5, 0, 1, 7, 0, 4},
             {0, 0, 8, 4, 0, 7, 0, 0, 0},
    };

    /*
    // Take board input from User
    cout << "Enter the Sudoko Board" << endl;
    for (int i = 0; i < 9; i++){
        cout << "Row " << i + 1 << endl;
        vector<char> row;
        for (int j = 0; j < 9; j++){
            char ch;
            cin >> ch;
            row.push_back(ch);
        }
        board.push_back(row);
    }
    */
    
    
    cout << "<------ THE GIVEN BOARD ------>" << endl<<endl;
    printGrid(board);
    
    

    if(SolveSudoko(board) == true){
        cout << "<------ SOLUTION ------>" << endl<<endl;
        printGrid(board);
    }else{
        cout << "NO SOLUTION FOUND" << endl;
    }

    return 0;
}