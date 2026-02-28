class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        vector<int> ans(n, -1);

        unordered_map<int,int> last;
        set<int> dryDays;

        for(int i = 0; i < n; i++){
            if(rains[i] == 0){
                dryDays.insert(i);
                ans[i] = 1;
            }
            else{
                int lake = rains[i];
                if(last.count(lake)){
                    auto it = dryDays.lower_bound(last[lake]);
                    if(it == dryDays.end()) return {};
                    ans[*it] = lake;
                    dryDays.erase(it);
                }
                last[lake] = i;
            }
        }
        return ans;
    }
};