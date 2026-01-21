class Solution {
public:
    bool isHappy(int n) {
        int temp=n;
        unordered_set<int> st;
        while(true){
            int first=0;
            while(n>0){
                int sec=n%10;
                first+=sec*sec;
                n/=10;
            }
            if(first==1){
                n=first;
                break;
            }
            n=first;
            if(st.find(first)!=st.end()) break;
            st.insert(first);
        }
        if(n==1){
           return true;
        }else{
            return false;
        }
        
    }
};