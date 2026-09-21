class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> ans(k, 0);
        vector<long long> dp(k, 0);

        for(int num : nums) {
            int mod = num % k;

            vector<long long> nextDp(k, 0);

            nextDp[mod] += 1;

            for(int r = 0; r < k; r++) {
                int newMod = (r * mod) % k;

                nextDp[newMod] += dp[r];
            }

            for(int r = 0; r < k; r++) {
                ans[r] += nextDp[r];
            }

            dp = nextDp;
        }

        return ans;
    }
};