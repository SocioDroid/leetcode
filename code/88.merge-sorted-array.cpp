class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        
        if(n==0)
            return;
        if(m==0){
            for(int i = 0; i<n; i++){
                nums1[i] = nums2[i];            
            }
            return;
        }
        int back = m+n-1, i = m-1, j = n-1;
        
        while(i>=0 && j>= 0){
            if(nums1[i] > nums2[j])
                nums1[back--] = nums1[i--];
            else
                nums1[back--] = nums2[j--];
        }
        
        while(j>=0){
            nums1[back--] = nums2[j--];
        }
    
        
        
        
        
    }
};