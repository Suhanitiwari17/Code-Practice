class Solution {
public:
    vector<string> result;
    
    void solve(int open, int close, string curr) {
        if(open == 0 && close == 0) {
            result.push_back(curr);
            return;
        }
        
        if(open > 0) {
            solve(open - 1, close, curr + "(");
        }
        
        if(close > open) {
            solve(open, close - 1, curr + ")");
        }
    }
    
    vector<string> generateParenthesis(int n) {
        solve(n, n, "");
        return result;
    }
};