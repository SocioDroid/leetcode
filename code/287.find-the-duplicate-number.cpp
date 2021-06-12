class Solution {
public:
    int findDuplicate(vector<int>& nums) {
          
        int rabbit = 0;
        int tortoise = 0;
        
        do{            
            rabbit =nums[nums[rabbit]];
            tortoise = nums[tortoise];            
        }
        while(nums[rabbit]!=nums[tortoise]);            
        
        tortoise = 0;
        while(nums[rabbit]!=nums[tortoise]){
            tortoise = nums[tortoise];
            rabbit = nums[rabbit];
        }

        // cout<<"Rabbit : "<<rabbit<<"\t Tot: "<<tortoise;
        return nums[rabbit];
        
    }
    
};