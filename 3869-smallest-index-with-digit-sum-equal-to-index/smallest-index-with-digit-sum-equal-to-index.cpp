class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        int n = nums.size();

        int ans = INT_MAX;

        for(int i=0 ; i<n ; i++){
            int numb = nums[i];

            int sum = 0;

            while(numb > 0){
                int d = numb % 10;
                sum += d;
                numb = numb/10;
            }

            if(sum == i){
                ans = min(ans , i);
            }
        }

        if(ans != INT_MAX) return ans;
        else return -1;
    }
};