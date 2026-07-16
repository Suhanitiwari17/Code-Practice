class Solution {
public:

    int gcd(int a, int b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    }

    long long gcdSum(vector<int>& nums) {
        vector<int> mx;
        int maxi = INT_MIN;

        for(int i=0 ; i<nums.size() ; i++){
            maxi = max(maxi, nums[i]);
            mx.push_back(maxi);
        }
        
        vector<int> prefixGcd(nums.size());
        for(int i=0 ; i<nums.size();i++){
            prefixGcd[i] = gcd(nums[i] , mx[i]);
        }

        sort(prefixGcd.begin() , prefixGcd.end());
        int i = 0, j = prefixGcd.size() - 1;
        long long sum = 0;

        while (i < j) {
             sum += gcd(prefixGcd[i], prefixGcd[j]);
             i++;
             j--;
        }
        return sum;
    }
};