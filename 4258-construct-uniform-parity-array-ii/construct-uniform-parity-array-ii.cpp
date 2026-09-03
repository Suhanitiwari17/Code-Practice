class Solution {
public:
    bool uniformArray(vector<int>& nums) {
        int minValue = *min_element(nums.begin(), nums.end());

        if (minValue % 2 == 1)
            return true;

        for (int num : nums) {
            if (num % 2 == 1)
                return false;
        }

        return true;
    }
};