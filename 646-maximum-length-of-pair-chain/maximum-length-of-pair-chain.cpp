class Solution {
public:
    int t[1001][1001];
    int solve(vector<vector<int>>& pairs , int i, int prev){
        if(i >= pairs.size()) return 0;

        int take = 0;

        if(prev != -1 && t[i][prev] != -1) return t[i][prev];
        
        if(prev == -1 || pairs[i][0] > pairs[prev][1]){
            take = 1 + solve(pairs , i + 1 , i);
        }

        int skip = solve(pairs , i+1 , prev);

        if(prev != -1) t[i][prev] = max(take,skip);

        return max(take,skip);

    }
    int findLongestChain(vector<vector<int>>& pairs) {
        memset(t,-1,sizeof(t));

        sort(begin(pairs) , end(pairs));

        return solve(pairs,0,-1);
    }
};