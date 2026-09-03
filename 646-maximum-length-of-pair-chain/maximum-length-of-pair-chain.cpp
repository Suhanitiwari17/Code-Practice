class Solution {
public:
    int t[1001][1001];
    int solve(vector<vector<int>>& nums , int prev , int curr){
        int n=nums.size();

        if(curr == n) return 0;

        if(prev != -1 &&  t[prev][curr] != -1) return t[prev][curr];

        int take = 0;
        if(prev == -1 || nums[curr][0] > nums[prev][1]){
            take = 1 + solve(nums , curr , curr+1);
        }

        int skip = solve(nums , prev , curr+1);

        if(prev != -1) t[prev][curr] = max(take,skip);

        return max(take,skip);
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        memset(t,-1,sizeof(t));
        sort(pairs.begin(),pairs.end());

        return solve(pairs,-1,0);
    }
};