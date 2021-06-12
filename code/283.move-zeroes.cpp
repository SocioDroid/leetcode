class Solution {
public:
    
    void print(vector<int> & nums){
        
        for(auto i: nums)
            cout<<i<<" ";
        cout<<endl;
    }
    void moveZeroes(vector<int>& nums) {
        
        if (nums.size() == 1)
            return;
        
        int count = 0;
        
        int zero = nums.size()-1;
        
        while(zero>=0 && !nums[zero]) zero--;
        
        for(int i = 0 ; i<=zero; i++){
            if(!nums[i]){                
                int temp = i;
                // cout<<"zero found at pos : "<<i<<endl;
                while(temp != nums.size()-1){
                    nums[temp] = nums[temp+1];
                    temp++;
                }
                nums[nums.size()-1] = 0;
                zero--;
                i--;
                // print(nums);
            }
        }
    }
};