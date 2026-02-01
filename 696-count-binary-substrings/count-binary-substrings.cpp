class Solution {
public:
    int countBinarySubstrings(string s) {
        int prevCount = 0;
        int currCount = 1;
        int ans = 0;

        for (int i = 1; i < s.size(); i++) {
            if (s[i] == s[i - 1]) {
                currCount++;
            } else {
                ans += min(prevCount, currCount);
                prevCount = currCount;
                currCount = 1;
            }
        }

        ans += min(prevCount, currCount);
        return ans;
    }
};
