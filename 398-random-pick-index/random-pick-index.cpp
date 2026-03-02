class Solution {
    vector<int> nums;
public:
    Solution(vector<int>& nums) {
        this->nums = nums;
    }
    int pick(int target) {
        int count = 0;
        int ans = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == target) {
                count++;
                if (rand() % count == 0) {
                    ans = i;
                }
            }
        }
        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */