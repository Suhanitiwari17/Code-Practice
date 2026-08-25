class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(int i=0 ; i<nums.size() ; i++){
            mp[nums[i]]++;
        }
        int i=k;
        while(i){
             if(mp.find(i)==mp.end()){
                return i;
            }
            i=i+k;
        }
        return 0;
    }
};