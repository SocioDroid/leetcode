class Solution {
public:
    
    void  dfs(vector<vector<int>> &grid , int i, int j, int &count)
    {
        // cout<<i<<" "<<j<<endl;
        
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j] != 1)
            return;
        
        grid[i][j] = -1;
        count ++;
        
        dfs(grid, i+1, j, count);
        dfs(grid, i, j+1, count);
        dfs(grid, i-1, j, count);
        dfs(grid, i, j-1, count);

        return;                
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        int max_count = 0;
        int m = grid.size();
        int n = grid[0].size();
        
        for(int i = 0; i<m; i++)
        {
            for(int j = 0; j<n; j++)
            {
                if(grid[i][j] == 1)
                {   
                    int count = 0;
                    dfs(grid, i, j, count);
                    max_count = max(max_count, count);
                }
            }
        }
        return max_count;
    }
};