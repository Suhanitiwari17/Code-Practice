class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;

    void dfs(int node, vector<vector<int>>& graph) {
        path.push_back(node);

        if (node == graph.size() - 1) {
            ans.push_back(path);
            path.pop_back();
            return;
        }

        for (int next : graph[node]) {
            dfs(next, graph);
        }

        path.pop_back();
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        dfs(0, graph);
        return ans;
    }
};