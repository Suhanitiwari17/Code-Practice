class Solution {
public:
    bool isPrime(int num) {
        if (num < 2) return false;
        if (num % 2 == 0) return num == 2;
        for (int i = 3; i * 1LL * i <= num; i += 2) {
            if (num % i == 0) return false;
        }
        return true;
    }

    int primePalindrome(int n) {
        if (n <= 2) return 2;
        if (n <= 3) return 3;
        if (n <= 5) return 5;
        if (n <= 7) return 7;
        if (n <= 11) return 11;

        for (int x = 1; x < 100000; x++) {
            string s = to_string(x);
            string rev = s;
            reverse(rev.begin(), rev.end());
            string pal = s + rev.substr(1); // odd length

            int num = stoi(pal);
            if (num >= n && isPrime(num)) {
                return num;
            }
        }
        return -1;
    }
};
