class Solution {
public:
    int minElement(vector<int>& nums) {
        vector<int> result;
        for(int i=0 ; i<nums.size() ; i++){
            int sum = 0;
            while(nums[i] > 0){
                int n = nums[i] % 10;
                sum += n;
                nums[i] = nums[i]/10;
            }
            result.push_back(sum);
        }
        sort(result.begin() , result.end());

        return result[0];
    }
};