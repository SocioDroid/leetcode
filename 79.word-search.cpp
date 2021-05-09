/*
 * @lc app=leetcode id=79 lang=cpp
 *
 * [79] Word Search
 *
 * https://leetcode.com/problems/word-search/description/
 *
 * algorithms
 * Medium (37.40%)
 * Likes:    5644
 * Dislikes: 245
 * Total Accepted:    658.4K
 * Total Submissions: 1.8M
 * Testcase Example:  '[["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]\n"ABCCED"'
 *
 * Given an m x n grid of characters board and a string word, return true if
 * word exists in the grid.
 * 
 * The word can be constructed from letters of sequentially adjacent cells,
 * where adjacent cells are horizontally or vertically neighboring. The same
 * letter cell may not be used more than once.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word
 * = "ABCCED"
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word
 * = "SEE"
 * Output: true
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word
 * = "ABCB"
 * Output: false
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * m == board.length
 * n = board[i].length
 * 1 <= m, n <= 6
 * 1 <= word.length <= 15
 * board and word consists of only lowercase and uppercase English letters.
 * 
 * 
 * 
 * Follow up: Could you use search pruning to make your solution faster with a
 * larger board?
 * 
 */

// @lc code=start
class Solution {
public:
    
    bool search(vector<vector<char>>& board, int i, int j, string word, string from_where) {
        
        
        int m = board.size();
        int n = board[0].size();
        
        if(word.length() == 0)
            return true;       
    
        char to_search = word[0];
        board[i][j] -=65;
        if(j+1 < n && board[i][j+1] == to_search && search(board, i, j+1, word.substr(1, word.length()), "first"))
        {
            
            return true;
        }
        
        if(i+1 < m && board[i+1][j] == to_search && search(board, i+1, j, word.substr(1,word.length()), "second"))
        {
            return true;
        }
        
        if(j-1 >= 0 && board[i][j-1] == to_search && search(board, i, j-1, word.substr(1,word.length()), "third"))
        {
            return true;
        }
        
        if(i-1 >= 0 && board[i-1][j] == to_search && search(board, i-1, j, word.substr(1,word.length()), "fourth"))
         {
            return true;
        }
        
        board[i][j] +=65;
        return false;
        
        
    }
    
    bool exist(vector<vector<char>>& board, string word) {
                    
        for(int i = 0 ; i < board.size(); i++)
        {
            for(int j = 0; j< board[0].size(); j++)
            {
                
                if(board[i][j] == word[0] && search(board, i, j, word.substr(1,word.length()),"Initial"))
                    return true;                    
            }   
        }
        return false;
        
    }
};
// @lc code=end

