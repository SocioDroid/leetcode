class Solution {
public:
    void print2d(vector<vector<int>> & nums){
	for(auto i: nums){
		for(auto j: i)
			cout<<j<<" ";
		cout<<endl;
	}
	cout<<"---------\n";
}


void print1d(vector<int> &nums){
	for(auto i: nums){
		cout<<i<<" ";
	}
	cout<<"--------\n";
}


    vector<vector<int>> generateMatrix(int n) {        
        vector<vector<int>> res(n, vector<int>(n,0));
        int total = n*n;
        int count = 1;
        
        int left = 0, top = 0, bottom = n-1, right = n-1;
        int dir = 0;
        while(count!=total+1){
            if(dir == 0)
            {
                
                cout<<"LeftDIR : Count: "<<count<<"\tl:"<<left<<"\tr:"<<right<<endl;
                for(int i = left; i<=right; i++)
                    res[top][i] = count++;
                top++;
                dir = 1;
            }
            else if(dir == 1)
            {
                cout<<"BottomDIR : Count: "<<count<<"\tt:"<<top<<"\tb:"<<bottom<<endl;

                for(int i = top; i<=bottom; i++)
                    res[i][right] = count++;
                right--;
                dir = 2;
            }
            else if(dir == 2)
            {
                cout<<"RIghtDIR : Count: "<<count<<"\tl:"<<left<<"\tr:"<<right<<endl;
                
                for(int i = right; i>=left; i--)
                    res[bottom][i] = count++;
                bottom--;
                dir = 3;
            }
            else if(dir == 3)
            {
                cout<<"BottomDIR : Count: "<<count<<"\tt:"<<top<<"\tb:"<<bottom<<endl;
                
                for(int i = bottom; i>=top; i--)
                    res[i][left] = count++;
                left++;
                dir = 0;
            } 
            // print2d(res);
        }
        // res[n/2][n/2] = total;
        return res;
        
    }
};