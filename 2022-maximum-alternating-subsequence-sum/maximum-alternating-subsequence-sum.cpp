class Solution {
public:
    long long t[1000001][2];
    long long solve(vector<int>& nums , int i , bool flag){
        int n = nums.size();

        if(i>=n) return 0;

        if(t[i][flag] != -1) return t[i][flag];

        long long val = nums[i];

        if(!flag){
            val= -val;
        }

        long long take = val + solve(nums , i+1 , !flag);
        
        long long skip = solve(nums , i+1 , flag);

        return t[i][flag] = max(take , skip);
    }
    long long maxAlternatingSum(vector<int>& nums) {
        memset(t,-1,sizeof(t));

        long long ans = solve(nums , 0 , true);

        return ans;
        
    }
};