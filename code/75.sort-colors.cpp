class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        
        if(n == 1)
            return;
        
        int i = 0;
        int j = n-1;
        
        while(i < n && !nums[i] ) i++;
        
        while(j >= 0 && nums[j] == 2) j--;
        
        
        int k = i;
        
        while (k <= j){
            
            if(!nums[k]) swap(nums[k++], nums[i++]);
            else if(nums[k] == 2) swap(nums[k], nums[j--]);
            else
                k++;
        }        
        
    }
};