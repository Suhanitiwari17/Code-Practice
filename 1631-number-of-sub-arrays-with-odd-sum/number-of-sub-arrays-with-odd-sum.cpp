class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int MOD = 1e9 + 7;
        long long ans = 0;
        
        int prefixSum = 0;
        int evenCount = 1;
        int oddCount = 0;
        
        for(int num : arr){
            prefixSum += num;
            if(prefixSum % 2 != 0){
                ans = (ans+evenCount) % MOD;
                oddCount++;
            } 
            else{
                ans = (ans+oddCount) % MOD;
                evenCount++;
            }
        }
        return ans;
    }
};