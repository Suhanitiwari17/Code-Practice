class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(), nums.end());
        
        vector<long long> prefix(nums.size());
        prefix[0] = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            prefix[i] = prefix[i - 1] + nums[i];
        }
        
        vector<int> ans;
        ans.reserve(queries.size());
        
        for (int q : queries) {
            int idx = upper_bound(prefix.begin(), prefix.end(), q) - prefix.begin();
            ans.push_back(idx);
        }
        
        return ans;
    }
};
