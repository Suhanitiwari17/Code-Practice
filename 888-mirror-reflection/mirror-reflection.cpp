class Solution {
public:
    int mirrorReflection(int p, int q) {
        int lcm = (p * q) / __gcd(p, q);

        int m = lcm / p; // vertical
        int n = lcm / q; // horizontal

        if (m % 2 == 1 && n % 2 == 1) return 1;
        if (m % 2 == 1 && n % 2 == 0) return 2;
        return 0;
    }
};

