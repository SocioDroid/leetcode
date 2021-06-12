class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        int targetrow = -1;
        for(int  i = 0; i<m; i++){
            if(matrix[i][n-1] >= target){
                targetrow = i;
                break;                
            }
        }
        
        if(targetrow == -1)
            return false;
        
        int start = 0, end = n-1;
        
        while(start<=end){
            int mid = (start+end)/2;
            int val = matrix[targetrow][mid];
            if(val==target){
                return true;                
            }
            else if(val>target)                
            {
                end = mid-1;
            }else{
                start = mid+1;
            }                    
        }
        return false;            
    }
};