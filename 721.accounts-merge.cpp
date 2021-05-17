/*
 * @lc app=leetcode id=721 lang=cpp
 *
 * [721] Accounts Merge
 *
 * https://leetcode.com/problems/accounts-merge/description/
 *
 * algorithms
 * Medium (52.62%)
 * Likes:    2431
 * Dislikes: 436
 * Total Accepted:    144.9K
 * Total Submissions: 275K
 * Testcase Example:  '[["John","johnsmith@mail.com","john_newyork@mail.com"],["John","johnsmith@mail.com","john00@mail.com"],["Mary","mary@mail.com"],["John","johnnybravo@mail.com"]]'
 *
 * Given a list of accounts where each element accounts[i] is a list of
 * strings, where the first element accounts[i][0] is a name, and the rest of
 * the elements are emails representing emails of the account.
 * 
 * Now, we would like to merge these accounts. Two accounts definitely belong
 * to the same person if there is some common email to both accounts. Note that
 * even if two accounts have the same name, they may belong to different people
 * as people could have the same name. A person can have any number of accounts
 * initially, but all of their accounts definitely have the same name.
 * 
 * After merging the accounts, return the accounts in the following format: the
 * first element of each account is the name, and the rest of the elements are
 * emails in sorted order. The accounts themselves can be returned in any
 * order.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: accounts =
 * [["John","johnsmith@mail.com","john_newyork@mail.com"],["John","johnsmith@mail.com","john00@mail.com"],["Mary","mary@mail.com"],["John","johnnybravo@mail.com"]]
 * Output:
 * [["John","john00@mail.com","john_newyork@mail.com","johnsmith@mail.com"],["Mary","mary@mail.com"],["John","johnnybravo@mail.com"]]
 * Explanation:
 * The first and third John's are the same person as they have the common email
 * "johnsmith@mail.com".
 * The second John and Mary are different people as none of their email
 * addresses are used by other accounts.
 * We could return these lists in any order, for example the answer [['Mary',
 * 'mary@mail.com'], ['John', 'johnnybravo@mail.com'], 
 * ['John', 'john00@mail.com', 'john_newyork@mail.com', 'johnsmith@mail.com']]
 * would still be accepted.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: accounts =
 * [["Gabe","Gabe0@m.co","Gabe3@m.co","Gabe1@m.co"],["Kevin","Kevin3@m.co","Kevin5@m.co","Kevin0@m.co"],["Ethan","Ethan5@m.co","Ethan4@m.co","Ethan0@m.co"],["Hanzo","Hanzo3@m.co","Hanzo1@m.co","Hanzo0@m.co"],["Fern","Fern5@m.co","Fern1@m.co","Fern0@m.co"]]
 * Output:
 * [["Ethan","Ethan0@m.co","Ethan4@m.co","Ethan5@m.co"],["Gabe","Gabe0@m.co","Gabe1@m.co","Gabe3@m.co"],["Hanzo","Hanzo0@m.co","Hanzo1@m.co","Hanzo3@m.co"],["Kevin","Kevin0@m.co","Kevin3@m.co","Kevin5@m.co"],["Fern","Fern0@m.co","Fern1@m.co","Fern5@m.co"]]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= accounts.length <= 1000
 * 2 <= accounts[i].length <= 10
 * 1 <= accounts[i][j] <= 30
 * accounts[i][0] consists of English letters.
 * accounts[i][j] (for j > 0) is a valid email.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, set<string>> graph;
        unordered_map<string, string> emailToName;
        //create graph
        for(auto account : accounts){
            string name = account[0];
            string firstemail = account[1];

            for(int i = 1; i<account.size(); i++){
                graph[firstemail].insert(account[i]);
                graph[account[i]].insert(firstemail);                    
                emailToName[account[i]] = name;
            }            
        }
        
        for(auto i: graph){
            cout<<i.first<<"\t\t-->     ";
            for(auto j : i.second){
                cout<<j<<" - ";
            }
            cout<<endl;            
        }
        //dfs here
        
        
        unordered_map<string, bool> visited;
        vector<vector<string>> result;
        
        for(auto i: graph){
            set<string> currentset;
            if(visited.find(i.first) == visited.end()){
                dfs(graph, i.first, visited, currentset);                
        }   
            if(!currentset.empty()){
                
                vector<string> currentemails(currentset.begin(), currentset.end());
                vector<string> resultset = {emailToName[currentemails[0]]};
                sort(currentemails.begin(), currentemails.end());
                
                resultset.insert(resultset.end(), currentemails.begin(), currentemails.end());
                result.push_back(resultset);
            }
        }
        
        return result;
    }
    
    void dfs(unordered_map<string, set<string>> &graph, string source, unordered_map<string, bool> &visited, set<string> &currentset){
        
        visited[source] = true;
        currentset.insert(source);
        
        for(auto adj: graph[source]){
            if(visited.find(adj) == visited.end())
                dfs(graph, adj, visited, currentset);
        }
    }
};
// @lc code=end

