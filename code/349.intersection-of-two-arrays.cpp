class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        
        unordered_map<int,bool> umap;
        
        for(auto i: nums1){
            umap[i] = true;
        }
        vector<int>ans;
        for(auto i: nums2){
            if(umap.find(i) != umap.end()){
                if(umap[i]){
                    ans.push_back(i);
                    umap[i] = false;
                }
            }
        }
        return ans;
    } 
};