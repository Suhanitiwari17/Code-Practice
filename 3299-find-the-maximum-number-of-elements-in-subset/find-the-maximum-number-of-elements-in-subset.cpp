class Solution {
public:
    int maximumLength(vector<int>& nums){
        long long result = 0;
        map<int, int> mp;
        for(auto &num : nums){
            mp[num]++;
        }
        for(auto &it : mp){
            long long val = it.first;
            long long freq = it.second;
            long long length = 0;
            if(val == 1){
                length += freq;
                mp[val] = 0;
                if(length % 2 == 0){
                    length--;
                }
                result = max(result, length);
                continue;
            }
            while(val <= 1000000000 && mp[val] > 0){
                length += 2;
                if(mp[val] == 1){
                    break;
                }
                mp[val] = 0;
                val = val * val;
            }
            length--;
            result = max(result, length);
        }
        return result;
    }
};