class NumArray {
public:
    int dp[10001];
    NumArray(vector<int>& nums) {
        int n = nums.size();
        memset(dp,0 ,sizeof(dp));
        
        for(int i =0; i<n; i++){
                dp[i+1] = nums[i]+dp[i];
            }    
    }
    
    int sumRange(int left, int right) {
        return dp[right+1]-dp[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */