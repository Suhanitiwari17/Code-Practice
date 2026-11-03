
class Solution {
public:
    int minMoves(vector<int>& nums) {
        int maxNum = *max_element(nums.begin(), nums.end());
        int moves = 0;

        for (int num : nums) {
            moves += maxNum - num;
        }

        return moves;
    }
};
