class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int minlen = INT_MAX;
        int left = 0;
        int sum=0; 

        for(int right = 0 ; right<nums.size() ; right++){
            sum += nums[right];

            while(sum >= target){
                minlen = min(minlen , right-left+1);
                sum -= nums[left];
                left++;
            }
        }
        return minlen == INT_MAX ? 0 : minlen;
    }
};