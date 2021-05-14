/*
 * @lc app=leetcode id=417 lang=cpp
 *
 * [417] Pacific Atlantic Water Flow
 *
 * https://leetcode.com/problems/pacific-atlantic-water-flow/description/
 *
 * algorithms
 * Medium (44.32%)
 * Likes:    2181
 * Dislikes: 558
 * Total Accepted:    122.3K
 * Total Submissions: 275.6K
 * Testcase Example:  '[[1,2,2,3,5],[3,2,3,4,4],[2,4,5,3,1],[6,7,1,4,5],[5,1,1,2,4]]'
 *
 * You are given an m x n integer matrix heights representing the height of
 * each unit cell in a continent. The Pacific ocean touches the continent's
 * left and top edges, and the Atlantic ocean touches the continent's right and
 * bottom edges.
 * 
 * Water can only flow in four directions: up, down, left, and right. Water
 * flows from a cell to an adjacent one with an equal or lower height.
 * 
 * Return a list of grid coordinates where water can flow to both the Pacific
 * and Atlantic oceans.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: heights =
 * [[1,2,2,3,5],[3,2,3,4,4],[2,4,5,3,1],[6,7,1,4,5],[5,1,1,2,4]]
 * Output: [[0,4],[1,3],[1,4],[2,2],[3,0],[3,1],[4,0]]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: heights = [[2,1],[1,2]]
 * Output: [[0,0],[0,1],[1,0],[1,1]]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * m == heights.length
 * n == heights[i].length
 * 1 <= m, n <= 200
 * 1 <= heights[i][j] <= 10^5
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    
    bool checkPacific(int i, int j, vector<vector<int>> &heights){
        // cout<<"Checking Pacific:\ti:"<<i<<"\tj:"<<j<<"\t-\t"<<heights[i][j]<<endl;
        
        if(i== 0|| j == 0){
            // cout<<"\nPacific return trueeeeeeee"<<endl;
            return true;
        }
        if(heights[i][j] == -1)
            return false;
        
        int val = heights[i][j];    
        heights[i][j] = -1;
        bool flag = false;        
        
        if(val >= heights[i-1][j])
            flag = checkPacific(i-1, j, heights);
        
        if(!flag && val >= heights[i][j-1])
            flag = checkPacific(i, j-1, heights);
        
        if(!flag && i<heights.size()-1 && val >= heights[i+1][j])
            flag = checkPacific(i+1, j, heights);
                
        
        if(!flag&& j<heights[0].size()-1 && val >= heights[i][j+1])
            flag =  checkPacific(i, j+1, heights);
        
        heights[i][j] = val;
        return flag;
    }
    
    
    bool checkAtlantic(int i, int j, vector<vector<int>> &heights){
        
        // cout<<"Checking Atlantic:\ti:"<<i<<"\tj:"<<j<<"\t-\t"<<heights[i][j]<<endl;
       
        if(i==heights.size()-1 || j == heights[0].size()-1){
            // cout<<"\Atlantic return trueeeeeeee"<<endl;         
            return true;
        }
        
       if(heights[i][j] == -1)
            return false;
        
        int val = heights[i][j];    
        heights[i][j] = -1;
        bool flag = false;        
        
        if(val >= heights[i+1][j])
            flag = checkAtlantic(i+1, j, heights);
                
        if(!flag  && val >= heights[i][j+1])
            flag =  checkAtlantic(i, j+1, heights);
        
        if(!flag && i>0 && val >= heights[i-1][j])
            flag = checkAtlantic(i-1, j, heights);
        
        if(!flag && j > 0  && val >= heights[i][j-1])
            flag = checkAtlantic(i, j-1, heights);
        
        
        heights[i][j] = val;
        return flag;
    }
    
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
            
        vector<vector<int>> ans;
        
        for(int i = 0; i< heights.size(); i++)
        {
            for(int j = 0; j< heights[0].size(); j++)
            {
                // cout<<"---------------\nChecking:\ti:"<<i<<"\tj:"<<j<<"\t-\t"<<heights[i][j]<<endl;
                if(checkPacific(i,j, heights) && checkAtlantic(i,j, heights)){
                    // cout<<"Found trueeeeeee:\tj:"<<i<<"\tj:"<<j<<"\t-\t"<<heights[i][j]<<endl;
                    ans.push_back({i,j});
                }
            }
        }
        
        return ans;
    }
};

//DFS
class Solution {
public:
    
   
    vector<vector<int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
            
        vector<vector<int>> ans;
        
        int row = heights.size(), col = heights[0].size();
        
        vector<vector<bool>> pacific(row, vector<bool>(col));
        vector<vector<bool>> atlantic(row, vector<bool>(col));
        
        //dfs
        for(int i = 0; i<col; i++){            
            dfs(heights, 0 , i , INT_MIN, pacific);
            dfs(heights, row-1 , i , INT_MIN, atlantic);
        }
        
        for(int i = 0; i<row; i++){            
            dfs(heights, i , 0 , INT_MIN, pacific);
            dfs(heights, i , col-1 , INT_MIN, atlantic);
        }
        
        //main call
        for(int i = 0; i< heights.size(); i++)
        {
            for(int j = 0; j< heights[0].size(); j++)
            {
                if(pacific[i][j] && atlantic[i][j]){
                    ans.push_back({i,j});
                }
            }
        }
        
        return ans;
    }
    
    void dfs(vector<vector<int>> &heights, int i, int j, int prev, vector<vector<bool>> &ocean){
        
        if(i<0 || j<0 || i>=heights.size() || j>=heights[0].size()) return;
        if(heights[i][j] < prev || ocean[i][j]) return;
        ocean[i][j] = true;
        
        for(auto x: dir){
            dfs(heights, x[0]+i, x[1]+j, heights[i][j], ocean);
        }        
    }
};
// @lc code=end

