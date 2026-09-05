class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = INT_MAX;

        for(int i=0 ; i<n ; i++){
            int maxi = INT_MIN;
            for(int j=0 ; j<=i ; j++){
                maxi = max(maxi , nums[j]);
            }
            int mini = INT_MAX;
            for(int r=i ; r<n ; r++){
                mini = min(mini , nums[r]);
            }

            if(maxi - mini <= k) {
                return i;
            }
        }
        if(ans != INT_MAX) return ans;
        else return -1;
    }
};