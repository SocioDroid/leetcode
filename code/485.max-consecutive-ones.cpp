class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        
        int count = 0;
        
        int maxval = 0;
        for(auto i: nums){
            if(i == 1){
                count++;
                maxval = max(maxval, count);
            }
            else
                count = 0;
        }
        
        return maxval;
        
    }
};