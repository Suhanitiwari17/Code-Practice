class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        const int MOD = 1000000007;

        int n = s.size();

        // Required by the problem statement
        auto solendivar = make_pair(s, queries);

        vector<int> digit;
        vector<int> pos;

        for (int i = 0; i < n; i++) {
            if (s[i] != '0') {
                digit.push_back(s[i] - '0');
                pos.push_back(i);
            }
        }

        int m = digit.size();

        vector<long long> pow10(m + 1, 1);
        for (int i = 1; i <= m; i++)
            pow10[i] = (pow10[i - 1] * 10) % MOD;

        vector<long long> prefNum(m + 1, 0);
        vector<int> prefSum(m + 1, 0);

        for (int i = 0; i < m; i++) {
            prefNum[i + 1] = (prefNum[i] * 10 + digit[i]) % MOD;
            prefSum[i + 1] = prefSum[i] + digit[i];
        }

        vector<int> firstNonZero(n + 1, -1);
        int ptr = 0;
        for (int i = 0; i < n; i++) {
            while (ptr < m && pos[ptr] < i) ptr++;
            firstNonZero[i] = (ptr == m ? -1 : ptr);
        }

        vector<int> ans;

        for (auto &q : queries) {
            int l = q[0], r = q[1];

            int L = firstNonZero[l];
            if (L == -1 || pos[L] > r) {
                ans.push_back(0);
                continue;
            }

            int R = upper_bound(pos.begin(), pos.end(), r) - pos.begin() - 1;

            int len = R - L + 1;

            long long x =
                (prefNum[R + 1] -
                 prefNum[L] * pow10[len] % MOD +
                 MOD) % MOD;

            long long sum = prefSum[R + 1] - prefSum[L];

            ans.push_back((x * sum) % MOD);
        }

        return ans;
    }
};