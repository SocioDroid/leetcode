/*
 * @lc app=leetcode id=997 lang=cpp
 *
 * [997] Find the Town Judge
 *
 * https://leetcode.com/problems/find-the-town-judge/description/
 *
 * algorithms
 * Easy (49.81%)
 * Likes:    1565
 * Dislikes: 131
 * Total Accepted:    169.2K
 * Total Submissions: 339.7K
 * Testcase Example:  '2\n[[1,2]]'
 *
 * In a town, there are n people labelled from 1 to n.  There is a rumor that
 * one of these people is secretly the town judge.
 * 
 * If the town judge exists, then:
 * 
 * 
 * The town judge trusts nobody.
 * Everybody (except for the town judge) trusts the town judge.
 * There is exactly one person that satisfies properties 1 and 2.
 * 
 * 
 * You are given trust, an array of pairs trust[i] = [a, b] representing that
 * the person labelled a trusts the person labelled b.
 * 
 * If the town judge exists and can be identified, return the label of the town
 * judge.  Otherwise, return -1.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: n = 2, trust = [[1,2]]
 * Output: 2
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: n = 3, trust = [[1,3],[2,3]]
 * Output: 3
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: n = 3, trust = [[1,3],[2,3],[3,1]]
 * Output: -1
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: n = 3, trust = [[1,2],[2,3]]
 * Output: -1
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: n = 4, trust = [[1,3],[1,4],[2,3],[2,4],[4,3]]
 * Output: 3
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= n <= 1000
 * 0 <= trust.length <= 10^4
 * trust[i].length == 2
 * trust[i] are all different
 * trust[i][0] != trust[i][1]
 * 1 <= trust[i][0], trust[i][1] <= n
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if(n==1 && trust.size())
            return 1;
        vector<bool> outgoing(n+1);
        // vector<vector<bool>> graph(n+1, vector<bool>(n+1));
        
        
//         for(auto t : trust){
//             graph[t[0]][t[1]] = true;
//             outgoing[t[0]] = true;
//         }

        
//         for(int i=1; i<=n; i++){
//             if(!outgoing[i]){
//                 for(int j = 1; j <=n; j++)
//                 {
//                     if(j==i)
//                         continue;
//                     if(!graph[j][i])
//                         return -1;   
//                 }
//                 return i;
//             }
//         }        
//         return -1;   

        unordered_map<int, int> incoming;
        
        for(auto t : trust){
            outgoing[t[0]] = true;
            incoming[t[1]]++;
        }

        
        for(int i=1; i<=n; i++){
            if(!outgoing[i] && incoming[i] == n-1)
                    return i;                        
        }        
        return -1;   
    }
};
// @lc code=end

