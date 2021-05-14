/*
 * @lc app=leetcode id=547 lang=cpp
 *
 * [547] Number of Provinces
 *
 * https://leetcode.com/problems/number-of-provinces/description/
 *
 * algorithms
 * Medium (60.93%)
 * Likes:    3046
 * Dislikes: 182
 * Total Accepted:    269.8K
 * Total Submissions: 442.5K
 * Testcase Example:  '[[1,1,0],[1,1,0],[0,0,1]]'
 *
 * There are n cities. Some of them are connected, while some are not. If city
 * a is connected directly with city b, and city b is connected directly with
 * city c, then city a is connected indirectly with city c.
 * 
 * A province is a group of directly or indirectly connected cities and no
 * other cities outside of the group.
 * 
 * You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the
 * i^th city and the j^th city are directly connected, and isConnected[i][j] =
 * 0 otherwise.
 * 
 * Return the total number of provinces.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: isConnected = [[1,1,0],[1,1,0],[0,0,1]]
 * Output: 2
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: isConnected = [[1,0,0],[0,1,0],[0,0,1]]
 * Output: 3
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= n <= 200
 * n == isConnected.length
 * n == isConnected[i].length
 * isConnected[i][j] is 1 or 0.
 * isConnected[i][i] == 1
 * isConnected[i][j] == isConnected[j][i]
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    
    void dfs(vector<vector<int>>& isConnected, int node, unordered_map<int, bool> &visited){
        
        if(visited.find(node) != visited.end())
            return;
        
        visited[node] = true;        
        
        for(int i =0; i<isConnected.size(); i++){
            if(node != i && isConnected[node][i] && visited.find(i) == visited.end())
                dfs(isConnected, i, visited);            
        }
        
    }
    
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        unordered_map<int, bool> visited;
        
        int province = 0;
        
        int n = isConnected.size();
        
        for(int i=0; i<n; i++){
            if(visited.find(i) == visited.end()){
                dfs(isConnected, i, visited);
                province++;
            }
            if(visited.size()==n)
                break;
        }
        
        return province;
        
    }
};
// @lc code=end

