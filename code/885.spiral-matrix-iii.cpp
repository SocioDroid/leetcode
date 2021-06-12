class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rstart, int cstart) {
        vector<vector<int>> ans;
        
        int len = 0;        
        int direction[] = {0,1,0,-1,0};
        int d = 0;
        ans.push_back({rstart, cstart});
        while(ans.size() < (rows*cols)){
            
            if(d == 0 || d == 2 )
                len++;
            
            for(int iter = 0; iter<len; iter++){
                
                rstart+= direction[d];
                cstart+= direction[d+1];
                
                if(rstart < rows && rstart >=0 && cstart <cols && cstart >=0 )
                    ans.push_back({rstart, cstart});                
            }
            
            d = ++d%4;            
        }
        return ans;
    }
};