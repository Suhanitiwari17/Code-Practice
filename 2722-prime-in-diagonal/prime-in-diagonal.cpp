class Solution {
public:
    bool isPrime(int n) {
        if (n <= 1) return false;
        for (int i = 2; i * i <= n; ++i) {
            if (n % i == 0) return false;
        }
        return true;
    }
    
    int diagonalPrime(vector<vector<int>>& nums) {
        int ans = 0;
        int n = nums.size();
        
        for (int i = 0; i < n; ++i) {
            int a = nums[i][i];              
            int b = nums[i][n - 1 - i];    

            if (isPrime(a)) ans = max(ans, a);
            if (isPrime(b)) ans = max(ans, b);
        }
        
        return ans;
    }
};
