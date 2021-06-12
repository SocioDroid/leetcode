class Solution {
public:
    string countAndSay(int n) {
        
        if(n == 1)
            return "1";
        if(n==2)
            return "11";
        
        string res = countAndSay(n-1);
        
        // cout<<"\nResult recvd : "<<res << endl;
        
        string temp = "";        
        int i = 0;
        // string res = "21";
        for(; i<res.size(); i++){
            
            cout<<"i:"<<i<<endl;
            
            int count = 1;
            
            char c = res[i];
            
            // cout<<"i:"<<i<<endl;

            
            while(i+1<res.size() && res[i+1] == c){
                
                count++;            
                // cout<<"Inside while: i :"<<i<<endl;
                i++;
                
            }
            temp+=to_string(count)+c;
            
            // cout<<i<<":i \tTemp : "<<temp<<endl;
            
            // cout<<"Temp : "<<temp<<endl;
        }        
        return temp;
    }
};