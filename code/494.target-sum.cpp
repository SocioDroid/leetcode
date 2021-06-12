class Solution {
public:
    
    void solve(vector<int>& nums, int index, int sum, int target, int &count){
        
        if(index >= nums.size()){
        
            if(sum == target)
                count++;        

            return;
        }
                    
        solve(nums, index+1, sum+nums[index], target, count);
        solve(nums, index+1, sum-nums[index], target, count);            
    }
    int findTargetSumWays(vector<int>& nums, int target) {        
        int count = 0;
        solve(nums, 0, 0, target, count);
        return count;
    }
};