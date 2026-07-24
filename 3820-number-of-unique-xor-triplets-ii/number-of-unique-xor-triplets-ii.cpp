class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int m = 2048;

        vector<vector<bool>> dp(4, vector<bool>(m, false));
        dp[0][0] = true;

        for (int x : nums) {
            vector<vector<bool>> temp = dp;

            for (int i = 0; i <= 3; i++) {
                for (int j = 0; j < m; j++) {
                    if (!dp[i][j]) continue;

                    if (i + 1 <= 3)
                        temp[i + 1][j ^ x] = true;

                    if (i + 2 <= 3)
                        temp[i + 2][j] = true;

                    if (i + 3 <= 3)
                        temp[i + 3][j ^ x] = true;
                }
            }

            dp = temp;
        }

        int ans = 0;
        for (int i = 0; i < m; i++) {
            if (dp[3][i]) ans++;
        }

        return ans;
    }
};