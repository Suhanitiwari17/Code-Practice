class Solution {
public:
    int dfs(int i, int m, vector<int>& piles, vector<vector<int>>& dp) {
        if(i >= piles.size()) return 0;
        if(dp[i][m] != -1) return dp[i][m];
        int res = INT_MIN, sum = 0;
        for(int x = 1; x <= 2 * m && i + x <= piles.size(); x++){
            sum += piles[i + x - 1];
            res = max(res, sum - dfs(i + x, max(m, x), piles, dp));
        }
        return dp[i][m] = res;
    }
    
    int stoneGameII(vector<int>& piles){
        int n = piles.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        int total = accumulate(piles.begin(), piles.end(), 0);
        int diff = dfs(0, 1, piles, dp);
        return (total + diff) / 2;
    }
};