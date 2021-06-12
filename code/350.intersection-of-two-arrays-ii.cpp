class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> umap;
        
        for(auto i: nums1){
            umap[i] += 1;
        }
        
        vector<int>ans;
        
        for(auto i: nums2){
            if(umap.find(i) != umap.end()){
                if(umap[i] > 0){
                    ans.push_back(i);
                    umap[i]--;
                }
            }
        }
        return ans;
    }
};
