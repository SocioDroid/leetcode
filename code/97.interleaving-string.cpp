class Solution {
public:
    
    bool solve(string &s1, int i, string &s2, int j, string &s3, int k){
        if(k == s3.size())
            return true;
        
        // cout<<s3[k] << " "<<k<<" "<<s1[i] << i << " " << s2[j]<<j<<endl;   
        if(s3[k] == s1[i] && solve(s1, i+1, s2, j, s3, k+1))
            return true;
                
        if(s3[k] == s2[j] && solve(s1, i, s2, j+1, s3, k+1))
            return true;
        
        return false;                    
    }
    
    bool isInterleave(string s1, string s2, string s3) {
        
        if(s3.size() < s1.size()+s2.size())
            return false;
        
        return solve(s1, 0, s2, 0, s3, 0);
//         int i = 0, j = 0;
        
//         for(int k = 0; k<s3.size(); k++){
//             if(s3[k] == s1[i]) i++;
//             else if(s3[k] == s2[j]) j++;
//             else {
//                 cout<<s3[k] << " "<<k<<" "<<s1[i] << i << " " << s2[j]<<j<<endl;   
//                 return false;
//             }
//         }
        
//         return true;
        
    }
};