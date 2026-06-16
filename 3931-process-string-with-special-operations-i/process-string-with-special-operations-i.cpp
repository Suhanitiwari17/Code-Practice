class Solution {
public:
    string processStr(string s) {
        int n = s.length();

        string ans="";

        for(char ch : s){
          if(ch >= 'a' && ch <= 'z'){
            ans.push_back(ch);
          }
          else if(ch == '#'){
            ans += ans;
          }
          else if(ch == '*'){
                if(!ans.empty()){
                    ans.pop_back();
                }
          }else if(ch == '%'){
            reverse (ans.begin() , ans.end());
          }
        }

        return ans;
    }
};