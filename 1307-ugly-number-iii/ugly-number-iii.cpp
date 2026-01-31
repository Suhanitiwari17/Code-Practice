class Solution {
public:
    long long lcm(long long x, long long y) {
        return x / __gcd(x, y) * y;
    }
    
    int nthUglyNumber(int n, int a, int b, int c) {
        long long left = 1, right = 2e9;
        long long ab = lcm(a,b), ac = lcm(a,c), bc = lcm(b,c);
        long long abc = lcm(ab,c);

        while(left < right) {
            long long mid = left + (right-left)/2;
            long long count = mid/a + mid/b + mid/c - mid/ab - mid/ac - mid/bc + mid/abc;
            if(count < n) left = mid + 1;
            else right = mid;
        }
        return (int)left;
    }
};
