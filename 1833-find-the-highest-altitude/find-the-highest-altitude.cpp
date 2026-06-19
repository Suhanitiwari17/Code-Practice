class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n = gain.size();

        vector<int> ans(n+1);

        ans[0] = 0;

        for(int i=0 ; i<n ; i++){
            ans[i+1] = ans[i] + gain[i];
        }

        sort(ans.begin() , ans.end());

        return ans[n];
    }
};