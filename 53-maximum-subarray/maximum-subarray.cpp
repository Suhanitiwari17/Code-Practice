class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currsum=0,maxsum=INT_MIN;
        for(int val:nums){
            currsum+=val;
            maxsum=max(currsum,maxsum);
            if(currsum<0){
                currsum=0;
            }
        }
        return maxsum;
    }
};