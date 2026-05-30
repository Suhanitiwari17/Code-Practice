class Solution {
public:
    vector<int> limitOccurrences(vector<int>& nums, int k) {
       vector<int> ans;

       int count = 0;

       for(int i=0 ; i<nums.size() ; i++){
        if(i==0 || nums[i] != nums[i-1]){
            count = 1;
        }
        else{
            count++;
        }

        if(count <= k) ans.push_back(nums[i]);
       }
       return ans;
    }
};