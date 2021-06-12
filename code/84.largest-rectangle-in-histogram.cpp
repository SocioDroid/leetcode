class Solution {
public:

    void print1d(vector<int> &nums){
        for(auto i: nums){
            cout<<i<<" ";
        }
        cout<<"\n--------\n";
    }

    int largestRectangleArea(vector<int>& heights) {
        
        int n = heights.size();
        
        // left
        vector<int> left(n);
        
        // index, value
        stack<int> st;
        
        for(int i = 0; i<n; i++)
        {
            if(st.empty())
                left[i] = -1;
            
            else if(heights[st.top()] >= heights[i])
            {
                while(!st.empty() && heights[st.top()] >= heights[i])
                {
                    st.pop();    
                }
                if(st.empty())                    
                    left[i] = -1;
                else
                    left[i] = st.top();                                
            }
            else if(heights[st.top()] < heights[i])
                left[i] = st.top();
            
            st.push(i);            
        }
        
        // print1d(left);
        // right
        
        vector<int> right(n);
        
        stack<int> st1;
        
        for(int i = n-1; i>=0; i--)
        {
            if(st1.empty())
                right[i] = n;
            
            else if(heights[st1.top()] >= heights[i])
            {
                while(!st1.empty() && heights[st1.top()] >= heights[i])
                {
                    st1.pop();    
                }
                if(st1.empty())                    
                    right[i] = n;
                else
                    right[i] = st1.top();                                
            }
            else if(heights[st1.top()] < heights[i])
                right[i] = st1.top();
            
            st1.push(i);            
        }
        
        // print1d(right);
        
        // width        
        int maxwidth = INT_MIN;
        for(int i = 0; i<n; i++)
        {
            maxwidth = max(maxwidth, (right[i] - left[i] -1 )* heights[i]);
        }
        
        return maxwidth;
    }
};