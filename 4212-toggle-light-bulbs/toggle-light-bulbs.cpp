class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
        int n= bulbs.size();
        vector<int> ans;
        unordered_map<int,int> mp;

        for(int i : bulbs){
          mp[i]++;
        }
        /*for(int i : bulbs){
            if(mp[i] % 2 == 0) continue;
            else{
                ans.push_back(i);
            }
        }*/
        for(auto &it:mp){
            if(it.second % 2!=0){
                ans.push_back(it.first);
            }
        }
        sort(ans.begin(), ans.end());
       return ans;
    }
};