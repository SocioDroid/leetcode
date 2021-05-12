/*
 * @lc app=leetcode id=743 lang=cpp
 *
 * [743] Network Delay Time
 *
 * https://leetcode.com/problems/network-delay-time/description/
 *
 * algorithms
 * Medium (45.84%)
 * Likes:    2572
 * Dislikes: 247
 * Total Accepted:    148.3K
 * Total Submissions: 323.4K
 * Testcase Example:  '[[2,1,1],[2,3,1],[3,4,1]]\n4\n2'
 *
 * You are given a network of n nodes, labeled from 1 to n. You are also given
 * times, a list of travel times as directed edges times[i] = (ui, vi, wi),
 * where ui is the source node, vi is the target node, and wi is the time it
 * takes for a signal to travel from source to target.
 * 
 * We will send a signal from a given node k. Return the time it takes for all
 * the n nodes to receive the signal. If it is impossible for all the n nodes
 * to receive the signal, return -1.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: times = [[2,1,1],[2,3,1],[3,4,1]], n = 4, k = 2
 * Output: 2
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: times = [[1,2,1]], n = 2, k = 1
 * Output: 1
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: times = [[1,2,1]], n = 2, k = 2
 * Output: -1
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= k <= n <= 100
 * 1 <= times.length <= 6000
 * times[i].length == 3
 * 1 <= ui, vi <= n
 * ui != vi
 * 0 <= wi <= 100
 * All the pairs (ui, vi) are unique. (i.e., no multiple edges.)
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    
    int minDistance(vector<int> distance, vector<bool>visited, int n){
        
        int min = INT_MAX, minidx = -1;
        for(int i = 1; i<=n; i++){
            if(visited[i]==false && distance[i] < min)
                minidx = i, min = distance[i];
        }
        return minidx;
        
    }
    
    void printg(vector<vector<int>> graph){
        
        for(auto i: graph){
            for(int val: i )
                cout<<val<<"\t";
            cout<<endl;            
        }
    }
    
    int maxcal(vector<int> distance )
    {
        int max_m = INT_MIN;

        for(auto i : distance)
        {
            if(i != INT_MAX)
                max_m = max(i, max_m);
        }

        return max_m;
    }
    
    int networkDelayTime(vector<vector<int>>& times, int n, int src) {
        
        vector<vector<int>> graph(n+1,vector<int>(n+1, -1));
        bool flag = false;
        for(auto i : times){
            if(i[0] == src)
                flag = true;
            graph[i[0]][i[1]] = i[2];            
        }
        printg(graph);
        if(!flag)
            return -1;        
        
        vector<int> distance(n+1);
        vector<bool>visited(n+1);

        for(int i =1 ;i<=n; i++){
            distance[i] = INT_MAX;
            visited[i] = false;
        }
        distance[src] = 0;
        int total_cost = INT_MIN;
        for(int count = 1; count<=n; count++){
            int u = minDistance(distance, visited, n);
            if( u == -1 ||distance[u] == INT_MAX)
                return -1;
            
            visited[u] = true;                                
            
            for(int v=1 ;v<=n; v++){             
                if(!visited[v] && graph[u][v]!=-1 && distance[u] != INT_MAX && (distance[v] > distance[u]+graph[u][v])){               
                    distance[v] = distance[u]+graph[u][v];                        
                }
            }
        }
        cout<<endl;
            
        
        for(int i=1; i<=n; i++){
            if(!visited[i])
                return -1;
        }
        
        return maxcal(distance);
    }
};
// @lc code=end

