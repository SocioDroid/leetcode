class Solution {
public:
    int maximumGap(vector<int>& nums) {
        
        if(nums.size()==1)
            return 0;
        
        sort(nums.begin(), nums.end());
        
        int max_val = INT_MIN;
        for(int i = 0; i<nums.size()-1; i++){            
            max_val = max((nums[i+1]-nums[i]), max_val);            
        }
        return max_val;
        
    }
};