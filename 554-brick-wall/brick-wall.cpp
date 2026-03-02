class Solution {
public:
    int leastBricks(vector<vector<int>>& wall){
        unordered_map<long long, int> mp;
        int maxEdges_sum = 0;
        for(int i = 0; i < wall.size(); i++){
            long long curr_edge_sum = 0;
            for(int j = 0; j < wall[i].size() - 1; j++){
                curr_edge_sum += wall[i][j];
                mp[curr_edge_sum]++;
                maxEdges_sum = max(maxEdges_sum, mp[curr_edge_sum]);
            }
        }
        return wall.size() - maxEdges_sum;
    }
};