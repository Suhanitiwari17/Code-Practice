class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        string ans = "";
        int n = s.size();

        for (int i = 0; i < n; i++) {
            int ones = 0;

            for (int j = i; j < n; j++) {
                ones += (s[j] == '1');

                if (ones == k) {
                    string cur = s.substr(i, j - i + 1);

                    if (ans.empty() ||
                        cur.size() < ans.size() ||
                        (cur.size() == ans.size() && cur < ans)) {
                        ans = cur;
                    }

                    break;
                }
            }
        }

        return ans;
    }
};