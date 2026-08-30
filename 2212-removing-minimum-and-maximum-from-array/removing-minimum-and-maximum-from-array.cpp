class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        if(n <= 2) return n;

        int minIdx = 0, maxIdx = 0;
        for(int k = 0; k < n; ++k){
            if (nums[k] < nums[minIdx]) minIdx = k;
            if (nums[k] > nums[maxIdx]) maxIdx = k;
        }

        int i = min(minIdx, maxIdx);
        int j = max(minIdx, maxIdx);

        return min({j + 1, n - i, (i + 1) + (n - j)});
    }
};