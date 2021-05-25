class Solution {
public:
    
    vector<int> perfectsquare(int n){
        
        int maxn = floor(pow(n,0.5));
        
        vector<int> powers;
        for(int i = 1; i<=maxn; i++)
        {
            powers.push_back(i*i);
        }
        return powers;        
    }
    int numSquares(int n) {
        
        vector<int> sq = perfectsquare(n);
        int m = sq.size();
        int dp[m][n+1];
        memset(dp, 0, sizeof(dp));
        
        int minval = INT_MAX;
        
        for(int i = 0; i<m; i++){
            for(int j = 1; j<=n; j++){
                
                if(sq[i] == j)
                    dp[i][j] = 1;
                
                else if(sq[i] > j){
                    dp[i][j] = dp[i-1][j];
                }
                
                else if(sq[i]<j){
                    if(i==0) dp[i][j] = 1+dp[i][j-sq[i]];
                    else dp[i][j] = min(1+dp[i][j-sq[i]], dp[i-1][j]);
                }
                                
                if(j==n)
                    minval = min(dp[i][j], minval);
            }
        }
        
        return minval;
    }
};