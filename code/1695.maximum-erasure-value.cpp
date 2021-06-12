class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_map<int,int> umap;
        int nsize=  nums.size();
        
        if(nsize == 1)
            return nums[0];
        
        for(auto i: nums){
            umap[i] = 0;
        }
        
        int max_sum = INT_MIN;
        
        int left = 0, right = 0;
        int sum = 0;
        
        while(right < nsize){
            if(umap[nums[right]] != 0){              
                
                while(umap[nums[right]]!=0){
                    sum-=nums[left];
                    umap[nums[left++]]--; 
                }                                
            }
            
            sum+=nums[right];
            umap[nums[right]]++;     
            max_sum = max(sum, max_sum);

            right++;
        }
        
        return max_sum;
        
    }
};