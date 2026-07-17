class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        
        int mx = *max_element(nums.begin(), nums.end());

        vector<int> freq(mx + 1, 0);
        for (int x : nums) freq[x]++;

        vector<long long> cntDiv(mx + 1, 0);

        
        for (int i = 1; i <= mx; i++) {
            for (int j = i; j <= mx; j += i)
                cntDiv[i] += freq[j];
        }

        vector<long long> exact(mx + 1, 0);

        
        for (int g = mx; g >= 1; g--) {
            long long c = cntDiv[g];
            exact[g] = c * (c - 1) / 2;

            for (int mult = 2 * g; mult <= mx; mult += g)
                exact[g] -= exact[mult];
        }

        vector<long long> pref(mx + 1, 0);
        for (int i = 1; i <= mx; i++)
            pref[i] = pref[i - 1] + exact[i];

        vector<int> ans;
        for (long long q : queries) {
            int g = lower_bound(pref.begin() + 1, pref.end(), q + 1) - pref.begin();
            ans.push_back(g);
        }

        return ans;
    }
};