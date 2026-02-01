class Solution {
public:
    vector<vector<int>> ans;
    
    void backtrack(vector<int>& nums, vector<int>& path, vector<bool>& used) {
        if (path.size() == nums.size()) {
            ans.push_back(path);
            return;
        }
        
        for (int i = 0; i < nums.size(); i++) {
          
            if (used[i]) continue;
           
            if (i > 0 && nums[i] == nums[i-1] && !used[i-1]) continue;
            
            path.push_back(nums[i]);
            used[i] = true;

            backtrack(nums, path, used);
            used[i] = false;

           path.pop_back();
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end()); 

        vector<bool> used(nums.size(), false);
        vector<int> path;

        backtrack(nums, path, used);


        return ans;
    }
};
