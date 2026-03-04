class Solution {
    int m, n;
    bool isValid(int seconds, vector<int> changeIndices, vector<int> nums){
        vector<int> lastPosition(n + 1, -1);
        for(int i = 0; i <= seconds; i++){
            int idx = changeIndices[i];
            lastPosition[idx] = i + 1;
        }
        for(int i = 1; i <= n; i++){
            if(lastPosition[i] == -1){
                return false;
            }
        }
        map<int, int> positionIndexMap;
        for(int i = 1; i <= n; i++){
            int position = lastPosition[i];
            positionIndexMap[position] = i;
        }
        int used_till = 0;
        for(auto &it : positionIndexMap){
            int position = it.first;
            int index = it.second;
            int req = 1 + nums[index - 1];
            if(used_till + req > position){
                return false;
            }
            used_till += req;
        }
        return true;
    }
public:
    int earliestSecondToMarkIndices(vector<int>& nums, vector<int>& changeIndices){
        m = changeIndices.size();
        n = nums.size();
        for(int time = 0; time < m; time++){
            if(isValid(time, changeIndices, nums)){
                return time + 1;
            }
        }
        return -1;
    }
};