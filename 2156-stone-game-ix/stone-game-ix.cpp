class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int cnt[3] = {};

        for (int x : stones)
            cnt[x % 3]++;

        int zero = cnt[0], one = cnt[1], two = cnt[2];

        auto check = [&](int a, int b) {
            if (a == 0) return false;

            a--;

            int pairs = min(a, b);
            int len = 1 + 2 * pairs + zero;

            a -= pairs;
            b -= pairs;

            if (a > 0) {
                len++;
                a--;
            }

            return (len % 2 == 1) && (a + b > 0);
        };

        return check(one, two) || check(two, one);
    }
};