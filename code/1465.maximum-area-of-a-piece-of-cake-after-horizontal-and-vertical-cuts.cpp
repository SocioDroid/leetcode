class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontal, vector<int>& vertical) {
        
        horizontal.push_back(0);
        horizontal.push_back(h);
        vertical.push_back(0);
        vertical.push_back(w);
        
        sort(horizontal.begin(), horizontal.end());
        sort(vertical.begin(), vertical.end());
        
        int hordiff = INT_MIN;
        int verdiff = INT_MIN;
        
        for(int i = 0; i<horizontal.size()-1; i++)
        {
            hordiff = max(hordiff, horizontal[i+1] - horizontal[i]);
        }
        
        for(int i = 0; i<vertical.size()-1; i++)
        {
            verdiff = max(verdiff, vertical[i+1] - vertical[i]);
        }
        int mod = 1000000007;
        
        long ans = (long)(verdiff%mod)*(hordiff%mod)%mod;
        
        return (int)ans;
    }
};