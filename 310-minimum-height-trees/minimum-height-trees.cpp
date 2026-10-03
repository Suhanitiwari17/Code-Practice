class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 1) return {0};

        vector<vector<int>> adj(n);
        vector<int> degree(n , 0);

        for(auto arr : edges){
            int u = arr[0];
            int v = arr[1];
            adj[u].push_back(v);
            adj[v].push_back(u);

            degree[u]++;
            degree[v]++;
        }

        queue<int> q;
        for(int i=0;i<n;i++){
            if(degree[i]==1) q.push(i);
        }

        int rem = n;

        while(rem > 2){
            int size = q.size();
            rem -= size;

            while(size--){
                int node = q.front();
                q.pop();

                for(int e : adj[node]){
                    degree[e]--;
                    if(degree[e] == 1) q.push(e);
                }
            }
        }
        vector<int> ans;

        while(!q.empty()){
            ans.push_back(q.front());
            q.pop();
        }

        return ans;
    }
};