/*
 * @lc app=leetcode id=37 lang=cpp
 *
 * [37] Sudoku Solver
 *
 * https://leetcode.com/problems/sudoku-solver/description/
 *
 * algorithms
 * Hard (47.47%)
 * Likes:    2822
 * Dislikes: 108
 * Total Accepted:    239.6K
 * Total Submissions: 502.8K
 * Testcase Example:  '[["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]'
 *
 * Write a program to solve a Sudoku puzzle by filling the empty cells.
 * 
 * A sudoku solution must satisfy all of the following rules:
 * 
 * 
 * Each of the digits 1-9 must occur exactly once in each row.
 * Each of the digits 1-9 must occur exactly once in each column.
 * Each of the digits 1-9 must occur exactly once in each of the 9 3x3
 * sub-boxes of the grid.
 * 
 * 
 * The '.' character indicates empty cells.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: board =
 * [["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]
 * Output:
 * [["5","3","4","6","7","8","9","1","2"],["6","7","2","1","9","5","3","4","8"],["1","9","8","3","4","2","5","6","7"],["8","5","9","7","6","1","4","2","3"],["4","2","6","8","5","3","7","9","1"],["7","1","3","9","2","4","8","5","6"],["9","6","1","5","3","7","2","8","4"],["2","8","7","4","1","9","6","3","5"],["3","4","5","2","8","6","1","7","9"]]
 * Explanation: The input board is shown above and the only valid solution is
 * shown below:
 * 
 * 
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * board.length == 9
 * board[i].length == 9
 * board[i][j] is a digit or '.'.
 * It is guaranteed that the input board has only one solution.
 * 
 * 
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    // constraints
    bool check(vector<vector<char>>& board, int row, int col){
        int n = board.size();
        char num = board[row][col];
        // check col
        for(int i = 0; i<n; i++){
            if(i!=col && board[row][i] == num)
                return false;
        }
        
        // check row
        for(int i = 0; i<n; i++){
            if(i!=row && board[i][col] == num)
                return false;
        }
        
        // check self grid
        int startrow = (row/3)*3;
        int startcol = (col/3)*3;
        for(int i = startrow; i<startrow+3; i++){
            for(int j = startcol; j<startcol+3; j++){
                if(i==row && j==col)
                    continue;
                if(board[i][j] == num)
                    return false;
            } 
        }
        cout<<"Returning true for: "<< row<<" " << col<<" " <<board[row][col]<<endl;
        return true;                
    }
    
    
    bool solve(vector<vector<char>>& board, int row, int col){
        
        int n = board.size();
        // base case    
        if(row>=n)
            return true;        
        if(col>=n)            
            return solve(board, row+1, 0);            
        char val = board[row][col];
        if(val!='.')
            return solve(board, row, col+1);
        // search space
        for(char i='1'; i<='9'; i++){                                    
                board[row][col] = i;
                if(check(board, row, col)){
                    // cout<<"Returning true for: "<< row<<" " << col<<" " <<board[row][col]<<endl;
                    
                    if(solve(board,row,col+1))
                        return true;
                                    
            }
        }
        
                        board[row][col] = '.';
        return false;
        
    }
        
    void solveSudoku(vector<vector<char>>& board) {
        // board[0][2]='9';
        // cout<<check(board,0,2);
        // int startrow = 0;
        // int startcol = 0;
        // for(int i = startrow; i<9; i++){
        //     for(int j = startcol; j<9; j++){
        //         if(board[i][j] =='.')
                    solve(board,0,0);
        //     }
        // }
    
    }
};

int main(){

    vector<vector<char>> board
    {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };

    Solution().solveSudoku(board);
    for(auto i: board){
        for(auto j: i)
        cout<<j<<" ";
        cout << endl; 
    }

}
// @lc code=end

