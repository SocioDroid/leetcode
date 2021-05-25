class Solution {
public:
    bool canPartition(vector<int>& nums) {
        
        int  k = 2;
        
        int sum = accumulate(nums.begin(), nums.end(), 0);
        

        if(sum%k != 0 || *max_element(nums.begin(), nums.end()) > sum/k)
            return false;
        // Base case checked
        
        vector<vector<bool>> dp(nums.size(), vector<bool>((sum/2)+1, false));
        
        
        
        for(int  i = 0; i<nums.size(); i++){
            for(int j = 0; j <=(sum/2); j++){
                if(j==0){
                    dp[i][j] = true;
                    continue;
                }
                if(nums[i] == j)
                    dp[i][j] = true;
                
                if(i==0)
                    continue;
                
                if(nums[i]>j)
                    dp[i][j] = dp[i-1][j];
                else if(nums[i]<j){
                    if(dp[i-1][j] == true) dp[i][j] = true;
                    else dp[i][j] = dp[i-1][j-nums[i]];
                    
                }
                    
            }
        }
        
        return dp[nums.size()-1][sum/2];
        
    }

};