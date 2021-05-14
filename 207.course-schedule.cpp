/*
 * @lc app=leetcode id=207 lang=cpp
 *
 * [207] Course Schedule
 *
 * https://leetcode.com/problems/course-schedule/description/
 *
 * algorithms
 * Medium (44.38%)
 * Likes:    5839
 * Dislikes: 247
 * Total Accepted:    587.5K
 * Total Submissions: 1.3M
 * Testcase Example:  '2\n[[1,0]]'
 *
 * There are a total of numCourses courses you have to take, labeled from 0 to
 * numCourses - 1. You are given an array prerequisites where prerequisites[i]
 * = [ai, bi] indicates that you must take course bi first if you want to take
 * course ai.
 * 
 * 
 * For example, the pair [0, 1], indicates that to take course 0 you have to
 * first take course 1.
 * 
 * 
 * Return true if you can finish all courses. Otherwise, return false.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: numCourses = 2, prerequisites = [[1,0]]
 * Output: true
 * Explanation: There are a total of 2 courses to take. 
 * To take course 1 you should have finished course 0. So it is possible.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
 * Output: false
 * Explanation: There are a total of 2 courses to take. 
 * To take course 1 you should have finished course 0, and to take course 0 you
 * should also have finished course 1. So it is impossible.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= numCourses <= 10^5
 * 0 <= prerequisites.length <= 5000
 * prerequisites[i].length == 2
 * 0 <= ai, bi < numCourses
 * All the pairs prerequisites[i] are unique.
 * 
 * 
 */

// @lc code=start
class Solution
{
public:
    int checkind(unordered_map<int, int> &hmap, int &n)
    {

        for (int i = 0; i < n; i++)
        {
            if (hmap.find(i) == hmap.end() || hmap[i] == 0)
                return i;
            else if (hmap[i] < 0)
                continue;
        }
        return -1;
    }

    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {

        vector<vector<int>> graph(numCourses, vector<int>(numCourses));

        unordered_map<int, int> umap;

        //make graph
        for (auto edge : prerequisites)
        {
            if (edge[1] == edge[0])
                return false;
            graph[edge[1]][edge[0]]++;
            umap[edge[0]]++;
        }

        int visitedCount = 0;

        while (true)
        {
            //get node with zero indegree
            int zeroind = checkind(umap, numCourses);

            if (zeroind == -1)
                return false;

            //mark node as visited so that it won't be returned next time;
            umap[zeroind] = -1;

            //delete the node from the graph by making the row[edge] zero
            for (int i = 0; i < numCourses; i++)
            {
                //if edge exists
                if (graph[zeroind][i])
                {
                    //remove the edge
                    graph[zeroind][i] = 0;
                    //decrement the indegree of the node whose edge is removed
                    umap[i]--;
                }
            }

            //base case for while loop termination
            visitedCount++;
            if (visitedCount == numCourses)
                break;
        }

        return true;
        // ------------------------------------- faster method
        vector<pair<int, set<int>>> graph(numCourses);

        for (auto edge : prerequisites)
        {
            if (edge[1] == edge[0])
                return false;
            int s = edge[1];
            int d = edge[0];
            graph[s].second.insert(d);
            graph[d].first++;
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i++)
        {
            if (graph[i].first == 0)
                q.push(i);
        }
        int count = numCourses;

        while (!q.empty())
        {

            int node = q.front();
            q.pop();

            for (auto adjele : graph[node].second)
            {
                if (graph[adjele].first == 1)
                    q.push(adjele);
                else
                    graph[adjele].first--;
            }

            count--;
        }

        return count == 0;
    }
};
// @lc code=end
