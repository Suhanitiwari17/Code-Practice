class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();

        int maxlen = 0;
        int left = 0;
        int zeroes = 0;

        for(int right=0 ; right<n ; right++){
            if(nums[right] == 0) zeroes++;

            while(zeroes > k){
                if(nums[left]==0) zeroes--;
                left++;
            }

            if(zeroes <= k){
                int len = right-left+1;
                maxlen = max(len , maxlen);
            }
        }
        return maxlen;
    }
};