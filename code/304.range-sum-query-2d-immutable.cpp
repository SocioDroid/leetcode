class NumMatrix {
public:
    
   void printmat(vector<vector<int>> &dp){
        for(auto i: dp){
            for(auto j: i){
                cout<<j<<" ";
            }
            
            cout<<endl;
        }    
        
        cout<<"---------\n";
    }
    
    vector<vector<int>> dp;
    
    NumMatrix(vector<vector<int>>& matrix) {
        
        int m = matrix.size();
        int n = matrix[0].size();
        
        dp = vector(m+1, vector<int>(n+1, 0));
        
        for(int i = 0; i<m; i++){
            dp[i+1][1]+=matrix[i][0]+dp[i][1];
        }
        
        for(int i =1; i<n; i++){
            dp[1][i+1]+=matrix[0][i]+dp[1][i];
        }
        
        for(int i = 2; i<=m; i++){
            for(int j = 2; j<=n; j++){
                dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + matrix[i-1][j-1];
            }
        }
        // printmat(dp);
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        row1+=1;
        col1+=1;
        row2+=1;
        col2+=1;
        return dp[row2][col2] - dp[row1-1][col2] - dp[row2][col1-1] + dp[row1-1][col1-1];
        // return 0;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */