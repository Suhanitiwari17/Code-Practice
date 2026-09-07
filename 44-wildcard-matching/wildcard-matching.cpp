class Solution {
public:
    int t[2001][2001];
    bool solve(int i , int j , string& s , string& p){
        if(j == p.length()){
            if(i == s.length()) return true;
            
        }

        if(t[i][j] != -1) return t[i][j];

        bool fcm = false;

        if(i<s.length() && (s[i]==p[j] || p[j]=='?')) fcm = true;


        if(p[j] == '*'){
            bool skip = solve(i , j+1 , s ,p);
            bool take = (i<s.length()) && solve(i+1 , j , s , p );


            return t[i][j] = take || skip;
        }

        else return t[i][j] = fcm && solve(i+1 , j+1 , s ,p);
        t[i][j] = false;


    }
    bool isMatch(string s, string p) {
        memset(t , -1 , sizeof(t));
        return solve(0,0,s,p);
    }
};