/*
 * @lc app=leetcode id=703 lang=cpp
 *
 * [703] Kth Largest Element in a Stream
 */

// @lc code=start
class KthLargest
{
public:
    int k;
    vector<int> nums;
    
    void heapify_top(int i){
        
        int n = this->nums.size();
        // cout<<"Received : "<<i<<endl;
        while(i<n/2){
            
            int mx = ((2*i)+1 < n && this->nums[(2*i)+1] < this->nums[i]) ? (2*i)+1 : i;
                mx = ((2*i)+2 < n && this->nums[(2*i)+2] < this->nums[mx]) ? (2*i)+2 : mx;
            
            if(mx == i)
                return;
            else{
                int temp = this->nums[mx];
                this->nums[mx] = this->nums[i];
                this->nums[i] = temp;
                i = mx;
            }            
        }        
    }

    void heapify_bottom(int index){

        int parent = (index-1)/2;
        if(parent>=0 && this->nums[index] < this->nums[parent]){
            swap(this->nums[index], this->nums[parent]);
            heapify_bottom(parent);
        }
    }

    void printHeap(){
        for(auto i: this->nums)
            cout<<i<<"\t";        
        cout<<endl;
    }

    KthLargest(int k, vector<int> &nums)
    {
        this->k = k;
        int n = nums.size();
        
        vector<int> temp;
        this->nums = temp;

        for(int i = 0; i<n; i++ ){                        
            
            if(i<k){
                this->nums.push_back(nums[i]);
                heapify_bottom(this->nums.size()-1);
            }else{

                if(this->nums[0]< nums[i]){
                    this->nums[0]=nums[i];
                    heapify_top(0);
                }
            }
         // printHeap();   
        }           
                
    }

    int add(int val)
    {
        if(this->nums.size()==0 || this->nums.size()<(this->k)){
            this->nums.push_back(val);
            heapify_bottom(this->nums.size()-1);            
        }else if(this->nums[0]<val){
            this->nums[0] = val;
            heapify_top(0);
        }
        return this->nums[0];
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
// @lc code=end

