class Solution {
public:
    int maxDepth(string s) {
        stack<int> st;
        int maxc = 0;
        int c = 0;
        for(char ch : s){
            if(ch == '('){
                c++;
                st.push(ch);
            }
            if(ch == ')'){
                if(c > maxc){
                    maxc = c;
                }
                c--;
                st.pop();
            }
        }
        return maxc;
    }
};