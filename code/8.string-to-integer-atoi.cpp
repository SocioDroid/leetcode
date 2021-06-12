class Solution {
public:
    int myAtoi(string s) {
        long long num = 0;
        int size = s.size();
            
        
        int i = 0;
        bool negative=false;
        
        while(i<size && s[i] == ' ')
            i++;
        
        
        // cout<<"i:"<<i<<endl;
        
        if(i<size-1 && (s[i] == '+' || s[i] == '-')){            
            if(s[i] == '-' )
                negative = true;
            i++;
        }
        // else if(i<size && ((int)s[i]<48 || (int)s[i]>57))
        //     return 0;
        
        
        while(i<size && ((int)s[i]>=48 && (int)s[i]<=57)){        
            // cout<<s[i]<<" : Now"<<endl;
            num *= 10;
            num+=(int)s[i] - 48;
            i++;
            if(num > INT_MAX)
                break;
        }
        
                
        if(num > INT_MAX){
            num = INT_MAX;            
            if(negative){
                num+=1;
                num*=-1;
                return num;
            }
            
        }   
        
        
        if(negative)
            return (int)num*-1;
        return (int)num;
    }
};