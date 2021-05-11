/*
 * @lc app=leetcode id=684 lang=cpp
 *
 * [684] Redundant Connection
 *
 * https://leetcode.com/problems/redundant-connection/description/
 *
 * algorithms
 * Medium (59.29%)
 * Likes:    2100
 * Dislikes: 250
 * Total Accepted:    129.9K
 * Total Submissions: 219K
 * Testcase Example:  '[[1,2],[1,3],[2,3]]'
 *
 * In this problem, a tree is an undirected graph that is connected and has no
 * cycles.
 * 
 * You are given a graph that started as a tree with n nodes labeled from 1 to
 * n, with one additional edge added. The added edge has two different vertices
 * chosen from 1 to n, and was not an edge that already existed. The graph is
 * represented as an array edges of length n where edges[i] = [ai, bi]
 * indicates that there is an edge between nodes ai and bi in the graph.
 * 
 * Return an edge that can be removed so that the resulting graph is a tree of
 * n nodes. If there are multiple answers, return the answer that occurs last
 * in the input.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: edges = [[1,2],[1,3],[2,3]]
 * Output: [2,3]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: edges = [[1,2],[2,3],[3,4],[1,4],[1,5]]
 * Output: [1,4]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * n == edges.length
 * 3 <= n <= 1000
 * edges[i].length == 2
 * 1 <= ai < bi <= edges.length
 * ai != bi
 * There are no repeated edges.
 * The given graph is connected.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    
    
    void printG(vector<vector<int>> edges){
        cout<<"----------------\n";
        for(auto row : edges){
            for(auto j : row){
                cout<<j<<"\t";
            }
            cout<<endl;
        }
        
    }
    
    map<int,set<int>> hmap;
    set<int> visited;
    
    bool dfs(int source, int target){
        
        if(visited.find(source)==visited.end())
        {
            visited.insert(source);
            // cout<<"SOurce :"<<source<<"\t target: "<<target<<endl;
            if(source == target)
                return true;
            for(auto i: hmap[source]){                
                if(dfs(i, target))
                    return true;
            }
        }
        return false;
        
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {        
        for(auto row : edges){
            visited.clear();
            int u = row[0];
            int v = row[1];
            
            if(hmap.find(u)!=hmap.end() && hmap.find(v)!=hmap.end() && dfs(u,v))
                return row;
            
            hmap[u].insert(v);
            hmap[v].insert(u);
            // cout<<"Inserted : \t"<<u<<"\t"<<v<<endl;            
        }
        
        return {};           
        
    }
};
// @lc code=end

