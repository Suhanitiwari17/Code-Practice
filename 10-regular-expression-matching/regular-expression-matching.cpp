class Solution {
public:
    bool solve(int i , int j, string& s , string& p){
        if(j == p.length()) {
            return i == s.length();
        }

        bool fcm = false;

        if(i < s.length() && ( s[i] == p[j] || p[j]=='.' ) ) fcm = true;

        if(p[j+1] == '*'){
            bool skip = solve(i , j+2 , s , p);
            bool take = fcm && solve(i+1 , j , s , p);

            return take || skip;
        }
        else{
            return fcm && solve(i+1 , j+1 , s , p);
        }
    }
    bool isMatch(string s, string p) {
        return solve(0,0,s,p);
    }
};