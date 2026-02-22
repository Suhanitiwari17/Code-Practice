class Solution {
public:
    int scoreDifference(vector<int>& nums) {
        int first = 0, second = 0;
        bool firstActive = true;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] % 2 == 1){
                firstActive = !firstActive;
            }
            if((i + 1) % 6 == 0){
                firstActive = !firstActive;
            }
            if(firstActive){
                first += nums[i];
            }
            else{
                second += nums[i];
            }
        }
        return first - second;
    }
};