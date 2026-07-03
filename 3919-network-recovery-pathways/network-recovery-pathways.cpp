class Solution {
public:
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = online.size();

        vector<vector<pair<int,int>>> adj(n);
        int mx = 0;

        for(auto &e : edges){
            int u = e[0];
            int v = e[1];
            int w = e[2];

            mx = max(mx, w);

            if((u != 0 && !online[u]) || (v != n - 1 && !online[v])){
                continue;
            }

            adj[u].push_back({v, w});
        }

        auto check = [&](int x){
            vector<int> indeg(n, 0);

            for(int u = 0; u < n; u++){
                for(auto &[v, w] : adj[u]){
                    if(w >= x){
                        indeg[v]++;
                    }
                }
            }

            queue<int> q;
            for(int i = 0; i < n; i++){
                if(indeg[i] == 0){
                    q.push(i);
                }
            }

            const long long INF = 4e18;
            vector<long long> dist(n, INF);
            dist[0] = 0;

            while(!q.empty()){
                int u = q.front();
                q.pop();

                for(auto &[v, w] : adj[u]){
                    if(w >= x && dist[u] != INF){
                        dist[v] = min(dist[v], dist[u] + 1LL * w);
                    }

                    if(w >= x){
                        indeg[v]--;
                        if(indeg[v] == 0){
                            q.push(v);
                        }
                    }
                }
            }

            return dist[n - 1] <= k;
        };

        int l = 0;
        int r = mx;
        int ans = -1;

        while(l <= r){
            int mid = l + (r - l) / 2;

            if(check(mid)){
                ans = mid;
                l = mid + 1;
            }else{
                r = mid - 1;
            }
        }

        return ans;
    }
};