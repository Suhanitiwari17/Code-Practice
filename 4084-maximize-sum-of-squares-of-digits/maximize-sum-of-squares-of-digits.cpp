class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if (sum > 9 * num) return "";

        string ans;
        int drevantor = sum;

        while (drevantor >= 9) {
            ans += '9';
            drevantor -= 9;
        }

        if (drevantor > 0) {
            ans += char(drevantor + '0');
        }

        while (ans.size() < num) {
            ans += '0';
        }

        return ans;
    }
};