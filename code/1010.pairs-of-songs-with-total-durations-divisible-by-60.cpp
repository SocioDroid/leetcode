class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        
        // mod it by 60 and store in a graph
        // unordered_map<int,int> hmap;
        vector<int> arr(60);
        int ans = 0;
        for(int i = 0; i<time.size(); i++)
        {                       
            arr[time[i]%60]++;            
        }
        // 2 sum problem : search in graph
        
        ans+= ((arr[0]-1)*arr[0])/2;
        ans+= ((arr[30]-1)*arr[30])/2;
        
        for(int i = 1; i<=29; i++)
            ans+=arr[i]*arr[60-i];
        
        return ans;
    }
};